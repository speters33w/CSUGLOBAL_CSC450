/*
 * A simple C++ program that obtains input from a user
 * and appends the user input into a file
 * Then reads the contents of the file,
 * reverses the contents,
 * then stores them in another file.
 * (CSC450_CT5_append_reverse.cpp)
 */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

inline bool exists_file(const string &name);

string read_file(const string &filePath, const string &fileName);

void append_string(const string &filePath, const string &fileName);

void reverse_string_to_file(string stringToReverse, const string &filePath, const string &reverseFileName);

/*
 * This is the main runner engine for the program.
 */
int main() {
    string filePath = "../"; // This relative path works with my IDE. Modify it if necessary.
    string fileName = "CSC450_CT5_mod5.txt";
    string reverseFileName = "CSC450-mod5-reverse.txt";
    append_string(filePath, fileName);
    cout << "Data appended successfully" << endl;
    string fileContents = read_file(filePath, fileName);
//    cout << fileContents << endl;
    reverse_string_to_file(fileContents, filePath, reverseFileName);
//    string reverseFileContents = read_file(filePath, reverseFileName);
//    cout << reverseFileContents << endl;
    return 0;
}

/*
 * Checks to see if a file exists.
 */
inline bool exists_file(const string &name) {
    ifstream f(name.c_str());
    return f.good();
}

/*
 * Reads contents of a text file and returns the entire contents as a string.
 */
string read_file(const string &filePath, const string &fileName) {
    ifstream t(filePath + fileName);
    stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

/*
 * Appends user input from the console to a file.
 * Allows multiple lines.
 * The user indicates the input is complete by typing q.
 */
void append_string(const string &filePath, const string &fileName) {
    bool done = false;
    string userString;
    ofstream fileStream;
    if (!exists_file(filePath + fileName)) {
        fprintf(stdout, "Could not open file for editing: %s%s.", filePath.c_str(), fileName.c_str());
        throw std::ios_base::failure("Could not open file for editing: " + filePath + fileName);
    }
    fileStream.open(filePath + fileName, ios::out | ios::app);
    cout << "Enter the data to append. Enter q to finish entry: " << endl;
    while (!done) {
        getline(cin, userString);
        if (userString == "q") {
            done = true;
        } else {
            fileStream << endl << userString;
        }
    }
    fileStream.close();
}

/*
 * Reverses a string and saves it to a file.
 * The string may include line breaks.
 */
void reverse_string_to_file(string stringToReverse, const string &filePath, const string &reverseFileName) {
    ofstream fileStream;
    reverse(stringToReverse.begin(), stringToReverse.end());
    fileStream.open(filePath + reverseFileName);
    fileStream << stringToReverse;
    fileStream.close();
}
