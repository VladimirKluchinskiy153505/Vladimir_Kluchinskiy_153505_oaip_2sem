#include <iostream>
#include <cmath>
#include <string>
#define ll long long int
using namespace std;
int Find(string word, string& str) {
    int sizeword = word.size();
    int sizestr = str.size();
    if (sizeword > sizestr) { return -1; }
    for (int i = 0; i < sizestr; i++) {
        if (str[i] == word[0]) {
            for (int j = 1; j < sizeword; j++) {
                if (word[j] != str[i + j]) {
                    break;
                }
                return i;
            }
        }
    }
    return -1;
}
void Replace(string& str, int pos, int num, string word) {
    for (int i = 0; i < num; i++) {
        str[pos + i] = word[i];
    }
}
void Reverse(string& str) {
    int size = str.size();
    for (int i = 0; i < (size / 2); i++)
    {
        swap(str[i], str[size - 1 - i]);
    }
}
void from10to3(string*&arr,int&size,ll*&val)
{
    for (int i = 0; i < size; i++) {
        arr[i] = "";
        while (val[i] >= 3) {
            arr[i].push_back((val[i] % 3) + 48);
            val[i] /= 3;
        }
        arr[i].push_back(val[i] + 48);
        Reverse(arr[i]);
    }
}
void dreadful(string*& arr, int& size) {
    for (int i = 0; i < size; i++) {
        int pos = Find("10",arr[i]);
        while (pos + 1) {
            Replace(arr[i],pos, 2, "03");
            pos = Find("10",arr[i]);
        }
        int pos1 = Find("20",arr[i]);
        while (pos1 + 1) {
            Replace(arr[i],pos1, 2, "13");
            pos1 = Find("20",arr[i]);
        }
        int pos2 = Find("30",arr[i]);
        while (pos2 + 1) {
            Replace(arr[i],pos2, 2, "23");
            pos2 = Find("30",arr[i]);
        }
        while (arr[i][0] == '0') {
            arr[i].erase(0, 1);
        }
    }
}
int main() {
    int size;
    cout << "Enter amount of Data:\n";
    cin >> size;
    cout << "\n";
    ll* val = new ll[size];
    string* arr = new string[size];
    cout << "Enter your numbers\n";
    for (int i = 0; i < size; i++) {
        cin >> val[i];
    }
    from10to3(arr, size, val);
    dreadful(arr, size);
    cout << "\n\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\n";
    }
    delete[] val;
    delete[] arr;
	return 0;
}