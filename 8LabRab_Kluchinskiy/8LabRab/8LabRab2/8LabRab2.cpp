#pragma warning( disable : 4996)
#include <fstream>
#include <iostream>
using namespace std;
int Check() {
    int a;
    while (!(scanf("%d", &a)) || (a < 0)) {
        printf("Invalid Input\n");
        while ((getchar()) != '\n');
    }
    return a;
}
struct Worker {
    char SNP[255];
    int number;
    double hours;
    double rate;
    double cash;
    void count() {
        double sum = 0;
        if (hours > 144) {
            sum = (hours - 144) * rate * 2;
            sum += 144 * rate;
        }
        else {
            sum = rate * hours;
        }
        sum *= 0.88;
        cash = sum;
    }
    void Print() {
        cout << SNP << "\t" << number << "\t" << hours << "\t" << rate<<"\n";
    }
};
int main()
{
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
    fin.get();
    Worker* arr = (Worker*)calloc(n,sizeof(Worker));
    for (int i = 0; i < n; i++) {
        fin >> arr[i].SNP>>arr[i].number>>arr[i].hours>>arr[i].rate;
        fin.get();
    }
    for (int i = 0; i < n; i++) {
        arr[i].count();
    }
    for (int i = 0; i < n; i++) {
        fout << "Name : "<<arr[i].SNP << "\n" <<"Service number : "<< arr[i].number << '\n' <<"Salary : " << arr[i].cash << "\n\n";
    }

    fin.close();
    fout.close();
    free(arr);
    system("notepad Output.txt");
    int a;
    do {
        printf("Do you want to correct Input?\n");
        printf("Press 0(No) or Natural value(Yes))\n");
        a = Check();
        if (a) {
            fout.open("Output.txt");
            if (!fout.is_open()) {
                cout << "Output Failed\n";
                return 0;
            }
            cout << "Outout is open\n";

            fin.open("Input.txt");
            if (!fin.is_open()) {
                cout << "Input Failed\n";
                return 0;
            }
            cout << "Input is Open\n";
            system("notepad Input.txt");
            fin >> n;
            Worker* newarr = (Worker*)calloc(n, sizeof(Worker));
            for (int i = 0; i < n; i++) {
                fin >> newarr[i].SNP >> newarr[i].number >> newarr[i].hours >> newarr[i].rate;
                fin.get();
            }
            for (int i = 0; i < n; i++) {
                newarr[i].count();
            }
            for (int i = 0; i < n; i++) {
                fout << "Name : " << newarr[i].SNP << "\n" << "Service number : " << newarr[i].number << '\n' << "Salary : " << newarr[i].cash << "\n\n";
            }
            fin.close();
            fout.close();
            free(newarr);
            system("notepad Output.txt");
        }
    } while (a);
   return 0;
}
