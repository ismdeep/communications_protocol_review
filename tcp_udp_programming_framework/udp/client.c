#include <winsock2.h>
#define PORT 1355

int main ()
{
	WSADATA wsaData;
	SOCKET sc;
	sockaddr_in to, fromserver;
	int len, namelen;

	WSAStartup(MAKEWORD(2,2), &wsaData);
	sc = socket(AF_INET, SOCKDGRAM, 0);
	memset (&to, 0, sizeof(to));
	to.sin_family = AF_INET;
	to.sin_port = htons(PORT);
	to.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset (&fromserver, 0, sizeof(fromserver));

	len = sendto(sc, "HELLO", strlen("HELLO"), 0, (sockaddr *)&to, sizeof(to));
	namelen = sizeof(fromserver);
	recvfrom(sc, buf, sizeof(buf), 0, (sockaddr *)&fromserver, &namelen);
	WSACleanup();
}

