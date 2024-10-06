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

bool isDateWithinPeriod(stDate Date, stPeriod Period)
{
	return !(CompareDates(Date, Period.StartDate) == enDatesCompared::Before || CompareDates(Date, Period.EndDate) == enDatesCompared::After);
}

int GetDifferanceInDays(stDate Date1, stDate Date2, bool IncludeLastDay = false)
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

int CountOverlappedDays(stPeriod Period1, stPeriod Period2)
{
	if (!isPeriodsOverlap(Period1, Period2))
		return 0;

	int Period1Length = CountPeriodLength(Period1, true);
	int Period2Length = CountPeriodLength(Period2, true);
	int OverlappedDays = 0;

	if (Period1Length < Period2Length)
	{
		while (isDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
		{
			if (isDateWithinPeriod(Period1.StartDate, Period2))
				OverlappedDays++;
			Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
		}
	}
	else
	{
		while (isDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
		{
			if (isDateWithinPeriod(Period2.StartDate, Period1))
				OverlappedDays++;
			Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
		}
	}
	return OverlappedDays;
}

int main()
{
	cout << "Enter Period One\n";
	stPeriod Period1 = ReadPeriodDates();

	cout << "\nEnter Period Two\n";
	stPeriod Period2 = ReadPeriodDates();

	cout << "Overlapped Days Counted are : " << CountOverlappedDays(Period1, Period2);

	system("pause>0");
	return 0;
}