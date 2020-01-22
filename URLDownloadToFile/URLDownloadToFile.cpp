// URLDownloadToFile.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "URLDownloadToFile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一のアプリケーション オブジェクトです。

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// MFC を初期化して、エラーの場合は結果を印刷します。
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			_tprintf(_T("致命的なエラー: MFC の初期化ができませんでした。\n"));
			nRetCode = 1;
		}
		else
		{
			string url = "https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1570595895021&di=de36da99ed7a969566493d1809cde39a&imgtype=0&src=http%3A%2F%2Fwx1.sinaimg.cn%2Fcrop.0.0.719.405%2F775c7a73ly1fxp9yf670aj20k00b9gn4.jpg";
			size_t len = url.length();
			int nmlen = MultiByteToWideChar(CP_ACP, 0, url.c_str(), len + 1, NULL, 0);
			wchar_t* buffer = new wchar_t[nmlen];
			MultiByteToWideChar(CP_ACP, 0, url.c_str(), len + 1, buffer, nmlen);
			HRESULT hr = URLDownloadToFile(NULL, buffer,_T("C:\\Users\\lj\\Desktop\\today.jpg"), 0, NULL);
			if (hr == S_OK)
			{
				cout << "ok" << endl;
			}
		}
	}
	else
	{
		_tprintf(_T("致命的なエラー: GetModuleHandle が失敗しました\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
