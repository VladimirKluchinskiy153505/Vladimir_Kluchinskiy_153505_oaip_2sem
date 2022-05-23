#pragma warning( disable : 4996)
#include "pch.h"
#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <gtest/gtest.h>
#define ll long long int
int subtract(uint32_t x, uint32_t y) {//разность
    while (y) {
        uint32_t borrow = (~x) & y;
        x = x ^ y;
        y = borrow << 1;
    }
    return x;
}
uint32_t inc(uint32_t i) {//++
    uint32_t mask = 1;
    while (i & mask) {
        i &= ~mask;
        mask <<= 1;
    }
    i |= mask;
    return i;
}

uint32_t divide(uint32_t n, uint32_t d) {//делить
    uint32_t q = 0;
    while (n >= d) {
        uint32_t i = 0, d_t = d;
        while (n >= (d_t << 1)) {
            i = inc(i);
            d_t <<= 1;
        }
        q |= 1 << i;
        n = subtract(n, d_t);

    }
    return q;
}

int add(uint32_t x, uint32_t y) { //добавить 
    while (y) {
        uint32_t carry = x & y;
        x = x ^ y;
        y = carry << 1;
    }
    return x;
}

uint32_t multiply(uint32_t a, uint32_t b) {//умножить
    uint32_t result = 0;
    while (b)
    {
        if (b & 1)
        {
            result = add(result, a);
        }
        a <<= 1;
        b >>= 1;
    }
    return result;
}

uint32_t mod(uint32_t a, uint32_t b) {//остаток по модулю
    uint32_t r = divide(a, b);
    return subtract(a, multiply(r, b));
}
TEST(Test1, TestName) {
    EXPECT_EQ(mod(4294967295, 11), 3);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}