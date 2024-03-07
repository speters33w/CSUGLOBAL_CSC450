#include <iostream>
#include <regex>
#include <string>

int get_integer();

using namespace std;

int main2() {
    int integer_1 = get_integer(), integer_2 = get_integer(), integer_3 = get_integer();
    fprintf(stdout, "Integer 1 = %d, Integer 2 = %d, Integer 3 = %d.",
            integer_1, integer_2, integer_3);
    return 0;
}

/*
 * This function autocorrects typos or improperly sanitized input
 * from a data source and ensures input may be interpreted as an integer.
 * <2112>, [(2112)], "2112,", 2112.0, <span style = "numeral">2112</span>
 * will all be interpreted as 2112.
 * 12ThreeFour56 will be interpreted as 1256
 * 67.89 will be interpreted as 67
 * 98-76 will be interpreted as 98
 * It will ask the user to re-enter data if there are no digit values.
 * It will ask the user to re-enter if the integer is out of range.
 * Valid integer data, e.g. -1234 or 9876 is returned as entered.
 */
int get_integer() {
    int integer;
    string input;
    bool valid;
    cout << "Enter an integer value: ";
    do {
        getline(cin, input);
        try {
            integer = stoi(regex_replace
                                   (input, regex(R"([^\-0-9.]+)"), ""));
            valid = true;
        } catch (invalid_argument const &ia) {
            valid = false;
            cout << "Input cannot be parsed. "
                    "Enter a valid integer value: ";
            cin.clear();
        } catch (out_of_range const &oor){
            valid = false;
            cout << "Input is out of range for this machine. "
                    "Enter a valid integer value: ";
            cin.clear();
        }
    } while (!valid);
    return integer;
}
