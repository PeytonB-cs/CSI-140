//	Author: Peyton - Ballard
//	Class : CSI - 140 - 05
//	Assignment : Module-06-Activity-1- Falling Distance - Function
//	Date Assigned : Sep 28th - 2:30pm
//	Due Date : Oct 1st - 2:30pm
//	Description :
//	This program calculates falling distance based off math done inside a function
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
#include <cmath>

using namespace std;

// declare constant variables
const double GRAVITY = 9.8;
const double HALF = 0.5;
const double TIME_EXPONENT = 2.0;

const int FIRST_SECOND = 1;
const int LAST_SECOND = 10;

const int TIME_WIDTH = 2;
const int DISTANCE_WIDTH = 10;
const int DISTANCE_PRECISION = 2;

// returns the distance in meters
double getFallingDistance(double time)
{
	// cacluates and returns distance
	return HALF * GRAVITY * pow(time, TIME_EXPONENT);
}

int main()
{
	// sets precision to control decimal numbers
	cout << fixed << setprecision(DISTANCE_PRECISION);

	// for loop to get the result
	for (int seconds = FIRST_SECOND; seconds <= LAST_SECOND; seconds++)
	{
		// print the result
		cout << setw(TIME_WIDTH) << seconds << ":"
			 << setw(DISTANCE_WIDTH) << getFallingDistance(seconds) << endl;
	}

	return 0;
}