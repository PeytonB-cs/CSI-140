//	Author: Peyton - Ballard
//	Class : CSI - 140 - 05
//	Assignment : Module-06 - Assignment - Functions - Cylinder
//	Date Assigned : Oct 1st - 2:30pm
//	Due Date : Oct 5th - 2:30pm
//	Description :
//	This program calculates volume with 4 functions each serving 1 step of the 4 step process
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
#include <cctype>

using namespace std;

// declare constants
const int SPACE = 20;
const double PI = 3.14159;
const char CONTINUE_CHAR = 'Y';

// declare prototypes
double getRadius();
double getHeight();
double computeVolume(double radius, double height);
void displayResult(double volume);
bool askToContinue();

int main()
{
	// declare variables for math
	double radius, height, volume;

	// declare variable for keep going prompt
	bool keepGoing;

	// main loop
	do
	{
		// call functions
		radius = getRadius();
		height = getHeight();
		volume = computeVolume(radius, height);
		displayResult(volume);
		keepGoing = askToContinue();
	} while (keepGoing);

	return 0;
}

// this function asks the user for a radius
double getRadius()
{
	// declare local variable
	double radius;

	// ask user for radius
	cout << setw(SPACE) << "Enter radius:  ";
	cin >> radius;

	// return the radius as the final output
	return radius;
}

// this function asks the user for a height
double getHeight()
{
	// declare local variable
	double height;

	// ask user for height
	cout << setw(SPACE) << "Enter height:  ";
	cin >> height;

	// return the height as the final output
	return height;
}

// this function takes a radius and height value and calculates a volume
double computeVolume(double radius, double height)
{
	// caclulate and return a volume
	return PI * radius * radius * height;
}

// this function displays a result for the compute volume function
void displayResult(double volume)
{
	// displays the result
	cout << setw(SPACE) << "Volume:  " << volume << endl;
}

// this function asks the user if they want to continue and terminates if not
bool askToContinue()
{
	// declare local variables
	char answer;

	// prompt the user
	cout << "\nCalculate another one?" << endl;
	cout << "Enter [Y] to continue, all other letters terminates: ";
	cin >> answer;

	// if the user answered Y
	if (toupper(answer) == CONTINUE_CHAR)
	{
		cout << endl;
		return true;
	}

	// if the user answered anything else
	cout << "Goodbye!" << endl;
	return false;
}