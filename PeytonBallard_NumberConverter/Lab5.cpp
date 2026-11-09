//	Author: Peyton - Ballard
//	Class : CSI - 140 - 05
//	Assignment : Module-11- Number System Converter
//	Date Assigned : Nov 2nd - 2:30pm
//	Due Date : Nov 9th - 2:30pm
//	Description :
//	This program allows the user to convert numbers into multiple different formats such as hexidecimal and binary using a menu and converter functions
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
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

const int LINE_WIDTH = 37;

// function prototypes
string convertInt2Str(int intValue);
int convertStr2Int(string stringValue);
bool isValidInput(string text);
string decimalToHex(int number);
void displayMenu();
string decimalToBinary(int number);
int digitValue(char ch);
bool isValidBaseInput(string text, int base);
int baseToDecimal(string text, int base);

int main()
{
    // declare variables
    string again = "y";
    string choice;

    do
    {
        // declare the input variable
        string input;

        // display the menu and prompt the user
        displayMenu();
        cout << setw(LINE_WIDTH) << "Enter your choice:  ";
        getline(cin, choice);

        // quit choice option
        if (choice == "Q" || choice == "q") {
            again = "n";
        }
        // branch for all other choices
        else if (choice == "1" || choice == "2" || choice == "3" || choice == "4") {

            // decimal to hex
            if (choice == "1") {
                // prompt the user
                cout << setw(LINE_WIDTH) << "Enter a number (base 10):  ";
                getline(cin, input);

                // this loop runs until the user gives a valid input
                while (!isValidInput(input)) {
                    if (input.length() > 0 && input[0] == '-') {
                        cout << setw(LINE_WIDTH) << "Error: no negative numbers." << endl;
                    }
                    else {
                        cout << setw(LINE_WIDTH) << "Error: use up to 9 digits." << endl;
                    }

                    // reprompt the user
                    cout << setw(LINE_WIDTH) << "Enter a number (base 10):  ";
                    getline(cin, input);
                }

                // convert the input
                int number = convertStr2Int(input);
                string hexResult = decimalToHex(number);

                // print the result
                cout << setw(LINE_WIDTH) << "The same number in base 16 is:  " << hexResult << endl;
            }

            // decimal to binary
            else if (choice == "2") {
                // prompt the user
                cout << setw(LINE_WIDTH) << "Enter a number (base 10):  ";
                getline(cin, input);

                // this loop runs until the user gives a valid input
                while (!isValidInput(input)) {
                    // check for a negative number to give a more specific error message
                    if (input.length() > 0 && input[0] == '-') {
                        cout << setw(LINE_WIDTH) << "Error: no negative numbers." << endl;
                    }
                    else {
                        cout << setw(LINE_WIDTH) << "Error: use up to 9 digits." << endl;
                    }

                    // reprompt the user
                    cout << setw(LINE_WIDTH) << "Enter a number (base 10):  ";
                    getline(cin, input);
                }

                // convert the input
                int number = convertStr2Int(input);
                string binaryResult = decimalToBinary(number);

                // print the result
                cout << setw(LINE_WIDTH) << "The same number in base 2 is:  " << binaryResult << endl;
            }

            // binary to decimal
            else if (choice == "3") {
                // prompt the user
                cout << setw(LINE_WIDTH) << "Enter a number (base 2):  ";
                getline(cin, input);

                // this loop runs until the user gives a valid input
                while (!isValidBaseInput(input, 2)) {
                    cout << setw(LINE_WIDTH) << "Error: use only 0 and 1 (up to 31 digits)." << endl;

                    // reprompt the user
                    cout << setw(LINE_WIDTH) << "Enter a number (base 2):  ";
                    getline(cin, input);
                }

                // convert the input
                int number = baseToDecimal(input, 2);

                // print the result
                cout << setw(LINE_WIDTH) << "The same number in base 10 is:  " << convertInt2Str(number) << endl;
            }

            // hex to decimal
            else if (choice == "4") {
                // prompt the user
                cout << setw(LINE_WIDTH) << "Enter a number (base 16):  ";
                getline(cin, input);

                // this loop runs until the user gives a valid input
                while (!isValidBaseInput(input, 16)) {
                    cout << setw(LINE_WIDTH) << "Error: use only 0-9 and A-F (up to 7 digits)." << endl;

                    // reprompt the user
                    cout << setw(LINE_WIDTH) << "Enter a number (base 16):  ";
                    getline(cin, input);
                }

                // convert the input
                int number = baseToDecimal(input, 16);

                // print the result
                cout << setw(LINE_WIDTH) << "The same number in base 10 is:  " << convertInt2Str(number) << endl;
            }

            // prompt the user to continue
            cout << setw(LINE_WIDTH) << "Convert another number? (y/n):  ";
            getline(cin, again);
        }
        else {
            // invalid menu selection
            cout << setw(LINE_WIDTH) << "Error: choose 1-4 or Q." << endl;
        }

    } while (again == "y" || again == "Y");

    return 0;
}

