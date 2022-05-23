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
ll from14to10(int x, int num) {
    ll sum = 0;
    if (x == 0xA) {
        sum += 10 * degree(14, num);
    }
    else if (x == 0xB) {
        sum += 11 * degree(14, num);
    }
    else if (x == 0xC) {
        sum += 12 * degree(14, num);
    }
    else if (x == 0xD) {
        sum += 13 * degree(14, num);
    }
    else {
        sum += x * degree(14, num);
    }
    return sum;
}
TEST(Test1, TestName) {
    int x = 0xA;
    EXPECT_EQ(from14to10(x, 0),10 );
}
TEST(Test2, TestName) {
    int x = 0xB;
    EXPECT_EQ(from14to10(x, 1), 154);
}

TEST(Test3, TestName) {
    int x = 0xC;
    EXPECT_EQ(from14to10(x, 0), 12);

}
TEST(Test4, TestName) {
    int x = 9;
    EXPECT_EQ(from14to10(x, 3), 24696);

}
TEST(Test5, TestName) {
    int x = 0xD;
    EXPECT_EQ(from14to10(x, 9), 268593608192);

}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}