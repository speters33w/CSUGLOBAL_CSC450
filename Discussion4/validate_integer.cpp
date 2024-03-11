// https://stackoverflow.com/questions/78134690/regex-match-a-pattern-that-only-contains-one-set-of-numeral-and-not-more
#include <cmath>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

void test_input(const string& input);

void run_tests();

int validate_integer(const string& input);

int main() {
    run_tests();
    return 0;
}

void test_input(const string& input){
    const char* inputValue = input.c_str();
    try {
        fprintf(stdout,
                "The input was: \"%s\"; The parsed integer is %d \n",
                inputValue,
                validate_integer(input));
    } catch (invalid_argument const &ia) {
        fprintf(stdout,
                "The input was: \"%s\"; Threw an invalid argument exception \n",
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
    //The following (correctly) throw invalid argument exceptions
    test_input("21,12");
    test_input("\"21\",\"12\","); // NOLINT(modernize-raw-string-literal)
    test_input("<span style = \"font-size:18.0pt\">2112</span>");
    test_input("21TwentyOne12");
    test_input("21-12");
    test_input("21.12.21.12");
    test_input("<span class=\"crimson-text\">-2112</span>");
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
int validate_integer(const string& input) {
    if(regex_match(input, regex("[^0-9.-]*[-.0-9]+[^0-9.]+[-.0-9]+.*"))
       | regex_match(input, regex("[^0-9-]*[-]+[^0-9]+.*"))
       | regex_match(input, regex(".*[.]+.*[.]+.*"))
       ) {
            throw std::invalid_argument("invalid input: " + input + " \n");
    }
    return round(stof(regex_replace(input, regex(R"([^0-9.-]+)"), "")));
}
#pragma clang diagnostic pop
