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
int main() 
{
	int N,sum=0;
	cout << "Enter amount of extensions" << endl;
	N = getNatValue();
	int* arr = new int [N];
	for (int i = 0; i < N; i++) {
		cout << "How many sockets in the extention " << i + 1 << endl;
		arr[i] = getNatValue();
		}
	for (int i = 0; i < N; i++) {
		sum += arr[i];
	}
	cout << "Total amount of sockets: " << sum;
	delete[] arr;
	return 0;
}