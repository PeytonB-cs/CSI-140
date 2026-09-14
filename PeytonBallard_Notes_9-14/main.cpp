#include <iostream>
using namespace std;

int main()
{
	// example of when to not use an if statement
	int x = 0;
	cout << "Enter a number between 1-3: ";
	cin >> x;
	if (x == 1)
		cout << "A" << endl;
	else if (x == 2)
		cout << "B" << endl;
	else if (x == 3)
		cout << "C" << endl;
	else
		cout << "ERROR" << endl;

	// example of when to use a switch statment
	int y;
	cout << "Enter a number between 1-3: ";
	cin >> y;
	switch (y) {
		case 1: 
			cout << "A" << endl;
			break; // break is very important if you dont add it the code breaks
		case 2:
			cout << "B" << endl;
			break;
		case 3:
			cout << "C" << endl;
			break;
		default: // what
			cout << "ERROR" << endl;
	}

	// example of a variable type enum
	enum WeaponType : int {
		NONE = 0,
		DAGGER,
		BOW,
		HALBERD,
		SPEAR,
		MORNING_STAR,
		SCIMITAR,
		SHIELD
	};

	// example of when to use an enum instead
	//const int DAGGER = 1;
	//const int BOW = 2;
	//const int HALBERD = 3;
	//const int SPEAR = 4;
	//const int MORNING_STAR = 5;
	//const int SCHIMITAR = 6;
	//const int SHIELD = 7;

	int weapon;
	cout << "Pick a weapon 0-7: " ;
	cin >> weapon;
	cout << "You have a ";
	switch (weapon) {
		case WeaponType::DAGGER:
			cout << "Dagger" << endl;
			break;
		case WeaponType::BOW:
			cout << "Bow" << endl;
			break;
		case WeaponType::HALBERD:
			cout << "Halberd" << endl;
			break;
		case WeaponType::SPEAR:
			cout << "Spear" << endl;
			break;
		case WeaponType::MORNING_STAR:
			cout << "Morning star" << endl;
			break;
		case WeaponType::SCIMITAR:
			cout << "Scimitar" << endl;
			break;
		case WeaponType::SHIELD:
			cout << "Shield" << endl;
			break;
		case WeaponType::NONE:
			cout << "Nothing" << endl;
			break;
		default:
			cout << "Nothing" << endl;
			break;
	}
}