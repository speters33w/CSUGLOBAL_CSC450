#include <iostream>
#include <regex>
#include <string>
#include <cmath>

void printf_overflow_example();
void use_get_integer();
int get_integer_from_data();
int digit_validation();
int cin_fail();
int afs();
void password();
int numeric_input_validation();

using namespace std;

int student_examples_main() {
    int value = -1;
//    printf_overflow_example(); // This was the example given by Jay Spears.
//    value = get_integer_from_data(); // This was my example.
//    value = digit_validation(); // This was the example given by Jason Huish.
//    value = cin_fail(); // This was the example given by Gino Garcia in response to Jason.
    value = afs(); // This was the example given by Kody Luke.
//    password(); // This was the example given by Brandin Porter.
//    value = numeric_input_validation(); // This was the example given by Ja'mira Yates.

    if(value != -1) {
        fprintf(stdout, "\nThe value returned is %d.", value);
    }
    return 0;
}

// This was the example given by Jay Spears.
// todo not displaying vulnerability.
// testString = "ThisStringConsumesMoreThanOne-HundredCharacters.ThatIs,IfYouEnterTheEntireStringAllTheWayToTheEndOfIt%p%p."
void printf_overflow_example() {
    char buffer[100];
    std::cout << "Enter your address: ";
    std::cin >> buffer;

    // Print whatever is in 'buffer' to the console (format vulnerability)
    printf(buffer);
}

// This was the example given by Jason Huish.
int digit_validation() {
    string input;
    bool control = false;  //loop controller
    cout << "Enter an  integer: ";
    cin >> input;
    while (control == false) {
        for (int i = 0; i < input.length(); i++) {
            if (isdigit(input[i]) == false ) { //isdigit returns true if the parameter can be converted to an int
                cout << "Not a number, try again." << endl;
                cin >> input;
            }
            else {
                control = true; //input is a number, breaks the loop
            }
        }
    }
    cout << input << " is a number.";

    return stoi(input);
}

// This was the example given by Gino Garcia.
int cin_fail() {
    int num;

    cin >> num;

    if(cin.fail()) {
        cout << "Bad" << endl;
        return -1;
    }
    else {
        cout << "Good" << endl;
        cout << num;
        return num;
    }
}

// This was the example given by Kody Luke.
int afs() {
        int a;
        float af;
        string afs;

//// This works well for a simple integer. Truncates chars after number
        cout << "input number" << endl;
        cin >> a;           //cin.good() returns boolean of if any exceptions occurred.
        while (!cin.good()){
            cin.clear();
            cin.ignore(INT_MAX, '\n'); // remember these to clear characters

            cout << "Improper input." << endl;
            cin >> a;
        }
        cout << a << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
/*
    cout << "input number" << endl;
    cin >> a;
    while(cin.fail()){
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        cout << "Improper input." << endl;
        cin >> a;
    }
    cout << a << endl;
*/
//////////////////////// Float, commented out lines work the same as first section
/*
     cout << "input float number" << endl;
        cin >> af;
        while (!cin.good()){ // Fails 1.!
            cin.clear();
            cin.ignore(INT_MAX, '\n');

            cout << "Improper input." << endl;
            cin >> af;
        }
        cout << af << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
*/

/*
    cout << "input float number" << endl;
    cin >> af;
    while (cin.fail()){
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        cout << "Improper input." << endl;
        cin >> af;
    }
    cout << af << endl;
    cin.clear();
    cin.ignore(INT_MAX, '\n');


    cout << "input float number" << endl;
    while (!(cin>>af)){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Improper input." << endl;
    }
    cout << af << endl;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
*/
        // This seams like the best way I have found so far to handle decimal numbers.
        cout << "input float number" << endl;
        bool valid = false;
        while(!valid) {
            getline(cin, afs);                                        // find_first_not_of()
            if (afs.find_first_not_of("1234567890.-") != string::npos) { // searches afs for chars not matching
                cout << "invalid number: " << afs << endl;                  // "1234567890.-", if something is found returns char
            }                                                               // else returns npos, which stands for no position
            else{
                valid = true;
            }
        }
        af = stof(afs); //converts string to float
        cout << af << endl;
//    return round(af); // NOLINT(cppcoreguidelines-narrowing-conversions)
        return a;
}

void password() {
    char password[9]; // buffer that allocates 8 characters

    cout << "Enter your password: ";
    cin >> password; //sets input as password, notice how there is no limit to user input


    if (strcmp(password, "password") == 0) { //compares password to stored password
        cout << "Access granted!" << endl; //if they are equal, grant access
    } else {
        cout << "Access denied!" << endl; //if not equal, access denied
    }
}

// This was the example given by Ja'mira Yates.
// From https://cplusplus.com/forum/beginner/58833/
int numeric_input_validation() {
    int num; //variable to store the number entered by the user.

    //Prompt the user to enter an integer.
    cout << "Enter an integer " ;
    cin >> num;

    //While the input entered is not an integer, prompt the user to enter an integer.
    while(!cin)
    {
        cout << "That was no integer! Please enter an integer: ";
        cin.clear();
        cin.ignore();
        cin >> num;
    }

    //Print the integer entered by the user to the screen.
    cout << "The integer entered is " << num << endl;

    return num;
}

// This was my example.
void use_get_integer() {
    int integer_1 = get_integer_from_data(), integer_2 = get_integer_from_data(), integer_3 = get_integer_from_data();
    fprintf(stdout, "Integer 1 = %d, Integer 2 = %d, Integer 3 = %d.",
            integer_1, integer_2, integer_3);
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
int get_integer_from_data() {
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
