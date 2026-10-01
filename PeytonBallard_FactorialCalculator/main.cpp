//	Author: Peyton - Ballard
//	Class : CSI - 140 - 05
//	Assignment : Module-05-Lab 2 - Factorial Number Calculator
//	Date Assigned : Sep - 21rst
//	Due Date : Sep 24th - 2:30 pm
//	Description :
//	This program calculates the factorial based on user input
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

int main() {
    // declare the number variable
    int n;

    // print instruction
    cout << "Compute Factorial. Enter -1 to end.\n\n";
    cout << "    Enter a number:  ";
    // get user input
    cin >> n;

    // outer loop to repeatedly get input
    while (n != -1) {
        // check if input is valid
        if (n < 0) {
            cout << "    Invalid Input!\n\n";
        }
        else {
            // declare the result variable
            unsigned long long result = 1;

            // interior loop to calculate the factorial
            for (int i = 1; i <= n; i++) {
                result *= i;
            }

            // print the result
            cout << "            Result:  " << result << "\n";

            // print the equation
            cout << "          Equation:  " << n << "! = ";
            if (n <= 1) {
                // 0! and 1! both print as just "1"
                cout << 1;
            }
            else {
                // second for loop prints 1 x 2 x 3 ... x n
                for (int i = 1; i <= n; i++) {
                    if (i > 1) cout << " x ";
                    cout << i;
                }
            }
            cout << " = " << result << "\n\n";
        }

        // get new input
        cout << "    Enter a number:  ";
        cin >> n;
    }
    // exit the program
    cout << "\n    Bye-Bye!\n";
    return 0;
}