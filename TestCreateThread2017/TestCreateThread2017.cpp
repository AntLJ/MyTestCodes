// TestCreateThread2017.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
#include <Windows.h>

using namespace std;

HANDLE hMutex;

DWORD WINAPI Fun(LPVOID)
{
	while (true)
	{
		WaitForSingleObject(hMutex, INFINITE);
		cout << "sub thread 1" << endl;
		Sleep(2000);
		ReleaseMutex(hMutex);
	}
}

int main()
{
	HANDLE handle1 = CreateThread(NULL, 0, Fun, NULL, 0, NULL);
	hMutex = CreateMutex(NULL, FALSE, L"screen");
	CloseHandle(handle1);

	while (true)
	{
		WaitForSingleObject(hMutex, INFINITE);
		cout << "main thread" << endl;
		Sleep(1000);
		ReleaseMutex(hMutex);
	}

	return 0;
}
