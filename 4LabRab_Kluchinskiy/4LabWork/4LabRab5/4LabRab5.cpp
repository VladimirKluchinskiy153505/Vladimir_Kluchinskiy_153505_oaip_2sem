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
	cout << "Enter amount of rows" << endl;
	rows = getNatValue();
	cout << "Enter amount of colums" << endl;
	cols = getNatValue();

	double** arr = new double* [rows+2];
	for (int i = 0; i < rows+2; i++)
	{
		arr[i] = new double[cols+2];
	}

	for (int i = 0; i < rows + 2; i++) {//filling with 0
		for (int j = 0; j < cols + 2; j++) {
			arr[i][j] = 0;
		}
	}
	cout << "Fill array" << endl;//filling
	for (int i = 1; i < rows + 1; i++) {
		for (int j = 1; j < cols + 1; j++) {
			arr[i][j] = getDoubleValue();
		}
	}
	int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
	int dy[8] = { -1,-1,0,1,1,1,0,-1 };
	double** newarr = new double* [rows];
		for (int i = 0; i < rows; i++) {
			newarr[i] = new double[cols];
		}

	for (int i = 1; i < rows + 1; i++) {
		for (int j = 1; j < cols + 1; j++) {
			double sum = 0;
			if(i==1&&j==1||(i==1&&j==cols)||(i==rows&&j==cols)||(i==rows&&j==1))//up left
			{ 
				for (int k = 0; k < 8; k++)
				{
					sum += arr[i + dy[k]][j + dx[k]];
				}
				newarr[i-1][j-1] = sum / 3;
			}
			else if (i == 1 || i == rows || j == 1 || j == cols) {
				for (int k = 0; k < 8; k++)
				{
					sum += arr[i + dy[k]][j + dx[k]];
				}
				newarr[i-1][j-1] = sum / 5;
			}
			else {
				for (int k = 0; k < 8; k++)
				{
					sum += arr[i + dy[k]][j + dx[k]];
				}
				newarr[i - 1][j - 1] = sum / 8;
			}
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << newarr[i][j] << "\t";
		}
		cout << endl;
	}
    for (int i = 0; i < rows+2; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	for (int i = 0; i < rows; i++)
	{
		delete[] newarr[i];
	}
	delete[] newarr;
	return 0;
}