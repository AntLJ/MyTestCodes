// TestPointerAndAddress.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


void increase(void *data, int type)
{
	switch (type)
	{
	case sizeof(char):
		(*((char*)data))++;
		break;
	case sizeof(short):
		(*((short*)data))++;
		break;
	case sizeof(long):
		(*((long*)data))++;
		break;
	default:
		break;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	// ------------------------pointer test1
	/*
	int value1 = 5, value2 = 15;
	int *myPointer;
	myPointer = &value1;
	*myPointer = 10;
	myPointer = &value2;
	*myPointer = 20;
	std::cout << "value1 = " << value1 << " / value2 = " << value2<<std::endl;
	*/


	// ------------------------pointer test2
	/*
	int value1 = 5, value2 = 15;
	int *p1, *p2;
	p1 = &value1;
	p2 = &value2;
	*p1 = 10;
	*p2 = *p1;
	p1 = p2;
	*p1 = 20;
	cout << "value1 = " << value1 << " / value2 = " << value2 <<endl;
	*/


	// ------------------------pointers and arrays
	/*
	int numbers[20];
	int *p;
	p = numbers;
	//numbers = p;	// wrong! numbers is constant pointer,constant means "can not be assigned"

	*p = 10;
	p++;
	*p = 20;
	p = &numbers[2];
	*p = 30;
	p = numbers + 3;
	*p = 40;
	p = numbers;
	*(p + 4) = 50;
	for (int n = 0; n < 5; n++)
	{
		cout << numbers[n] << ", ";
	}
	cout << endl;
	*/


	// ------------------------void pointer
	char a = 5;
	short b = 9;
	long c= 12;
	increase(&a, sizeof(a));
	increase(&b, sizeof(b));
	increase(&c, sizeof(c));

	cout << (int)a << "," << b << "," << c<< endl;


	return 0;
}

