// TestAtexit.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
#include "stdafx.h"
#include <iostream>
using namespace std;

int atexit(void (*)(void));
void fn1(void), fn2(void), fn3(void), fn4(void);

int _tmain(void)
{
	atexit(fn1);
	atexit(fn2);
	atexit(fn3);
	atexit(fn4);
	printf("This is executed first.\n");
	return 0;
}

void fn1()
{
	printf("next.\n");
}
void fn2()
{
	printf("execute \n");
}
void fn3()
{
	printf("is \n");
}
void fn4()
{
	printf("This \n");
}
