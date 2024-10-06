#pragma warning (disable: 4996)

#include <iostream>
#include <ctime>
#include <vector>
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

void SwapDates(stDate &Date1, stDate &Date2)
{
	stDate TempDate = Date1;
	Date1 = Date2;
	Date2 = TempDate;
}

int CountDifferentBetweenTwoDates(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;
	short ResultSign = 1;

	if (!IsDate1BeforeDate2(Date1, Date2))
	{
		SwapDates(Date1, Date2);
		ResultSign = -1;
	}
	
	
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		++Days;
		Date1 = IncreaseDateByOneDay(Date1);
	}
	
	return IncludeEndDay ? ++Days*ResultSign : Days*ResultSign;
}

int main()
{
	stDate Date1 = ReadDate();
	stDate Date2 = ReadDate();

	cout << "Difference between two dates : " << CountDifferentBetweenTwoDates(Date1, Date2);
}