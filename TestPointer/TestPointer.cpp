// TestPointer.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	const char *p;	// *p is const
	char c1 = 'a';
	char c2 = 'b';
	p = &c1;
	cout << "&p: " << &p << endl;
	cout << "*p: " << *p << endl;
	cout << "&c1: " << c1 << endl;
	cout << "&c2: " << c2 << endl;
	char c3 = *p;
	cout << "c3: " << c3 << endl;

	p = &c2;
	cout << "&p: " << &p << endl;
	cout << "*p: " << *p << endl;
	cout << "&c1: " << &c1 << endl;
	cout << "&c2: " << &c2 << endl;
	// *p = c1;	// error! This line means: you want to change *p to c1, but *p is const



	char* const p2 = &c1;	// p2 is const
	cout << "&p2: " << &p2 << endl;
	cout << "*p2: " << *p2 << endl;
	cout << "&c1: " << c1 << endl;
	cout << "&c2: " << c2 << endl;

	*p2 = c2;
	cout << "&p2: " << &p2 << endl;
	cout << "*p2: " << *p2 << endl;
	cout << "&c1: " << &c1 << endl;
	cout << "&c2: " << &c2 << endl;
	// p2 = &c1;	// error! This line means: you want to change p2 to point at c1, but p2 is const
	*/

	char *p = nullptr;
	char c1 = 'a';
	char c2 = 'b';
	char c3 = 'c';

	//*p = c1;	// null pointer error
	p = &c1;	// it means p points at c1's address, *p and c1 are the same
	if (*p == c1)
	{
		int i = 0;
	}
	c1 = 'd';
	cout << "*p: " << *p << endl;
	cout << "&p: " << &p << endl;
	cout << "&c1: " << &c1 << endl;
	cout << "&c2: " << &c2 << endl;

	*p = c2;
	cout << "*p: " << *p << endl;
	cout << "&p: " << &p << endl;
	cout << "&c1: " << &c1 << endl;
	cout << "&c2: " << &c2 << endl;

	*p = c3;
	cout << "*p: " << *p << endl;
	cout << "&p: " << &p << endl;
	cout << "&c1: " << &c1 << endl;
	cout << "&c2: " << &c2 << endl;


	return 0;
}
