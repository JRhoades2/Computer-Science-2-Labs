//Jordan Rhoades
//lab5inB


#include <iostream>
#include <string>
#include "graph1.h"
using namespace std;


class Word
{
private:
	string word;
	int* x; //x-coords
	int* y; //y-coords


public:
	Word();
	~Word();
	void setWord(string word);
	void  setCoords(int x_val, int y_val);
	string getWord();
	void draw();
};


Word::Word()
{
	//Initialize pointers to NULL, word to “”
	x = NULL;
	y = NULL;
	word = "";
}
Word::~Word()
{
	//Cleanup pointers
	delete[] x; 
	delete[] y;
}

void  Word::setCoords(int x_val, int y_val)
{
	//Dynamically allocate x/y arrays
	//Set the values in the x/y arrays based on x_val/y_val
	x = new int[(int)getWord().length()];
	y = new int[(int)getWord().length()];

	for (int i = 0; i < (int)getWord().length(); i++)
	{
		x[i] = x_val + 32 * i;
	}

	for (int i = 0; i < (int)getWord().length(); i++)
	{
		y[i] = y_val;
	}

}
void Word::setWord(string word)
{
	this->word = word;

}
string Word::getWord()
{
	return word;
}

void Word::draw()
{
	string letter = "a.bmp";
	for (int i = 0; i < (int)getWord().length(); i++)
	{
		letter[0] = getWord()[i];
		displayBMP(letter, x[i], y[i]);
	}

}


// 
//  
//Reverses input word

void reverseWord(Word& copy, int x_val, int y_val);

int main()
{
	int x = 0;
	int y = 0;
	string input;
	int size = 0;
	Word word;
	char repeat;

	do
	{
		displayGraphics();



		//Prompt the user for the word to be displayed..
		cout << "Enter word: ";
		cin >> input;
		cout << endl;

		// Invoke setWord method that sets the private data field word.
		word.setWord(input);


		//Prompt for the inital x/y coord
		cout << "Enter initial x/y coord: ";
		cin >> x >> y;

		//Set the x/y coords
		word.setCoords(x, y);
		// Invoke the draw method that displays the alphabetic images corresponding
		word.draw();

			//5. Add the delay
			Sleep(3000);

		//6. Invoke the reverseWord independent function to reverse the original 
		reverseWord(word, x, y);


		//5. Repeat as many times as desired.
		cout << "Repeat? <y/n>: ";
		cin >> repeat;

		clearGraphics();


	} while (repeat == 'y' || repeat == 'Y');

	return 0;
}

void reverseWord(Word& copy, int x_val, int y_val)
{
	//Reverse the copy
	//Display the reversed word

	string myWord = copy.getWord();
	string reverseWord = myWord;
	int length = copy.getWord().length();

	
	for (int i = 0; i < length; i++)
	{
		myWord[i] = reverseWord[length - i - 1];
	}

	copy.setWord(myWord);
	copy.draw();

}
