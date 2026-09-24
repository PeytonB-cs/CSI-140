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