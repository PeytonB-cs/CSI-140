//	Author: Peyton - Ballard-Charbonneau
//	Class : CSI - 140 - 05
//	Assignment : Module-02-Lab-1-Finding Average
//	Date Assigned : Aug 31st
//	Due Date : Due - Sep 3rd and 2:30 pm
//	Description :
//	This programs purpose is to take 5 values and average them
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

int main()
{
	// declare the variables
	int grade1 = 55;
	int grade2 = 87;
	int grade3 = 92;
	int grade4 = 63;
	int grade5 = 97;

	// get the sum
	int sum = grade1 + grade2 + grade3 + grade4 + grade5;

	// calculate the average
	float average = (float)sum / 5;

	// print quiz values before average
	cout << "Quiz 1: " << grade1 << endl;
	cout << "Quiz 2: " << grade2 << endl;
	cout << "Quiz 3: " << grade3 << endl;
	cout << "Quiz 4: " << grade4 << endl;
	cout << "Quiz 5: " << grade5 << endl;

	// print the average
	cout << "Avg   : " << average << endl;
}