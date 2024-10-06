#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};

vector <string> SplitString(string Text, string Separator)
{	
	int SeparatorPos = 0;
	vector <string> Words;
	string Word="";

	while ((SeparatorPos = Text.find(Separator)) != string::npos)
	{
		Word = Text.substr(0, SeparatorPos);
		if (Word != "")
			Words.push_back(Word);
		Text.erase(0, (SeparatorPos + Separator.length()));
	}
	if (Text != "")
		Words.push_back(Text);
	return Words;
}

stDate ConvertDateTextToStruct(string DateText)
{
	vector <string> SplittedDate = SplitString(DateText, "/");
	stDate Date;
	Date.Day = stoi(SplittedDate[0]);
	Date.Month = stoi(SplittedDate[1]);
	Date.Year = stoi(SplittedDate[2]);
	return Date;
}

string ConvertDateStructToText(stDate Date)
{
	string Text = "";
	Text += to_string(Date.Day) + "/";
	Text += to_string(Date.Month) + "/";
	Text += to_string(Date.Year);
	return Text;
}

int main()
{
	string DateText;
	cout << "Enter Date as dd/mm/yy : ";
	cin >> DateText;

	stDate Date = ConvertDateTextToStruct(DateText);

	cout << "\nDay : " << Date.Day;
	cout << "\nMonth : " << Date.Month;
	cout << "\nYear : " << Date.Year;

	cout << "\n\nYou entered : " << ConvertDateStructToText(Date);



}