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

stDate IncreaseDateByXDays(stDate Date, int NumOfDays)
{
	for (int i = 0; i < NumOfDays; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

stDate IncreaseDateBy1Week(stDate Date)
{
	return IncreaseDateByXDays(Date, 7);
}

stDate IncreaseDateByXWeeks(stDate Date, int NumOfWeeks)
{
	for (int i = 0; i < NumOfWeeks; i++)
	{
		Date = IncreaseDateBy1Week(Date);
	}
	return Date;
}

stDate IncreaseDateBy1Month(stDate Date)
{
	if (isLastMonth(Date))
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
	}
	
	if (Date.Day > NumberOfDaysInAMonth(Date.Month, Date.Year))
	{
		Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
	}

	return Date;
}

stDate IncreaseDateByXMonths(stDate Date, int NumOfMonths)
{
	for (int i = 0; i < NumOfMonths; i++)
	{
		Date = IncreaseDateBy1Month(Date);
	}
	return Date;
}

stDate IncreaseDateBy1Year(stDate Date)
{
	Date.Year++;
	return Date;
}

stDate IncreaseDateByXYears(stDate Date, int NumOfYears)
{
	for (int i = 0; i < NumOfYears; ++i)
	{
		Date = IncreaseDateBy1Year(Date);
	}
	return Date;
}

stDate IncreaseDateByXYearsFaster(stDate Date, int NumOfYears)
{
	Date.Year += NumOfYears;
	return Date;
}

stDate IncreaseDateBy1Decade(stDate Date)
{
	Date.Year += 10;
	return Date;
}

stDate IncreaseDateByXDecades(stDate Date, int NumOfDecades)
{
	for (int i = 0; i < NumOfDecades; i++)
	{
		Date = IncreaseDateBy1Decade(Date);
	}
	return Date;
}

stDate IncreaseDateByXDecadesFaster(stDate Date, int NumOfDecades)
{
	Date.Year += NumOfDecades * 10;
	return Date;
}

stDate IncreaseDateBy1Century(stDate Date)
{
	Date.Year += 100;
	return Date;
}

stDate IncreaseDateBy1Millenium(stDate Date)
{
	Date.Year += 1000;
	return Date;
}

int main()
{
	stDate Date = ReadDate();

	Date = IncreaseDateBy1Month(Date);

	cout << "New Date : " << Date.Month << "/" << Date.Day << "/" << Date.Year << endl;


	return 0;
}