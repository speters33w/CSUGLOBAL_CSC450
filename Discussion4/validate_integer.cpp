// https://stackoverflow.com/questions/78134690/regex-match-a-pattern-that-only-contains-one-set-of-numeral-and-not-more
#include <cmath>
#include <cstring>
#include <iostream>
#include <regex>
#include <string>
//#define PCRE2_CODE_UNIT_WIDTH 8
//#include <pcre2.h>

using namespace std;

void test_input(const string& input);

void run_tests();

int validate_integer(const string& input);

int main(int argc, char *argv[]) {
    if (argc == 1
    || strcmp(argv[1],  "-h") == 0
    || strcmp(argv[1], "--h") == 0
    || strcmp(argv[1],  "/?") == 0
            ){
        cout << endl << "parseint attempts to parse an integer from unsanitized input. \n"
        << R"(Syntax: parseint "string1" "string2" ...)" << endl << endl;
        run_tests();
    }
    else {
        for (int i = 1; i < argc; ++i) {
            cout << validate_integer(argv[i]) << endl;
        }
    }
    return 0;
}

void test_input(const string& input){
    const char* inputValue = input.c_str();
    try {
        fprintf(stdout,
                "If the input is: \"%s\"; The parsed integer is %d \n",
                inputValue,
                validate_integer(input));
    } catch (invalid_argument const &ia) {
        fprintf(stdout,
                "\"%s\" will throw an invalid argument exception \n",
                inputValue);
    } catch (out_of_range const &oor) {
        fprintf(stdout,
                "\"%s\" will throw an out of range exception \n",
                inputValue);
    }
}

void run_tests() {
    test_input("<2112>");
    test_input("{2112}");
    test_input("[(2112)]");
    test_input("\"2112,\"");
    test_input("-2112");
    test_input("<span style = \"numeral\">2112</span>");
    test_input("yyz=2112");
    test_input("The number is 2112.");
    test_input(".2112");
    test_input("2112.0");
    test_input("21.12");
    test_input("98.89");
    test_input("2112-The Year");
    test_input("2,112,112");
    //The following should (correctly) throw out of range exceptions
    test_input("211221122112");
    //Input like the following will unfortunately throw an invalid argument exception
    test_input("<span style = \"font-size:18.0pt\">2112</span>");
    test_input("<span class=\"crimson-text\">-2112</span>");
    //The following should (correctly) throw invalid argument exceptions
    test_input("21,12");
    test_input("\"21\",\"12\","); // NOLINT(modernize-raw-string-literal)
    test_input("21TwentyOne12");
    test_input("21-12");
    test_input("21.12.21.12");
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
int validate_integer(const string& input) {
    // force out of range exception if integer will be out of range
    string oorCheck = "0" + input;  // so .2112 will be valid
    stoi(regex_replace(oorCheck, regex(R"([^0-9.-]+)"), ""));
    if(regex_match(input, regex(".*([,]+[0-9]{3})+.*"))){
        return round(stof(regex_replace(input, regex(R"([^0-9.-]+)"), "")));
    }
    if(regex_match(input, regex("[^0-9.-]*[-.0-9]+[^0-9.]+[-.0-9]+.*"))
       || regex_match(input, regex("[^0-9-]*[-]+[^0-9]+.*"))
       || regex_match(input, regex(".*[.]+.*[.]+.*"))
       ) {
            throw std::invalid_argument("invalid input: " + input + " \n");
    }
    return round(stof(regex_replace(input, regex(R"([^0-9.-]+)"), "")));
}
#pragma clang diagnostic pop
