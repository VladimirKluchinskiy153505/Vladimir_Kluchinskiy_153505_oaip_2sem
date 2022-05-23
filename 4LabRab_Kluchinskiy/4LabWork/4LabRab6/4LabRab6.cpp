#include <iostream>
#include <cmath>
using namespace std;
int getNatValue()
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
			if (n == 0)
			{
				cout << "Invalid output" << endl;
				continue;
			}
			return n;
		}
	}
}
double getDoubleValue()
{
	while (true)
	{
		double a;
		bool p = true;
		string str;
		cin >> str;
		bool counterpoint = (count(str.begin(), str.end(), '.') > 1);
		bool counterE = (count(str.begin(), str.end(), 'e') > 1);
		bool counterMinus = (count(str.begin(), str.end(), '-') > 2);

		for (int i = 0; i < str.size(); i++)
		{
			if (!(str.at(i) == '0' || str.at(i) == '-' || str.at(i) == '1' || str.at(i) == '2' || str.at(i) == '3' || str.at(i) == '4' ||
				str.at(i) == '5' || str.at(i) == '6' || str.at(i) == '7' || str.at(i) == '8' || str.at(i) == '9' || str.at(i) == '.' || str.at(i) == 'e') || counterpoint || counterE || counterMinus)
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
	int rows, cols;
	double max;
	cout << "Enter amount of rows" << endl;
	rows = getNatValue();
	cout << "Enter amount of colums" << endl;
	cols = getNatValue();
	double** arr = new double* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new double[cols];
	}

	double** newarr = new double* [rows];
	for (int i = 0; i < rows; i++) {
		newarr[i] = new double[cols];
	}

	cout << "Fill array" << endl;//filling
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = getDoubleValue();
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			max = 0;
			for (int ii = 0; ii <= i; ii++) {
				for (int jj = 0; jj <= j; jj++) {
					if (arr[ii][jj] > max)
					{
						max = arr[ii][jj];
					}
				}
			}
			newarr[i][j] = max;
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << newarr[i][j] << "\t";
		}
		cout << endl;
	}



	for (int i = 0; i < rows; i++)
	{
		delete[] newarr[i];
	}
	delete[] newarr;
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}