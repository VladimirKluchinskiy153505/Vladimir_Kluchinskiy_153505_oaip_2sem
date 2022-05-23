#pragma warning( disable : 4996)
#include "pch.h"
#include <gtest/gtest.h>
#include <string>
using namespace std;
void Improve(string& str) {
	int size = str.length();
	while (str.find("x") != string::npos) {//x
		str.replace(str.find("x"), 1, "ks");
	}
	while (str.find("X") != string::npos) {//X
		str.replace(str.find("X"), 1, "Ks");
	}

	while (str.find("w") != string::npos) {//w
		str.replace(str.find("w"), 1, "v");
	}
	while (str.find("W") != string::npos) {//W
		str.replace(str.find("W"), 1, "V");
	}

	while (str.find("ph") != string::npos) {//ph
		str.replace(str.find("ph"), 2, "f");
	}
	while (str.find("Ph") != string::npos) {//Ph
		str.replace(str.find("Ph"), 2, "F");
	}

	while (str.find("you") != string::npos) {//you
		str.replace(str.find("you"), 3, "u");
	}
	while (str.find("You") != string::npos) {//You
		str.replace(str.find("You"), 3, "U");
	}

	while (str.find("oo") != string::npos) {//oo
		str.replace(str.find("oo"), 2, "u");
	}
	while (str.find("Oo") != string::npos) {//Oo
		str.replace(str.find("Oo"), 2, "U");
	}

	while (str.find("ee") != string::npos) {//ee
		str.replace(str.find("ee"), 2, "i");
	}
	while (str.find("Ee") != string::npos) {//Ee
		str.replace(str.find("Ee"), 2, "I");
	}

	while (str.find("th") != string::npos) {//th
		str.replace(str.find("th"), 2, "z");
	}
	while (str.find("Th") != string::npos) {//Th
		str.replace(str.find("Th"), 2, "Z");
	}

	while (str.find("qu") != string::npos) {//qu
		str.replace(str.find("qu"), 2, "kv");
	}
	while (str.find("Qu") != string::npos) {//Qu
		str.replace(str.find("Qu"), 2, "Kv");
	}

	while (str.find("q") != string::npos) {//q
		str.replace(str.find("q"), 1, "k");
	}
	while (str.find("Q") != string::npos) {//Q
		str.replace(str.find("Q"), 1, "K");
	}

	while (str.find("ce") != string::npos) {//ce
		str.replace(str.find("ce"), 2, "se");
	}
	while (str.find("Ce") != string::npos) {//Ce
		str.replace(str.find("Ce"), 2, "Se");
	}

	while (str.find("ci") != string::npos) {//ci
		str.replace(str.find("ci"), 2, "si");
	}
	while (str.find("Ci") != string::npos) {//Ci
		str.replace(str.find("Ci"), 2, "Si");
	}

	while (str.find("cy") != string::npos) {//cy
		str.replace(str.find("cy"), 2, "sy");
	}
	while (str.find("Cy") != string::npos) {//Cy
		str.replace(str.find("Cy"), 2, "Sy");
	}

	while (str.find("c") != string::npos) {//c
		str.replace(str.find("c"), 1, "k");
	}
	while (str.find("C") != string::npos) {//C
		str.replace(str.find("C"), 1, "K");
	}

	while (str.find("kk") != string::npos) {
		str.replace(str.find("kk"), 2, "k");
	}
	while (str.find("ss") != string::npos) {
		str.replace(str.find("ss"), 2, "s");
	}
	while (str.find("vv") != string::npos) {
		str.replace(str.find("vv"), 2, "v");
	}
	while (str.find("ff") != string::npos) {
		str.replace(str.find("ff"), 2, "f");
	}
	while (str.find("tt") != string::npos) {
		str.replace(str.find("tt"), 2, "t");
	}
	while (str.find("pp") != string::npos) {
		str.replace(str.find("pp"), 2, "p");
	}
	while (str.find("dd") != string::npos) {
		str.replace(str.find("dd"), 2, "d");
	}
	while (str.find("gg") != string::npos) {
		str.replace(str.find("gg"), 2, "g");
	}
	while (str.find("hh") != string::npos) {
		str.replace(str.find("hh"), 2, "h");
	}
	while (str.find("ll") != string::npos) {
		str.replace(str.find("ll"), 2, "l");
	}
	while (str.find("jj") != string::npos) {
		str.replace(str.find("jj"), 2, "j");
	}
	while (str.find("zz") != string::npos) {
		str.replace(str.find("zz"), 2, "z");
	}
	while (str.find("bb") != string::npos) {
		str.replace(str.find("bb"), 2, "b");
	}
	while (str.find("nn") != string::npos) {
		str.replace(str.find("nn"), 2, "n");
	}
	while (str.find("mm") != string::npos) {
		str.replace(str.find("mm"), 2, "m");
	}
}
TEST(Case1, Check) {
	string str1 = "Too swift for Theex, too quick for Gallow,";
	string str2 = "Tu svift for Ziks, tu kvik for Galov,";
	Improve(str1);
	EXPECT_EQ(str1, str2);
}
TEST(Case2, Check) {
	string str1 = "Too strong for young Prince Joseph to follow.";
	string str2 = "Tu strong for ung Prinse Josef to folov.";
	Improve(str1);
	EXPECT_EQ(str1, str2);
}
TEST(Case3, Check) {
	string str1 = "Racing against the inevitable, scientists are working on solving the problem by genetically modifying the Cavendish with genes from TR-4-resistant banana species.";
	string str2 = "Rasing against ze inevitable, sientists are vorking on solving ze problem by genetikaly modifying ze Kavendish viz genes from TR-4-resistant banana spesies.";
	Improve(str1);
	EXPECT_EQ(str1, str2);
}
TEST(Case4, Check) {
	string str1 = "In an attempt to escape the fungus, farmers abandoned infected fields, flooded them and then replanted crops somewhere else, often cutting down rainforest to do so.";
	string str2 = "In an atempt to eskape ze fungus, farmers abandoned infekted fields, fluded zem and zen replanted krops somevhere else, often kuting dovn rainforest to do so.";
	Improve(str1);
	EXPECT_EQ(str1, str2);
}
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}