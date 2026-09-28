#include <iostream>

using namespace std;

// defining a global constant
const float PI = 3.14;

// defining functions
// you can name functions whatever you want (aside names already taken inside the language).
// you can have a function return a certain type of variable.
float calculateCircleCircumference(float r) {
	return 2.0 * PI * r;
}

float calculateCircleArea(float r = 5.0) {
	// static variables are not redeclared when function is called again
	static int count = 0;
	count++;
	cout << count << ' ';

	// calculate circle area
	return PI * r * r;
}

// void function example
void displayStars(int columns, int rows = 1) {
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < columns; col++) {
			cout << '*';
		}
		cout << endl;
	}
}

// overload functions have multiple variants under the same name but different types int and float in this case
int average(int a, int b) {
	return (a + b) / 2;
}

float average(float a, float b) {
	return (a + b) / 2;
}

// AVOID global variables where possible
float y = 5;

int main()
{
	displayStars(6);

	int x = average(6, 7);

	cout << x << endl;

	for (int i = 0; i < 10; i++)
	{
		calculateCircleArea();
	}
}
