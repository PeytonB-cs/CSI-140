#pragma once
#include "types.h"

void displayItem(const Item& item);
void incrementItem(Item& item);
Item createItem(const string& name, const float cost, const int count);