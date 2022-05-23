#include <iostream>
#include <cmath>
using namespace std;
double getDoubleValue()
{
	while (true)
	{
		cout << "Enter a double value" << endl;

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
	int n,pMax,pMin,counter0=0;
	double minV, maxV;
	cout << "Enter size of array" << endl;
	cin >> n;
	double* arr = new double[n];
	cout << "Fill array" << endl;
	for (int i = 0; i < n; i++)//filling
	{
		cin >> arr[i];
	}
	cout << endl;
	minV = arr[0]; pMin = 0;
	maxV = arr[0]; pMax = 0;
	for(int i=1;i<n;i++)//find max and min
	{
		if (arr[i] > maxV)
		{
			maxV = arr[i];
			pMax = i;
		}
		if (arr[i] < minV)
		{
			minV = arr[i];
			pMin = i;
		}
    }
	if (pMax >= pMin)//filling 0 between max and min and finding zeros before and after
	{
		for (int i = pMin+1; i < pMax ; i++)
		{
			arr[i] = 0;
		}
		for (int i = 0; i < pMin; i++)
		{
			if(arr[i]==0)
			{
				counter0++;
			}
		}
		for (int i = pMax+1; i < n; i++)
		{
			if (arr[i] == 0)
			{
				counter0++;
			}
		}
	}
	else {
		for (int i = pMax + 1; i < pMin; i++)
		{
			arr[i] = 0;
		}
		for (int i = 0; i < pMax; i++)
		{
			if (arr[i] == 0)
			{
				counter0++;
			}
		}
		for (int i = pMin + 1; i < n; i++)
		{
			if (arr[i] == 0)
			{
				counter0++;
			}
		}
	}
	if (abs(pMax - pMin - 1+counter0) > (n / 2))//output
	{
		int minimal = min(pMin, pMax);
		for (int i = 0; i < minimal; i++)
		{
			if (arr[i] == 0) { continue; }
			cout << arr[i] << " ";
		}
		cout << arr[pMin]<<" ";
		int maximal = max(pMin, pMax);
		cout << arr[pMax]<<" ";
		for (int i = maximal + 1; i < n; i++)
		{
			if (arr[i] == 0) { continue; }
			cout << arr[i] << " ";
		}
	}
	else {
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
	}
	
	delete[] arr;
	return 0;
}