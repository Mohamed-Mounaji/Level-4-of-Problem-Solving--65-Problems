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

bool isLastMonth(stDate Date)
{
	return (Date.Month == 12);
}

bool isLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

stDate IncreaseDateByOneDay(stDate Date)
{
	if (isLastDayInMonth(Date))
	{
		if (isLastMonth(Date))
		{
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}
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

int GetDifferanceInDays(stDate Date1, stDate Date2, bool IncludeLastDay =false)
{
	int Days = 0;
	while (isDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}
	return IncludeLastDay ? ++Days : Days;
}

int CountPeriodLength(stPeriod Period, bool IncludeLastDay = false)
{
	return GetDifferanceInDays(Period.StartDate, Period.EndDate, IncludeLastDay);
}

int main()
{
	cout << "Enter period :\n";
	stPeriod Period = ReadPeriodDates();

	cout << "Period Length is : " << CountPeriodLength(Period) << endl;
	cout << "Period Length (including last day) is : " << CountPeriodLength(Period, true);
	return 0;
}