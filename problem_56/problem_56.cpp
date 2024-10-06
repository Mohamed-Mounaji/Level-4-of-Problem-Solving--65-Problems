#include <iostream>

using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
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
	Date.Day = ReadNum("Enter a day : ");
	Date.Month = ReadNum("Enter a month : ");
	Date.Year = ReadNum("Enter a year : ");

	return Date;
}

bool isDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool isDate1EqualToDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
}

bool isDate1AfterDate2(stDate Date1, stDate Date2)
{
	return !isDate1BeforeDate2(Date1, Date2) && !isDate1EqualToDate2(Date1,Date2);
}

int main()
{
	cout << "Enter Date 1\n";
	stDate Date1 = ReadDate();

	cout << "\nEnter Date 2\n";
	stDate Date2 = ReadDate();

	if (isDate1AfterDate2(Date1, Date2))
		cout << "\nYes, Date one is after date two.\n";
	else
		cout << "\nNo, Date one is not after date two.\n";

	return 0;
}