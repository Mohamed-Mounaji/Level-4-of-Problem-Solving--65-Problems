#include <iostream>
#include <string>

using namespace std;

short ReadYear()
{
	short Year;
	cout << "Enter a year: ";
	cin >> Year;
	return Year;
}

short ReadMonth()
{
	short Month;
	cout << "Enter a Month: ";
	cin >> Month;
	return Month;
}


bool isLeapYear(int Year)
{
	return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

int NumOfDaysInMonth(short Year, short Month)
{
	if (Month > 12 || Month < 1)
		return 0;
	int Arr[] = { 0, 31, 28, 31, 30, 31, 30,31, 31 ,30,31,30,31 };
	return (isLeapYear(Year) && Month == 2 ? 29 : Arr[Month]);
}

int NumOfHoursInMonth(short Year, short Month)
{
	return NumOfDaysInMonth(Year, Month) * 24;
}

int NumOfMinInMonth(short Year, short Month)
{
	return NumOfHoursInMonth(Year, Month) * 60;
}

int NumOfSecInMonth(short Year, short Month)
{
	return NumOfMinInMonth(Year, Month) * 60;
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();
	cout << "\nNumber of Days    In Year [" << Month << "] is : " << NumOfDaysInMonth(Year, Month);
	cout << "\nNumber of Hours   In Year [" << Month << "] is : " << NumOfHoursInMonth(Year, Month);
	cout << "\nNumber of Minutes In Year [" << Month << "] is : " << NumOfMinInMonth(Year, Month);
	cout << "\nNumber of Seconds In Year [" << Month << "] is : " << NumOfSecInMonth(Year, Month);
}