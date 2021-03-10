#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main(){

	/* create a socket */
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0); // Creates the network socket
	// printf("%d\n", network_socket);

	/* specify an address for the socket */
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET; // Address type
	server_address.sin_port = htons(9002); // htons converts the port number
	server_address.sin_addr.s_addr = INADDR_ANY; // Ip Address. INADDR_ANY connects to local network
												 // It will resolve any IP address on the local machine

	int connection_status = connect(network_socket, (struct sockaddr*) &server_address, sizeof(server_address));

	// Check for errors
	if (connection_status == -1) {
		printf("connection_status = %d\n", connection_status);
		printf("Fail to connect\n");
	}

	// Receive data from te server
	char server_response[256];
	recv(network_socket, &server_response, sizeof(server_response), 0); // 0 -> flag

	// print out the server's response
	printf("The server sent the data: %s\n", server_response);

	// Close the socket
	close(network_socket);

	return 0;
}
