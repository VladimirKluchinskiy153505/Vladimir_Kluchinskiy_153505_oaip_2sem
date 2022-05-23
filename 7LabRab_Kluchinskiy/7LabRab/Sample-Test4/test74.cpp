#pragma warning( disable : 4996)
#include "pch.h"
#include <gtest/gtest.h>
#define ll long long int
void PushBackTo(char x, char*& ARR, int& SIZE) {
    char* NewArr = new char[SIZE + 1];
    for (int i = 0; i < SIZE; i++) {
        NewArr[i] = ARR[i];
    }
    NewArr[SIZE] = x;
    SIZE++;
    delete[]ARR;
    ARR = NewArr;
}
void DelFirst(char*& ARR, int& SIZE) {
    char* NewArr = new char[SIZE - 1];
    for (int i = 1; i < SIZE; i++) {
        NewArr[i - 1] = ARR[i];
    }
    SIZE--;
    delete[]ARR;
    ARR = NewArr;
}
void DelLast(char*& ARR, int& SIZE) {
    char* NewArr = new char[SIZE - 1];
    for (int i = 0; i < SIZE - 1; i++) {
        NewArr[i] = ARR[i];
    }
    SIZE--;
    delete[]ARR;
    ARR = NewArr;
}
TEST(Test1, TestName) {
    int size = 5;
    char* arr=new char[size];
    for (int i = 0; i < size; i++) {
        arr[i] = 48 + i;
    }
    DelFirst(arr, size);
    EXPECT_EQ(arr[0], '1');
    delete[]arr;
}
TEST(Test2, TestName) {
    int size = 5;
    char* arr = new char[size];
    for (int i = 0; i < size; i++) {
        arr[i] = 48 + i;
    }
    DelLast(arr, size);
    EXPECT_EQ(arr[size-1], '3');
    delete[]arr;
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}