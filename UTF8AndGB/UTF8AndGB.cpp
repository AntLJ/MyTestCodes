// UTF8AndGB.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "UTF8AndGB.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// �B��̃A�v���P�[�V���� �I�u�W�F�N�g�ł��B

CWinApp theApp;

using namespace std;


char* UTF8ToGB(const char* utf8)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len+1];
	memset(wstr, 0, len+1);
	MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len+1];
	memset(str, 0, len+1);
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
	if(wstr) delete[] wstr;
	return str;
}

char* GBToUTF8(const char* gb2312)
{
	int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len+1];
	memset(wstr, 0, len+1);
	MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len+1];
	memset(str, 0, len+1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
	if(wstr) delete[] wstr;
	return str;
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// MFC �����������āA�G���[�̏ꍇ�͌��ʂ�������܂��B
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			_tprintf(_T("�v���I�ȃG���[: MFC �̏��������ł��܂���ł����B\n"));
			nRetCode = 1;
		}
		else
		{
			
		}
	}
	else
	{
		_tprintf(_T("�v���I�ȃG���[: GetModuleHandle �����s���܂���\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
