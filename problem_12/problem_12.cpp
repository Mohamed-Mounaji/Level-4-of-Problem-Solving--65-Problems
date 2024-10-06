#include <iostream>

using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
};

short ReadNum(string Message)
{
	short Num;
	cout << Message;
	cin >> Num;
	return Num;
}

stDate ReadFullDate()
{
	stDate Date;
	Date.Year = ReadNum("Please, enter a year : ");
	Date.Month = ReadNum("Please, enter a month : ");
	Date.Day = ReadNum("Please, enter a day : ");
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

short NumberOfDaysFromTheBeginningOfTheYear(short Year, short Month, short Day)
{
	short TotalDays = Day;
	for (int i = 1; i < Month; i++)
	{
		TotalDays += NumberOfDaysInAMonth(i, Year);
	}
	return TotalDays;
}

stDate AddDaysToDate(stDate Date, int Days)
{
	int Remainder = Days + NumberOfDaysFromTheBeginningOfTheYear(Date.Year, Date.Month, Date.Day);
	Date.Month = 1;
	short MonthDays = 0;

	while (true)
	{
		MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
		if (Remainder >= MonthDays)
		{
			Remainder -= MonthDays;
			Date.Month++;
			if (Date.Month > 12)
			{
				Date.Month = 1;
				Date.Year++;
			}
		}
		else
		{
			Date.Day = Remainder;
			break;
		}
	}

	return Date;
}

int main()
{
	stDate Date = ReadFullDate();
	short Days = ReadNum("Enter number of days to add : ");

	Date = AddDaysToDate(Date, Days);
	cout << "\nThe Date after adding [" << Days << "] is : ";
	printf("%d/%d/%d", Date.Day, Date.Month, Date.Year);
	

}

