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

stDate ReadDate()
{
	stDate Date;
	Date.Year = ReadNum("Enter a year : ");
	Date.Month = ReadNum("Enter a month : ");
	Date.Day = ReadNum("Enter a day : ");
	return Date;
}

bool isDate1EqualDate2(stDate Date1, stDate Date2)
{
	return ((Date1.Year == Date2.Year) ? (Date1.Month == Date2.Month)? (Date1.Day == Date2.Day) : false : false);
}


int main()
{
	stDate Date1 = ReadDate();
	cout << "\n";
	stDate Date2 = ReadDate();

	if (isDate1EqualDate2(Date1, Date2))
		cout << "\nYes, Date One is  Equal to Date two\n";
	else
		cout << "\nNo, Date One is not equal to date two\n";
}