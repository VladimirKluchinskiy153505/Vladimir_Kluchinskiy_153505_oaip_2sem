#include "pch.h"
#include <cmath>
#include <gtest/gtest.h>
double findmax(double* Arr, int begin, int size) {
	if (size == 1) { return Arr[begin]; }
	if (size == 2) { return __max(Arr[begin], Arr[begin + 1]); }
	return __max(findmax(Arr, begin, size / 3), findmax(Arr, begin + (size / 3), size - size / 3));
}
TEST(Case1, Check) {
	double arr1[10] = { 1,2,3,9,8,7,6,5,4 };
	EXPECT_EQ(findmax(arr1,0,10),9);
}
TEST(Case2, Check) {
	double arr1[4] = { 1,555,7,999 };
	EXPECT_EQ(findmax(arr1, 0, 4), 999);
}
TEST(Case3, Check) {
	double arr1[8] = { -1,-2,-3,0.23,-1,-7,-6,0 };
	EXPECT_EQ(findmax(arr1, 0, 8), 0.23);
}
TEST(Case4, Check) {
	double arr1[3] = { 8,9,2 };
	EXPECT_EQ(findmax(arr1, 0, 3), 9);
}
TEST(Case5, Check) {
	double arr1[14] = { 6,88,44,11,-66,5,8,7,0,0,444,888,8,365 };
	EXPECT_EQ(findmax(arr1, 0, 14), 888);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}