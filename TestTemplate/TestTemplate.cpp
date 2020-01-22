// TestTemplate.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

/*************************************************************************
 * these two lines below are equal
 *************************************************************************/
// template <class identifier> function_declaration;
// template <typename identifier> function_declaration;

/*************************************************************************
 * function template
 *************************************************************************/
template <class GenericType> GenericType getMax(GenericType a, GenericType b)
{
	return (a > b ? a : b);
}

// usually we use T instead of GenericType, because T is shorter, and it is a more important mark of template
template <class T>
T getMin(T a, T b)	// declaration of the function can be in an new line
{
	return (a < b ? a : b);
}


/*************************************************************************
 * class template
 *************************************************************************/
template <class T>
class pair1
{
	T values[2];
public:
	pair1(T first, T second)
	{
		values[0] = first;
		values[1] = second;
	}
	T getMax2();
};

template <class T>
T pair1<T>::getMax2()
{
	T retval;
	retval = (value1 > value2 ? value1 : value2)
	return retval;
}


/*************************************************************************
 * template specialization
 * template<> class class_name <type>
 *************************************************************************/
template<class T> class pair2
{
	T value1, value2;
public:
	pair2(T first, T second)
	{
		value1 = first;
		value2 = second;
	}
	T module() {return 0;}
};

template<>
class pair2<int>
{
	int value1, value2;
public:
	pair2(int first, int second)
	{
		value1 = first;
		value2 = second;
	}
	int module2();
};

int pair2<int>::module2()
{
	return (value1%value2);
}


/*************************************************************************
 * parameter of template
 *************************************************************************/
template <class T, int N>
class array
{
	T memBlock[N];
public:
	void setMember(int x, T value);
	T getMember(int x);
};

template<class T, int N>
void array<T, N>::setMember(int x, T value)
{
	memBlock[x] = value;
}

template<class T, int N>
T array<T, N>::getMember(int x)
{
	return memBlock[x];
}

// we can set default value for the template parameters, just like the function parameters' default value
//template<class T>           // most commonly used: one class parameter
//template<class T, class U>  // two class parameters
//template<class T, int N>    // one class and an integer
//template<class T = char>    // has one default value(type)
//template<int Tfunc(int)>    // parameter is a function



/*************************************************************************
 * template and multiple-file project
 *************************************************************************/

// the implementation(declaration) of function template or class template and its prototype must be in the same file
// it means we should not save the interface in a single file, instead we should put the interface and implement in the same file that uses the template



/*************************************************************************
 * main function
 *************************************************************************/
int _tmain(int argc, _TCHAR* argv[])
{
	// test of function template
	int x = 1, y = 2;
	int bigger  = getMax<int>(x, y);
	int smaller = getMin(x, y);	// <int> can be omitted



	// test of class template
	pair1<int>    myInt(115, 36);
	pair1<float>  myfloat(3.0f, 2.18f);


	// test of template specialization
	pair2<int>   myints(100, 75);
	pair2<float> myfloats(100.0f, 75.0f);
	cout << myints.module2() << endl;
	// cout << myfloats.module2() << endl;	// error:module2 is not member of pair2<float>

	// test of template parameters
	array<int, 5>   myArrayInt;
	array<float, 5> myArrayFloat;
	myArrayInt.setMember(0, 100);
	myArrayFloat.setMember(3, 3.1416f);
	cout << myArrayInt.getMember(0) << endl;
	cout << myArrayFloat.getMember(3) << endl;


	return 0;
}

