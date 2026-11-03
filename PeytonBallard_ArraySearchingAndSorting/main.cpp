//	Author: Peyton - Ballard
//	Class : CSI - 140 - 05
//	Assignment : Module 10 - Lab - Array Sorting + Searching
//	Date Assigned : Oct 29th - 2:30pm
//	Due Date : Nov 2nd - 11:59pm
//	Description :
//	This program gives the user an array and menu and allows them to perform actions such as searching and sorting
//	Certification of Authenticity :
//	I certify that this is entirely my own work, except where I have given
//	fully - documented references to the work of others.I understand the
//	definition and consequences of plagiarism and acknowledge that the assessor
//	of this assignment may, for the purpose of assessing this assignment :
//	-Reproduce this assignment and provide a copy to another member of
//	academic staff; and /or
//	-Communicate a copy of this assignment to a plagiarism checking
//	service(which may then retain a copy of this assignment on its
//		database for the purpose of future plagiarism checking)

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// declare the prototype functions
void printMenu();
void populateArray(int arr[], int size);
void printArray(const int arr[], int size);
void insertionSort(int arr[], int size);
int linearSearch(const int arr[], int size, int target);
int binarySearch(const int arr[], int size, int target);
int randomNumber(const int MIN, const int MAX);

int main()
{
    // choose seed for random numbers
    srand(static_cast<unsigned int>(time(0)));
    
    // declare variables
    const int SIZE = 20;
    int numbers[SIZE];
    int choice = 0;
    bool isSorted = false;

    // populate and print the array for the user before anything
    populateArray(numbers, SIZE);
    printArray(numbers, SIZE);

    // run the loop to print the menu and give the user choice
    do
    {
        // print the menu
        printMenu();
        // take in the choice
        cin >> choice;

        // use the number to decide what function to run
        if (choice == 1) {
            // repopulate the array and print it
            populateArray(numbers, SIZE);
            printArray(numbers, SIZE);
            // set the array as unsorted
            isSorted = false;
        }
        else if (choice == 2) {
            // sort the array and print it
            insertionSort(numbers, SIZE);
            printArray(numbers, SIZE);
            // set the array as sorted
            isSorted = true;
        }
        else if (choice == 3) {
            // declare a target variable
            int target;

            // prompt the user for a target
            cout << "Enter number to search for: ";
            cin >> target;

            int result;
            // if sorted use binary search if not use linear search
            if (isSorted) {
                result = binarySearch(numbers, SIZE, target);
            }
            else {
                result = linearSearch(numbers, SIZE, target);
            }

            // checks if the index was found or not
            if (result != -1) {
                cout << target << " found at index " << result << endl;
            }
            else {
                cout << target << " not found\n";
            }
            // print array for next action
            printArray(numbers, SIZE);
        }
        else if (choice == 4) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice." << endl;
            printArray(numbers, SIZE);
        }
    } while (choice != 4);
}

// this function prints the menu number options 1-4
void printMenu() {
    cout << "1) Populate new numbers \n2) Sort array \n3) Search array \n4) Exit" << endl << ">> ";
}

// populates an array of 20 with random numbers between 0 and 99
void populateArray(int arr[], int size) {
    const int MIN = 0;
    const int MAX = 99;
    for (int i = 0; i < size; i++) {
        arr[i] = randomNumber(MIN, MAX);
    }
}

// prints an array
void printArray(const int arr[], int size) {
    // prints part 1 before it collects the array
    cout << "Array: [";
    // collects the arrays values
    for (int i = 0; i < size; i++)
    {
        if (i > 0)
        {
            cout << ", ";
        }
        cout << arr[i];
    }
    // closes the brackets
    cout << "]" << endl;
}

// sorts an array using insertion sort due to it being short, fast on small arrays and stable.
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key;
    }
}

// searches an array for a target using linear search. Linear search is used here because binary search requires a sorted input
int linearSearch(const int arr[], int size, int target) {
    // search through each index one by one for the target
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) return i;
    }
    // target not found
    return -1;
}

// searches an array for a target using a binary search. Binary search is used here because the input is sorted
int binarySearch(const int arr[], int size, int target) {
    // declare low and high variables
    int low = 0;
    int high = size - 1;

    // loop through checking the middle element and throw away the half that doesnt contain the target
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    // target not found
    return -1;
}

// generates a random number within a range
int randomNumber(const int MIN, const int MAX) {
    return MIN + (rand() % (MAX - MIN + 1));
}