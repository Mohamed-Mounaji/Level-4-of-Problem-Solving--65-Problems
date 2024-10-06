#include <iostream>
#include <string>

using namespace std;

int ReadYear()
{
	int Year;
	cout << "Enter a year: ";
	cin >> Year;
	return Year;
}

bool isLeapYear(int Year)
{
	return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

short NumOfDaysInYear(int Year)
{
	return (isLeapYear(Year) ? 366 : 365);
}

int NumOfHoursInYear(int Year)
{
	return NumOfDaysInYear(Year) * 24;
}

int NumOfMinInYear(int Year)
{
	return NumOfHoursInYear(Year) * 60;
}

int NumOfSecInYear(int Year)
{
	return NumOfMinInYear(Year) * 60;
}

int main()
{
	int Year = ReadYear();

	cout << "\nNumber of Days    In Year [" << Year << "] is : " << NumOfDaysInYear(Year);
	cout << "\nNumber of Hours   In Year [" << Year << "] is : " << NumOfHoursInYear(Year);
	cout << "\nNumber of Minutes In Year [" << Year << "] is : " << NumOfMinInYear(Year);
	cout << "\nNumber of Seconds In Year [" << Year << "] is : " << NumOfSecInYear(Year);
}