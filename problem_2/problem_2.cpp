#include <iostream>

using namespace std;

int ReadYear()
{
	int Year;
	cout << "Enter a year : ";
	cin >> Year;
	return Year;
}

bool isLeapYear(int Year)
{
	if (Year % 400 == 0)
	 return true;
	
	else if (Year % 4 == 0 && Year % 100 != 0)
		return true;
	
	else
		return false;
}

int main()
{
	int Year = ReadYear();

	if (isLeapYear(Year))
		cout << "\nThis year is a leap year.\n";
	else
		cout << "\nThis year is not a leap year.\n";
}