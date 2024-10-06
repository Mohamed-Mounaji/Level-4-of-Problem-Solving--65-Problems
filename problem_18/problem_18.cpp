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

int CountDifferentBetweenTwoDates(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		++Days;
		Date1 = IncreaseDateByOneDay(Date1);
	}
	return IncludeEndDay ? ++Days : Days;
}

stDate GetCurrentDate()
{
	stDate CurrDate;
	time_t timeS = time(0);
	tm* CurrentTime = localtime(&timeS);
	CurrDate.Day = CurrentTime->tm_mday ;
	CurrDate.Month = CurrentTime->tm_mon +1;
	CurrDate.Year = CurrentTime->tm_year + 1900;
	return CurrDate;

}



int main()
{

	cout << "Enter Your BirthDay :\n \n";
	stDate BirthDay = ReadDate();

	stDate TodayDate;
	TodayDate.Day = 11;
	TodayDate.Month = 1;
	TodayDate.Year = 2024;

	cout << "\nYour Age is : " << CountDifferentBetweenTwoDates(BirthDay, TodayDate) << endl;
	cout << "\nYour Age is : " << CountDifferentBetweenTwoDates(BirthDay, GetCurrentDate());

	

	return 0;
}