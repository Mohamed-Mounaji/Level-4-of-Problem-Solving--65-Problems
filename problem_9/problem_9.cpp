#include <iostream>
#include <iomanip>

using namespace std;

short ReadNum(string Message)
{
	short Num;
	cout << Message;
	cin >> Num;
	return Num;
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

string GetMonthName(short Month)
{
	if (Month < 1 || Month> 12)
		return "?";
	string ArrMonth[] = { "Jan", "Feb","Mar","Apr","May","June","July","Aug","Sep","Oct","Nov","Dec" };
	return ArrMonth[Month - 1];
}

void PrintMonthCalender(short Year, short Month)
{
	printf("\n_______________%s_______________\n\n", GetMonthName(Month).c_str());
	cout << "Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

	int DayOrder = GetDayOrder(Year, Month, 1);

	for (int i = 0; i < DayOrder; i++)
	{
		cout << "     ";
	}

	for (short i = 1; i <= NumberOfDaysInAMonth(Month, Year); ++i)
	{
		DayOrder++;
		cout << setw(3) << i << "  ";
		if (DayOrder == 7)
		{
			DayOrder = 0;
			cout << endl;
		}

	}

	cout << "\n_________________________________\n";
}

void PrintYearCalender(short Year)
{
	cout << "\n_________________________________\n";
	cout << "\n        Calender - " << Year << "\n";
	cout << "_________________________________\n";

	for (int i = 1; i <= 12; ++i)
	{
		PrintMonthCalender(Year, i);
		//cout << "\n";
	}
}

int main()
{
	int Year = ReadNum("Enter a year : ");

	PrintYearCalender(Year);

}