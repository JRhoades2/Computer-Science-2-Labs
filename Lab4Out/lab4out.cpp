//Jordan Rhoades
//lab4out
//creates custom postal addressing system

#include <iostream>
#include <string>
#include <cctype>
#include "graph1.h"

using namespace std;


string getString(string prompt);
bool validateName(string name);
bool validateAddress(string address);
bool validateCity(string city);
bool validateState(string state);
bool validateZip(string zip);
string convertToUpper(string input);
void displayLetter(string fn, string ln, string addr, string city, string state, string zip, int weight);


int main()
{

	string fn = "";
	string ln = "";
	string addr = "";
	string city = "";
	string state = "";
	string zip = "";
	string phone = "";
	string dummy = "";
	int weight = 0;
	bool res = false;
	string again = "";

	do
	{

		//obtaining the strings;
		do
		{
			fn = getString("Enter First Name: ");
			res = validateName(fn);
		} while (!res);

		do
		{
			ln = getString("Enter Last Name: ");
			res = validateName(ln);

		} while (!res);

		do
		{
			addr = getString("Enter Street Address: ");
			res = validateAddress(addr);

		} while (!res);

		do
		{
			city = getString("Enter City: ");
			res = validateCity(city);
		} while (!res);

		do
		{
			state = getString("Enter State: ");
			res = validateState(state);
		} while (!res);

		do
		{
			zip = getString("Enter Zip Code: ");
			res = validateZip(zip);
		} while (!res);
		//the getString function on page 8 of the lab4out doc states to get a phone number
		//but we don't ever user a phone number variable anywhere else in the program
		//phone = getString("Enter Phone: ");

		state = convertToUpper(state);

		displayLetter(fn, ln, addr, city, state, zip, weight);

		cout << "Would you like to run this code again? (Y or N) ";
		getline(cin, again);

		clearGraphics();
		system("cls");

	} while (again[0] == 'y' || again[0] == 'Y');



	return 0;
}

//generic program to aquire any string
string getString(string prompt)
{
	string variable;
	//Prompt user for name using getline (prompt contains the message displayed to user))
	cout << prompt;
	getline(cin, variable);

	return variable;
}



bool validateName(string name)
{
	int i = 0;
	bool result = true;
	//Validate the name – return true if valid, false if not
	for (i = 0; i < name.length(); i++)
	{
		result = true;
		if (isalpha(name[i]) == 0)
		{
			if (isspace(name[i]) == 0)
			{
				cout << "Please enter a valid name!" << endl;
				result = false;
			}
		}
	}
	return result;
}

bool validateAddress(string address)
{
	bool result = true;
	int i = 0;
	//Validate the address – return true if valid, false if not
	for (i = 0; i < address.length(); i++)
	{
		result = true;
		if (isalnum(address[i]) == 0)
		{
			if (isspace(address[i]) == 0)
			{
				cout << "Please enter a valid address!" << endl;
				result = false;
			}
		}
	}
	return result;
}

bool validateCity(string city)
{
	bool result = true;

	if (isupper(city[0]) == 0)
	{
		cout << "Please enter a city with capitalized first letter!\n";
		result = false;
	}
	else
	{
		int i = 0;

		for (i = 0; i < city.length(); i++)
		{
			result = true;

			if (isalpha(city[i]) == 0)
			{
				cout << "Please enter a valid city!\n";
				result = false;
			}
		}
	}
	return result;
}

bool validateState(string state)
{
	bool result = true;

	if (state.length() > 2 or state.length() < 2)
	{
		result = false;
		cout << "Please Enter a valid state initials!\n";
	}
	int i = 0;
		for (i = 0; i < state.length(); i++)
		{
			if (isalpha(state[i]) == 0)
			{
				cout << "Please enter a valid state initials!\n";
				result = false;
			}
		}
	
	return result;
}

bool validateZip(string zip)
{
	bool result = true;
	int i = 0;
	if (zip.length() > 5 or zip.length() < 5)
	{
		result = false;
		cout << "Enter a valid zip code!\n";
	}
		for (i = 0; i < zip.length(); i++)
		{
			if (isdigit(zip[i]) == 0)
			{
				cout << "Please enter a valid zip code!\n";
				result = false;
			}
		}
	

	return result;
}

string convertToUpper(string input)
{
	int i = 0;
	for (i = 0; i < input.length(); i++)
	{
		if (islower(input[i]))
		{
			input[i] = toupper(input[i]);
		}
	}
	
	return input;
}

void displayLetter(string fn, string ln, string addr, string city, string state, string zip, int weight)
{
	do
	{
		cout << "Enter weight: ";
		cin >> weight;
		if (weight > 6 || weight < 1)
		{
			cout << "Please enter a weight from 1 to 6 inclusively\n";
		}
	} while (weight > 6 || weight < 1);
	cin.ignore();

	displayGraphics();

	displayBMP("envelope.bmp", 0, 0);
	displayBMP("returnAddress.bmp", 43, 26);
	
	if (weight == 1)
	{
		displayBMP("stamp.bmp", 525, 20);
	}
	if (weight == 2)
	{
		displayBMP("stamp.bmp", 525, 20);
		displayBMP("stamp.bmp", 450, 20);
	}
	if (weight == 3)
	{
		displayBMP("stamp.bmp", 525, 20);
		displayBMP("stamp.bmp", 450, 20);
		displayBMP("stamp.bmp", 375, 20);
	}
	if (weight == 4)
	{
		displayBMP("stamp.bmp", 525, 20);
		displayBMP("stamp.bmp", 450, 20);
		displayBMP("stamp.bmp", 375, 20);
		displayBMP("stamp.bmp", 525, 99);
	}
	if (weight == 5)
	{
		displayBMP("stamp.bmp", 525, 20);
		displayBMP("stamp.bmp", 450, 20);
		displayBMP("stamp.bmp", 375, 20);
		displayBMP("stamp.bmp", 525, 99);
		displayBMP("stamp.bmp", 450, 99);
	}
	if (weight == 6)
	{
		displayBMP("stamp.bmp", 525, 20);
		displayBMP("stamp.bmp", 450, 20);
		displayBMP("stamp.bmp", 375, 20);
		displayBMP("stamp.bmp", 525, 99);
		displayBMP("stamp.bmp", 450, 99);
		displayBMP("stamp.bmp", 375, 99);
	}

	gout << setPos(315,210) << setColor(0, 255, 0) << fn << " " << ln << endg;
	gout << setPos(315, 225) << setColor(0, 255, 0) << addr << endg;
	gout << setPos(315, 240) << setColor(0, 255, 0) << city << ", " << state << " " << zip << endg;

	setColor(drawLine(200,385,200+290,385,2), 255, 255, 255);
	setColor(drawLine(200, 385, 200, 385 + 85, 2), 255, 255, 255);
	setColor(drawLine(200, 385 + 85, 200 + 290, 385 + 85, 2),255, 255, 255);
	setColor(drawLine(200 + 290, 385, 200 + 290, 385 + 85, 2), 255, 255, 255);

	gout << setPos(205, 400) << setColor(0, 255, 0) << "Weight: " << weight << " ounces" << endg;
	gout << setPos(205, 425) << setColor(0, 255, 0) << "Cost of First Class Stamp: 47 Cents" << endg;
	gout << setPrecision(2);
	gout << setPos(205, 450) << setColor(0, 255, 0) << "Total Mailing Cost: $" << (weight * .47) << endg;
}