#include <iostream>
#include <iomanip>

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

stDate DateOfDayByNumberOrderOfTheDay(short DayOrder,short Year)
{
	stDate Date;
	Date.Year = Year;
	Date.Month = 1;

	short RemainingDays = DayOrder;
	short MonthDays;
	
	while (true)
	{
		MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
		if (MonthDays <= RemainingDays)
		{
			Date.Month++;
			RemainingDays -= MonthDays;
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}
	return Date;
}

int main()
{
	short Year = ReadNum("Enter a year : ");
	short Month = ReadNum("Enter a month : ");
	short Day = ReadNum("Enter a day : ");

	short DayOrder = NumberOfDaysFromTheBeginningOfTheYear(Year, Month, Day);
	cout << "\nThe number of the days from the beginning of the year is " << DayOrder;

	stDate Date = DateOfDayByNumberOrderOfTheDay(DayOrder, Year);
	printf("\nDate : %d/%d/%d", Date.Month, Date.Day, Date.Year);


}
