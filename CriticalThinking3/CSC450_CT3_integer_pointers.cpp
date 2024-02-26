/*
 * A simple C/C++ program that takes three integers from a user,
 * creates memory pointers for those integers,
 * then prints the integers and pointer references to the screen.
 * (CSC450_CT3_integer_pointers.cpp)
 */

#include <iostream>
#include <regex>
#include <string>

void show_pointers();

int get_integer();

using namespace std;

int main() {
    show_pointers();
    return 0;
}

/*
 * This function will ask the user to enter an integer using the get_integer() function three times.
 * It will print the values and a memory pointer to each integer.
 * The memory pointers are freed at the end of the function, though this is probably not necessary
 * as the memory will be freed at function termination.
 */
void show_pointers() {
    int integer_1 = get_integer(), integer_2 = get_integer(), integer_3 = get_integer();
    void *pointer_1 = malloc(sizeof(integer_1)),
         *pointer_2 = malloc(sizeof(integer_2)),
         *pointer_3 = malloc(sizeof(integer_3));
    printf("Integer 1: %-11d Integer 1 Pointer: %p\n"
           "Integer 2: %-11d Integer 2 Pointer: %p\n"
           "Integer 3: %-11d Integer 3 Pointer: %p\n",
           integer_1, pointer_1, integer_2, pointer_2, integer_3, pointer_3);
    free(pointer_3);
    free(pointer_2);
    free(pointer_1);
    /* Note: free() only deallocates the memory and frees it for usage by another thread.
     * The value remains in memory until overwritten.
     * free() may only be used if the pointer is created with malloc().
     * Using delete on a pointer can result in undefined behavior and is not recommended.
     * Setting a pointer to NULL will also free the memory.
     */
} // Variables are freed from memory here.

/*
 * This function autocorrects typos or improperly sanitized input from a data source
 * and ensures input may be interpreted as an integer.
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
            integer = stoi(regex_replace(input, regex(R"([^\-0-9.]+)"), ""));
            valid = true;
        } catch (invalid_argument const &ia) {
            valid = false;
            cout << "Input cannot be parsed. Enter a valid integer value: ";
            cin.clear();
        } catch (out_of_range const &oor){
            valid = false;
            cout << "Input is out of range for this machine. Enter a valid integer value: ";
            cin.clear();
        }
    } while (!valid);
    return integer;
} // Variables other than the return value are freed from memory here.

/*
 * This function will ask the user to enter an integer using the get_integer() function three times.
 * It will print the values and a memory pointer to each integer.
 * The pointers are not stored in a variable and are freed at the function termination.
 * If they were stored and returned, delete or free() could be used to deallocate the storage in memory
 * depending on the way the pointer was created.
 */
[[maybe_unused]] void alternate_solution() {
    int integer_1 = get_integer(), integer_2 = get_integer(), integer_3 = get_integer();
    printf("Integer 1: %-11d Integer 1 Pointer: %p\n"
           "Integer 2: %-11d Integer 2 Pointer: %p\n"
           "Integer 3: %-11d Integer 3 Pointer: %p\n",
           integer_1, &integer_1, integer_2, &integer_2, integer_3, &integer_3);
} // Variables are freed from memory here.

/*
 * The loop in this function defeats the purpose of the assignment,
 * as the pointer will always be to the local integer variable within the for each loop.
 * It will print the same pointer address to the screen three times because at each iteration
 * the local integer variable is destroyed and overwritten.
 * It does not provide the pointer address for integer_1, integer_2, or integer_3.
 * It is unused and left here for demonstration.
 */
[[maybe_unused]] void integer_pointers_loop() {
    int counter = 0, integer_1 = get_integer(), integer_2 = get_integer(), integer_3 = get_integer();
    const int INTEGER_ARRAY[3] = {integer_1, integer_2, integer_3};
    for (int integer: INTEGER_ARRAY) {
        counter++;
        printf("Integer %d: %-11d Pointer %d: %p\n", counter, integer, counter, &integer);
    }
} // Variables are freed from memory here.