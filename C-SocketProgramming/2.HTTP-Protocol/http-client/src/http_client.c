#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <arpa/inet.h> // functions to convert network address

#include "http_client.h"

int http_client_start(int argc, char **argv)
{
	(void)argc;

	char *address;
	address = argv[1];

	int client_socket;
	client_socket = socket(AF_INET, SOCK_STREAM, 0);

	// Connect to an address
	struct sockaddr_in remote_address;
	remote_address.sin_family = AF_INET;
	remote_address.sin_port = htons(80); // 80 is standard port to http servers

	inet_aton(address, (struct in_addr *) &remote_address.sin_addr.s_addr); // convert the string (IP) from cmdline to address 

	// Connect soccket to the remote address
	connect(client_socket, (struct sockaddr *) &remote_address, sizeof(remote_address));

	// Vars to hold the request response
	char request[] = "GET / HTTP/1.1\r\n\r\n";
	char response[4096];

	send(client_socket, request, sizeof(request), 0);

	recv(client_socket, &response, sizeof(response), 0);

	printf("response from the server: %s\n", response);

	close(client_socket);

	return 0;
}
