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
int degree(int a, int b) {
	if (b == 0)
	{
		return 1;
	}
	return a * degree(a, b - 1);
}

int main()
{
	int n, k = 1, m;
	cout << "Enter a natural number" << endl;
	n = getNatValue();
	m = n;
	while ((m / 10))
	{
		k++;
		m = m / 10;
	}
	int* arr = new int[k];
	for (int i = 0; i < k; i++)
	{
		arr[i] = (n / degree(10, i)) % 10;
	}
	cout << "What number rank do you want to see" << endl;
	cin >> m;
	cout << "Your number has " << k << " signs" << endl;
	cout << "The i sign is: "<<arr[m];
	delete[] arr;
	return 0;
}
