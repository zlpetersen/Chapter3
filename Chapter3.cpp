// Chapter3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::cin;
using std::string;

void cls();  // clear screen
void pause();  // pauses screen
int intinches();  // inches to feet and inches
int bmi();  // body mass index calculator
int lat_dec();  // latitude in degrees, minutes, seconds to decimal
int sec_time();  // seconds to days, hours, minutes, seconds
int country_world();  // % of world pop lives in country
int mpg();  // calculates MPG from miles and gallons
int lpk_mpg();  // calculates MPG from European liters/100 km

const int ipf = 12;  // inches per foot
const float ftm = 0.0254;  // meters per foot
const float lbk = 2.2;  // lbs per kg
const int hday = 24;  // hours per day
const int mhr = 60;  // mins per hour
const int smin = 60;  // secs per min
const float hundk = 62.14;  // miles per 100 km
const float lpg = 3.875;  // liters per gallon


void cls()
{
	system("CLS");
	cout.flush();
}

void pause()
{
	cout << std::endl;
	system("PAUSE");
}

int intinches()
{
	cls();
	cout << "Enter inches:\n>____\b\b\b\b";
	int inches;
	cin >> inches;
	int feet = inches / ipf;
	int in = inches % ipf;
	cout << "Your height is " << feet << " feet " << in << " inches.";
	pause();
	return 0;
}

int bmi()
{
	cls();
	cout << "Enter your height in feet and inches:\nFeet:___\b\b\b";
	int ft;
	cin >> ft;
	cout << "\nInches:___\b\b\b";
	int in;
	cin >> in;
	int ht = ftm * (ft * ipf + in);  // height in meters
	cout << "\nEnter your weight in pounds:\n>___\b\b\b";
	int wt;
	cin >> wt;
	int wk = wt / lbk;  // weight in kg
	float bmi = wk / ht ^ 2;
	cout << "Your BMI is " << bmi;
	pause();
	return 0;
}

int lat_dec()
{
	cls();
	cout << "Enter a latitude in degrees, minutes, and seconds:";
	cout << "\nDegrees>_____\b\b\b\b\b";
	double deg;
	cin >> deg;
	cout << "\nMinutes>_____\b\b\b\b\b";
	double min;
	cin >> min;
	cout << "\nSeconds>_____\b\b\b\b\b";
	double sec;
	cin >> sec;
	double dec = deg + (min + (sec / 60)) / 60;
	cout << deg << " degrees, " << min << " minutes, " << sec << " seconds = " << dec << " degrees";
	pause();
	return 0;
}

int sec_time()
{
	cls();
	cout << "Enter the number of seconds:\n>________\b\b\b\b\b\b\b\b";
	int sec;
	cin >> sec;
	int mins = sec / smin;
	int hrs = mins / mhr;
	int days = hrs / hday;
	hrs %= mhr;
	mins %= smin;
	int secs = sec % smin;
	cout << sec << " seconds = " << days << " days, " << hrs
		 << " hours, " << mins << " minutes, " << secs << " seconds";
	pause();
	return 0;
}

int country_world()
{
	cls();
	cout << "Enter the worlds's population:\n> ";
	long long pop;
	cin >> pop;
	cout << "Enter the population of your country:\n> ";
	long long cpop;
	cin >> cpop;
	double ppop = (double(cpop) / double(pop)) * 100;
	cout << "The population of your country is " << ppop << "% of the world population";
	pause();
	return 0;
}

int mpg()
{
	cls();
	cout << "Enter number of miles:\n> ";
	float miles;
	cin >> miles;
	cout << "Enter number of gallons:\n> ";
	float gal;
	cin >> gal;
	float mpg = miles / gal;
	cout << "Your car got " << mpg << " miles per gallon";
	pause();
	return 0;
}

int lpk_mpg()
{
	cls();
	cout << "Enter many liters per 100 km:\n> ";
	float liters;
	cin >> liters;
	float gals = liters / lpg;
	float mpg = hundk / gals;
	cout << liters << "/100km is " << mpg << " miles per gallon";
	pause();
	return 0;
}

int main()
{
	while (true)
	{
		system("CLS");
		cout << "Pick an option:\n1. Inches to Feet and Inches\n"
			<< "2. BMI Calculator\n3. Latitude to Decimal Degrees\n4. Seconds to Days, Hours, Minues, Seconds\n5. "
			<< "World Population Percentage\n6. MPG Calculator\n7. Liters/100km to MPG\n8. Quit\n>___\b\b\b";
		int choice = 0;
		cin >> choice;
		string n;
		if (choice == 1) choice = intinches();
		else if (choice == 2) choice = bmi();
		else if (choice == 3) choice = lat_dec();
		else if (choice == 4) choice = sec_time();
		else if (choice == 5) choice = country_world();
		else if (choice == 6) choice = mpg();
		else if (choice == 7) choice = lpk_mpg();
		else if (choice == 8) break;
		else
		{
			cout << "Please enter a valid value\n";
			system("PAUSE");
		}
		cin.clear();
		cin.ignore(100, '\n');
	}
	return 0;
}

