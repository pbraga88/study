#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main(){

	char server_message[256] = "You have reached the server!";

	// create the server socket
	int server_socket; 
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	// define the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY; // Resolve any IP address on the local machine

	// bind the socket to our specified IP and port
	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

	// listen for connections
	listen(server_socket, 5); //2nd argument: How many connections can wait for this socket


	int client_socket;
	printf("The server is runnning\n");
	while(1){
		// Accept connections on server_socket
		client_socket = accept(server_socket, NULL, NULL);// NULLs says where the connection is coming from

		// Send the message
		send(client_socket, server_message, sizeof(server_message), 0);
	}
	// Close the socket
	printf("Bye\n");
	close(server_socket);


	return 0;
}
