/*
 * Simple Program with a few Errors corrected.
 * (CSC450_CT1_mod1_2.cpp)
 */

#include <iostream>
#include <iomanip>
//#include <conio.h>

// Standard namespace declaration
using namespace std;

// Main Function that calls this function is in critical_thinking_1.cpp
// To run this as a stand-alone application, change the name of this function to main()
int CSC450_CT1_mod1_2() {

    //this should be printed out
    double myMoney = 1000.50;


    // Standard Output Statement
    cout << "Please be sure to correct all syntax errors in this program." << endl;

    cout << "I have corrected all errors for this program." << endl;

    cout << "The total amount of money available is ";
    cout << setprecision(2) << fixed << "$" << myMoney << endl;

    // Wait For Output Screen
    getchar();

    // Function return Statement
    return 0;
}
