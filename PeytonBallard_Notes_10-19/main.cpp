#include <iostream>;
#include <fstream>;
#include <sstream>; // string streams

using namespace std;

int main()
{
	// 2 seperate strings and a output string to combine to
	string firstName = "Peyton";
	string lastName = "Ballard";
	string fullName = "";

	// you can combine like this
	fullName = firstName + ' ' + lastName;

	// or like this
	stringstream sstream;
	sstream << firstName << ' ' << lastName;

	int x = 5;
	string xAsString = to_string(x);

	fullName = sstream.str();

	// string stream can also do output
	stringstream outStream("peyton 5 2.4 a");
	string name;
	outStream >> name;
	int y = 0;
	outStream >> y;
	double myDub = 0;
	outStream >> myDub;
	char a = ' ';
	outStream >> a;

	// print output
	cout << fullName << endl;

	// print outstream
	cout << name << ", " << y << ", " << myDub << ", " << a << endl;
}