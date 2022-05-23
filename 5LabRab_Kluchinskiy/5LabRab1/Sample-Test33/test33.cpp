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
double findAver(int* Arr, int size) {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += Arr[i];
	}
	return (sum / size);
}
void Magic(int Arr[2][4],int *&qwe,int &size)
{
	for (int j = 1; j < 4; j += 2) {
		for (int i = 0; i < 2; i++) {

			if (Arr[i][j] % 2) {
				PushBackTo(Arr[i][j], qwe, size);
			}
		}
	}
}
TEST(Case1, Check) {
	int Arr[2][4] = { {1,1,3,3},{5,5,7,7 } };
	int size = 0;
	int* qwe = new int[size];
	Magic(Arr, qwe, size);
	EXPECT_TRUE((qwe[0]==1)&&(qwe[1]==5)&&(qwe[2]==3)&&(qwe[3]==7));
	delete[] qwe;
}
TEST(Case2, Check) {
	int arr[5] = { 1,2,3,4,5 };
	EXPECT_EQ(findAver(arr,5), 3);
}
TEST(Case3, Check) {
	int arr[6] = { 1,2,3,4,5,3 };
	EXPECT_EQ(findAver(arr, 5), 3);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}