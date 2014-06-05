#include <winsock2.h>
#include <stdio.h>

#define PORT 124
#define LEN 1024
#pragma commet(lib, "ws2_32.lib")

void main ()
{
	WSADATA wsaData;
	SOCKET s;
	int len;
	sockaddr_in to;
	char buf[LEN];
	
	WSAStartup(MAKEWORD(2,2), &wsaData);
	s = socket(AF_INET, SOCKSTREAM, 0);
	memset (&to, 0, sizeof(to));
	to.sin_family = AF_INET;
	to.sin_addr.s_addr = inet_addr("127.0.0.1");
	int x = connect(s, (sockaddr *)&to, sizeof(to));

	scanf ("%s", buf);
	int y = send (s, buf, strlen(buf), 0);

	len = recv(s, buf, LEN, 0);
	printf ("Recv:%s\n", buf);

	closesocket(s);
	WSACleanup();
}


