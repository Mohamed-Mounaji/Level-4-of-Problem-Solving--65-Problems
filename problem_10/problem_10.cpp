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

short NumOfDaysFromBeginningOfAyear(int Year, int Month, int Day)
{
	short NumOfDays = Day;
	for (int i = 1; i < Month; ++i)
	{
		NumOfDays += NumberOfDaysInAMonth(i, Year);
	}
	return NumOfDays;
}

int main()
{
	short Day = ReadNum("Enter a Day : ");
	short Month = ReadNum("Enter a month : ");
	short Year = ReadNum("Enter a year : ");

	printf("\nThe number of the days from the beginning of the year is %d \n", NumOfDaysFromBeginningOfAyear(Year, Month, Day));
}
