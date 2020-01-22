// TestNamespace.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

namespace first
{
	int var = 5;
}

namespace second
{
	double var = 3.1416;
}

int _tmain(int argc, _TCHAR* argv[])
{
	{
		using namespace first;
		cout << var << endl;
	}
	{
		using namespace second;
		cout << var << endl;
	}
	return 0;
}

