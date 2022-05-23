#pragma warning( disable : 4996)
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
#include <filesystem>
#include <experimental/filesystem>
#define ll long long
using namespace std;
int Check() {
    int n;
    while (true) {
        cin >> n;
        if (cin.fail() || (n < 0) || (n > 4)) {
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        break;
    }
    return n;
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
 
        this->SupplyDate = SupplyDate.substr(0, 10);
      
    }
    string GetName() {
        return name;
    }
    double GetPrice() {
        return price;
    }
    int GetNumber() {
        return number;
    }
    int GetCostone() {
        return costone;
    }
    string GetDate() {
        return SupplyDate;
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
void Output1(Warehouse* arr, int n, fstream& fs) {
    fs.seekg(0, ios::beg);
    fs << n<<"\n\n";
    for (int i = 0; i < n-1; i++) {
        fs << arr[i].GetName() << "\n" << arr[i].GetNumber() << "\n" << arr[i].GetCostone() << "\n" << arr[i].GetSupplyDate() << "\n\n";
    }
    fs << arr[n-1].GetName() << "\n" << arr[n-1].GetNumber() << "\n" << arr[n-1].GetCostone() << "\n" << arr[n-1].GetSupplyDate();
}
void Add(Warehouse* &arr, int &SIZE) {
    Warehouse* newarr = new Warehouse[SIZE + 1];
    string name; int number; double costone; string SupplyDate;
    for (int i = 0; i < SIZE; i++) {
        newarr[i] = arr[i];
    }
    cout << "Enter name\n";
    cin >> name;
    newarr[SIZE].SetName(name);
    cout << "Enter number\n";
    cin >> number;
    newarr[SIZE].SetNumber(number);
    cout << "Enter costone\n";
    cin >> costone;
    newarr[SIZE].SetCostone(costone);
    cout << "Enter Supply date\n";
    cin >> SupplyDate;
    newarr[SIZE].SetSupplyDate(SupplyDate);
    delete[]arr;
    arr = newarr;
    SIZE+=1;
    fstream fs;
    fs.open("Input.txt",fstream::in|fstream::out|fstream::app);
    fs << "\n";
    fs  << arr[SIZE - 1].GetName() << "\n" << arr[SIZE - 1].GetNumber() << "\n" << arr[SIZE - 1].GetCostone() << "\n" << arr[SIZE - 1].GetSupplyDate() << "\n";
    fs.close();
    system("notepad Input.txt");
}
void Eraze(Warehouse*& arr, int& SIZE) {
    Warehouse* newarr = new Warehouse[SIZE - 1];
    int k,y;
    cout << "What structure do you want to eraze(1,2,...,n)\n";
    cin >> y;
    k = y - 1;
    for (int i = 0; i < k; i++) {
        newarr[i] = arr[i];
    }
    for (int i = k+1; i < SIZE; i++) {
        newarr[i-1] = arr[i];
    }
    delete[]arr;
    arr = newarr;
    SIZE -= 1;
    fstream fs;
    fs.open("Input.txt", fstream::in | fstream::out);
    int sumbytes = 5;
    for (int i = 0; i < SIZE; i++) {
        sumbytes += size(arr[i].GetName()) + 2;
        sumbytes += size(to_string(arr[i].GetNumber())) + 2;
        sumbytes += size(to_string(arr[i].GetCostone())) + 2;
        sumbytes += size(arr[i].GetSupplyDate()) + 2;
    }
    experimental::filesystem::resize_file("Input.txt", sumbytes);
    Output1(arr, SIZE, fs);
 
    fs.close();
    system("notepad Input.txt");
}
void Edit(Warehouse*& arr, int& SIZE) {
    int y, k;
    string name; int number; double costone; string SupplyDate;
    cout << "Which structure do you want to Edit(1,2,3..n)\n";
    cin >> y;
    k = y - 1;
    cout << "Enter name\n";
    cin >> name;
    arr[k].SetName(name);
    cout << "Enter number\n";
    cin >> number;
    arr[k].SetNumber(number);
    cout << "Enter costone\n";
    cin >> costone;
    arr[k].SetCostone(costone);
    cout << "Enter Supply date\n";
    cin >> SupplyDate;
    arr[k].SetSupplyDate(SupplyDate);
    fstream fs;
    fs.open("Input.txt", fstream::in | fstream::out);
    int sumbytes = 5;
    for (int i = 0; i < k; i++) {
        sumbytes += size(arr[i].GetName()) + 2;
        sumbytes += size(to_string(arr[i].GetNumber())) + 2;
        sumbytes += size(to_string(arr[i].GetCostone())) + 2;
        sumbytes += size(arr[i].GetSupplyDate()) + 2;
        sumbytes += 2;
    }
    cout << sumbytes;
    fs.seekp(sumbytes,ios::beg);
    fs<< arr[k].GetName() << "\n" << arr[k].GetNumber() << "\n" << arr[k].GetCostone() << "\n" << arr[k].GetSupplyDate();
    fs.close();
    system("notepad Input.txt");
}
Warehouse* Fillarr(int n,ifstream &fin) {
    Warehouse* arr = new Warehouse[n];
    fin.get();
    for (int i = 0; i < n; i++) {
        string name; int number; double costone; string SupplyDate;
        fin >> name >> number >> costone >> SupplyDate;
        arr[i].SetName(name); arr[i].SetNumber(number); arr[i].SetCostone(costone); arr[i].SetSupplyDate(SupplyDate);
        arr[i].CountDays(); arr[i].CountPrice();
        fin.get();
    }
    return arr;
}
void Output(Warehouse* arr, int n, ofstream& fout) {
    for (int i = 0; i < n; i++) {
            fout << "Name : " << arr[i].GetName() << "\n" << "Supply Date : " << arr[i].GetSupplyDate() << "\n" << "Price : " << arr[i].GetPrice()<<"\n\n";
    }
}
int main()
{
    int n,p;
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
    Warehouse* arr = Fillarr(n, fin);
    fin.close();

    do {
        cout << "Delete elemet press 1\n";
        cout << "Add element press 2\n";
        cout << "Edit element press 3\n";
        cout << "Sort elements press 4\n";
        cout << "exit press 0\n";
        p = Check();
        if (p == 1) {
            Eraze(arr, n);
        }
        else if (p == 2) {
            Add(arr, n);
        }
        else if (p == 3) {
            Edit(arr, n);
        }
        else if (p == 4) {
            Quicksort(arr, 0, n-1);
        }

    } while (p);
    Output(arr, n,fout);
    fout.close();
    system("notepad Output.txt");
    return 0;
}
