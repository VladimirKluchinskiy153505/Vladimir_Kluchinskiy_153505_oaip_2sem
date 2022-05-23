#include <iostream>
#pragma warning( disable : 4996)
using namespace std;
int getNatValue(const int& l)
{
	while (true)
	{
		int n;
		bool p = true;
		string str;
		cin >> str;

		for (int i = 0; i < str.size(); i++)
		{
			if (!(str.at(i) == '0' || str.at(i) == '1' || str.at(i) == '2' || str.at(i) == '3' || str.at(i) == '4' ||
				str.at(i) == '5' || str.at(i) == '6' || str.at(i) == '7' || str.at(i) == '8' || str.at(i) == '9'))
			{
				p = false;
				cout << "Please try again." << endl;
				cin.ignore(32767, '\n');
				break;
			}
		}
		if (p)
		{
			n = atoi(str.c_str());
			cin.ignore(32767, '\n');
			if (n>=l)
			{
				cout << "Invalid output" << endl;
				continue;
			}
			return n;
		}
	}
}
int main()
{
	int am=1,p;
	char* line = new char[255];
	cout << "Enter line" << endl;

	cin.getline(line, 255, '\n');
	int l = strlen(line);

	char* newline = new char[l+1];
	strcpy(newline, line);
	delete[] line;

	cout << "Enter Posision from (0;size(Line))\n";
	p = getNatValue(l);
	for (int i = 0; i <p; i++) {
		if (newline[i] == char(32)) {
			am++;
		}
	}
	cout <<"Number of the word is:"<<am;
    delete[] newline;
	return 0;
}