//	Author: Peyton - Ballard
//	Class : CSI - 140 - 05
//	Assignment : Module-03-Lab-2-Random Report
//	Date Assigned : Sep 7th - 2:30pm
//	Due Date : Sep 10th - 2:30pm
//	Description :
//	This program takes in information and prints it out with math done on the inputed number
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
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	// declare question answer varibles
	string name;
	string location;
	int number;

	// declare math variables
	int absolute;
	double squared;
	int rounded;

	// declare and asign the line variable
	string line;
	line.assign(32, '-');

	// print instructions
	cout << line << endl;
	cout << setw(30) << "Please enter the following data" << endl;

	// question 1
	cout << setw(33) << "Your full name: ";
	getline(cin, name);

	// question 2
	cout << setw(33) << "City and state you live: ";
	getline(cin, location);

	// question 3
	cout << setw(33) << "Enter a negative number: ";
	cin >> number;

	// gettinge the values for absolute, squared and rounded
	absolute = abs(number);
	squared = sqrt(absolute);
	rounded = round(squared);

	// Generate 2 random numbers within the range of absolute and rounded
	unsigned int seed = time(0);
	srand(seed);
	int rand1 = rounded + (rand() % (absolute - rounded + 1));
	int rand2 = rounded + (rand() % (absolute - rounded + 1));

	cout << line << endl;
	cout << "YOUR REPORT" << endl;
	cout << line << endl;

	// print answers
	cout << "Hello " << name << endl;
	cout << "You live in " << location << endl;
	cout << setw(43) << "Absolute value of the number you entered : " << absolute << endl;
	cout << setw(43) << "Square root of that number : " << fixed << setprecision(2) << squared << endl;
	cout << setw(43) << "Rounding this to nearest integer : " << rounded << endl;
	cout << "Two random numbers between " << rounded << " and " << absolute << " are " << rand1 << " and " << rand2 << endl;

	cout << line << endl;
	cout << "END OF REPORT" << endl;
}