/*
 * A simple C++ program that demonstrates pointers and arrays.
 * Modified from another student's program from module 7
 * in CSU Global's CSC300 Programming III course
 * by Stephan Peters (speters33w).
 */

#include <iostream>
#include <bits/stdc++.h>

void printArray(int*, int);

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr; // Pointing to the first element of the array

    std::cout << "sizeof an int: "<< sizeof(int) << std::endl;
    std::cout << "sizeof ptr: "<< sizeof ptr << std::endl;  // this may vary on different machines
    std::cout << "sizeof arr: "<< sizeof arr / sizeof(int) << std::endl;

    // Passing array to a function
    printArray(ptr, sizeof(arr) / sizeof(int));

    // Dynamic memory allocation
    int dynArrSize = 3;
    int *dynamicArray = new int[dynArrSize];
    dynamicArray[0] = 10;
    dynamicArray[1] = 20;
    dynamicArray[2] = 30;

    std::cout << "sizeof dynamicArray (pointer): "<< sizeof dynamicArray << std::endl << std::endl;

    // Accessing array elements using pointer
    for (int i = 0; i < dynArrSize; ++i) {
        std::cout << "Element " << i << ": " << *(dynamicArray + i) << std::endl;
//        *dynamicArray++;
    }

    // Overwrite memory with zeros
    memset(ptr, 0, (sizeof(arr)));

    memset(dynamicArray, 0, (sizeof(int) * dynArrSize));

    return 0;
}

void printArray(int *arr, int size) {
    std::cout << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Element " << i << ": " << arr[i] << std::endl;
    }
    std::cout << std::endl;
}
