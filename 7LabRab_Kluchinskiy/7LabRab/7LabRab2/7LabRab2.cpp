#pragma warning( disable : 4996)
#include <iostream>
#include <string>
#define ll long long int
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
			if (n ==0)
			{
				cout << "Invalid output" << endl;
				continue;
			}
			return n;
		}
	}
}
ll degree(ll x, int n) {
    if (n == 0) { return 1; }
    ll res;
    res = degree(x, n >> 1);
    if (n & 1) { return res * res * x; }
    else { return res * res; }
}
using namespace std;
int main() {
    int n;
    cout << "Enter amount of Numbers\n";
     n=getNatValue();
    for (int i = 0; i < n; i++) {
        ll x, k = 8;
        cin >> x;
        while (abs(x) >= degree(2, k) - 1) {
            k += 4;
        }
        cout << "Additional code is:\n";
        for (int i = k - 1; i >= 0; --i)
        {
            cout << int((x >> i) & 1);
        }
        cout << "\n";
    }
    return 0;
}