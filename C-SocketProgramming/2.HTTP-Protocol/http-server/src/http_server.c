#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

#include "http_server.h"

int http_start()
{
	// open .html file and read to response_data
	FILE *html_data;
	html_data = fopen("index.html", "r");

	char response_data[1024];
	fgets(response_data, 1024, html_data);

	char http_header[2048] = "HTTP/1.1 200 OK\r\n\n";
	strcat(http_header, response_data); // Add index to http_header
	
	// Create a socket
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	// Define the address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(8001);
	server_address.sin_addr.s_addr = INADDR_ANY;

	bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

	listen(server_socket, 5);

	int client_socket;

	printf("HTTP Server Running...\n");
	while (1) {
		client_socket = accept(server_socket, NULL, NULL);
		send(client_socket, http_header, sizeof(http_header), 0);
		close(client_socket);
	}

	// close(server_socket);

	return 0;
}
