// Tests2017_Semaphore.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
#include <windows.h>
using namespace std;


HANDLE g_hSemaphore = NULL;                             //声明信号量变量

unsigned long WINAPI Fun(LPVOID lpParamter)
{
	int iRunTime = 0;
	//执行100次跳出
	while (++iRunTime < 100)
	{
		WaitForSingleObject(g_hSemaphore, INFINITE);      //信号量值-1
		cout << "Fun() is running!" << endl;
		ReleaseSemaphore(g_hSemaphore, 1, NULL);          //信号量值+1
		Sleep(10);
	}
	ExitThread(-1);
}

int main()
{
	g_hSemaphore = CreateSemaphore(NULL          //信号量的安全特性
		, 1            //设置信号量的初始计数。可设置零到最大值之间的一个值
		, 1            //设置信号量的最大计数
		, NULL         //指定信号量对象的名称
	);
	if (NULL == g_hSemaphore)
	{
		cout << "create hSemaphore failed! error_code:" << GetLastError() << endl;
		return 0;
	}

	int iRunTime = 0;
	unsigned long ulThreadId = 0;
	//创建一个子线程
	HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, &ulThreadId);

	//执行100次跳出
	while (++iRunTime < 100)
	{
		WaitForSingleObject(g_hSemaphore, INFINITE);   //信号量值-1
		cout << "main() is running, Thread id is " << ulThreadId << endl;
		ReleaseSemaphore(g_hSemaphore, 1, NULL);       //信号量值+1
		Sleep(10);
	}
	system("pause");
	return 0;
}
