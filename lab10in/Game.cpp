#include <iostream>
#include <cstring>
#include <fstream>
#include "graph1.h"
#include "Game.h"

using namespace std;


Game::Game()
{
	fileName = "";
	word = "";
}


string Game::getFileName()
{
	return fileName;

}
void Game::setFileName(string fn)
{
	fileName = fn;
}
void Game::setWord(int rand_no)
{
	int wordCount = 0;

	//open file
	fstream in_file("words1.txt", ios::in);

	//test if file opened
	if (!in_file)
	{
		cout << "Error opening file!";
	}

	//read words onen at a time
	while (true)
	{
		string rand_word = "";
		in_file >> word;

		if (wordCount == rand_no)
		{
			rand_word = word;
			break;
		}

		wordCount++;
	}

	in_file.close();

}
string Game::getWord()
{
	return word;
}
void Game::draw()
{
	int length = word.length();
	int x = 100;
	int y = 250;

	for (int i = 0; i < length; i++)
	{
		fileName = "";
		fileName += word[i];
		fileName += ".bmp";
		displayBMP(fileName, x, y);
		x += 33;
	}
	

}
