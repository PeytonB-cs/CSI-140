#include <iostream>
#include <vector>
#include <array>

using namespace std;

void printVector(vector<string> vector)
{
	int count = vector.size();
	for (int i = 0; i <= count; i++) {
		cout << vector[i] << ',';
	}
}

void printArray(string array[], int count) {
	cout << sizeof(array) << endl;
	for (int i = 0; i < count; i++) {
		cout << array[i] << ", ";
	}
}

int main()
{
	int x = 0;
	int y = 0;
	int z = 0;

	//declare an array
	//int arr[10];

	//array size must be constant not dynamic
	const int ARRAY_SIZE = 10;
	int arr[ARRAY_SIZE];

	//one way to initialize an array manually
	//int arr[ARRAY_SIZE] = {
	//	0, 1, 2, 3, 4
	//};
	//arr[0] = 5;

	string names[] = {
		"Eric", "Bob", "Eliza"
	};

	//cout << sizeof(names); //Size in bytes
	int count = sizeof(names) / sizeof(string);
	printArray(names, 3);

	//initialize array
	//for (int i = 0; i < ARRAY_SIZE; i++) {
	//	arr[i] = i;
	//	//cout << arr[i];
	//}
	////output array
	//for (int i = 0; i < ARRAY_SIZE; i++) {
	//	cout << arr[i] << ", ";
	//}

	//template array
	array<string, 5> myTemplateArray;
	myTemplateArray.size();

	//vectors
	vector<int> myVector;
	myVector.reserve(10);

	myVector.push_back(5);
	myVector.push_back(3);

	myVector.pop_back();

	myVector.insert(myVector.begin(), 3);

	int numElements = myVector.size();
	int maxElements = myVector.capacity();
}