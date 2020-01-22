// TestMultiThread.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

/*
DWORD WINAPI Fun(LPVOID lpParamter)
{
	for (int i = 0; i < 10; i++)
		cout << "A Thread Fun Display!" << endl;
	return 0L;
}

int main()
{
	HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);
	CloseHandle(hThread);
	for (int i = 0; i < 10; i++)
		cout << "Main Thread Display!" << endl;
	return 0;
}
*/

/*
DWORD WINAPI Fun(LPVOID lpParamter)
{
	for (int i = 0; i < 10; i++)
	{
		cout << "A Thread Fun Display!" << endl;
		Sleep(200);
	}

	return 0L;
}

int main()
{
	HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);
	CloseHandle(hThread);
	for (int i = 0; i < 10; i++)
	{
		cout << "Main Thread Display!" << endl;
		Sleep(500);
	}

	return 0;
}
*/

/*
DWORD WINAPI Fun(LPVOID lpParamter)
{
	for (int i = 0; i < 10; i++)
	{
		//cout << "A Thread Fun Display!" << endl;
		cout << "A Thread Fun Display!\n";
		Sleep(200);
	}

	return 0L;
}

int main()
{
	HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);
	CloseHandle(hThread);
	for (int i = 0; i < 10; i++)
	{
		//cout << "Main Thread Display!" << endl;
		cout << "Main Thread Display!\n";
		Sleep(500);
	}

	return 0;
}
*/


HANDLE hMutex = NULL;//mutex variable
//thread function
DWORD WINAPI Fun(LPVOID lpParamter)
{
	for (int i = 0; i < 10; i++)
	{
		// require a mutex lock
		WaitForSingleObject(hMutex, INFINITE);
		cout << "A Thread Fun Display!" << endl;
		Sleep(100);
		// release mutex lock
		ReleaseMutex(hMutex);
	}
	return 0L;

}

int main()
{
	// create a sub thread
	HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);
	hMutex = CreateMutex(NULL, FALSE, L"screen");
	// close thread handle
	CloseHandle(hThread);
	// main thread's excute location
	for (int i = 0; i < 10; i++)
	{
		// require a mutex lock
		WaitForSingleObject(hMutex, INFINITE);
		cout << "Main Thread Display!" << endl;
		Sleep(100);
		// release mutex lock
		ReleaseMutex(hMutex);
	}
	return 0;
}




