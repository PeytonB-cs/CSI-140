//	Author: Peyton - Ballard
//	Class : CSI - 140 - 05
//	Assignment : Module-03-Lab-1-Change Calculator
//	Date Assigned : Sep - 3rd
//	Due Date : Sep 7th - 2:30 pm
//	Description :
//	This program calculates the correct amount of bills to give to a customer
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
	// declare the variables for the change
	int hundreds = 0;
	int fifties = 0;
	int twenties = 0;
	int tens = 0;
	int fives = 0;
	int ones = 0;

	// declare variables for the amount
	int amount = 0;
	int remainder = 0;

	// ask user for the amount
	cout << "Enter Amount: " << "$";
	
	// take in user input for the amount
	cin >> amount;

	// calculate 100s
	hundreds = amount / 100;
	remainder = amount - (hundreds * 100);

	// calculate 50s
	fifties = remainder / 50;
	remainder = remainder - (fifties * 50);

	// calculate 20s
	twenties = remainder / 20;
	remainder = remainder - (twenties * 20);

	// calculate 10s
	tens = remainder / 10;
	remainder = remainder - (tens * 10);
	
	// calculate 5s
	fives = remainder / 5;
	remainder = remainder - (fives * 5);

	// calculate 1s
	ones = remainder / 1;
	remainder = remainder - ones;

	// print the results
	cout << setw(14) << "$100 Bill(s): " << hundreds << endl;
	cout << setw(14) << "$50 Bill(s): " << fifties << endl;
	cout << setw(14) << "$20 Bill(s): " << twenties << endl;
	cout << setw(14) << "$10 Bill(s): " << tens << endl;
	cout << setw(14) << "$5 Bill(s): " << fives << endl;
	cout << setw(14) << "$1 Bill(s): " << ones << endl;

}