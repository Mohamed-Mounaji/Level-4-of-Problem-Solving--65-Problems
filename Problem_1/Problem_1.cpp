#include <iostream>

using namespace std;

unsigned long int ReadLongInt()
{
	unsigned long int Num;
	cout << "Enter Number : ";
	cin >> Num;
	return Num;
}

string NumberToText(unsigned long int Num)
{


	if (Num == 0)
	{
		return "";
	}
	else if(Num>=1 && Num <= 19)
	{
		string Arr[] = { "", "One", "Two", "Three" , "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
			"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
		return Arr[Num] + " ";
	}
	else if (Num >= 20 && Num <= 99)
	{
		string Arr[] = { "", "", "Twenty", "Thirty", "Fourty", "fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
		return Arr[Num/10] + "-"+ NumberToText(Num % 10);
	}
	else if (Num >= 100 && Num <= 999)
	{
		return NumberToText(Num / 100) + (Num / 100 == 1? "Hundred ": "Hundreds ") + NumberToText(Num % 100);
	}
	else if (Num >= 1000 && Num <= 999999)
	{
		 
		return NumberToText(Num / 1000) + (Num / 1000 == 1 ? "Thousand " : "Thousands ") + NumberToText(Num % 1000);
	}
	else if (Num >= 1000000 && Num <= 999999999)
	{
		return NumberToText(Num / 1000000) + ( Num / 1000000 == 1 ?"Million " : "Millions ") + NumberToText(Num % 1000000);
	}
	else if (Num >= 1000000000 && Num <= 999999999999)
	{
		return NumberToText(Num / 1000000000) + (Num / 1000000000 == 1 ? "Billion " : "Billions ") + NumberToText(Num % 1000000000);
	}

}


int main()
{
	unsigned long int Number = ReadLongInt();
	string NumberText = NumberToText(Number);

	cout << "\n" << NumberText;
}