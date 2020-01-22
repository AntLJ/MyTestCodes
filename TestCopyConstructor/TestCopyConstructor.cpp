// TestCopyConstructor.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

/*
//this -> no this
struct X
{
private:
	int len;
	char *ptr;
public:
	int getLen(){
		return len;
	}
	char * getPtr(){
		return ptr;
	}
	X& set(char *);
	X& cat(char *);
	X& copy(X&);
	void print();
};

X&  X::set(char *pc){
	len = strlen(pc);
	ptr = new char[len];
	strcpy_s(ptr, 20, pc);
	return *this;
}

X&  X::cat(char *pc){
	len += strlen(pc);
	strcat_s(ptr, 20, pc);
	return *this;
}

X&  X::copy(X& x){
	set(x.getPtr());
	return *this;
}

void X::print(){
	cout << ptr << endl;
}
*/

struct X
{
private:
	int len;
	char *ptr;
public:
	int getLen(X * const THIS){
		return THIS->len;
	}
	char * getPtr(X * const THIS){
		return THIS->ptr;
	}
	X& set(X* const, char*);
	X& cat(X* const, char *);
	X& copy(X* const, X&);
	void print(X* const);
};

X&  X::set(X* const THIS, char* pc){
	THIS->len = strlen(pc);
	THIS->ptr = new char[THIS->len];
	strcpy_s(THIS->ptr, 20, pc);
	return *THIS;
}

X&  X::cat(X* const THIS, char *pc){
	len += strlen(pc);
	strcat_s(ptr, 20, pc);
	return *this;
}

X&  X::copy(X* const THIS, X& x){
	THIS->set(THIS, x.getPtr(&x));
	return *THIS;
}

void X::print(X* const THIS){
	cout << THIS->ptr << endl;
}


int main(void)
{
	X xobj1;
	xobj1.set(&xobj1, "abcd").cat(&xobj1, "efgh");
	xobj1.print(&xobj1);

	X xobj2;
	xobj2.copy(&xobj2, xobj1).cat(&xobj2, "ijkl");
	xobj2.print(&xobj2);

	return 0;
}