// Converts an int to a string, takes in an int value which it converts, it returns the int value as a string
// (provided by the document on Canvas)
string convertInt2Str(int intValue)
{
    stringstream stringValue;
    stringValue << intValue;
    return stringValue.str();
}

// Converts a string to an int, takes in a string which it converts, it returns the string as an int
// (provided by the document on Canvas)
int convertStr2Int(string stringValue)
{
    int intValue;
    stringstream str;
    str << stringValue;
    str >> intValue;
    return intValue;
}

// Checks that the input is a non-empty string of at most 9 digits (0-9), takes in a string the user entered, returns true or false if valid or invalid
bool isValidInput(string text)
{
    // reject empty input
    if (text.length() == 0) {
        return false;
    }

    // reject input that is too long to fit in an int
    if (text.length() > 9) {
        return false;
    }

    // reject letters, '-', '+', '.', spaces, and any other non-digit
    for (size_t i = 0; i < text.length(); i++) {
        if (text[i] < '0' || text[i] > '9') {
            return false;
        }
    }

    // if every check passed, the input is valid
    return true;
}

// Converts a non-negative base 10 number to a base 16 string, takes in a base 10 value to convert, returns a hexidecimal string
string decimalToHex(int number)
{
    string result = "";

    // zero is handled here, since the loop would skip it and return an empty string
    if (number == 0) {
        return "0";
    }

    while (number > 0) {
        // the remainder is the next hex digit, starting from the right
        int remainder = number % 16;

        string digit;

        // 0-9 stay as digits; 10-15 become the letters A-F
        if (remainder < 10) {
            digit = convertInt2Str(remainder);
        }
        else {
            digit = string(1, 'A' + (remainder - 10));
        }

        // put the new digit in front of the digits found so far, since remainders come out last-to-first
        result = digit + result;

        // integer division drops the remainder and moves to the next digit
        number /= 16;
    }

    return result;
}

// Prints the conversion menu
void displayMenu()
{
    cout << endl;
    cout << "  1. Decimal -> Hexadecimal" << endl;
    cout << "  2. Decimal -> Binary" << endl;
    cout << "  3. Binary -> Decimal" << endl;
    cout << "  4. Hexadecimal -> Decimal" << endl;
    cout << "  Q. Quit" << endl;
    cout << endl;
}

// Converts a non-negative base 10 number to a base 2 string, takes in the base 10 number to convert, returns the binary digits as a string
string decimalToBinary(int number)
{
    string result = "";

    // zero is handled here, since the loop would skip it and return an empty string
    if (number == 0) {
        return "0";
    }

    while (number > 0) {
        // the remainder (0 or 1) is the next binary digit, starting from the right
        int remainder = number % 2;

        // put the new digit in front of the digits found so far, since remainders come out last-to-first
        result = convertInt2Str(remainder) + result;

        // integer division drops the remainder and moves to the next digit
        number /= 2;
    }

    return result;
}

// Finds the numeric value of one digit character, takes in a character, returns the value of the character as a hex digit
int digitValue(char ch)
{
    // digits 0-9 are worth their own value
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    }

    // uppercase letters A-F are worth 10-15
    if (ch >= 'A' && ch <= 'F') {
        return ch - 'A' + 10;
    }

    // lowercase letters a-f are worth 10-15
    if (ch >= 'a' && ch <= 'f') {
        return ch - 'a' + 10;
    }

    // not a valid digit
    return -1;
}

// Checks that the input only uses digits that are legal in the given base, takes in the text the user entered and a base (2 or 16, returns true or false if valid or invalid within the selected base.
bool isValidBaseInput(string text, int base)
{
    // declare max length variable
    int maxLength;

    // reject empty input
    if (text.length() == 0) {
        return false;
    }

    // set the max length based on the base
    if (base == 2) {
        maxLength = 31;
    }
    else {
        maxLength = 7;
    }

    // check if the length is greater than the max length
    if (text.length() > (size_t)maxLength) {
        return false;
    }

    // check that every character is a legal digit for this base
    for (size_t i = 0; i < text.length(); i++) {
        int value = digitValue(text[i]);

        // -1 means not a hex character; value >= base means too big for this base
        if (value < 0 || value >= base) {
            return false;
        }
    }

    // if the checks passed, the input is valid
    return true;
}

// Converts a string in the given base to a base 10 int, takes in a validated string of digits and a base, returns the base 10 value
int baseToDecimal(string text, int base)
{
    int value = 0;

    // build up the value one digit at a time
    for (size_t i = 0; i < text.length(); i++) {
        // goes left to right through the values and folds one digit in each iteration
        value = value * base + digitValue(text[i]);
    }

    return value;
}