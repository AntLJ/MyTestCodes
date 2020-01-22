// TestBase2015.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <set>
using namespace std;

int main()
{
	const std::set<wstring> aaa = { L"ア", L"イ" };
	cout << __func__ << endl;
}

