// Test2017.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
#include<sstream>
using namespace std;

long toLong(string s)
{
	long ll;
	istringstream iss(s);
	iss >> ll;

	return ll;
}


int main()
{
	string s = "-12356";
	long asdf = toLong(s);

	return 0;
}
