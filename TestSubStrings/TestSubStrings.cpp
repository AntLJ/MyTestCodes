// TestSubStrings.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int sum = 0;
char str[] = "hart";
int length;
char * out;

void doCombine(char in[], char out[], int length, int rec ,int start)
{
	for (int i = start; i < length; i++)
	{
		out[rec] = in[i];
		out[rec + 1] = 0;
		printf("%s\n", out);
		if (i < (length - 1))
		{
			doCombine(in, out, length, rec + 1, i + 1);
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	length  = strlen(str);
	out = (char *)malloc(length + 1);
	doCombine(str, out, length, 0, 0);

	return 0;
}
