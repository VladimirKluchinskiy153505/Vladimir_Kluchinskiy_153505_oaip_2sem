#pragma warning( disable : 4996)
#include <iostream>
using namespace std;
void Print( char* &L, const int& SIZE) {
	int i = 0, first = 0, second = 0;
	while (i!=SIZE) {
		while (true) {//нашли пробел или конец стоки
			if ((L[i] == char(32))||(L[i]=='\0')) {
				second = i;
				break;
			}
			i++;
		}// проверяем слово между first and second
		if (!(L[first] == 'e' || L[first] == 'E' || L[first] == 'y' || L[first] == 'Y' || L[first] == 'u' || L[first] == 'U' || L[first] == 'i' || L[first] == 'I' || L[first] == 'o' || L[first] == 'O' || L[first] == 'a' || L[first] == 'A')) {
			first = second + 1;
		}
		else {
			if (L[second - 1] == 'e' || L[second - 1] == 'E' || L[second - 1] == 'y' || L[second - 1] == 'Y' || L[second - 1] == 'u' || L[second - 1] == 'U' || L[second - 1] == 'i' || L[second - 1] == 'I' || L[second - 1] == 'o' || L[second - 1] == 'O' || L[second - 1] == 'a' || L[second - 1] == 'A') {
				for (int j = first; j < second; j++) {
					cout << L[j];
				}
				cout << " ";
			}
			first = second + 1;
		}
		i++;
	}
}
int main()
{
	char* line = new char[1024];
	cout << "Enter line" << endl;

	cin.getline(line, 1024, '\n');
	int l = strlen(line);

	char* newline = new char[l + 1];
	strcpy(newline, line);
	delete[] line;
	Print(newline, l + 1);
	delete[] newline;
	return 0;
}