// Test4096.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#define ROW 4
#define COL 4
//定义全局变量的好处：在函数之间不用传参
//              缺点：只能完成一次游戏，要想继续玩就必须将数组重置为全0；
int arr[ROW][COL] = { 0 };
int score = 0;

//设置光标的句柄，通俗的说，就是设置光标的位置
void SetCurPos(SHORT x, SHORT y)
{
	HANDLE hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { x, y };
	SetConsoleCursorPosition(hStdOutput, coord);
}
//隐藏光标
void ViewInit(int width, int height)
{
	HANDLE hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(hStdOutput, &info);
	info.bVisible = 0;
	SetConsoleCursorInfo(hStdOutput, &info);
}

//打印
void GamePrint()
{
	printf("SCORE = %d", score);
	SetCurPos(0, 2);
	int i = 0;
	for (i = 0; i < ROW; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			printf(" ");
			for (int j = 0; j < 4; j++)
			{
				printf("-");
			}
		}
		printf("\n");
		for (int k = 0; k < 4; k++)
		{
			printf("|");
			if (arr[i][k])
			{
				printf("%4d", arr[i][k]);
			}
			else
			{
				for (int j = 0; j < 4; j++)
				{
					printf(" ");
				}
			}

		}
		printf("|\n");
		if (i == ROW - 1)
		{
			for (int k = 0; k < 4; k++)
			{
				printf(" ");
				for (int j = 0; j < 4; j++)
				{
					printf("-");
				}
			}
			printf("\n");
		}
	}
	SetCurPos(0, 12);
	printf("上下左右或wsad表示方向\n");
}
//生成随机数
void RandNum() //生成随机数
{
	int x = 0;
	int y = 0;
	do
	{
		x = rand() % 4;
		y = rand() % 4;
	} while (arr[x][y]);
	arr[x][y] = (rand() % 10 ? 2 : 4);
}

//判断是否获胜
int IfWin()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (arr[i][j] == 4096)
			{
				return 1; // 表示赢了
			}
		}
	}
	return 0; //表示继续游戏
}

bool IfLose()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (arr[i][j] == 0)
			{
				return false; // 只要还有一个空着(==0)，则表示可以继续游戏
			}
		}
	}
	for (int i = 0; i < ROW - 1; i++)
	{
		for (int j = 0; j < COL - 1; j++)
		{
			if (arr[i][j] == arr[i][j + 1] || arr[i][j] == arr[i + 1][j])
			{
				return false; // 只要还有任意两个相邻的数是相等的，则表示可以继续游戏
			}
		}
	}

	for (int j = 0; j < COL - 1; j++)
	{
		if (arr[ROW - 1][j] == arr[ROW - 1][j + 1])
		{
			return false; // 最后一列没有判断，所以特别拉出来作判断
		}
	}
	for (int i = 0; i < ROW - 1; i++)
	{
		if (arr[i][COL - 1] == arr[i + 1][COL - 1])
		{
			return false; // 最后一行没有判断，所以特别拉出来作判断
		}
	}

	return true;
}

