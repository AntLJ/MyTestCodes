// PointerToFunction.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>

int addition(int a, int b)
{
	return (a + b);
}

int subtraction(int a, int b)
{
	return (a - b);
}

int times(int length, int hight, int width)
{
	return (length * hight * width);
}

int (*minus)(int, int) = subtraction;

int operation(int x, int y, int (*functocall)(int, int))
{
	int g;
	g = (*functocall)(x, y);
	return (g);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int m, n;
	m = operation(7, 5, addition);
	n = operation(20, m, minus);

	int (*times2)(int, int, int) = times;
	int v = times2(3,4,5);

	std::cout << "m = " << m << ", n = " << n << std::endl;
	return 0;
}

