#include <iostream>

using namespace std;


void readArray(double arr[], int size) {
    cout << "Enter 5 numbers, separated by spaces, then press ENTER to finish." << endl << ">> ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
};
void printArray(const double arr[], int size) {
    cout << "Your array: [";
    for (int i = 0; i < size; i++)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << arr[i];
    }
    cout << "]" << endl;
};

// this function prints the menu with all the number options
void printMenu() {
    cout << "1) New array \n2) Replace at index \n3) Sum array \n4) Quit" << endl << ">> ";
}
void replaceAtIndex(double arr[], int size) {
    int index;
    cout << "Replace at which index?" << endl << ">> ";
    cin >> index;

    while (index < 0 || index >= size)
    {
        cout << "Error: invalid index." << endl;
        cout << "Replace at which index?" << endl << ">> ";
        cin >> index;
    }
    
    double newValue;
    cout << "Enter your number:" << endl << ">> ";
    cin >> newValue;
    arr[index] = newValue;
}
double sumArray(const double arr[], int size) {
    double sum = 0.0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    const int SIZE = 5;
    double numbers[SIZE];
    int choice = 0;

    readArray(numbers, SIZE);
    printArray(numbers, SIZE);

    do
    {
        printMenu();
        cin >> choice;

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