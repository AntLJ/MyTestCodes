// Test2017MainProcessConsole.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int main(int argc, char*argv[])
{
	//LPTSTR 与 wchar_t* 等价(Unicode环境下)
	LPTSTR cWinDir = new TCHAR[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, cWinDir);

	LPTSTR sConLin = wcscat(cWinDir, L"\\Test2017Sub.exe a b c d");
	//LPTSTR sConLin = wcscat(cWinDir, L"\\SysMets1.exe");

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));

	//创建一个新进程
	if (CreateProcess(
		NULL,		//	指向一个NULL结尾的、用来指定可执行模块的宽字节字符串
		sConLin,	//	命令行字符串
		NULL,		//	指向一个SECURITY_ATTRIBUTES结构体，这个结构体决定是否返回的句柄可以被子进程继承。
		NULL,		//	如果lpProcessAttributes参数为空（NULL），那么句柄不能被继承。<同上>
		false,		//	指示新进程是否从调用进程处继承了句柄。 
		0,			//	指定附加的、用来控制优先类和进程的创建的标 = 0
					//	CREATE_NEW_CONSOLE	新控制台打开子进程
					//	CREATE_SUSPENDED	子进程创建后挂起，直到调用ResumeThread函数
		NULL,		//	指向一个新进程的环境块。如果此参数为空，新进程使用调用进程的环境
		NULL,		//	指定子进程的工作路径
		&si,		//	决定新进程的主窗体如何显示的STARTUPINFO结构体
		&pi			//	接收新进程的识别信息的PROCESS_INFORMATION结构体
	))
	{
		cout << "create process success" << endl;

		// 下面两行关闭句柄，解除本进程和新进程的关系，不然有可能不小心调用TerminateProcess函数关掉子进程
		// CloseHandle(pi.hProcess);
		// CloseHandle(pi.hThread);
	}
	else {
		cerr << "failed to create process" << endl;
	}

	Sleep(10000);

	//终止子进程
	TerminateProcess(pi.hProcess, 300);

	//终止本进程，状态码
	ExitProcess(1001);

	return 0;
}
