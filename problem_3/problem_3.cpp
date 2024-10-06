#include <iostream>

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

int main()
{
	int Year = ReadYear();
	
	if (isLeapYear(Year))
		cout << "This year is leap";
	else
		cout << "This year is not leap";
}