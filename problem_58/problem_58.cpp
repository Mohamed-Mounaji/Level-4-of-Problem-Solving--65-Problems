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

bool isPeriodsOverlap(stPeriod Period1, stPeriod Period2)
{
	return !(CompareDates(Period1.StartDate, Period2.EndDate) == enDatesCompared::After 
		     || 
		CompareDates(Period1.EndDate, Period2.StartDate) == enDatesCompared::Before);
}

int main()
{
	cout << "Enter Period 1:";
	stPeriod Period1 = ReadPeriodDates();

	cout << "\nEnter Period 2:";
	stPeriod Period2 = ReadPeriodDates();

	if (isPeriodsOverlap(Period1, Period2))
		cout << "\nYes, Periods Overlap.\n";
	else
		cout << "\nNo, Periods Do Not Overlap.\n";


	return 0;
}
