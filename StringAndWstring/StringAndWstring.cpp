// StringAndWstring.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "StringAndWstring.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// �B��̃A�v���P�[�V���� �I�u�W�F�N�g�ł��B

CWinApp theApp;

using namespace std;

// string����wstring�ւ̕ϊ�
wstring stringToWString(const string& str)
{
	std::wstring wszStr; 
    int nLength = MultiByteToWideChar( CP_UTF8, 0, str.c_str(), -1, NULL, NULL );
    wszStr.resize(nLength);
    LPWSTR lpwszStr = new wchar_t[nLength];
    MultiByteToWideChar( CP_UTF8, 0, str.c_str(), -1, lpwszStr, nLength );
    wszStr = lpwszStr;
    delete [] lpwszStr;
	return wszStr;
}

// wstring����string�ւ̕ϊ�
string wstringToString(const wstring& wstr)
{
	std::string str; 
	int nLength = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, NULL, 0, NULL, NULL); 
    str.resize(nLength);
    LPSTR lpwszStr = new char[nLength];
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, lpwszStr, nLength, NULL, NULL); 
    str = lpwszStr;
    delete [] lpwszStr;
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
			// TODO: �K�v�ɉ����ăG���[ �R�[�h��ύX���Ă��������B
			_tprintf(_T("�v���I�ȃG���[: MFC �̏��������ł��܂���ł����B\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: �A�v���P�[�V�����̓�����L�q����R�[�h�������ɑ}�����Ă��������B
		}
	}
	else
	{
		// TODO: �K�v�ɉ����ăG���[ �R�[�h��ύX���Ă��������B
		_tprintf(_T("�v���I�ȃG���[: GetModuleHandle �����s���܂���\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
