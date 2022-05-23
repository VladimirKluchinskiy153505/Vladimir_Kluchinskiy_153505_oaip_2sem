#include "pch.h"
#include <gtest/gtest.h>
void PushBackTo(int x, int*& QWE, int& SIZE) {
	SIZE++;
	QWE[SIZE - 1] = x;
}
void FindEvenOnDiag(int Arr[5][6],int *&qwe,int &size) {
	for (int i = 0, j = 0; (i < 5) && (j < 6); i++, j++) {
		if (Arr[i][j] % 2 == 0) {
			PushBackTo(Arr[i][j], qwe, size);
		}
	}
}
TEST(Case1, Check) {

	int size = 0;
	int* qwe = new int[5];
	int arr[5][6] = { {1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18},{19,20,21,22,23,24},{25,26,27,28,29,30}};
	FindEvenOnDiag(arr, qwe, size);
	EXPECT_TRUE((qwe[0]==8)&&(qwe[1]==22));
	delete[] qwe;
}
TEST(Case2, Check) {

	int size = 0;
	int* qwe = new int[5];
	int arr[5][6] = { {11,22,33,44,55,66},{7,82,9,10,11,12},{13,14,15,16,17,18},{19,20,21,22,23,24},{25,26,27,28,29,30} };
	FindEvenOnDiag(arr, qwe, size);
	EXPECT_TRUE((qwe[0] == 82) && (qwe[1] == 22));
	delete[] qwe;
}
TEST(Case3, Check) {

	int size = 0;
	int* qwe = new int[5];
	int arr[5][6] = { {11,21,31,41,51,61},{7,8,9,10,11,12},{13,14,156,16,17,18},{19,20,21,22,23,24},{25,26,27,28,29,30} };
	FindEvenOnDiag(arr, qwe, size);
	EXPECT_TRUE((qwe[0] == 8) && (qwe[1] == 156));
	delete[] qwe;
}
//int main(int argc, char** argv) {
//	::testing::InitGoogleTest(&argc, argv);
//	return RUN_ALL_TESTS();
//}