/*
 * A simple C++ program that takes two string inputs from a user,
 * concatenates the two strings,
 * then prints the resulting output to the screen.
 * (CSC450_CT2_string.cpp)
 */

#include <iostream>

void concatenate();

using namespace std;

int main() {
    for (auto _ = 3; _--;) concatenate();
    return 0;
}

void concatenate() {
    string string_a;
    string string_b;
    cout << "Enter a string: ";
    getline(cin, string_a);
    cout << "Enter another string: ";
    getline(cin, string_b);
    string_a.append(" " + string_b);
    printf("\nThe strings are: %s\n\n", string_a.c_str());
}
