#pragma warning( disable : 4996)
#include "pch.h"
#include <gtest/gtest.h>
#include <string>
using namespace std;
void PushBackTo(int x, int*& ARR, int& SIZE) {
	int* NewArr = new int[SIZE + 1];
	for (int i = 0; i < SIZE; i++) {
		NewArr[i] = ARR[i];
	}
	NewArr[SIZE] = x;
	SIZE++;
	delete[]ARR;
	ARR = NewArr;
}
void Find(char* L, const int& SIZE,int*&num,int&sizenum) {
	for (int i = 0; i < SIZE; i++) {
		if (L[i] == '0' || L[i] == '1' || L[i] == '2' || L[i] == '3' || L[i] == '4' || L[i] == '5' || L[i] == '6' || L[i] == '7' || L[i] == '8' || L[i] == '9') {
			int x = (int)L[i] - (int)'0';
			PushBackTo(x, num, sizenum);
		}
	}
}
int summary(int* arr, int& size) {
	int sum=0;
	for (int i = 0; i < size; i++) {
		sum += arr[i] * pow(-1, i);
	}
	return sum;
}

TEST(Case1, Check) {
	char Line[] = "sdd1vnb24vnf63vbn,-5h";
	int l = sizeof(Line) / sizeof(char), size = 0,sum;
	int* num = new int[size];
	Find(Line, l,num,size);
	sum = summary(num, size);
	EXPECT_EQ(sum, -5);
	delete[] num;
}
TEST(Case2, Check) {
	char Line[] = "323ess4557 8 io";
	int l = sizeof(Line) / sizeof(char), size = 0, sum;
	int* num = new int[size];
	Find(Line, l, num, size);
	sum = summary(num, size);
	EXPECT_EQ(sum,-1 );
	delete[] num;
}
TEST(Case3, Check) {
	char Line[] = "[]];'.]'.4/]'/]'9/]]0'/-7/]/.[;.];";
	int l = sizeof(Line) / sizeof(char), size = 0, sum;
	int* num = new int[size];
	Find(Line, l, num, size);
	sum = summary(num, size);
	EXPECT_EQ(sum, -12);
	delete[] num;
}
TEST(Case4, Check) {
	char Line[] = "0 0 0 0 0 0 0 2000000 2100000";
	int l = sizeof(Line) / sizeof(char), size = 0, sum;
	int* num = new int[size];
	Find(Line, l, num, size);
	sum = summary(num, size);
	EXPECT_EQ(sum, -1);
	delete[] num;
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}