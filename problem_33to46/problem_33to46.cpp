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

bool isFirstMonth(stDate Date)
{
	return (Date.Month == 1);
}

bool isFirstDayInMonth(stDate Date)
{
	return Date.Day == 1;
}

stDate DecreaseDateByOneDay(stDate Date)
{
	if (isFirstMonth(Date) && isFirstDayInMonth(Date))
	{
		Date.Year--;
		Date.Month = 12;
		Date.Day = 31;
	}
	else if (isFirstDayInMonth(Date))
	{
		Date.Month--;
		Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
	}
	else
	{
		Date.Day--;
	}
	return Date;
}

stDate DecreaseDateByXDays(stDate Date, int X)
{
	for (int i = 0; i < X; ++i)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
	for (int i = 0; i < 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

stDate DecreaseDateByXWeeks(stDate Date,int X)
{
	for (int i = 0; i < X; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}
	return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
	if (isFirstMonth(Date))
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}
	short MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > MonthDays)
		Date.Day = MonthDays;
	return Date;
}

stDate DecreaseDateByXMonths(stDate Date, int X)
{
	for (int i = 0; i < X; ++i)
	{
		Date = DecreaseDateByOneMonth(Date);
	}
	return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
	Date.Year--;
	return Date;
}

stDate DecreaseDateByXYears(stDate Date, int X)
{
	for (int i = 0; i < X; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}

stDate DecreaseDateByXYearsFaster(stDate Date, int X)
{
	Date.Year -= X;
	return Date;
}

stDate DecreaseDateByOneDecade(stDate Date)
{
	Date.Year -= 10;
	return Date;
}

stDate DecreaseDateByXDecades(stDate Date, int X)
{
	for (int i = 0; i < X; i++)
	{
		Date = DecreaseDateByOneDecade(Date);
	}
	return Date;
}

stDate DecreaseDateByXDecadesFaster(stDate Date, int X)
{
	Date.Year -= X * 10;
	return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{
	Date.Year -= 100;
	return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date)
{
	Date.Year -= 1000;
	return Date;
}

int main()
{
	stDate Date = ReadDate();

	Date = DecreaseDateByOneMillennium(Date);

	cout << "Date After Update : " << Date.Month << "/" << Date.Day << "/" << Date.Year << endl;
}