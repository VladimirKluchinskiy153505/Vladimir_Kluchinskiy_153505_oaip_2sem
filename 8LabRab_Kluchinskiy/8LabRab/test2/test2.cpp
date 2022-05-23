#pragma warning( disable : 4996)
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#define ll long long int
using namespace std;
int Check(int n) {
    int a;
    while (!(scanf("%d", &a)) || (a < 0) || (a > n)) {
        printf("Invalid Input\n");
        while ((getchar()) != '\n');
    }
    return a;
}
class Warehouse {
private:
    string name;
    ll number;
    double costone;
    string SupplyDate;
    string NowDate = "27.12.2021";
    double price;
    ll days = 0;
public:
    void SetName(string name) {
        this->name = name;
    }
    void SetNumber(int number) {
        this->number = number;
    }
    void SetCostone(double costone) {
        this->costone = costone;
    }
    void SetSupplyDate(string SupplyDate) {
        this->SupplyDate = SupplyDate;
    }
    string GetName() {
        return name;
    }
    double GetPrice() {
        return price;
    }
    ll GetDays() {
        return days;
    }
    string GetSupplyDate() {
        return SupplyDate;
    }
    void CountPrice() {
        price = costone * number;
    }
    void CountDays() {
        int d, m, y, d0, m0, y0;
        d = stoi(NowDate.substr(0, 2));
        m = stoi(NowDate.substr(3, 2)) * 30;
        y = stoi(NowDate.substr(6, 4)) * 365;
        d0 = stoi(SupplyDate.substr(0, 2));
        m0 = stoi(SupplyDate.substr(3, 2)) * 30;
        y0 = stoi(SupplyDate.substr(6, 4)) * 365;
        days = d + m + y - d0 - m0 - y0;
    }
    void Print() {
        cout << name << " " << price << " " << SupplyDate << " " << days << "\n";
    }
};
int Partition(Warehouse*& val, int start, int end) {
    int grav = start;
    for (int i = start; i < end; i++) {
        if (val[i].GetName() <= val[end].GetName()) {
            swap(val[i], val[grav]);
            grav++;
        }
    }
    swap(val[grav], val[end]);
    return grav;
}
void Quicksort(Warehouse*& val, int start, int end) {
    if (start < end) {
        int q = Partition(val, start, end);
        Quicksort(val, start, end - 1);
        Quicksort(val, q + 1, end);
    }
}
int main()
{
    /* std::cout << std::fixed << 221414252135125453453245325234.0 << std::endl;*/
    int n;
    ofstream fout;
    fout.open("Output.txt");
    if (!fout.is_open()) {
        cout << "Output Failed\n";
        return 0;
    }
    cout << "Outout is open\n";

    ifstream fin;
    fin.open("Input.txt");
    if (!fin.is_open()) {
        cout << "Input Failed\n";
        return 0;
    }
    cout << "Input is Open\n";
    system("notepad Input.txt");

    fin >> n;
    Warehouse* arr = new Warehouse[n];
    fin.get();
    for (int i = 0; i < n; i++) {
        string name; int number; double costone; string SupplyDate;
        fin >> name >> number >> costone >> SupplyDate;
        arr[i].SetName(name); arr[i].SetNumber(number); arr[i].SetCostone(costone); arr[i].SetSupplyDate(SupplyDate);
        arr[i].CountDays(); arr[i].CountPrice();
        fin.get();
    }
    for (int i = 0; i < n; i++) {
        arr[i].Print();
    }
    for (int i = 0; i < n; i++) {
        fout << "Name : " << arr[i].GetName() << "\n" << "Supply Date : " << arr[i].GetSupplyDate() << "\n" << "Price : " << arr[i].GetPrice() << "\n\n";
    }
    fin.close();
    fout.close();
    system("notepad Output.txt");
    int k;
    do {
        int y;
        cout << "Enter number of structure which you want to correct(1,2,...,n) or 0 if you don't want to do it\n";
        k = Check(n);
        y = k - 1;
        if (k) {
            string name; int number; double costone; string SupplyDate;
            cout << "Enter New name\n";
            cin >> name;
            cout << "Enter New number\n";
            cin >> number;
            cout << "Enter New costone\n";
            cin >> costone;
            cout << "Enter New SupplyDate\n";
            cin >> SupplyDate;
            arr[y].SetName(name); arr[y].SetNumber(number); arr[y].SetCostone(costone); arr[y].SetSupplyDate(SupplyDate);
            arr[y].CountDays(); arr[y].CountPrice();
            ofstream fout;
            fout.open("Input.txt");
            if (!fout.is_open()) {
                cout << "Input Failed\n";
                return 0;
            }
            cout << "Input is open\n";

            /*fin.open("Input.txt");
            if (!fin.is_open()) {
                cout << "Input Failed\n";
                return 0;
            }*/
            cout << "Input is Open\n";
            fout.seekp(26, ios::beg);
            fout.write("Name : ", sizeof(Warehouse));/* << arr[y].GetName() << "\n" << "Supply Date : " << arr[y].GetSupplyDate() << "\n" << "Price : " << arr[y].GetPrice() << "\n\n";*/
            fin.close();
            fout.close();
            system("notepad Input.txt");
        }
    } while (k);

    /*Quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        if ((arr[i].GetPrice() > 1000000) && (arr[i].GetDays() > 30)) {
            fout << "Name : " << arr[i].GetName() << "\n" << "Supply Date : " << arr[i].GetSupplyDate() << "\n" << "Price : " << arr[i].GetPrice() << "\n\n";
        }
    }*/
    delete[] arr;
    return 0;
}
