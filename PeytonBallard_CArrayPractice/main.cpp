//	Author: Peyton - Ballard
//	Class : CSI - 140 - 05
//	Assignment : Module-09-Lab-1-CArrayPractice
//	Date Assigned : Oct 22nd - 2:30pm
//	Due Date : Oct 26th - 2:30pm
//	Description :
//	This program allows the user to create, read, modify, and get the sum of arrays using functions and basic menus
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

using namespace std;

// this function prompts the user to enter numbers to create an array
void readArray(double arr[], int size) {
    // prompts the user for their numbers 
    cout << "Enter 5 numbers, separated by spaces, then press ENTER to finish." << endl << ">> ";
    // collects the numbers in this loop
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
};

// this function prints the array
void printArray(const double arr[], int size) {
    // prints part 1 before it collects the array
    cout << "Your array: [";
    // collects the arrays values
    for (int i = 0; i < size; i++)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << arr[i];
    }
    // closes the brackets
    cout << "]" << endl;
};

// this function prints the menu with all the number options
void printMenu() {
    cout << "1) New array \n2) Replace at index \n3) Sum array \n4) Quit" << endl << ">> ";
}
// this function takes in an index and value and replaces the number at that index with the value
void replaceAtIndex(double arr[], int size) {
    // declare the index value
    int index;

    // prompt the user
    cout << "Replace at which index?" << endl << ">> ";
    cin >> index;

    // invalid input handling
    while (index < 0 || index >= size)
    {
        cout << "Error: invalid index." << endl;
        cout << "Replace at which index?" << endl << ">> ";
        cin >> index;
    }
    
    // declare the new value
    double newValue;

    // prompt the user
    cout << "Enter your number:" << endl << ">> ";
    cin >> newValue;
    arr[index] = newValue;
}

// this function takes in the array and adds the numbers together to return a sum
double sumArray(const double arr[], int size) {
    // declare sum
    double sum = 0;

    // add the numbers to sum
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    // return sum
    return sum;
}

int main()
{
    // declare variables
    const int SIZE = 5;
    double numbers[SIZE];
    int choice = 0;

    // make and print an array first
    readArray(numbers, SIZE);
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
            readArray(numbers, SIZE);
            printArray(numbers, SIZE); 
        }
        else if (choice == 2) {
            replaceAtIndex(numbers, SIZE);
            printArray(numbers, SIZE);
        }
        else if (choice == 3) {
            cout << "Sum of array: " << sumArray(numbers, SIZE) << endl;
            printArray(numbers, SIZE);
        }
        else if (choice == 4) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice." << endl;
        }
    } while (choice != 4);
}