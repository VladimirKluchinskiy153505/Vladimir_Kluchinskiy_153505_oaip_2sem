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
double getDoubleValue()
{
	while (true)
	{
		//cout << "Enter a double value" << endl;

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
void sortArr(double*& arr, int& size)
{
	int zeropoz=-1, am0 = 0 , rep=0, newsize;
	for (int i = 0; i < size; i++) {//finding first 0
		if (arr[i] == 0) {
			zeropoz = i;
			am0++;
			break;
		}
	}
	for (int i = zeropoz+1; i < size; i++) {//finding amount of 0
		if (arr[i] == 0) {
			am0++;
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if ((arr[i] == arr[j]) && (arr[i] != 0)) {// finding amount of repetings
				rep++;
				arr[j] = 0;
			}
		}
	}
	if (am0 == 0) { am0 = 1; }
	newsize = size - rep-am0+1;
	double* newarr = new double[newsize];
	int j = 0;
	for (int i = 0; i < size; i++) {
		if ((arr[i] != 0) || (i == zeropoz))
		{
			newarr[j] = arr[i];
			j++;
		}
	}
	size = newsize;
	delete[] arr;
	arr = newarr;
}
int main()
{
	double a;
	int n;
	cout << "Enter size of array" << endl;
	n = getNatValue();
	double* arr = new double[n];
	cout << "Fill array" << endl;
	for (int i = 0; i < n; i++) {
		arr[i] = getDoubleValue();
	}
	sortArr(arr, n);
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout<<arr[i]<<" ";
	}
	delete[] arr;
	return 0;
}