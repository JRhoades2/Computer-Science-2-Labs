//Jordan Rhoades
//lab6out
//lottery balls

#include <iostream>
#include "graph1.h"
#include "Lottery.h"
#include <ctime>
using namespace std;




int main()
{

	int no_balls = 0;
	bool valid = false;
	bool res = false;
	Lottery lott1;
	int num = 0;
	int matches = 0;
	float winnings = 0.0;
	char again;

	srand(time(0));
	displayGraphics();
	do
	{




		cout << "How many lottery balls do you want to play?(inbetween 3 and 10 inclusive): ";
		cin >> no_balls;
		valid = lott1.setNoBalls(no_balls);
		if (valid == false)
		{
			cout << "\nInput invalid\n";
		}



		for (int i = 0; i < lott1.getNoBalls(); i++)
		{
			do
			{
				cout << "Enter lottery #" << i + 1 << " <between 1 and 40>: ";
				cin >> num;
				res = lott1.addNumber(num);
				if (res == false)
				{
					cout << "\nReEnter the lottery number\n";
				}

			} while (res == false);
		}

		lott1.displayYourNumbers();
		lott1.processWinningNumbers();
		matches = lott1.getMatches();
		winnings = lott1.computeWinnings();

		gout << setPos(20, 50) << setColor(0, 255, 0) << "Number of Balls Played: " << no_balls << endg;
		gout << setPos(20, 70) << setColor(0, 255, 0) << "Number of Matches " << matches << endg;
		gout << setPos(20, 90) << setPrecision(2) << setColor(0, 255, 0) << "Your Payout: " << winnings << endg;

		cout << "\nWould you like to run the program?";
		cin >> again;

		clearGraphics();

	} while (again == 'y' || again == 'Y');

	return 0;
}