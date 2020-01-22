// TestBounce.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	int x = 0, y = 5;
	int v_x = 1, v_y = 1;
	int left = 0, top = 0;
	int right = 20, down = 40;
	while (1)
	{
		x = v_x + x;
		y = v_y + y;
		system("cls"); // clear the screen
		for (int i = 0; i < x; i++)
		{
			printf("\n");
		}
		for (int j = 0; j < y; j++)
		{
			printf(" ");
		}
		printf("o");
		printf("\n");
		if (y == top || y == down)
		{
			v_y = -1 * v_y;
		}
		if (x == right || x == left)
		{
			v_x = -1 * v_x;
		}

	}
	return 0;
}