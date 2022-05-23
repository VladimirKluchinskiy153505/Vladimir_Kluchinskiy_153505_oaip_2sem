#include <iostream>
#include <cmath>
using namespace std;
double getDoubleValue()
{
	while (true)
	{
		cout << "Enter a double value"<<endl;

		double a;
		bool p = true;
		string str;
		cin >> str;
		bool counterpoint = (count(str.begin(), str.end(), '.') > 1);
		bool counterE= (count(str.begin(), str.end(), 'e') > 1);
		bool counterMinus= (count(str.begin(), str.end(), '-') > 2);

		for (int i = 0; i < str.size(); i++)
		{
			if (!(str.at(i) == '0' || str.at(i) == '-' || str.at(i) == '1' || str.at(i) == '2' || str.at(i) == '3' || str.at(i) == '4' ||
				str.at(i) == '5' || str.at(i) == '6' || str.at(i) == '7' || str.at(i) == '8' || str.at(i) == '9' || str.at(i) == '.'||str.at(i)=='e') || counterpoint|| counterE||counterMinus)
			{
				p = false;
				cout << "Please try again.\n";
				cin.ignore(32767, '\n');
				break;
			}
		}
		if (p)
		{
			a = atof(str.c_str());
			cin.ignore(32767, '\n');
			return a;
		}
	}
}
int main()
{
	const int k=3;
	int j=0;
	double midl,sum=0;
	double arr[k];
	for (int i = 0; i < k; i++)
	{
		arr[i] = getDoubleValue();
	}
	for (int i = 0; i < k; i++)
	{
		sum += arr[i];
	}
	midl = sum / k;
	for (int i = 0; i < k; i++)
	{
		if(abs(midl-arr[i])<=3)
		{
			j++;
		}
	}
	cout << j;
    return 0;
}