#include <iostream>
#include <string>

using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};

struct stPeriod {
	stDate StartDate;
	stDate EndDate;
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

bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return  0;
	int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

}

bool isValidDate(stDate Date)
{
	short MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);

	return Date.Month <= 12 && Date.Month >= 1 ? (Date.Day >= 1 && Date.Day <= MonthDays) : false;
}

int main()
{
	stDate Date = ReadDate();
	
	if (isValidDate(Date))
		cout << "\nYes, this a valid date.\n";
	else
		cout << "\nNo, this is not a valid date.\n";

	system("pause>0");
	return 0;
}