//向左移
bool MoveLeft()
{
	// 先判断能不能向左了
	bool canLeft = false;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			// if two neighborhood are same, and neither is not zero, for example "4, 4, 0, 0" or "2, 2, 0, 0" or "8, 8, 2, 2" or "0, 16, 16, 0", these are all true
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] != 0)
			{
				canLeft = true;
				break;
			}
			// if there are zeros(one or more) upper than the numbers , for example "4, 0, 0, 4" or "4, 0, 4, 0" or "0, 2, 4, 8" or "0, 0, 0, 2", these are all true
			if (arr[i][j] == 0 && arr[i][j + 1] != 0)
			{
				canLeft = true;
				break;
			}
		}
		if (canLeft)
			break;
	}
	if (!canLeft)
		return false;

	for (int i = 0; i < ROW; i++)
	{
		int j = 1;
		int k = 0;
		for (; j < 4; j++)
		{
			if (arr[i][j] > 0)
			{
				if (arr[i][k] == 0)
				{
					arr[i][k] = arr[i][j];
					arr[i][j] = 0;
				}
				else if (arr[i][k] == arr[i][j])
				{
					arr[i][k] = 2 * arr[i][k];
					score += arr[i][k];
					arr[i][j] = 0;
					k++;
				}
				else
				{
					arr[i][++k] = arr[i][j];
					if (j != k)
					{
						arr[i][j] = 0;
					}
				}
			}
		}
	}
	return true;
}
//向右移
bool MoveRight()
{
	// 先判断能不能向右了
	bool canRight = false;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 1; j < 4; ++j)
		{
			// if two neighborhood are same, and neither is not zero, for example "0, 0, 4, 4" or "0, 0, 2, 2" or "8, 8, 2, 2" or "0, 16, 16, 0", these are all true
			if (arr[i][j] == arr[i][j - 1] && arr[i][j] != 0)
			{
				canRight = true;
				break;
			}
			// if there are zeros(one or more) lower than the numbers , for example "4, 0, 0, 4" or "4, 0, 4, 0" or "0, 2, 4, 0", these are all true
			if (arr[i][j] == 0 && arr[i][j - 1] != 0)
			{
				canRight = true;
				break;
			}
		}
		if (canRight)
			break;
	}
	if (!canRight)
		return false;

	for (int i = 0; i < ROW; i++)
	{
		int j = 2;
		int k = 3;
		for (; j >= 0; j--)
		{
			if (arr[i][j] > 0)
			{
				if (arr[i][k] == 0)
				{
					arr[i][k] = arr[i][j];
					arr[i][j] = 0;
				}
				else if (arr[i][k] == arr[i][j])
				{
					arr[i][k] = 2 * arr[i][k];
					score += arr[i][k];
					arr[i][j] = 0;
					k--;
				}
				else
				{
					arr[i][--k] = arr[i][j];
					if (j != k)
					{
						arr[i][j] = 0;
					}
				}
			}
		}
	}
	return true;
}
//向上移
bool MoveUp()
{
	// 先判断能不能向上了
	bool canUp = false;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			// if two neighborhood are same, and neither is not zero, for example "4, 4, 0, 0" or "2, 2, 0, 0" or "8, 8, 2, 2" or "0, 16, 16, 0", these are all true
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] != 0)
			{
				canUp = true;
				break;
			}
			// if there are zeros(one or more) upper than the numbers , for example "4, 0, 0, 4" or "4, 0, 4, 0" or "0, 2, 4, 8" or "0, 0, 0, 2", these are all true
			if (arr[i][j] == 0 && arr[i + 1][j] != 0)
			{
				canUp = true;
				break;
			}
		}
		if (canUp)
			break;
	}
	if (!canUp)
		return false;

	for (int j = 0; j < COL; j++)
	{
		int k = 0;
		for (int i = 1; i < 4; i++)
		{
			if (arr[i][j] > 0)
			{
				if (arr[k][j] == arr[i][j])
				{
					score += arr[k++][j] *= 2;
					arr[i][j] = 0;
				}
				else if (arr[k][j] == 0)
				{
					arr[k][j] = arr[i][j];
					arr[i][j] = 0;
				}
				else
				{
					arr[++k][j] = arr[i][j];
					if (i != k)
					{
						arr[i][j] = 0;
					}
				}
			}
		}
	}
	return true;
}
//向下移
bool MoveDown()
{
	// 先判断能不能向下了
	bool canDown = false;
	for (int i = 1; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			// if two neighborhood are same, and neither is not zero, for example "0, 0, 4, 4" or "0, 0, 2, 2" or "8, 8, 2, 2" or "0, 16, 16, 0", these are all true
			if (arr[i][j] == arr[i - 1][j] && arr[i][j] != 0)
			{
				canDown = true;
				break;
			}
			// if there are zeros(one or more) lower than the numbers , for example "4, 0, 0, 4" or "4, 0, 4, 0" or "0, 2, 4, 0", these are all true
			if (arr[i][j] == 0 && arr[i - 1][j] != 0)
			{
				canDown = true;
				break;
			}
		}
		if (canDown)
			break;
	}
	if (!canDown)
		return false;

	for (int j = 0; j < COL; j++)
	{
		int i = 2;
		int k = 3;
		for (; i >= 0; i--)
		{
			if (arr[i][j] > 0)
			{
				if (arr[k][j] == 0)
				{
					arr[k][j] = arr[i][j];
					arr[i][j] = 0;
				}
				else if (arr[k][j] == arr[i][j])
				{
					arr[k][j] = 2 * arr[k][j];
					score += arr[k][j];
					arr[i][j] = 0;
					k--;
				}
				else
				{
					arr[--k][j] = arr[i][j];
					if (i != k)
					{
						arr[i][j] = 0;
					}
				}
			}
		}
	}
	return true;
}
//游戏继续
bool GameContinue()
{
	//为了判断在键盘上按下的哪个键
	int ch1 = 0;
	int ch2 = 0;
	while (1)
	{
		if (ch1 = _getch())
		{
			ch2 = _getch();
			if (ch2 == 72 || ch2 == 'w')
			{
				if (!MoveUp())
				{
					return false;
				}
				break;
			}
			if (ch2 == 80 || ch2 == 's')
			{
				if (!MoveDown())
				{
					return false;
				}
				break;
			}
			if (ch2 == 75 || ch2 == 'a')
			{
				if (!MoveLeft())
				{
					return false;
				}
				break;
			}
			if (ch2 == 77 || ch2 == 'd')
			{
				if (!MoveRight())
				{
					return false;
				}
				break;
			}
		}
	}
	return true;
}

void game()
{
	srand((unsigned int)time(NULL));
	ViewInit(20, 10);
	RandNum();
	RandNum();
	GamePrint();
	//arr[0][0] = 4096; //测试退出用的
	while (1)
	{
		if (IfLose())
		{
			printf("GAME OVER!\n");
			return;
		}
		if (IfWin() == 1)
		{
			printf("YOU WIN!\n");
			printf("Do you want to quit?y/n\n");
			// TODO:这里需要添加判断，是否退出的询问，如果输入y则退出, 如果输入n则继续
			if ('y' == _getch())
			{
				exit(0);
			}
			else if ('n' == _getch())
			{
				// do nothing
			}
		}
		if (IfWin() == 0)
		{
			if (GameContinue())
			{
				system("cls");
				RandNum();
				GamePrint();
			}
		}
	}
}

int main()
{
	game();
	system("pause");
	return 0;
}
