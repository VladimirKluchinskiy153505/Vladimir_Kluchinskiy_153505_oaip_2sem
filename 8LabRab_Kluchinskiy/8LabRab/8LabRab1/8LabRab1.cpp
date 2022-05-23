#pragma warning( disable : 4996)
#include <iostream>
#include <string>
using namespace std;
int GetNumN() {
	int a;
	while (!(scanf("%d", &a))||(a<=0)) {
		printf("Invalid Input\n");
		while ((getchar()) != '\n');
	}
	return a;
}
int Check() {
	int a;
	while (!(scanf("%d", &a)) || (a < 0)) {
		printf("Invalid Input\n");
		while ((getchar()) != '\n');
	}
	return a;
}
double GetNumD() {
	double a;
	while (!(scanf("%Lf", &a))){
		printf("Invalid Input\n");
		while ((getchar())!= '\n');
    }
	return a;
 }
struct Student {
	string SNP;
	string adress;
	double first;
	double second;
	double third;
	double mid;
	void avtomat() {
		third = (first + second) / 2;
	}
	void countmid() {
		mid = (first + second + third) / 3;
	}
};
int Partition(Student*& val, int start, int end) {
	int grav = start;
	for (int i = start; i < end; i++) {
		if (val[i].SNP <= val[end].SNP) {
			swap(val[i], val[grav]);
			grav++;
		}
	}
	swap(val[grav], val[end]);
	return grav;
}
void Quicksort(Student*& val, int start, int end) {
	if (start < end) {
		int q = Partition(val, start, end);
		Quicksort(val, start, end - 1);
		Quicksort(val, q + 1, end);
	}
}
void resize(Student*& arr, int& size, int& newsize) {
	Student* newarr = new Student[newsize];
	for (int i = 0; i < newsize; i++) {
		newarr[i] = arr[i];
	}
	delete[] arr;
	size = newsize;
	arr = newarr;
}
void widen(Student*& arr, int& size, int& u) {
	int newsize = size + u;
	Student* newarr = new Student[newsize];
	for (int i = 0; i < size; i++) {
		newarr[i] = arr[i];
	}
	for (int i = size; i < newsize; i++) {
		printf("Enter Surname, Name, Patronymic\n");
		cin.ignore(32767, '\n');
		getline(cin, newarr[i].SNP);
		printf("Enter Adress\n");
		getline(cin, newarr[i].adress);
		printf("Enter First Mark\n");
		newarr[i].first = GetNumD();
		if (newarr[i].first <= 1) {
			int a;
			printf("You have an option to expel this Student and Students\n");//1
			printf("Press 0(No) or Natural value(Yes))\n");
			a = Check();
			if (a) {
				resize(newarr,newsize , i);
				break;
			}
		}
		printf("Enter Second\n");
		newarr[i].second = GetNumD();
		if ((newarr[i].first >= 4) && (newarr[i].second >= 4)) {//00
			int a;
			printf("You may put the third mark as arithmetic mean of the previous two\n");
			printf("Press 0(No) or Natural value(Yes))\n");
			a = Check();
			if (a) {
				newarr[i].avtomat();
				newarr[i].countmid();
				printf("\n\n");
				continue;
			}

		}
		printf("Enter Third mark:\n");
		newarr[i].third = GetNumD();
		newarr[i].countmid();
		printf("\n\n");
	}
	delete[] arr;
	size = newsize;
	arr = newarr;
}
void del(Student*& arr, int& size, int &num) {
	int newsize = size-1;
	Student* newarr = new Student[newsize];
	for (int i = 0; i < num; i++) {
		newarr[i] = arr[i];
	}
	for (int i = num+1; i < size; i++) {
		newarr[i-1] = arr[i];
	}
	delete[] arr;
	size = newsize;
	arr = newarr;
	num--;
}
void erase(Student*& arr, int& size) {//5
	double X;
	printf("Marks lower than X are unacceptable\n");
	printf("Enter X\n");
		X = GetNumD();
		for (int i = 0; i < size; i++) {
			if ((arr[i].first < X) || (arr[i].second < X) || (arr[i].third < X)) {
				int a;
				printf("%s%s", arr[i].SNP.c_str(), " failed test\n");
				printf("If you want to expel him press 0\n");
			    printf("If you want to rewrite his Structure press any Natural value\n");
				a = Check();
				if (a) {
					printf("Enter Surname, Name, Patronymic\n");
					cin.ignore(32767, '\n');
					getline(cin, arr[i].SNP);
					printf("Enter Adress\n");
					getline(cin, arr[i].adress);
					printf("Enter First Mark\n");
					arr[i].first = GetNumD();
					printf("Enter Second\n");
					arr[i].second = GetNumD();
					printf("Enter Third mark:\n");
					arr[i].third = GetNumD();
				}
				else {
					del(arr, size, i);
				}
			}
		}
		printf("\n\n");
}
int main() {
	int n,a;
	printf("Enter amount of Students\n");
	n = GetNumN();
	Student* arr = new Student[n];
	for (int i = 0; i < n; i++) {
		printf ("Enter Surname, Name, Patronymic\n");
		cin.ignore(32767,'\n');
		getline(cin,arr[i].SNP);
	    printf("Enter Adress\n");
		getline(cin, arr[i].adress);
		printf("Enter First Mark\n");
		 arr[i].first=GetNumD();
		printf("Enter Second\n");
		arr[i].second=GetNumD();
		if ((arr[i].first <= 1)||(arr[i].second<=1)) {
			printf("You have an option to expel this Student and other Students\n");//1
			printf("Press 0(No) or Natural value(Yes))\n");
			a = Check();
			if (a) {
				resize(arr, n, i);
				break;
			}
		}
		if ((arr[i].first >= 4) && (arr[i].second >=4)) {//00
			printf("You may put the third mark as arithmetic mean of the previous two\n");
			 printf("Press 0(No) or Natural value(Yes))\n");
			a=Check();
			if (a) {
				arr[i].avtomat();
				arr[i].countmid();
				printf("\n\n");
				continue;
			}

		}
		printf("Enter Third mark:\n");
		arr[i].third=GetNumD();
		arr[i].countmid();
		printf("\n\n");
	}
	printf("Do you want to add elements\n");//3
	printf("Press 0(No) or Natural value(Yes))\n");
	a = Check();
	if (a) {
		int u;
		printf("How  many elements do you want to add?\n");
		u = GetNumN();
		widen(arr, n, u);
	}
	printf("Do you want to see the list of Excellent students(All marks exceed or equal Mark)?\n");//4
	printf("Press 0(No) or Natural value(Yes))\n");
	a = Check();
	if (a) {
		printf("Enter Mark\n");
		int Mark = GetNumD();
		for (int i = 0; i < n; i++) {
			if ((arr[i].first >= Mark) && (arr[i].second >= Mark) && (arr[i].third >= Mark)) {
				printf("%s : %s\n\n","SNP",arr[i].SNP.c_str());
				printf("%s : %s\n", "Adress",arr[i].adress.c_str());
				printf("%s : %Lf\n","First", arr[i].first);
				printf("%s : %Lf\n","Second", arr[i].second);
				printf("%s : %Lf\n\n","Third", arr[i].third);
			}
		}
	}
	erase(arr, n);
	Quicksort(arr, 0, n - 1);//6
	printf("Array of the mid marks in the alphabet order\n");//2
	for (int i = 0; i < n; i++) {
		printf("%s  : %Lf\n",arr[i].SNP.c_str(), arr[i].mid);
		printf("%s : %s\n", "Adress", arr[i].adress.c_str());
		printf("%s : %Lf\n", "First", arr[i].first);
		printf("%s : %Lf\n", "Second", arr[i].second);
		printf("%s : %Lf\n\n", "Third", arr[i].third);

	}
	delete[] arr;
	return 0;
}