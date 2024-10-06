#pragma warning (disable : 4996)
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
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

short GetDayOrder(short Year, short Month, short Day)
{
	int a = (14 - Month) / 12;
	int y = Year - a;
	int m = Month + 12 * a - 2;

	short d = (Day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
	return d;
}

short GetDayOrder(stDate Date)
{
	return GetDayOrder(Date.Year, Date.Month, Date.Day);
}

string DayNameByIndex(short Index)
{
	string Arr[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	return Arr[Index];
}

string ConvertDateToText(stDate Date)
{
	string sDate = "";
	sDate += DayNameByIndex(GetDayOrder(Date)) + ", ";
	sDate += to_string(Date.Month) + "/";
	sDate += to_string(Date.Day) + "/";
	sDate += to_string(Date.Year);
	return sDate;
}

bool isLastDayInMonth(stDate Date)
{
	return NumberOfDaysInAMonth(Date.Month, Date.Year) == Date.Day;
}

stDate IncreaseDayByOneDay(stDate Date)
{
	if (isLastDayInMonth(Date))
	{
		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
			Date.Day = 1;
		}
	}
	else
	{
		Date.Day++;
	}
	return Date;
}

bool isDate1BeforeDate2(stDate Date1, stDate Date2)
{
	if (Date1.Year < Date2.Year)
	{
		return true;
	}
	else if (Date1.Year == Date2.Year)
	{
		if (Date1.Month < Date2.Month)
			return true;
		else if (Date1.Month == Date2.Month)
		{
			if (Date1.Day < Date2.Day)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
	{
		return false;
	}
}

bool isWeekEnd(stDate Date)
{
	short DayOrder = GetDayOrder(Date);
	return DayOrder == 5 || DayOrder == 6;
}

int CountVecationDays(stDate StartDay, stDate EndDay)
{
	int Days = 0;
	while (isDate1BeforeDate2(StartDay, EndDay))
	{
		if(!isWeekEnd(StartDay))
			Days++;
		StartDay = IncreaseDayByOneDay(StartDay);
	}
	return Days;
}

int main()
{
	cout << "Vecation Start :\n";
	stDate VecationStart = ReadDate();

	cout << "\nDecation end :\n";
	stDate VecationEnd = ReadDate();

	cout << "\nVecation From : " << ConvertDateToText(VecationStart);
	cout << "\nVecation End : " << ConvertDateToText(VecationEnd) << endl;

	cout << "\n\nActucal vecation days : " << CountVecationDays(VecationStart, VecationEnd);


	return 0;
}