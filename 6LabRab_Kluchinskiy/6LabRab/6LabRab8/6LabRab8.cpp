#pragma warning( disable : 4996)
#include <iostream>
#include <string>
using namespace std;
int search(string &orig, string &str1) {
	int l1 = str1.length(), l0 = orig.length();
	int n0 = orig.find(str1[0]);
	int i, j, cov, b1, b2;
	while (n0 != string::npos) {
		for (int y = 0; y < l1; y++) {//все возможные смещения вправо
			i = 1; cov = 1;//одно покрытие есть т.к. мы нашли n0
			while (i <= y) {//идём вправо на i символов, начиная с n0 и попадаем в n0+i
				if (orig[n0 + i] == str1[i]) {
					cov++;

				}
				else { break; }
				i++;
			}
			i--;
			if (cov < (y + 1)) { continue; }
			j = 1;
			while (j <= l1 - y - 1) {//идём влево на l1-i-1 символов начиная с n0+i
				b1 = n0 + i - j; b2 = i + j;
				if ((0 <= b1) && (b1 < l0) && (b2 <= l1)) {
					if ((orig[b1] == str1[b2])) {
						cov++;
					}
					else { break; }
				}
				else { break; }
				j++;
			}
			if (cov == l1) {
				return 1;
			}
		}
		n0 = orig.find(str1[0], n0 + 1);
	}
	return 0;
}
void PushBackTo(int x, int*& ARR, int& SIZE) {
	SIZE++;
	ARR[SIZE - 1] = x;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, size = 0;
	cout << "Enter amount of input\n";
	cin >> n;
	cin.ignore();
	int* answer = new int[n];
	cout << "Enter your lines\n";
	for (int w = 0; w < n; w++) {
		string str, str1;
		getline(cin, str);
		getline(cin, str1);
		cout << "\n";
		PushBackTo(search(str, str1), answer, size);
	}
	for (int s = 0; s < n; s++) {
		if (answer[s] == 1) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	delete[] answer;
	return 0;
}