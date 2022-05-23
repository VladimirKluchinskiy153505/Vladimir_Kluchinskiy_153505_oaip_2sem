#include "pch.h"
#include <gtest/gtest.h>
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
int findNulls(int Arr[3][3]) {
	int am = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (Arr[i][j] == 0) {
				am++;
			}
		}
	}
	return am;
}
TEST(Case1, Check) {
	int Arr[3][3] = { {1,2,3},{0,0,6},{7,0,9} };
	EXPECT_EQ(findNulls(Arr), 3);
}
TEST(Case2, Check) {
	int Arr[3][3] = { {0,2,3},{0,0,6},{7,0,9} };
	EXPECT_EQ(findNulls(Arr), 4);
}
TEST(Case3, Check) {
	int Arr[3][3] = { {1,2,0},{0,0,6},{0,0,9} };
	EXPECT_EQ(findNulls(Arr), 5);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}