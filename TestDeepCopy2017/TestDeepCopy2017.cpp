// TestDeepCopy2017.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
using namespace std;

class CA
{
public:
	CA(int b, const char* cStr)
	{
		a = b;
		str = new char[b];
		strcpy_s(str, strlen(cStr) + 1, cStr);
	}
	CA(const CA& c)
	{
		a = c.a;
		str = new char[a]; // deep copy, [str = c.str] is shallow copy
		if (str)
		{
			strcpy_s(str, strlen(c.str) + 1, c.str);
		}
	}
	void show()
	{
		cout << str << endl;
	}
	~CA()
	{
		delete str;
	}

private:
	int a;
	char *str;
};




int main()
{
	CA A(10, "Hello!");
	CA B = A;
	B.show();




	char pp[] = "hhh";
	char *p;

	p = pp;
	cout << p << endl;
	cout << *p << endl;
	cout << ++*p << endl;

	return 1;
}
