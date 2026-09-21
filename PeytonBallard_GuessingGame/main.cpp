//	Author: Peyton - Ballard
//	Class : CSI - 140 - 05
//	Assignment : Module-05-Lab - Guessing game
//	Date Assigned : Sep 17th - 2:30pm
//	Due Date : Sep 21st - 2:30pm
//	Description :
//	This program is a guessing game using a loop to have the player input a number until they guess it
//	Certification of Authenticity :
//	I certify that this is entirely my own work, except where I have given
//	fully - documented references to the work of others.I understand the
//	definition and consequences of plagiarism and acknowledge that the assessor
//	of this assignment may, for the purpose of assessing this assignment :
//	-Reproduce this assignment and provide a copy to another member of
//	academic staff; and /or
//	-Communicate a copy of this assignment to a plagiarism checking
//	service(which may then retain a copy of this assignment on its
//		database for the purpose of future plagiarism checking)

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	// set the random seed
	unsigned int seed = time(0);
	srand(seed);

	// declare the outer variable
	int playAgain = 1;

	// outer loop where the game is
	while (playAgain == 1)
	{
		// declare random variables
		int min = 1;
		int max = 100;
		int randNum = min + (rand() % (max - min + 1));

		// declare guessing variables
		int guess = 0;
		int userGuesses = 0;
		bool quitEarly = false;

		// prompt the user
		cout << "Guess the number between 1 and 100: ";
		cin >> guess;

		// inner loop where the guessing is
		while (guess != randNum)
		{
			if (guess == 0)
			{
				quitEarly = true;
				break;
			}

			userGuesses++;

			if (guess < randNum)
			{
				cout << "Too low!" << endl;
			}
			else
			{
				cout << "Too high!" << endl;
			}

			// declare a distance 
			int distance = abs(guess - randNum);

			// check the distance and give a hint based on it
			if (distance <= 2)
				cout << "Burning hot!" << endl;
			else if (distance <= 10)
				cout << "Hot!" << endl;
			else if (distance <= 25)
				cout << "Getting close!" << endl;
			else
				cout << "Cold!" << endl;

			cout << "Guess the number between 1 and 100: ";
			cin >> guess;
		}

		if (quitEarly)
		{
			cout << "You quit after " << userGuesses << " guesses." << endl;
			break; // leave the outer loop too, program ends
		}

		// count the winning guess as well
		userGuesses++;

		// tell the user they got the right number
		cout << "Correct! The number was " << randNum << "." << endl;
		cout << "Number of guesses: " << userGuesses << endl;

		// prompt the player to play again or quit
		cout << "Play again? (0 for No, 1 for Yes): ";
		cin >> playAgain;
	}

	return 0;
}