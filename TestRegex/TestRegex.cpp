// TestRegex.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <regex>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// all match
    regex reg1("\\w+day");
    string s1 = "saturday";
    string s2 = "saturday and sunday";
    smatch r1;
    smatch r2;
    cout << boolalpha << regex_match(s1, r1, reg1) << endl; //true
    cout << boolalpha << regex_match(s2, r2, reg1) << endl; //false
    cout << r1.str() << endl;                               //saturday
    cout << r2.str() << endl;                               //null
    cout << endl;

	// first search
	smatch rr1;
    smatch rr2;
    cout << boolalpha << regex_search(s1, rr1, reg1) << endl; //true
    cout << rr1.str() << endl;                                //saturday
    cout << boolalpha << regex_search(s2, rr2, reg1) << endl; //true
    cout << rr2.str() << endl;                                //saturday
    cout << endl;

	// all search
	cout << "iterator_result：" << endl;
    sregex_iterator it(s2.begin(), s2.end(), reg1);
    sregex_iterator end;
    for(; it != end; ++it)
    {
        cout << it->str() << endl;
        //cout << *it << endl; //err
    }

	// all search 2
    cout << "token_iterator_result：" << endl;
    sregex_token_iterator tit(s2.begin(), s2.end(), reg1);
    sregex_token_iterator tend;
    for(; tit != tend; ++tit)
    {
        cout << tit->str() << endl;
        cout << *tit << endl;
    }

	// child el
	regex reg2("(\\d{1,3}):(\\d{1,3}):(\\d{1,3}):(\\d{1,3})");
    string ip = "0:11:222:333";
    smatch m; 
    regex_match(ip, m, reg2);
    cout << "output：str()" << endl;
    cout << m.str() << endl;      //0:11:222:333
    cout << m.str(1) << endl;     //0
    cout << m.str(2) << endl;     //11
    cout << m.str(3) << endl;     //222
    cout << m.str(4) << endl;     //333

    cout << "output：[i]" << endl; //result same as before
    cout << m[0] << endl;
    cout << m[1] << endl;
    cout << m[2] << endl;
    cout << m[3] << endl;
    cout << m[4] << endl;




	return 0;
}

