#include <iostream>
#include <ws2tcpip.h>
#include <WinSock2.h>
#include <tchar.h>


int main (int argc, char* argv[]) {
SOCKET ClientSocket;
int port = 55555;
WSADATA wsaData;
int wsaerr;
WORD wVersionRequested = MAKEWORD(2, 2);
wsaerr = WSAStartup(wVersionRequested, &wsaData);

if (wsaerr != 0) {
	std::cout << "The WinSock DLL not found!" << std::endl; 
		return 0;
}
else {
	std::cout << "The WinSock dll found!" << std::endl;
	std::cout << "The Status: " << wsaData.szSystemStatus << std::endl;
}
//setting client socket
	ClientSocket = INVALID_SOCKET;
	ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ClientSocket == INVALID_SOCKET) {
		std::cout << "Error at socket(): " << WSAGetLastError << std::endl;
		WSACleanup();
		return 0;
	}
	else {
		std::cout << "Socket() is OK!" << std::endl;
}

	//BOSS: CONNECTION

	sockaddr_in ClientService;
	ClientService.sin_family = AF_INET;
	InetPton(AF_INET,_T("127.0.0.1"),&ClientService.sin_addr.s_addr);
	ClientService.sin_port = htons(port);
	if (connect(ClientSocket,(SOCKADDR*)&ClientService,sizeof(ClientService)) == SOCKET_ERROR){
	std::cout << "Client connect() Failed to connect! "; std::cout << "Status: " << wsaData.szSystemStatus <<std::endl; std::cout << "Error:" << WSAGetLastError << std::endl;
	WSACleanup();
	return 0;
}
	
	else {
		std::cout << "Client: connect() is OK." << std::endl;
		std::cout << "Client: Can start sending and receiving data..." << std::endl;
	}
	system("pause");
	WSACleanup();
	return 0;

}
