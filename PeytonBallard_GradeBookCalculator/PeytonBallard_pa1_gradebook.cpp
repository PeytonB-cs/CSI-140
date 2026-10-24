//	Author: Peyton - Ballard
//	Class : CSI - 140 - 05
//	Assignment : Module-08-Lab-1-Grade-book Calculator
//	Date Assigned : Oct 15th - 2:30pm
//	Due Date : Oct 22nd - 2:30pm
//	Description :
//	This program takes in an input file with grades and outputs a file with a breakdown of the grade information
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
#include <fstream>

using namespace std;

int main()
{
	//declare variables
	string inputFileName;
	string outputFileName;
	string categoryName;

	//constant widths
	const int COLUMN_WIDTH = 17;
	const int POSSIBLE_POINTS_WIDTH = 15;
	const int CATEGORY_WIDTH = 32;
	const int FOOTER_WIDTH = 28;
	const int TOTAL_VALUE_WIDTH = 8;
	const int GRADE_VALUE_WIDTH = 7;

	const int GET_PERCENTAGE = 100;
	const int CATEGORY_COUNT = 3;

	double possiblePoints = 0, 
		   weight = 0, 
		   scoredPoints = 0,
		   categoryPercent = 0,
		   unweightedSum = 0,
		   weightedGrade = 0,
		   totalPossible = 0,
		   totalScored = 0;

	//declare files
	ifstream inputFile;
	ofstream outputFile;

	//get input file
	cout << "Enter input file name: ";
	cin >> inputFileName;
	inputFile.open(inputFileName);
	if (!inputFile) {
		cout << "Error: could not open file" << endl;
		return 1;
	}

	//get output files
	cout << "Enter output file name: ";
	cin >> outputFileName;
	outputFile.open(outputFileName);
	if (!outputFile) {
		cout << "Error: could not open file" << endl;
		return 1;
	}

	//create the output files header
	outputFile << fixed << setprecision(2);

	outputFile << left << setw(CATEGORY_WIDTH) << "Category"
		<< right << setw(POSSIBLE_POINTS_WIDTH) << "Possible Points"
		<< setw(COLUMN_WIDTH) << "Weight %"
		<< setw(COLUMN_WIDTH) << "Scored Points"
		<< setw(COLUMN_WIDTH) << "Category %" << endl;

	//this for loop collects information, processes it and outputs it
	for (int i = 1; i <= 3; i++) {
		//get the information
		getline(inputFile, categoryName);
		inputFile >> possiblePoints >> weight >> scoredPoints;
		weight = weight / GET_PERCENTAGE;
		inputFile.ignore(1000, '\n');

		//do the math
		categoryPercent = scoredPoints / possiblePoints * GET_PERCENTAGE;
		totalPossible = totalPossible + possiblePoints;
		totalScored = totalScored + scoredPoints;
		unweightedSum = unweightedSum + categoryPercent;
		weightedGrade = weightedGrade + (categoryPercent * weight);

		//output the information into the output file
		outputFile << left << setw(CATEGORY_WIDTH) << categoryName
			<< right << setw(POSSIBLE_POINTS_WIDTH) << possiblePoints
			<< setw(COLUMN_WIDTH) << weight
			<< setw(COLUMN_WIDTH) << scoredPoints
			<< setw(COLUMN_WIDTH) << categoryPercent << endl;
	}

	//calculate the unweighted grade
	double unweightedGrade = unweightedSum / CATEGORY_COUNT;

	//output the final variables
	outputFile << endl << endl;
	outputFile << right;
	outputFile << setw(FOOTER_WIDTH) << "Total Possible Points:" << setw(TOTAL_VALUE_WIDTH) << totalPossible << endl;
	outputFile << setw(FOOTER_WIDTH) << "Total Scored Points:" << setw(TOTAL_VALUE_WIDTH) << totalScored << endl;
	outputFile << setw(FOOTER_WIDTH) << "Unweighted Grade Percentage:" << setw(GRADE_VALUE_WIDTH) << unweightedGrade << endl;
	outputFile << setw(FOOTER_WIDTH) << "Weighted Grade Percentage:" << setw(GRADE_VALUE_WIDTH) << weightedGrade << endl;

	//close the files
	inputFile.close();
	outputFile.close();

	//return 0
	return 0;
}