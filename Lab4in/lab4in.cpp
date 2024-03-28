//Jordan Rhoades
//Lab 4 in
//Creates a form for inputting/validating information

#include <iostream>
#include <string>
#include <cctype>
#include "graph1.h"

using namespace std;

//Prototypes are below
string getString(string prompt);
bool validateName(string name);
bool validateAddress(string address);
bool validatePhone(string phone);
string convertToUpper(string string);
void displayFields(string name, string address, string phone);


int main()
{
	//Variable Declaration/Initialization
	string name = "";
	string address = "";
	string phone = "";
	string upperName = "";
	bool res = false;
	char again;


	//Display graphics window
	displayGraphics();
	do
	{
		name = "";
		address = "";
		phone = "";
		upperName = "";
		res = false;

		//Process name info
		do
		{
			//Prompt for the name - 
			name = getString("Enter Name: ");

			//validate the name
			res = validateName(name);

		} while (!res);

		//Process the address info
		do
		{
			//Get the address
			address = getString("Enter Address: ");

			//validate the address
			res = validateAddress(address);

		} while (!res);

		//Process phone info
		do
		{
			//Get the phone
			phone = getString("Enter Phone: ");

			//validate the phone
			res = validatePhone(phone);

		} while (!res);



		//Convert the name to all uppercase
		upperName = convertToUpper(name);

		//Display the fields
		displayFields(upperName, address, phone);

		cout << "Would you like to run this program again? (Y or N) ";
		cin >> again;
		cin.ignore();


	} while (again == 'y' || again == 'Y');

	return 0;
}




//Prompts for input based on input parameter prompt
string getString(string prompt)
{
	string variable;
	//Prompt user for name using getline (prompt contains the message displayed to user))
	cout << prompt;
	getline(cin, variable);

	return variable;

}

//Validates characters of name
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

//Validates characters of address
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



//Validates characters of phone number
bool validatePhone(string phone)
{
	bool result = true;
	//Validate the phone – return true if valid, false if not
	if (phone.length() != 10)
	{
		cout << endl << "Please enter a valid phone number!" << endl;
		result = false;

	}
	else
	{


		for (int i = 0; i < phone.length(); i++)
		{
			result = true;

			if (isdigit(phone[i]) == 0)
			{

				cout << "Please enter a valid phone number!" << endl;
				result = false;

			}
		}
	}
	return result;
}

//Converts text to uppercase
string convertToUpper(string input)
{
	//Convert input to all uppercase
	for (int i = 0; i < input.length(); i++)
	{
		input[i] = toupper(input[i]);
	}
	//Return converted input
	return input;
}

//Displays the information in graphics window
void displayFields(string name, string address, string phone)
{
	//Draw the form (rectangles)
	int rectangle1 = drawRect(230, 85, 170, 20);
	setColor(rectangle1, 128, 128, 128);
	int rectangle2 = drawRect(230, 125, 325, 20);
	setColor(rectangle2, 128, 128, 128);
	int rectangle3 = drawRect(230, 165, 125, 20);
	setColor(rectangle3, 128, 128, 128);

	//Display the fields
	gout << setPos(150, 100) << setColor(0, 255, 0) << "Name:     " << name << endg;
	gout << setPos(150, 140) << setColor(0, 255, 0) << "Address:  " << address << endg;
	gout << setPos(150, 180) << setColor(0, 255, 0) << "Phone:    " << phone << endg;



}
