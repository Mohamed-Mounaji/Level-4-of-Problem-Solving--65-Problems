#include <iostream>

using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
};

short ReadNum(string Message)
{
	short Num;
	cout << Message;
	cin >> Num;
	return Num;
}

stDate ReadFullDate()
{
	stDate Date;
	Date.Year = ReadNum("Please, enter a year : ");
	Date.Month = ReadNum("Please, enter a month : ");
	Date.Day = ReadNum("Please, enter a day : ");
	return Date;
}

bool isDate1LessThanDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false : false);
}

int main()
{
	cout << "Date [1]\n";
	stDate Date1 = ReadFullDate();

	cout << "\n\nDate[2]\n";
	stDate Date2 = ReadFullDate();

	if (isDate1LessThanDate2(Date1, Date2))
		cout << "\nYes, Date One is less than date two.\n";
	else
		cout << "\nNo, Date One is NOT less than date two.\n";
}