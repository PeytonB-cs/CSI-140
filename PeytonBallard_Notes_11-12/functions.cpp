#include <iostream>
#include "functions.h"

using namespace std;

void displayItem(const Item& item) {
	cout << item.name << ' ' << '$' << item.cost << ' ' << item.count << "\n";
}

void incrementItem(Item& item) {
	item.count++;
}

Item createItem(const string& name, const float cost, const int count) {
	Item item;

	item.name = name;
	item.cost = cost;
	item.count = count;

	return item;
}