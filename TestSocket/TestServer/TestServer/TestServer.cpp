// TestServer.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>

#include <WINSOCK2.H>

using namespace std;

#include <string>
using std::string;

#pragma comment(lib,"ws2_32.lib")

void main()
{
	// 创建套接字
	WORD myVersionRequest;
	WSADATA wsaData;                    // 包含系统所支持的WinStock版本信息
	myVersionRequest = MAKEWORD(1, 1);  // 初始化版本1.1
	int err;
	err = WSAStartup(myVersionRequest, &wsaData);
	if (!err) {
		printf("socket opened!\n");
	}
	else {
		// 进一步绑定套接字
		printf("socket unopened!");
		return;
	}
	SOCKET serSocket = socket(AF_INET, SOCK_STREAM, 0); // 创建了可识别套接字
	// 需要绑定的参数
	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//ip地址
	addr.sin_port = htons(3000); // 绑定端口
	// 将套接字绑定到指定的网络地址
	// 将地址和套节字绑定
	if (bind(serSocket, (SOCKADDR*)&addr, sizeof(SOCKADDR)) == -1)
	{
		printf("fail to bind.\n");
		exit(1);
	}// 绑定完成

	// 开始监听连接请求
	if (listen(serSocket, 10) == -1)                    // 第二个参数代表能够接收的最多的连接数
	{
		printf("fail to listen.\n");
		exit(1);
	}
	printf("waiting...\n");
	SOCKADDR_IN clientsocket;
	int len = sizeof(SOCKADDR);
	SOCKET serConn;
	// 等待客户端的连接
	serConn = accept(serSocket, (SOCKADDR*)&clientsocket, &len);
	if (serConn == -1)
	{
		printf("fail to accept.\n");
		exit(1);
	}
	cout << "Client " << inet_ntoa(clientsocket.sin_addr) << " connected " << endl;             // 客户端已连接

	/*
	string recvBuf = "";
	while (1)
	{
		char sendBuf[100];
		sprintf(sendBuf, "server : welcome %s to server.", inet_ntoa(clientsocket.sin_addr));
		// 在对应的IP处并且将这行字打印到那里
		send(serConn, sendBuf, strlen(sendBuf) + 1, 0);
		char receiveBuf[100];
		//memset(receiveBuf, 0, sizeof(receiveBuf));
		// 接收客户端传来的信息
		recv(serConn, receiveBuf, strlen(receiveBuf) + 1, 0);
		const char* quit = "quit;";
		// 如果客户端传来了quit信号，则服务端关闭，客户端也关闭
		if (!strcmp(receiveBuf, "quit;")) {
			break;
		}
		if (receiveBuf[strlen(receiveBuf) - 1] == ';')
		{
			printf("%s\n", receiveBuf);
			memset(receiveBuf, 0, sizeof(receiveBuf));
		}
	}
	*/
	
	string recvBuf = "";
	while (1)
	{
		char sendBuf[100] = { "server received your message!" };
		send(serConn, sendBuf, strlen(sendBuf) + 1, 0);
		char receiveBuf[100];
		memset(receiveBuf, 0, sizeof(receiveBuf));
		// 接收客户端传来的信息
		recv(serConn, receiveBuf, strlen(receiveBuf) + 1, 0);
		recvBuf += receiveBuf;
		if (receiveBuf[strlen(receiveBuf) - 1] == ';')
		{
			recvBuf = recvBuf.substr(0, recvBuf.length() - 1);
			cout << recvBuf << endl;

			// 如果客户端传来了quit信号，则服务端关闭，客户端也关闭
			if (!strcmp(recvBuf.c_str(), "quit"))
			{
				break;
			}
			recvBuf = "";
		}
	}
	closesocket(serConn);   //关闭
	WSACleanup();           //释放资源的操作
	exit(1);
}
