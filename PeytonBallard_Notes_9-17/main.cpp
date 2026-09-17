#include <iostream>

using namespace std;

int main()
{
	// simple while loop example
	int x = 0;
	while (x < 5) {
		cout << x << endl;
		x++;
	}

	// prompt user
	cout << "Enter a number (-1 to exit): ";
	
	// declare variable and take in user input
	int y = 0;
	cin >> y;

	// while loop
	// a while loop checks the paramaters first
	while (y != -1)
	{
		cout << "Your number: " << y << endl;
		cout << "Enter a number (-1 to exit): ";
		cin >> y;
	}
	cout << "Bye" << endl;

	// declare variable
	int z;

	// do while loop
	// a do while loop runs the code then checks the paramater
	do {
		cout << "Enter a number (-1 to exit): ";
		cin >> z;
		cout << "Your number: " << y << endl;
	} while (x != -1);
	cout << "Bye" << endl;
}