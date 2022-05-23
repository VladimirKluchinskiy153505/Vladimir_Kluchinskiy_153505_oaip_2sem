#pragma warning( disable : 4996)
#include "pch.h"
#include <gtest/gtest.h>
#define ll long long int
ll degree(ll x, int n) {
    if (n == 0) { return 1; }
    ll res;
    res = degree(x, n >> 1);
    if (n & 1) { return res * res * x; }
    else { return res * res; }
}
ll from14to10(char*& arr, const int& l) {
    ll sum = 0; int j = 0;
    if (arr[0] == '-') { j++; }
    for (int i = l - 2; i >= j; i--) {
        if ((arr[i] == 'a') || (arr[i] == 'A')) {
            sum += 10 * degree(14, l - 2 - i);
        }
        else if ((arr[i] == 'b') || (arr[i] == 'B')) {
            sum += 11 * degree(14, l - 2 - i);
        }
        else if ((arr[i] == 'c') || (arr[i] == 'C')) {
            sum += 12 * degree(14, l - 2 - i);
        }
        else if ((arr[i] == 'd') || (arr[i] == 'D')) {
            sum += 13 * degree(14, l - 2 - i);
        }
        else {
            sum += (int(arr[i]) - int('0')) * degree(14, l - 2 - i);
        }
    }
    if (arr[0] == '-') { sum *= -1; }
    return sum;
}
TEST(Test1, TestName) {
    char *arr = "ABCD";
  EXPECT_EQ(from14to10(arr,5), 29777);
}
TEST(Test2, TestName) {
    char* arr = "99999";
    EXPECT_EQ(from14to10(arr, 6), 372339);
}
TEST(Test3, TestName) {
    char* arr = "1234D";
    EXPECT_EQ(from14to10(arr, 6), 44561);

}
TEST(Test4, TestName) {
    char* arr = "000001";
    EXPECT_EQ(from14to10(arr, 7), 1);
}
TEST(Test5, TestName) {
    char* arr = "a1234b";
    EXPECT_EQ(from14to10(arr, 7), 5422799);
}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}