//Jordan Rhoades
//Lab1out
//obtain and display graph of month vs. monthly sales and give sales statistics

#include <iostream>
#include "graph1.h"
#include <typeinfo>
using namespace std;


int getNoMonths();
void getSales(int sales[], int no_months);
int getMax(int sales[], int no_months);
int getMin(int sales[], int no_months);
double getAverage(int sales[], int no_months);
void displayResults(int sales[], int no_months, int max, int min, double avg);

const int MAX_MONTH = 6;

int main()
{
	int sales[MAX_MONTH];
	int no_months = 0;
	int max = 0;
	int min = 0;
	double avg = 0;

	
	no_months = getNoMonths();
	//cout << endl << "checking no_Months:" << no_months << endl;

	getSales(sales, no_months);
	/*for(int i = 0; i < no_months;i++)
		cout << endl << sales[i];
	*/

	max = getMax(sales, no_months);
	//cout << "max: " << max << endl;

	min = getMin(sales, no_months);
	//cout << "min: " << min << endl;

	//displayGraphics();

	displayResults(sales, no_months, max, min, avg);

	system("pause");
	return 0;
}
//asking user to input number of months (between 3 and 6 months)
int getNoMonths()
{
	int no_months = 0;

	do
	{
		cout << "Enter the number of months to process (between 3 and 6 inclusive): ";
		cin >> no_months;
	} while (no_months < 3 || no_months > 6);

	return no_months;
}
//asks user to input sales for each month
void getSales(int sales[], int no_months)
{
	int i = 0;
	int sale = 0;
	for (int i = 0; i < no_months; i++)
	{
		//int sale = 0;
		
		do
		{
			cout << "Enter sales for month #" << i + 1 << ": ";
			cin >> sales[i];
		
			//cout << typeid(sales[i]).name() << endl;

		} while (sales[i] < 0);
		//sales[i] = sale;

	}
}
//takes sales array and finds the max 
int getMax(int sales[], int no_months)
{
	int temp = sales[0];
	int i = 0;
	int max = 0;
	for (int i = 1; i < no_months; i++)
	{
		if (temp < sales[i])
			temp = sales[i];

	}
	max = temp;
	return max;
}
//takes sales array and finds the min
int getMin(int sales[], int no_months)
{
	int temp = sales[0];
	int i = 0;
	int min = 0;
	for (int i = 1; i < no_months; i++)
	{
		if (temp > sales[i])
			temp = sales[i];
	}
	min = temp;
	return min;
}
//displays results in the form of a graph and sales statistics
void displayResults(int sales[], int no_months, int max, int min, double avg)
{
	int x = 0;
	int y = 0;
	int z = 0;
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	avg = 0;

	for (int y = 0; y < no_months; y++)
	{
		z = sales[y] + z;
	}
	avg = z / no_months;
	//cout << avg;

	displayGraphics();
	//x and y axes
	drawLine(200,280,200,130,1);
	drawLine(200,280,640,280,1);
	gout << setPos(135, 195) << setColor(0, 255, 0) << "Monthly" << endg;
	gout << setPos(135, 210) << setColor(0, 255, 0) << "Sales" << endg;
	gout << setPos(360,295)<< setColor(0, 255, 0) << "Months" << endg;

	//sales statistics (box and text)
	gout << setPos(205, 340) << setColor(0, 255, 0) << "Sales Statistics"  << endg;

	gout << setPos(205, 380) << setColor(0, 255, 0) << "Max Sales: $" << max << endg;
	gout << setPos(205, 400) << setColor(0, 255, 0) << "Min Sales: $" << min << endg;
	gout << setPos(205, 420) << setColor(0, 255, 0) << "Avg Sales: $" << int(avg) << endg;

	drawLine(200, 345, 400, 345, 1);
	drawLine(400,345,400,445,1);
	drawLine(200, 345, 200, 445,1);
	drawLine(200,445,400,445,1);
	//drawRect(200, 345, 200, 100);

	//header/title
	displayBMP("sales1.BMP",250,25);
	gout << setPos(375, 75) << setColor(0, 255, 0) << "Sales for " << no_months << " months" << endg;
	
	//calc height
	int height[MAX_MONTH];
	for(int x = 0; x < no_months; x++)
	{
		height[x] = (double (sales[x]) / max) * 100.0;
		if (height[x] == 0)
			height[x] = 1;
	}
	
	//bars on graph
	if (no_months == 3)
	{ 
		i = drawRect(201, 279, 50, -height[0]);
		setColor(i, 255, 0, 0);
		j = drawRect(276, 279, 50, -height[1]);
		setColor(j, 0, 255, 0);
		k = drawRect(351, 279, 50, -height[2]);
		setColor(k, 0, 0, 255);
		gout << setPos(201, -height[0]+279) << setColor(0, 255, 0) << "Jan"  << endg;
		gout << setPos(276, -height[1]+279) << setColor(0, 255, 0) << "Feb" << endg;
		gout << setPos(351, -height[2]+279) << setColor(0, 255, 0) << "Mar" << endg;
	}
	if (no_months == 4)
	{
		i = drawRect(201, 279, 50, -height[0]);
		setColor(i, 255, 0, 0);
		j = drawRect(276, 279, 50, -height[1]);
		setColor(j, 0, 255, 0);
		k = drawRect(351, 279, 50, -height[2]);
		setColor(k, 0, 0, 255);
		l = drawRect(426, 279, 50, -height[3]);
		setColor(l, 255, 255, 0);
		gout << setPos(201, -height[0] + 279) << setColor(0, 255, 0) << "Jan" << endg;
		gout << setPos(276, -height[1] + 279) << setColor(0, 255, 0) << "Feb" << endg;
		gout << setPos(351, -height[2] + 279) << setColor(0, 255, 0) << "Mar" << endg;
		gout << setPos(426, -height[3] + 279) << setColor(0, 255, 0) << "Apr" << endg;
	}
	if (no_months == 5)
	{
		i = drawRect(201, 279, 50, -height[0]);
		setColor(i, 255, 0, 0);
		j = drawRect(276, 279, 50, -height[1]);
		setColor(j, 0, 255, 0);
		k = drawRect(351, 279, 50, -height[2]);
		setColor(k, 0, 0, 255);
		l = drawRect(426, 279, 50, -height[3]);
		setColor(l, 255, 255, 0);
		m = drawRect(501, 279, 50, -height[4]);
		setColor(m, 255, 0, 255);
		gout << setPos(201, -height[0] + 279) << setColor(0, 255, 0) << "Jan" << endg;
		gout << setPos(276, -height[1] + 279) << setColor(0, 255, 0) << "Feb" << endg;
		gout << setPos(351, -height[2] + 279) << setColor(0, 255, 0) << "Mar" << endg;
		gout << setPos(426, -height[3] + 279) << setColor(0, 255, 0) << "Apr" << endg;
		gout << setPos(501, -height[4] + 279) << setColor(0, 255, 0) << "May" << endg;
	}
	if (no_months == 6)
	{
		i = drawRect(201, 279, 50, -height[0]);
		setColor(i, 255, 0, 0);
		j = drawRect(276, 279, 50, -height[1]);
		setColor(j, 0, 255, 0);
		k = drawRect(351, 279, 50, -height[2]);
		setColor(k, 0, 0, 255);
		l = drawRect(426, 279, 50, -height[3]);
		setColor(l, 255, 255, 0);
		m = drawRect(501, 279, 50, -height[4]);
		setColor(m, 255, 0, 255);
		n = drawRect(576, 279, 50, -height[5]);
		setColor(n, 0, 255, 255);
		gout << setPos(201, -height[0] + 279) << setColor(0, 255, 0) << "Jan" << endg;
		gout << setPos(276, -height[1] + 279) << setColor(0, 255, 0) << "Feb" << endg;
		gout << setPos(351, -height[2] + 279) << setColor(0, 255, 0) << "Mar" << endg;
		gout << setPos(426, -height[3] + 279) << setColor(0, 255, 0) << "Apr" << endg;
		gout << setPos(501, -height[4] + 279) << setColor(0, 255, 0) << "May" << endg;
		gout << setPos(576, -height[5] + 279) << setColor(0, 255, 0) << "June" << endg;
	}

}

