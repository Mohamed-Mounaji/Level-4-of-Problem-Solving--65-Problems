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

short ReadDay()
{
	short Day;
	cout << "Enter a day : ";
	cin >> Day;
	return Day;
}

short GetDayOrder(short Year, short Month, short Day)
{
	int a = (14 - Month) / 12;
	int y = Year-a;
	int m = Month + 12*a - 2;

	short d = (Day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
	return d;
}

string DayNameByIndex(short Index)
{
	string Arr[7] = { "Sun", "Mon", "Tue", "Wed", "Thur", "Fri", "sat" };
	return Arr[Index];
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();

	cout << "\nDate      : " << Month << "/" << Day << "/" << Year; 
	cout << "\nDay Order : " << GetDayOrder(Year, Month, Day);
	cout << "\nDay Name  : " << DayNameByIndex(GetDayOrder(Year, Month, Day));
}