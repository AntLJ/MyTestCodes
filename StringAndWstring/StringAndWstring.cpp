// StringAndWstring.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "StringAndWstring.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一のアプリケーション オブジェクトです。

CWinApp theApp;

using namespace std;

// stringからwstringへの変換
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

// wstringからstringへの変換
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
		// MFC を初期化して、エラーの場合は結果を印刷します。
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: 必要に応じてエラー コードを変更してください。
			_tprintf(_T("致命的なエラー: MFC の初期化ができませんでした。\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: アプリケーションの動作を記述するコードをここに挿入してください。
		}
	}
	else
	{
		// TODO: 必要に応じてエラー コードを変更してください。
		_tprintf(_T("致命的なエラー: GetModuleHandle が失敗しました\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
