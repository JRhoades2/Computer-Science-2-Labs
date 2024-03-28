//Jordan Rhoades
//lab2out
//


#include <iostream>
#include <ctime>
#include "graph1.h"
using namespace std;


void getWager(int* wager);
void deal(int* pc1_no, int* pc2_no, int* deal1_no, int* deal2_no);
int computeScore(int card1_no, int card2_no);
void displayResults(int pc1_no, int pc2_no, int deal1_no, int deal2_no, int player_score, int dealer_score);


int main()
{
	char again;
	
	do
	{
		int wager = 0;
		int pc1_no = 0;
		int pc2_no = 0;
		int deal1_no = 0;
		int deal2_no = 0;
		int player_score = 0;
		int dealer_score = 0;

		//Intialize random number generator generator
		srand(time(0));

		//obtaining wager
		getWager(&wager);

		//dealing numbers pertaining to cards for player and dealer
		deal(&pc1_no, &pc2_no, &deal1_no, &deal2_no);

		//cout << pc1_no << endl << pc2_no << endl << endl << deal1_no << endl << deal2_no << endl;

		//deal1_no = 1;
		//deal2_no = 1;

		//player's score
		player_score = computeScore(pc1_no, pc2_no);

		//dealer's score
		dealer_score = computeScore(deal1_no, deal2_no);

		//checking to see what numbers are picked and if they add up correctly
		//cout << endl << "Player's picked numbers: " << endl << pc1_no << endl << pc2_no << endl;
		//cout << endl << "Dealer's picked numbers: " << endl << deal1_no << endl << deal2_no << endl;
		//cout << endl << player_score << endl << dealer_score << endl;

		//display cards, score, and who won
		displayResults(pc1_no, pc2_no, deal1_no, deal2_no, player_score, dealer_score);


		cout << endl << "Would you like to play again? (Y or N) ";
		cin >> again;
	
		
		
		clearGraphics();
		system("cls");


	} while (again == 'y' || again == 'Y');
	
	return 0;
}
//get user to input wager amount
void getWager(int* wager)
{
	do
	{
		cout << "Enter your wager ($5 Minimum): ";
		cin >> *wager;
		
		if (*wager < 5)
		{
			cout << endl << "Wager must be greater than or equal to $5!" << endl;
		}

	} while (*wager < 5);
}
//getting a random number for all suites (also for player and dealer)
void deal(int* pc1_no, int* pc2_no, int* deal1_no, int* deal2_no)
{
	//hearts
	*pc1_no = rand() % 13 + 1;
	//Diamonds
	*pc2_no = rand() % 13 + 1;
	//clubs
	*deal1_no = rand() % 13 + 1;
	//spaids
	*deal2_no = rand() % 13 + 1;
}
//general function to compute any score
int computeScore(int card1_no, int card2_no)
{
	if (card1_no > 10)
	{
		card1_no = 10;
	}

	if (card1_no == 1)
	{
		card1_no = 11;
	}

	if (card2_no > 10)
	{
		card2_no = 10;
	}
	
	if (card2_no == 1 && card1_no != 11)
	{
		card2_no = 11;
	}
	/*if (card1_no == 11)
	{
		card1_no = 10;
	}
	if (card1_no == 1)
	{
		card1_no = 11;
	}
	if (card1_no == 12)
	{
		card1_no = 10;
	}
	if (card1_no == 13)
	{
		card1_no = 10;
	}
	if (card2_no == 11)
	{
		card2_no = 10;
	}
	if (card2_no == 1 && card1_no != 11)
	{
		card2_no = 11;
	}
	if (card2_no == 12)
	{
		card2_no = 10;
	}
	if (card2_no == 13)
	{
		card1_no = 10;
	}*/

	return card1_no + card2_no;
}

//to state scores, cards that were drawn, and to tell who won
void displayResults(int pc1_no, int pc2_no, int deal1_no, int deal2_no, int player_score, int dealer_score)
{
	//tell graphics window to open
	displayGraphics();

	//type text to show whose cards are who and the scores
	gout << setPos(75,90) << "Your Cards" << endg;
	gout << setPos(400, 90) << "Dealer Cards" << endg;
	gout << setPos(75, 220) << "Your Total: " << player_score << endg;
	gout << setPos(400, 220) << "Dealer Total: " << dealer_score << endg;



	//who won?
	if (player_score > dealer_score)
	{
		gout << setPos(290, 300) << "You Win!" << endg;
	}
	if (player_score < dealer_score)
	{
		gout << setPos(290, 300) << "You Lose!" << endg;
	}
	if (player_score == dealer_score)
	{
		gout << setPos(290, 300) << "Tie!" << endg;
	}

	//display the cards
	displayBMP("back.bmp", 75, 100);
	if (pc1_no == 1)
	{
		displayBMP("h14.bmp", 151, 100);
	}
	else
		displayBMP("h" + to_string(pc1_no) + ".bmp", 151, 100);

	if (pc2_no == 1)
	{
		displayBMP("d14.bmp", 227, 100);
	}
	else
		displayBMP("d" + to_string(pc2_no) + ".bmp", 227, 100);

	displayBMP("back.bmp", 400, 100);

	if (deal1_no == 1)
	{
		displayBMP("c14.bmp", 476, 100);
	}
	else
		displayBMP("c" + to_string(deal1_no) + ".bmp", 476, 100);

	if (deal2_no == 1)
	{
		displayBMP("s14.bmp", 552, 100);
	}
	else
		displayBMP("s" + to_string(deal2_no) + ".bmp", 552, 100);

}