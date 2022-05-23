#include <iostream>
#include <cmath>
using namespace std;
int getIntegerValue()
{
	while (true)
	{
		cout << "Enter integer value" << endl;
		int n;
		bool p = true;
		string str;
		cin >> str;

		for (int i = 0; i < str.size(); i++)
		{
			if (!(str.at(i)=='-'||str.at(i) == '0' || str.at(i) == '1' || str.at(i) == '2' || str.at(i) == '3' || str.at(i) == '4' ||
				str.at(i) == '5' || str.at(i) == '6' || str.at(i) == '7' || str.at(i) == '8' || str.at(i) == '9') || (str.at(i) == '-') && (i > 0))
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
			return n;
		}
	}
}
int main()
{
	const int N=2, M=3;
	int arr[N][M];
	int MAXi;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = getIntegerValue();
		}
	}
	for (int i = 0; i < N; i++)
	{
		MAXi = 0;
		for (int j = 0; j < M; j++)
		{
			if(arr[i][j]>MAXi)
			{
				MAXi = arr[i][j];
			}
		}
		cout << "Max element of string "<<i<<" is: "<<MAXi << endl;
    }
	return 0;
}