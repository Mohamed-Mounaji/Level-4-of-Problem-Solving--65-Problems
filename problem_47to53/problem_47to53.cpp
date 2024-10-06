#pragma warning (disable : 4996)
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
	int a = (14 - Date.Month) / 12;
	int y = Date.Year - a;
	int m = Date.Month + 12 * a - 2;

	short d = (Date.Day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
	return d;
}

stDate GetSystemDate()
{
	stDate Date;
	time_t timeS = time(0);
	tm* Time = localtime(&timeS);
	Date.Day = Time->tm_mday;
	Date.Month = Time->tm_mon +1;
	Date.Year = Time->tm_year + 1900;
	return Date;
}

string DayNameByIndex(short Index)
{
	string Arr[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	return Arr[Index];
}

bool isEndOfWeek(stDate Date)
{
	short DayOrder = GetDayOrder(Date);
	return (DayOrder == 6);
}

bool isWeekEnd(stDate Date)
{
	short DayOrder = GetDayOrder(Date);
	return (DayOrder == 5 || DayOrder == 6);
}

bool isBusinessDay(stDate Date)
{
	short DayOrder = GetDayOrder(Date);
	return (DayOrder != 6 && DayOrder != 5);
}

short DaysUntilTheEndOfWeek(stDate Date)
{
	short DayOrder = GetDayOrder(Date);
	return 6 - DayOrder;
}

short DaysUntilTheEndOfMonth(stDate Date)
{
	short MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
	return MonthDays - Date.Day;
}

short DaysUntilTheEndOfYear(stDate Date)
{
	short Days = DaysUntilTheEndOfMonth(Date);
	Date.Month++;
	for (Date.Month; Date.Month <= 12; Date.Month++)
	{
		Days += NumberOfDaysInAMonth(Date.Month, Date.Year);
	}
	return Days;
}

int main()
{
	stDate CurrDate = GetSystemDate();
	
	cout << "Today is " << DayNameByIndex(GetDayOrder(CurrDate)) << ", " << CurrDate.Month << "/" <<
						CurrDate.Day << "/" << CurrDate.Year << endl;

	cout << "\nIs it end of week?";
	if (isEndOfWeek(CurrDate))
		cout << "\nYes, End of week.\n";
	else
		cout << "\nNo, not end of week.\n";

	cout << "\nIs it weekend ?";
	if (isWeekEnd(CurrDate))
		cout << "\nYes, it is weekend.\n";
	else
		cout << "\nNo, it is not weekend.\n";

	cout << "\nIs business day?";
	if (isBusinessDay(CurrDate))
		cout << "\nYes, Today is a business day\n";
	else
		cout << "\nNo, Today is not a business day\n";

	cout << "\nDays until the end of week : " << DaysUntilTheEndOfWeek(CurrDate) << " Day(s)\n";

	cout << "Days until the end of the month : " << DaysUntilTheEndOfMonth(CurrDate) << " Day(s)\n";

	cout << "Days until the end of the year : " << DaysUntilTheEndOfYear(CurrDate) << " Day (s)\n";


}
