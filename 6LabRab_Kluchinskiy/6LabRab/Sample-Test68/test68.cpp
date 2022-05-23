#include "pch.h"
#include <gtest/gtest.h>
#include <string>
using namespace std;
int search(string& orig, string& str1) {
	int l1 = str1.length(), l0 = orig.length();
	int n0 = orig.find(str1[0]);
	int i, j, cov, b1, b2;
	while (n0 != string::npos) {
		for (int y = 0; y < l1; y++) {//все возможные смещения вправо
			i = 1; cov = 1;//одно покрытие есть т.к. мы нашли n0
			while (i <= y) {//идём вправо на i символов, начиная с n0 и попадаем в n0+i
				if (orig[n0 + i] == str1[i]) {
					cov++;
                }
				else { break; }
				i++;
			}
			i--;
			if (cov < (y + 1)) { continue; }
			j = 1;
			while (j <= l1 - y - 1) {//идём влево на l1-i-1 символов начиная с n0+i
				b1 = n0 + i - j; b2 = i + j;
				if ((0 <= b1) && (b1 < l0) && (b2 <= l1)) {
					if ((orig[b1] == str1[b2])) {
						cov++;
					}
					else { break; }
				}
				else { break; }
				j++;
			}
			if (cov == l1) {
				return 1;
			}
		}
		n0 = orig.find(str1[0], n0 + 1);
	}
	return 0;
}

TEST(Case1, Check) {
	string str1="abcdefedcm";
	string str2="cdefedcb";
	int res = search(str1, str2);
	EXPECT_EQ(res,1);
}
TEST(Case2, Check) {
	string str1 = "QWERTY";
	string str2 = "YTREWQ";
	int res = search(str1, str2);
	EXPECT_EQ(res, 1);
}
TEST(Case3, Check) {
	string str1 = "mkcgfcg";
	string str2 = "cgcfg";
	int res = search(str1, str2);
	EXPECT_EQ(res, 1);
}
TEST(Case4, Check) {
	string str1 = "mkcgfag";
	string str2 = "cgcfg";
	int res = search(str1, str2);
	EXPECT_EQ(res, 0);
}
TEST(Case5, Check) {
	string str1 = "erprporip";
	string str2 = "pi";
	int res = search(str1, str2);
	EXPECT_EQ(res, 1);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}