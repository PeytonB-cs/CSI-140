#include <iostream>

using namespace std;

int main()
{
	int x = 2;
	int y = 2;

	cout << 2 * x++ << ' '; // postfix increment
	cout << 2 * ++y << ' '; // prefix increment
	cout << ' ' << x;
	cout << ' ' << y;
}