#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	const int WIDTH = 10;

	string name;
	cout << "Enter your name: ";
	getline(cin, name);

	//ios::in input only
	//ios::out output only
	//ios::app append

	//declare the output files
	ofstream inputFile;
	ofstream outputFile;

	//open the input file
	inputFile.open("input.txt");
	//check if file exists
	if (inputFile.fail()) {
		cout << "random file doesnt exist\n";
		inputFile.close();
		return 1;
	}
	string myString;
	//getline(inputFile, myString);
	cout << "my string: " << myString;

	outputFile.open("test.txt", ios::app);

	//print what ends up in the text file
	outputFile << "Name: " << setw(WIDTH) << name << endl;

	//do not forget to close
	outputFile.close();
}