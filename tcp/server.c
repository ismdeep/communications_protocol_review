#include <winsock2.h>
#include <stdio.h>
#include <io.h>

#define PORT 124
#define LEN  1024
#pragma comment (lib, "ws2_32.lib")

int main ()
{
	WSADATA wsaData;
	SOCKET sl;
	sockaddr_in in, from;
	int fromlen, i;
	char buf[LEN];
	SOCKET sc;

	WSAStartup (MAKEWORD(2,2), &wsaData);
	memset (&in, 0, sizeof(in));
	in.sin_family = AF_INET;
	in.sin_port   = htons(PORT);
	in.sin_addr.s_addr = inet_addr ("127.0.0.1");
	sl = socket (AF_INET, SOCK_STREAM, 0);
	bind (sl, (sockaddr *)&in, sizeof(in));
	listen(sl, 5);
	memset (&from, 0, sizeof(from));
	fromlen = sizeof(from);
	sc = accept (sl, (sockaddr *)from, &fromlen);

	/* get buf */
	len = recv(ss, buf, LEN, 0);
	printf ("Recv:%s\n", buf);
	/* send buf */
	send (sc, buf, len, 0);

	closesocket(sc);
	closesocket(sl);
	WSACleanup();
}

