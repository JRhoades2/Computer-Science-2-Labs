//Jordan Rhoades
//Lab2in
//asks user to give number of dice then code calc. score and shows the randomly rolled dice

#include <iostream>
#include <ctime>
#include "graph1.h"

using namespace std;

//Protoypes
void getDiceCount(int* noDice);
void rollDice(int* dice, int noDice);
void computeScore(int* dice, int noDice, int* score);
void displayResults(int* dice, int noDice, int score);

int main()
{
	
	//Variable Declaration/Initialization
	char again;
	int noDice = 0;
	const int MAX_DICE = 5;
	int dice[MAX_DICE] = { 0 };
	int score = 0;

	do
	{
		

		//Initialize random number generator 
		srand(time(0));
		//Display Graphics
		displayGraphics();

		//1. Get the number of dice to roll
		getDiceCount(&noDice);

		//2. Roll the Dice (i.e., generates a random number for each dice
		rollDice(dice, noDice);

		//3. Compute the score
		computeScore(dice, noDice, &score);

		//4. Display the dice and results
		displayResults(dice, noDice, score);

		cout << endl << "Would you like to run this program again? (Type Y or N)" << endl;
		cin >> again;

		clearGraphics();
		system("cls");

	} while (again == 'y' || again == 'Y');

	return 0;

}

//Functions
void getDiceCount(int* noDice)
{
	//Prompts for the number of Dice to display and stores in the noDice variable
	//User input should be between 1 and 5 inclusively – reprompt if not within range
	do
	{
		cout << "Please enter the number of dice (between 1 and 5): ";
		cin >> *noDice;
		if (*noDice > 6 || *noDice < 1)
			cout << endl << "Number of dice must be between 1 and 5 inclusively!" << endl;
	} while (*noDice > 5 || *noDice < 1);
}


void rollDice(int* dice, int noDice)
{
	//Generates noDice random numbers corresponding to the rolling of the dice
	//Each random number is stored in the dice parameter
	//Each random number should be stored 
	int i = 0;

	for (i = 0; i < noDice; i++)
	{
		dice[i] = rand() % 6 + 1;
	}
}

void computeScore(int* dice, int noDice, int* score)
{
	//Variable Declaration
	int i = 0;
	*score = 0;

	//Adds up each random number stored in the dice array
	//Stores the result in the score parameter
	for (i = 0; i < noDice; i++)
	{
		*score += dice[i];
	}
}

void displayResults(int* dice, int noDice, int score)
{
	//Display each Die starting at 100,100
	//Each Die has a width of 104
	//Display the Score at (50,225)
	int i = 0;
	int x = 50;
	int y = 100;
	for (i = 0; i < noDice; i++)
	{
		displayPNG(to_string(dice[i]) + "Die.png", x , y);
		x += 129;
	}

	gout << setColor(255, 0, 0) << setPos(50, 255) << "Score: " << score << endg;

}
