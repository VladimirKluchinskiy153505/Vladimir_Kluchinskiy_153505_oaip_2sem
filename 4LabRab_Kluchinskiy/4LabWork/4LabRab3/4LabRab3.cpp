#include <iostream>
#include <cmath>
using namespace std;
int getNatValue()
{
	while (true)
	{
		cout<< "Enter matrix order" << endl;
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
int getIntegerValue()
{
	while (true)
	{
		int n;
		bool p = true;
		string str;
		cin >> str;

		for (int i = 0; i < str.size(); i++)
		{
			if (!(str.at(i) == '-' || str.at(i) == '0' || str.at(i) == '1' || str.at(i) == '2' || str.at(i) == '3' || str.at(i) == '4' ||
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
	int N= getNatValue(),sumup=0,sumd=0,sumdown=0;
	int **arr = new int *[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
	}
	cout << "Enter integer value"<< "\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = getIntegerValue();
		}
		cout << endl;
	}
	for (int i = 0; i < N; i++)
	{
		if(arr[i][0]>=0)
		{continue;}
		for (int j = 0; j < N; j++)
		{
			if (j > i)
			{
				sumup += arr[i][j];
			}
			else if (j == i)
			{
				sumd += arr[i][j];
			}
			else { 
				sumdown += arr[i][j]; }

		}
	}
	cout << "Sum up: " << sumup << "\n"
		<< "Sum on digonal: " << sumd << "\n"
		<< "sum down: " << sumdown;
      for (int i=0; i < N; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}