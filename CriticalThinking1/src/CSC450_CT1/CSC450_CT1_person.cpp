//
// Created by StephanPeters on 2/12/2024.
//

/*
 * A simple C++ console application that prints information for a fictional person.
 * Returns the snarky responses from the bank form in the Infocom Text Adventure "Bureaucracy".
 * (CSC450_CT1_person.cpp)
 */

#include <iostream>
#include <random>
#include <string>
#include <conio.h>

// Standard namespace declaration
using namespace std;

// Main Function that calls this function is in critical_thinking_1.cpp
// To run this as a stand-alone application, change the name of this function to main()
int CSC450_CT1_person() {
    string first_name;
    string last_name;
    string street_address;
    string city;
    string zip;

    // Generate random number to pick snarky response.
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist(0, 2); // distribution in range [0, 2]

    // Snarky responses
    string first_name_response = {"Your parents had the last laugh."};
    string last_name_response[] = {"How embarrassing for you.", "A well-known criminal family.",
                                   "One of a long line of losers."};
    string street_address_response[] = {"Due to be condemned.", "The bad part of town.",
                                        "Next to the dump."};
    string city_response[] = {"What a dump.", "What a pit.", "You'd better move again."};

    // Get information from user.
    cout << "First name: ";
    getline(cin, first_name);
    cout << first_name_response << endl << endl;

    cout << "Last name: ";
    getline(cin, last_name);
    cout << last_name_response[dist(rng)] << endl << endl;

    cout << "Street address: ";
    getline(cin, street_address);
    cout << street_address_response[dist(rng)] << endl << endl;

    cout << "City: ";
    getline(cin, city);
    cout << city_response[dist(rng)] << endl << endl;

    cout << "Zip Code: ";
    getline(cin, zip);
    cout << endl << endl;

    // Print information to screen
    cout << first_name << last_name << endl;
    cout << street_address << endl;
    cout << city << ", " << zip << endl << endl;

    cout << "Welcome to Bureaucracy" << endl << "A Paranoid Fantasy" << endl;

    getch();

    return 0;
}