//Jordan Rhoades
//lab5out
//having user input time then showing a clock of the time they entered


#include <iostream>
#include <math.h>
#include "graph1.h"

using namespace std;

class Clock
{
private:
	int hour;
	int min;
	int sec;


public:
	Clock();
	bool setHour(int hour_val);
	bool setMin(int min_val);
	bool setSec(int sec_val);
	int getHour();
	int getMin();
	int getSec();
	void draw();

};
Clock::Clock()
{
	hour = 0;
	min = 0;
	sec = 0;
}

bool Clock::setHour(int hour_val)
{
	bool result = false;

	if (hour_val < 0)
	{
		hour = 0;
	}

	else if (hour_val > 11)
	{
		hour_val = 11;
	}
	else 
	{
		result = true;
		hour = hour_val;
	}
	return result;
}

int Clock::getHour()
{
	return hour;
}

bool Clock::setMin(int min_val)
{
	bool result = false;

	if (min_val < 0)
	{
		min = 0;
	}
	else if (min_val > 59)
	{
		hour = 59;
	}
	else
	{
		result = true;
		min = min_val;
	}
	return result;
}

int Clock::getMin()
{
	return min;
}

bool Clock::setSec(int sec_val)
{
	bool result = false;

	if (sec_val < 0)
	{
		sec = 0;
	}
	else if (sec_val > 59)
	{
		sec = 59;
	}
	else
	{
		result = true;
		sec = sec_val;
	}
	return result;
}

int Clock::getSec()
{
	return sec;
}

void Clock::draw()
{
	
	int alpha,
		length_of_s_hand = 150,
		length_of_m_hand = 180,
		length_of_h_hand = 133,
		center_x = 320,
		center_y = 215,
		end_x,
		end_y;
	

	// draw white background to hid the black background
	//display everything
	drawRect(0, 0, 640, 440);

	displayPNG("clock_face.png", 123, 25);


	alpha = sec * 6;

	if (alpha >= 0 && alpha < 90)
	{
		end_x = center_x + (cos((90 - alpha)*atan(1)*4 / 180.0))*length_of_s_hand;
		end_y = center_y - (sin((90 - alpha)*atan(1)*4 / 180.0))* length_of_s_hand;
	}

	else if (alpha >= 90 && alpha < 180)
	{
		end_x = center_x + (cos((alpha - 90)*atan(1)*4 / 180.0))* length_of_s_hand;
		end_y = center_y + (sin((alpha - 90)*atan(1)*4 / 180.0))*length_of_s_hand;
	}

	else if (alpha >= 180 && alpha < 270)
	{
		end_x = center_x - (cos((270 - alpha)*atan(1)*4 / 180.0))*length_of_s_hand;
		end_y = center_y + (sin((270 - alpha)*atan(1)*4 / 180.0))*length_of_s_hand;
	}

	else if (alpha >= 270 && alpha < 360)
	{
		end_x = center_x - (cos((alpha - 270)*atan(1)*4 / 180.0))*length_of_s_hand;
		end_y = center_y - (sin((alpha - 270)*atan(1)*4 / 180.0))*length_of_s_hand;
	}

	setColor(drawLine(center_x, center_y, end_x, end_y, 1) , 255, 0, 0);
	
	alpha = min * 6 + (sec / 60.0) * 6;

	if (alpha >= 0 && alpha < 90)
	{
		end_x = center_x + (cos((90 - alpha)*atan(1)*4 / 180.0))*length_of_m_hand;
		end_y = center_y - (sin((90 - alpha)*atan(1)*4 / 180.0))* length_of_m_hand;
	}

	else if (alpha >= 90 && alpha < 180)
	{
		end_x = center_x + (cos((alpha - 90)*atan(1)*4 / 180.0))* length_of_m_hand;
		end_y = center_y + (sin((alpha - 90)*atan(1)*4 / 180.0))*length_of_m_hand;
	}

	else if (alpha >= 180 && alpha < 270)
	{
		end_x = center_x - (cos((270 - alpha)*atan(1)*4 / 180.0))*length_of_m_hand;
		end_y = center_y + (sin((270 - alpha)*atan(1)*4 / 180.0))*length_of_m_hand;
	}

	else if (alpha >= 270 && alpha < 360)
	{
		end_x = center_x - (cos((alpha - 270)*atan(1)*4 / 180.0))*length_of_m_hand;
		end_y = center_y - (sin((alpha - 270)*atan(1)*4 / 180.0))*length_of_m_hand;
	}


	setColor(drawLine(center_x, center_y, end_x, end_y, 2), 0, 0, 0);
	
	alpha = hour * 30 + (min / 60.0) * 30;

	if (alpha >= 0 && alpha < 90)
	{
		end_x = center_x + (cos((90 - alpha)*atan(1)*4 / 180.0))*length_of_h_hand;
		end_y = center_y - (sin((90 - alpha)*atan(1)*4 / 180.0))* length_of_h_hand;
	}

	else if (alpha >= 90 && alpha < 180)
	{
		end_x = center_x + (cos((alpha - 90)*atan(1)*4 / 180.0))* length_of_h_hand;
		end_y = center_y + (sin((alpha - 90)*atan(1)*4 / 180.0))*length_of_h_hand;
	}

	else if (alpha >= 180 && alpha < 270)
	{
		end_x = center_x - (cos((270 - alpha)*atan(1)*4 / 180.0))*length_of_h_hand;
		end_y = center_y + (sin((270 - alpha)*atan(1)*4 / 180.0))*length_of_h_hand;
	}

	else if (alpha >= 270 && alpha < 360)
	{
		end_x = center_x - (cos((alpha - 270)*atan(1)*4 / 180.0))*length_of_h_hand;
		end_y = center_y - (sin((alpha - 270)*atan(1)*4 / 180.0))*length_of_h_hand;
	}

	setColor(drawLine(center_x, center_y, end_x, end_y, 4) , 0, 0, 0);

	

	
}






int main()
{
	int hour;
	int min;
	int sec;

	bool result;
	char again;
	Clock clock1;
	
	//cout << atan(1) * 4;

	do
	{

		cout << "Enter the number of seconds: ";
		cin >> sec;

		result = clock1.setSec(sec);
		if (result == false)
		{
			cout << "\nYou entered an incorrect seconds value!\n";
		}





		cout << "Enter the number of minutes: ";
		cin >> min;
		result = clock1.setMin(min);
		if (result == false)
		{
			cout << "\nYou entered an incorrect minutes value!\n";
		}




		cout << "Enter the number of hours: ";
		cin >> hour;
		result = clock1.setHour(hour);
		if (result == false)
		{
			cout << "\nYou entered an incorrect hour value!\n";
		}



		displayGraphics();

		clock1.draw();

		gout << setPos(270, 420) << setColor(0, 0, 0) << "Time: " << clock1.getHour() << ":" << clock1.getMin() << ":" << clock1.getSec() << endg;


		cout << "\nWould you like to run the program again?\n";
		cin >> again;

		clearGraphics();

	} while (again == 'y' || again == 'Y');

	return 0;
}