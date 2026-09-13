//	Author: Peyton - Ballard
//	Class : CSI - 140 - 05
//	Assignment : Module-04-Lab-1 Calculator
//	Date Assigned : Sep 10th - 2:30pm
//	Due Date : Sep 17th - 2:30pm
//	Description :
//	This program is a calculator taking in 2 values and an operator and completing the math problem
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

using namespace std;

int main()
{
	// Declare my variables
	double num1 = 0,
		   num2 = 0,
		   output = 0;
	char op;
	const int LINE_WIDTH = 26;

	// First input
	cout << setw(LINE_WIDTH) << "Enter First Number: ";
	cin >> num1;

	// Second input
	cout << setw(LINE_WIDTH) << "Enter Second Number: ";
	cin >> num2;

	// Third input
	cout << setw(LINE_WIDTH) << "Enter Operator (+,-,*,/): ";
	cin >> op;

	// Switch for the operator
	switch (op) 
	{
		case '+': output = num1 + num2;
				  cout << setw(LINE_WIDTH) << "Result: " << output << endl;
				  break;
		case '-': output = num1 - num2;
				  cout << setw(LINE_WIDTH) << "Result: " << output << endl;
				  break;
		case '*': output = num1 * num2;
				  cout << setw(LINE_WIDTH) << "Result: " << output << endl;
				  break;
		case '/': // Check if the user is trying to divide by 0
				  if (num2 == 0)
				  {
					  cout << setw(LINE_WIDTH) << "Result: " << "CANNOT DIVIDE BY 0" << endl;
				  }
				  else
				  {
					  output = num1 / num2;
					  cout << setw(LINE_WIDTH) << "Result: " << output << endl;
				  }
				  break;
		default: // Any non operator
				 cout << setw(LINE_WIDTH) << "Result: " << "INVALID OPERATION. MUST BE +,-,*,or /" << endl;
				 break;
	}

	return 0;
}