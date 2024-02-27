/*
 * A simple C++ program that demonstrates accessing memory beyond scope.
 * Modified from
 * C++ POINTERS (2020) - How to use pointers and arrays (for beginners)
 * https://www.youtube.com/watch?v=DsS-ZiYOWy4
 */
#include <iostream>
using namespace std;

int main() {

    // Create the array and pointer.
    int luckyNumbers[5];
    int *pointer = &luckyNumbers[0];

    // Get input from user.
    for (int i = 0; i <= 4; i++){
        cout << "Number: ";
        cin >> luckyNumbers[i];
    }

    // Print the pointer size to the console.
    cout << "Size of pointer: " << sizeof pointer << endl;

    cout << endl << "Output the value and pointer to the console correctly. " << endl;
    for (int i = 0; i <  5; i++){
        cout << "Value: " << *(luckyNumbers + i) << endl;
        cout << "Pointer reference: " << pointer + i << endl;
    }

    cout << endl << "Output the value and pointer to the console, \n"
                    "but incorrectly access a memory location not in the array." << endl;
    for (int i = 0; i <= 5; i++){
        if (i == 5){
            cout << "This value is from the memory space at " <<
            pointer << " + 0x" << hex << sizeof pointer/2 * (i) << endl;
        }
        cout << "Value: " << *(luckyNumbers + i) << endl;
        cout << "Pointer reference: " << pointer + i << endl;
    }

    system("pause>0");
    return 0;
}
