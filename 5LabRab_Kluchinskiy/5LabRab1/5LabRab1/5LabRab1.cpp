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
void fillArray(double *Arr,int size){
	for (int i = 0; i < size; i++) {
		Arr[i] = getDoubleValue();
	}
}
void showArray(double* Arr, int size) {
	for (int i = 0; i < size; i++) {
			cout << Arr[i] << "\n";
	}
}
void countArrayZ(double* ArrZ, int size,double*ArrX,double*ArrY) {
	double m;
	for (int k = 0; k < size; k++) {
		if (abs(sin(k + 1)) <= 0.2) {
			m = k+1;
		}
		else if ((0.2 <= abs(sin(k + 1))) && (abs(sin(k + 1)) < 0.9))
		{
			m = sqrt(k+1);
		}
		else {
			m = sqrt(sqrt(k+1));
		}
		ArrZ[k] = ArrX[k] + m * ArrY[k];
	}
}
int main()
{
	int n, k, m;
	cout << "Enter size of array" << "\n";
	n = getDoubleValue();
	double* z = new double[n];
	double* x = new double[n];
	double* y = new double[n];
	cout << "Fill array X" << "\n";
	fillArray(x,n);

	cout << "\n";
	cout << "Fill array Y" << "\n";

	fillArray(y, n);
	cout << "\n";

	countArrayZ(z,n,x,y);

	cout << "array Z:" << "\n";
	showArray(z, n);
	delete[] z;
	delete[] x;
	delete[] y;
	return 0;
}