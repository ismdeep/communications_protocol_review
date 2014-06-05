#include <winsock2.h>
#include <stdio.h>

#define PORT 1355
#define LEN 256

int main ()
{
	WSADATA wsaData;
	SOCKET ss;
	sockaddr_in in,from;
	char buf[LEN] = {0};
	int namelen, len;

	WSAStartup(MAKEWORD(2,2), &wsaData);
	ss = socket(AF_INET, SOCK_DGRAM, 0);
	memset (&in, 0, sizeof(in));
	in.sin_family = AF_INET;
	in.sin_port = htons(PORT);
	in.sin_addr.s_addr = inet_addr("127.0.0.1");
	bind(ss, (sockaddr *)&in, sizeof(in));
	memset (&from, 0, sizeof(from));
	namelen = sizeof(from);

	/* recv buf */
	len = recvfrom(ss, buf, LEN, 0, (sockaddr *)&from, &namelen);
	printf ("Recv:%s\n", buf);
	/* send buf */
	sendto(ss, buf, sizeof(buf), 0, (sockaddr *)&from, sizeof(from));

	WSACleanup();
}

