#include <iostream>
#include <cmath>
using namespace std;
int getNatValue()
{
	while (true)
	{
		//cout << "Enter matrix order" << endl;
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
			if (n == 0)
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
	int n, k,i,j;
	cout << "Enter your number" << endl;
	n = getNatValue();
	k = sqrt(n-1);
	if ((n - k * k) <= (k + 1))
	{
		i = n - k * k;
		j = k + 1;
	}
	else {
		i = k + 1;
		j = (k + 1) * (k + 1) - n + 1;
	}
	cout << "Your number is situated in row " << i << " and colum " << j;
	return 0;
}