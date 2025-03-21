/*
    Author: [Your Name]
    Assignment: Dynamic Memory and Arrays in C++
    Description: Implements dynamic array creation, expansion, deletion, error handling, and sorting.
*/

#include <iostream>
#include <limits>   // For input validation
#include <algorithm> // For std::sort
using namespace std;

// Function to deallocate dynamic array
void deleteArray(int* &arr) {
    delete[] arr;
    arr = nullptr;
}

// Function to sort dynamic array
void sortArray(int* arr, int size) {
    sort(arr, arr + size);
    cout << "Sorted array elements: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to validate integer input
bool getValidInteger(int &value) {
    cin >> value;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

int main() {
    int size;

    // 1. Introduction to Dynamic Arrays
    cout << "--- Introduction to Dynamic Arrays ---\n";
    cout << "Dynamic arrays are arrays whose size is determined at runtime.\n";
    cout << "They are useful when the amount of data is unknown or changes during program execution.\n";
    cout << "For example, collecting user input until a stop condition is met requires dynamic memory.\n\n";

    // Task 1: Creating a Dynamic Array
    cout << "Enter the size of the array: ";
    while (!(getValidInteger(size)) || size <= 0) {
        cout << "Invalid input. Please enter a positive integer: ";
    }

    int* array = new int[size];

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; ++i) {
        while (!(getValidInteger(array[i]))) {
            cout << "Invalid input. Enter an integer: ";
        }
    }

    cout << "The array elements are: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Task 2: Expanding the Dynamic Array
    string choice;
    cout << "Would you like to add more elements? (yes/no): ";
    cin >> choice;

    if (choice == "yes") {
        int additional;
        cout << "How many more elements? ";
        while (!(getValidInteger(additional)) || additional < 0) {
            cout << "Invalid number. Enter a non-negative integer: ";
        }

        int newSize = size + additional;
        int* newArray = new int[newSize];

        // Copy old elements to new array
        for (int i = 0; i < size; ++i) {
            newArray[i] = array[i];
        }

        cout << "Enter the elements: ";
        for (int i = size; i < newSize; ++i) {
            while (!(getValidInteger(newArray[i]))) {
                cout << "Invalid input. Enter an integer: ";
            }
        }

        // Delete old array and update pointer
        deleteArray(array);
        array = newArray;
        size = newSize;

        cout << "The new array elements are: ";
        for (int i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    // Task 5: Sort the array
    sortArray(array, size);

    // Task 3: Deleting the array
    deleteArray(array);

    return 0;
}
