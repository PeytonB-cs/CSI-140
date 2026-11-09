#include <iostream>
#include <vector>

using namespace std;

// create a bundle of variables using structs this example is larger and it makes more sense to pass by reference
struct Item {
	// declare struct variables
	string name = "Default";
	float cost = 0;
	int count = 1;
};

// smaller struct example is much easier to copy and more convient to pass by value
struct Vector2 {
	float x, y;
};

struct Address {
	string city;
	string street;
};

struct Person {
	vector<Item> items;
	Address address;
	string name;
};

// function prototypes
void displayItem(const Item& item);
void incrementItem(Item& item);
Item createItem(const string& name, const float cost, const int count);

int main()
{
	//// dont do this it can cause bugs when items are not parrallel use structs instead
	//string itemNames[100];
	//float itemCosts[100];
	//int itemAmounts[100];

	//// this is how you should do it instead with a struct
	//Item items[100];

	// declare items like this
	Item spear;

	// add values like this
	spear.name = "Spear";
	spear.cost = 10;
	spear.count = 5;

	// declare items like this (example 2)
	Item shield;

	// add values like this (example 2)
	shield.name = "Shield";
	shield.cost = 5;
	shield.count = 2;

	Item morningStar = createItem("Morningstar", 5, 10);

	// vector example of an item array
	vector<Item> items;
	items.push_back(spear);
	items.push_back(shield);
	items.push_back(morningStar);

	// display all items inside the vector
	for (const Item& item : items) {
		displayItem(item);
	}

	for (int i = 0; i < items.size(); i++) {
		displayItem(items[0]);

		Item& item = items[i];
		item.name = "1";
		item.cost = 15;
		item.count = 12;
	}

	Person bob;
	bob.name = "Bob";
	bob.address.city = "New York";
	bob.address.street = "Main";
	bob.items.push_back(createItem("sword", 800000000, 2));
	bob.items.push_back(createItem("shield", 40000, 7));
}

// this function displays an item that is passed through alonside its cost and count
void displayItem(const Item& item) {
	cout << item.name << ' ' << '$' << item.cost << ' ' << item.count << "\n";
}

// this function increments the item
void incrementItem(Item& item) {
	item.count++;
}

// this function creates an item
Item createItem(const string& name, const float cost, const int count) {
	// declare the item
	Item item;

	// input values
	item.name = name;
	item.cost = cost;
	item.count = count;

	return item;
}