// TestStringCopy.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void getMemory(char* p, int num)
{
	p = (char*)malloc(sizeof(char) * num); // useless
}

void getMemoryOk(char** p, int num)
{
	*p = (char*)malloc(sizeof(char) * num);
}

char * getMemoryOk2(char * p, int num)
{
	p = (char*)malloc(sizeof(char) * num);
	return p;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char* str = NULL;

	//getMemory(str, 100); // useless
	getMemoryOk(&str, 100);
	strcpy_s(str, 100, "hello");

	cout << *str << endl;	// part of str, default is the first character of str
	cout << str << endl;	// str itself
	cout << &str << endl;	// address of str


	char* str2 = NULL;
	str2 = getMemoryOk2(str2, 100);
	strcpy_s(str2, 100, "hello");
	
	cout << *str2 << endl;	// part of str, default is the first character of str
	cout << str2 << endl;	// str itself
	cout << &str2 << endl;	// address of str

	return 0;
}
