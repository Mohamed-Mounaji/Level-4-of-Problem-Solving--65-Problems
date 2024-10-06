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
	string Word = "";

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

stDate TextToDateStruct(string DateText)
{
	vector <string> SplittedDate = SplitString(DateText, "/");
	stDate Date;
	Date.Day = stoi(SplittedDate[0]);
	Date.Month = stoi(SplittedDate[1]);
	Date.Year = stoi(SplittedDate[2]);
	return Date;
}

string DateStructToText(stDate Date)
{
	string Text = "";
	Text += to_string(Date.Day) + "/";
	Text += to_string(Date.Month) + "/";
	Text += to_string(Date.Year);
	return Text;
}

string ReplaceWordInString(string Text, string OrigWord, string NewWord)
{
	int WordPos = Text.find(OrigWord);
	Text.erase(WordPos, OrigWord.length());
	Text.insert(WordPos, NewWord);
	return Text;
}

string FormatDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{
	string FormattedDate = "";
	FormattedDate = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
	FormattedDate = ReplaceWordInString(FormattedDate, "mm", to_string(Date.Month));
	FormattedDate = ReplaceWordInString(FormattedDate, "yyyy", to_string(Date.Year));
	return FormattedDate;
}

int main()
{
	string DateString;
	cout << "Please Enter Date dd/mm/yyyy : ";
	getline(cin >> ws, DateString);

	stDate Date = TextToDateStruct(DateString);

	cout << "\n" << FormatDate(Date) << endl;
	cout << "\n" << FormatDate(Date, "yyyy/dd/mm") << "\n";
	cout << "\n" << FormatDate(Date, "mm/dd/yyyy") << "\n";
	cout << "\n" << FormatDate(Date, "mm-dd-yyyy") << "\n";
	cout << "\n" << FormatDate(Date, "dd-mm-yyyy") << "\n";
	cout << "\n" << FormatDate(Date, "Day:dd, month:mm, year:yyyy");
	system("pause>0");

	
	return 0;
}