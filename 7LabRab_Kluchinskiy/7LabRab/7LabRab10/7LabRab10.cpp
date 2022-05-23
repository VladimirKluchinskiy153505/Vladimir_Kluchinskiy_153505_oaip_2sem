#include <iostream>
#include <cmath>
#include<string>
#include<iomanip>
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
			if ((n > 240) || (n < 1))
			{
				cout << "Invalid output" << endl;
				continue;
			}
			return n;
		}
	}
}
int degree(int x, int n) {
	if (n == 0) { return 1; }
	int res;
	res = degree(x, n >> 1);
	if (n & 1) { return res * res * x; }
	else { return res * res; }
}
int from2to10(int x) {
	int sum = 0, dev = 1, k = 0;
	while (x) {
		sum += (x % 10) * degree(2, k);
		x = x / 10;
		k++;
	}
	return sum;
}
int dif(int b, int a) {
	string str1 = to_string(b);
	while (str1.find('0') != string::npos) {
		str1.erase(str1.find('0'), 1);
	}
	int c = stoi(str1) - a;
	return from2to10(c);
}
void PushBackTo111(int x, int*& ARR, int& SIZE) {
	ARR[SIZE] = x;
	SIZE++;
}
int from10to3(int x, int n = 3) {
	if (x < n) { return x; }
	return from10to3(x / n, n) * 10 + x % n;
}
int from10to2(int x, int n = 2) {
	if (x < n) { return x; }
	return from10to3(x / n, n) * 10 + x % n;
}
int countZeroz(int x, int s) {
	int count = 0;
	string str = to_string(x);
	int size = str.size();
	for (int i = 0; i < size; i++) {
		if (str[i] == '0') { count++; }
	}
	count += s - size;
	return count;
}
int main()
{
	int n, num, r, deadnum = 0, deadnum2 = 0;
	bool slave1, slave2, slave3, slave4, slave5 = false;
	int size1 = 0, size2 = 0, size3 = 0, size4 = 0, size5 = 0;
	int death[5] = { 0,0,0,0,0 };
	int* val1 = new int[80];
	int* val2 = new int[80];
	int* val3 = new int[80];
	int* val4 = new int[80];
	int* val5 = new int[80];
	cout << "Enter a number of a poisoned barrel\n";
	n = getNatValue();
	num = from10to3(n);
	cout << "Divide barrels into 5 groups:\n";
	for (int i = 1; i <= 240; i++) {
		r = from10to3(i);
		if (r < 10000) {
			PushBackTo111(r, val1, size1);
			if (num == r) { death[0] = 1; deadnum++; }
		}
		if ((r / 1000) % 10 == 0) {
			PushBackTo111(r, val2, size2);
			if (num == r) {
				death[1] = 1; deadnum++;
			}
		}
		if ((r / 100) % 10 == 0) {
			PushBackTo111(r, val3, size3);
			if (num == r) {
				death[2] = 1; deadnum++;
			}
		}
		if ((r / 10) % 10 == 0) {
			PushBackTo111(r, val4, size4);
			if (num == r) {
				death[3] = 1; deadnum++;
			}
		}
		if (r % 10 == 0) {
			PushBackTo111(r, val5, size5);
			if (num == r) {
				death[4] = 1; deadnum++;
			}
		}
	}
	for (int i = 0; i < 80; i++) {
		cout << val1[i] << setw(15) << val2[i] << setw(15) << val3[i] << setw(15) << val4[i] << setw(15) << val5[i] << "\n";
	}
	cout << "\n\n";
	cout <<"Number of the barrel\n"<< num << "\n";
	cout << "At first day died: " << deadnum << "\n";
	cout << "DeathArr is\n";
	for (int i = 0; i < 5; i++) {
		cout << death[i] << setw(3);
	}
	cout << "\n";
	if (death[0]) { cout << "First Slave died\n"; }
	if (death[1]) { cout << "Second Slave died\n"; }
	if (death[2]) { cout << "Third Slave died\n"; }
	if (death[3]) { cout << "Fouth Slave died\n"; }
	if (death[4]) { cout << "Fifth Slave died\n"; }
	if (deadnum == 0) {
		cout << "We have to check 32 barrels\n";
		int binorder = dif(num, 11111)+1;
		int binrepr = from10to2(binorder);
		cout << "The spoiled barrel has number " << binorder << "   " << binrepr << "(in binary)" << "\n";
		cout << countZeroz(binrepr, 5) << " extra slaves will dye\n";
	}
	else if (deadnum == 1) {
		cout << "We have to check 16 barrels:\n";
		int binorder = dif(num, 1111)+1;//number of barrel
		int binrepr = from10to2(binorder);
		cout << "The spoiled barrel has number " << binorder << "   " << binrepr << "(in binary)" << "\n";
		cout << countZeroz(binrepr, 4) << " extra slaves will dye\n";
	}
	else if (deadnum == 2) {
		cout << "We have to check 8 barrels:\n";
		int binorder = dif(num, 111)+1;
		int binrepr = from10to2(binorder);
		cout << "The spoiled barrel has number " << binorder << "   " << binrepr << "(in binary)" << "\n";
		cout << countZeroz(binrepr, 3) << " extra slaves will dye\n";
	}
	else if (deadnum == 3) {
		cout << "We have to check 4 barrels:\n";
		int binorder = dif(num, 11)+1;
		int binrepr = from10to2(binorder);
		cout << "The spoiled barrel has number " << binorder << "   " << binrepr << "(in binary)" << "\n";
		cout << countZeroz(binrepr, 2) << " extra slaves will dye\n";
	}
	else if (deadnum == 4) {
		cout << "We have to check 4 barrels:\n";
		int binorder = dif(num, 1)+1;
		int binrepr = from10to2(binorder);
		cout << "The spoiled barrel has number " << binorder << "   " << binrepr << "(in binary)" << "\n";
		cout << countZeroz(binrepr, 1) << " extra slaves will dye\n";
	}
	delete[] val1;
	delete[] val2;
	delete[] val3;
	delete[] val4;
	delete[] val5;
	return 0;
}