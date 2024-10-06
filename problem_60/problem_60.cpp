#include <iostream>
#include <string>

using namespace std;

enum enDatesCompared { Before = -1, Equal = 0, After = 1 };

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

stPeriod ReadPeriodDates()
{
	stPeriod Period;
	cout << "\nEnter Start Date:\n";
	Period.StartDate = ReadDate();

	cout << "\nEnter End Date:\n";
	Period.EndDate = ReadDate();
	return Period;
}

bool isDate1EqualToDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
}

bool isDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool isDate1AfterDate2(stDate Date1, stDate Date2)
{
	return !isDate1BeforeDate2(Date1, Date2) && !isDate1EqualToDate2(Date1, Date2);
}

enDatesCompared CompareDates(stDate Date1, stDate Date2)
{
	if (isDate1BeforeDate2(Date1, Date2))
		return enDatesCompared::Before;
	else if (isDate1AfterDate2(Date1, Date2))
		return enDatesCompared::After;
	else
		return enDatesCompared::Equal;
}

bool isDateWithinPeriod(stDate Date, stPeriod Period)
{
	return !(CompareDates(Date, Period.StartDate) == enDatesCompared::Before || CompareDates(Date, Period.EndDate) == enDatesCompared::After);
}

int main()
{
	cout << "Enter period :\n";
	stPeriod Period = ReadPeriodDates();

	cout << "\n\nEnter Date To Check:\n";
	stDate Date = ReadDate();

	if (isDateWithinPeriod(Date, Period))
		cout << "\nYes, the Date is within the Period.";
	else
		cout << "\nNo, the Date is NOT within the Period.";

	system("pause>0");
	return 0;
}