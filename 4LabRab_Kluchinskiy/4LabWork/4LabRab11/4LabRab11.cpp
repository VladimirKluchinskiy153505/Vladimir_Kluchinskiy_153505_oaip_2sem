#define s1 sum111_nnn
#define s2 sum11n_nn1
#define s3 sum1n1_n1n
#define s4 sumn11_1nn
#include <iostream>
#include <cmath>
using namespace std;
int getIntegerValue()
{
	while (true)
	{
		//cout << "Enter integer value" << endl;
		int n;
		bool p = true;
		string str;
		cin >> str;

		for (int i = 0; i < str.size(); i++)
		{
			if (!(str.at(i) == '-' || str.at(i) == '0' || str.at(i) == '1' || str.at(i) == '2' || str.at(i) == '3' || str.at(i) == '4' ||
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
			return n;
		}
	}
}
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
	int n,sum111_nnn=0,sum11n_nn1=0,sum1n1_n1n=0,sumn11_1nn=0;
	cout << "Enter size of cube" << endl;
	n = getNatValue();
	int*** arr = new int** [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int* [n];
		for (int j = 0; j < n; j++) {
			arr[i][j] = new int[n];
		}
	}
	cout << "Fill the Cube" << endl;
	for (int i = 0; i < n; i++) {
		for(int j=0;j<n;j++){
			for (int k = 0; k < n; k++) {
			arr[i][j][k]=getIntegerValue();
			}
			cout << "\n";
		}
		cout << "\n" << "\n";
	}
	for (int i = 0, j = 0, k = 0; i < n, j < n, k < n; i++, j++, k++)
	{
		sum111_nnn += arr[i][j][k];
	}
	for (int i = 0, j = 0, k = n-1;( i < n, j < n, k >=0); i++, j++, k--)
	{
		sum11n_nn1 += arr[i][j][k];
	}
	for (int i = 0, j = n-1, k = 0; (i < n, j >=0, k <n); i++, j--, k++)
	{
		sum1n1_n1n += arr[i][j][k];
	}
	for (int i = n-1, j = 0, k = 0; (i >=0, j <n, k < n); i--, j++, k++)
	{
		sumn11_1nn += arr[i][j][k];
	}

	cout << sum111_nnn << " " << sum11n_nn1 << " " << sum1n1_n1n << " " << sumn11_1nn << endl;
	if ((s1 >= s2) && (s1 >= s3) && (s1 >= s4))
	{
		cout << "Diagonal with the most sum lies from (0,0,0) to (n-1,n-1,n-1), the sum is: " << s1<<endl;
	}
	if ((s2 >= s1) && (s2 >= s3) && (s2 >= s4))
	{
		cout << "Diagonal with the most sum lies from (0,0,n-1) to (n-1,n-1,0), the sum is: " << s2 << endl;
	}
	if ((s3 >= s1) && (s3 >= s2) && (s3 >= s4))
	{
		cout << "Diagonal with the most sum lies from (n-1,0,n-1) to (0,n-1,0), the sum is: " << s2 << endl;
	}
	if ((s4 >= s1) && (s4 >= s2) && (s4 >= s3))
	{
		cout << "Diagonal with the most sum lies from (n-1,0,0) to (0,n-1,n-1), the sum is: " << s4;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			delete[] arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
			delete[] arr[i];
	}
	delete[] arr;

	return 0;
}