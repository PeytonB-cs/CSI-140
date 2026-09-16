#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	// unfinished class demo code
	//string myString = "Peyton Ballard";
	//int length = myString.length();
	//char c = myString[6];
	//myString[7] = 'e';
	//cout << c << endl;

	// unfinished class demo code
	//const int SIZE = 17;

	string firstName = "Peyton";
	string lastName = "Ballard";

	string fullName = firstName + ' ' + lastName;

	cout << fullName << endl;
	
	const char* nameC = fullName.c_str();

	string border;
	border.assign(16, '*');
	cout << border << endl;

	// get and set a new seed based on time
	unsigned int seed = time(0);
	srand(seed);

	// generate 1 random number and print it
	int min = 3;
	int max = 7;
	int x = rand() % (max - min + 1) + min;
	cout << x << endl;
}