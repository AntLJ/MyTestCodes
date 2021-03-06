// Test2048.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>

#include<cstdio>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;
int mp[4][4], score;
bool map[4][4];
bool cal[4][4];
void DeBug()
{
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j)
			cout << map[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j)
			cout << mp[i][j] << " ";
		cout << endl;
	}
}
void Init()
{
	srand(time(NULL));
	int x, y, v, now = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (!map[i][j])
				now++;
	if (now == 0)
		return;
	int cnt = rand() % now, n = 0;
	bool flag = false;
	for (int i = 0; i < 4; ++i) {
		flag = false;
		for (int j = 0; j < 4; ++j)
			if (!map[i][j]) {
				if (cnt == n) {
					x = i;
					y = j;
					flag = true;
					break;
				}
				else
					n++;
			}
		if (flag)
			break;
	}
	v = rand() % 2;
	if (v)
		v = 4;
	else
		v = 2;
	mp[x][y] = v;
	map[x][y] = true;
}
void print()
{
	for (int j = 0; j < 4; ++j)
		printf("----");
	printf("\n");
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			printf("|");
			if (map[i][j] && mp[i][j] != 0) {
				if (score < mp[i][j])
					score = mp[i][j];
				printf("%3d", mp[i][j]);
			}
			else
				printf("   ");

		}
		printf("|\n");
		for (int j = 0; j < 4; ++j)
			printf("----");
		printf("\n");
	}
	printf("↑ : up  ↓ : down  ← : left  → : right\n");
	printf("push 'r' to start a new game\npush 'e' to exit game\n");
}
void MoveUp()
{
	bool canUp = false;
	for (int j = 0; j < 4; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			// if two neighborhood are same, and neither is not zero, for example "4, 4, 0, 0" or "2, 2, 0, 0" or "8, 8, 2, 2" or "0, 16, 16, 0", these are all true
			if (mp[i][j] == mp[i + 1][j] && mp[i][j] != 0)
			{
				canUp = true;
				break;
			}
			// if there are zeros(one or more) upper than the numbers , for example "4, 0, 0, 4" or "4, 0, 4, 0" or "0, 2, 4, 8", these are all true
			if (mp[i][j] == 0 && mp[i + 1][j] != 0)
			{
				canUp = true;
				break;
			}
		}
		if (canUp)
			break;
	}
	if (!canUp)
		return;

	bool flag;
	for (int i = 1; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (!map[i][j])
				continue;
			flag = false;
			int pos = i;
			for (int k = i - 1; k >= 0; --k) {
				if (!map[k][j]) {
					pos = k;
					continue;
				}
				if ((mp[k][j] == mp[i][j]) && (!cal[k][j])) {
					mp[k][j] += mp[i][j];
					cal[k][j] = true;
					flag = true;
					map[i][j] = false;
				}
				else
					break;
			}
			if (!flag) {
				mp[pos][j] = mp[i][j];
				mp[i][j] = 0;
				map[i][j] = false;
				map[pos][j] = true;
			}
		}
	}
	Init();
}
void MoveDown()
{
	bool canDown = false;
	for (int j = 0; j < 4; ++j)
	{
		for (int i = 1; i < 4; ++i)
		{
			// if two neighborhood are same, and neither is not zero, for example "0, 0, 4, 4" or "0, 0, 2, 2" or "8, 8, 2, 2" or "0, 16, 16, 0", these are all true
			if (mp[i][j] == mp[i - 1][j] && mp[i][j] != 0)
			{
				canDown = true;
				break;
			}
			// if there are zeros(one or more) lower than the numbers , for example "4, 0, 0, 4" or "4, 0, 4, 0" or "0, 2, 4, 0", these are all true
			if (mp[i][j] == 0 && mp[i - 1][j] != 0)
			{
				canDown = true;
				break;
			}
		}
		if (canDown)
			break;
	}
	if (!canDown)
		return;

	bool flag;
	for (int i = 2; i >= 0; --i) {
		for (int j = 0; j < 4; ++j) {
			if (!map[i][j])
				continue;
			flag = false;
			int pos = i;
			for (int k = i + 1; k < 4; ++k) {
				if (!map[k][j]) {
					pos = k;
					continue;
				}
				if ((mp[k][j] == mp[i][j]) && (!cal[k][j])) {
					mp[k][j] += mp[i][j];
					cal[k][j] = true;
					flag = true;
					map[i][j] = false;
					mp[i][j] = 0;
				}
				else
					break;
			}
			if (!flag) {
				mp[pos][j] = mp[i][j];
				map[i][j] = false;
				mp[i][j] = 0;
				map[pos][j] = true;
			}
		}
	}
	Init();
}
void MoveRight()
{
	bool flag;
	for (int i = 0; i < 4; ++i) {
		for (int j = 2; j >= 0; --j) {
			if (!map[i][j])
				continue;
			flag = false;
			int pos = j;
			for (int k = j + 1; k < 4; ++k) {
				if (!map[i][k]) {
					pos = k;
					continue;
				}
				if ((mp[i][k] == mp[i][j]) && (!cal[i][k])) {
					mp[i][k] += mp[i][j];
					cal[i][k] = true;
					flag = true;
					map[i][j] = false;
				}
				else
					break;
			}
			if (!flag) {
				mp[i][pos] = mp[i][j];
				map[i][j] = false;
				map[i][pos] = true;
			}
		}
	}
	Init();
}
void MoveLeft()
{
	bool flag;
	for (int i = 0; i < 4; ++i) {
		for (int j = 1; j < 4; ++j) {
			if (!map[i][j])
				continue;
			flag = false;
			int pos = j;
			for (int k = j - 1; k >= 0; --k) {
				if (!map[i][k]) {
					pos = k;
					continue;
				}
				if ((mp[i][k] == mp[i][j]) && (!cal[i][k])) {
					mp[i][k] += mp[i][j];
					cal[i][k] = true;
					flag = true;
					map[i][j] = false;
				}
				else
					break;
			}
			if (!flag) {
				mp[i][pos] = mp[i][j];
				map[i][j] = false;
				map[i][pos] = true;
			}
		}
	}
	Init();
}
bool gameover()
{
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (!map[i][j])
				return false;
			if (i > 0) {
				if (mp[i - 1][j] == mp[i][j])
					return false;
			}
			if (j > 0)
				if (mp[i][j - 1] == mp[i][j])
					return false;
		}
	}
	return true;
}
void Lose()
{
	char ch;
	system("cls");
	printf("*******************\n");
	printf("**** GAME OVER ****\n");
	printf("**** SCORE:%3d ****\n", score);
	printf("*******************\n\n");
	printf("Push any button to continue\n");
	ch = _getch();
	return;
}
void Win()
{
	char ch;
	system("cls");
	printf("*******************\n");
	printf("**** YOU  WIN! ****\n");
	printf("*******************\n\n");
	printf("Push any button to continue\n");
	ch = _getch();
	return;
}
void start()
{
	system("cls");
	printf("********************\n");
	printf("* game start glhf~ *\n");
	printf("********************\n");
	int x = 5e8;
	bool flag = false;
	while (x--);
	memset(mp, 0, sizeof(mp));
	memset(map, false, sizeof(map));
	score = 0;
	char ch;
	Init();
	while (!gameover())
	{
		memset(cal, false, sizeof(cal));
		system("cls");
		print();
		DeBug();
		ch = _getch();
		switch (ch)
		{
		case 72:MoveUp(); break;
		case 80:MoveDown(); break;
		case 75:MoveLeft(); break;
		case 77:MoveRight(); break;
		case 'e':exit(0);
		case 'r':return;
		}
		if (score >= 2048) {
			flag = true;
			break;
		}
	}
	if (flag)
		Win();
	else
		Lose();
	return;
}

int main()
{
	system("title yourname");
	char ch;
	while (1)
	{
		system("cls");
		printf("push ENTER to start game\nESC to exit\n");
		ch = _getch();
		if (ch == 13)
			start();
		else if (ch == 27)
			break;
	}
	return 0;
}
