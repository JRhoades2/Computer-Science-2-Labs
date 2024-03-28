#include <iostream>
#include "graph1.h"
#include "Lottery.h"
#include <ctime>
using namespace std;

Lottery::Lottery()
{
	int no_balls = 0;
	int* yourNumbers = NULL;
	int* winningNumbers = NULL;
	int matches = 0;
	int it = 0;
}

Lottery::~Lottery()
{
	delete[] yourNumbers;
	delete[] winningNumbers;
}

bool Lottery::setNoBalls(int no_balls)
{
	bool valid = false;
	if (no_balls < 3)
	{
		valid = false;
		this->no_balls = 3;
		yourNumbers = new int[this->no_balls];
		winningNumbers = new int[this->no_balls];
		it = 0;
		return valid;
		
	}
	if (no_balls > 10)
	{
		this->no_balls = 10;
		valid = false;
		yourNumbers = new int[this->no_balls];
		winningNumbers = new int[this->no_balls];
		it = 0;
		return valid;
		
	}
	else
	{
		valid = true;
		this->no_balls = no_balls;
		yourNumbers = new int[this->no_balls];
		winningNumbers = new int[this->no_balls];
		it = 0;
		return valid;

	}
	
}

int Lottery::getNoBalls()
{
	return no_balls;
}

bool Lottery::addNumber(int num)
{
	
	
	if (num < 1 || num > 40)
	{
		return false;
	}

	
		for (int j = 0; j < no_balls; j++)
		{
			
			if (num == yourNumbers[j])
			{
				return false;
			}
			else
			{
				yourNumbers[it] = num;
				it = it +1;
				return true;
			
			}
		}

}

void Lottery::selectionSort()
{
	int n = 0;
	int k = 0;
	int sm_index = 0;
	int smallest = 0;
	int temp1 = 0;
	int temp2 = 0;

	for (k = 0; k < no_balls ; k++)	       // size-1 = number of passes
	{
		smallest = yourNumbers[k];
		sm_index = k;

		for (n = k + 1; n < no_balls; n++)    // size = # elem. to look at
		{
			if (yourNumbers[n] < smallest)
			{
				smallest = yourNumbers[n];
				sm_index = n;
			}
		}

		if (smallest < yourNumbers[k])
		{
			temp1 = yourNumbers[k];
			yourNumbers[k] = yourNumbers[sm_index];
			yourNumbers[sm_index] = temp1;
		}
	}
}

void Lottery::insertionSort()
{
	int i = 0;
	int j = 0;
	int v = 0;

	// For each element after the first:
	for (i = 1; i < no_balls; i++)
	{
		// Look back through the previous (sorted) elts.
		// Insert this elt after first that is smaller,
		// moving the others up as you go by them.
		v = winningNumbers[i];

		for (j = i - 1; j >= 0 && winningNumbers[j] > v; j--)
		{
			// a[j] is bigger; move it up
			winningNumbers[j + 1] = winningNumbers[j];
		}

		// a[j] <= v; put v after a[j]
		winningNumbers[j + 1] = v;
	}
}

void Lottery::displayYourNumbers()
{
	

	for (int i = 0; i < no_balls; i++)
	{
		displayBMP(to_string(yourNumbers[i]) + ".bmp", 20 +40*i, 350);
		Sleep(1000);
	}
	gout << setPos(20, 410) << setColor(0, 255, 0) << "Winning Numbers" << endg;

	selectionSort();

	for (int i = 0; i < no_balls; i++)
	{
		displayBMP(to_string(yourNumbers[i]) + ".bmp", 20 + 40 * i, 350);
		;
	}
}

void Lottery::processWinningNumbers()
{
	bool duplicate = false;
	
	
	for (int i = 0; i < no_balls; i++)
	{

		winningNumbers[i] = rand() % 40 + 1;

		do
		{
			duplicate = false;
			for (int j = 0; j < i; j++)
			{
				if (winningNumbers[i] == winningNumbers[j])
				{
					winningNumbers[i] = rand() % 40 + 1;
					duplicate = true;
					break;
				}
			}
		} while (duplicate);
	}

	for (int i = 0; i < no_balls; i++)
	{
		displayBMP(to_string(winningNumbers[i]) + ".bmp", 20 + 40 * i, 220);
		Sleep(1000);
	}
	Sleep(3000);
	insertionSort();
	for (int i = 0; i < no_balls; i++)
	{
		displayBMP(to_string(winningNumbers[i]) + ".bmp", 20 + 40 * i, 220);
		
	}
	gout << setPos(20, 280) << setColor(0, 255, 0) << "Winning Numbers" << endg;
}

int Lottery::binarySearch(int target) 
{
	//Variable Declaration/Initialization
	int low = 0;
	int high = 0;
	int middle = 0;
	bool found = false;
	int index = -1;

	//Initialize low/high
	low = 0;
	high = no_balls - 1;

	while ((low <= high) && (!found))
	{
		middle = (low + high) / 2;

		if (winningNumbers[middle] == target)
			found = true;
		else if (target > winningNumbers[middle])
			low = middle + 1;
		else
			high = middle - 1;
	}

	if (!found)
	{
		index = -1;
	}
	else
	{
		index = middle;
	}
	return(index);

}
int Lottery::getMatches()
{
	int match;
	
	for (int i = 0; i < no_balls; i++)
	{
		match = binarySearch(yourNumbers[i]);
		if (match == -1)
		{
			cout << "\nNo match!\n";
		}
		else
		{
			cout << "\nMatch!\n";
			matches = matches + 1;
		}

	}
	return matches;
}

int Lottery::computeWinnings()
{
	float winnings;
	winnings = pow(10.0, matches);
	
	return winnings;
}
