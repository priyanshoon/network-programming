#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    // creating a socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int connection_status = connect(network_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    // check for error with connection
    if (connection_status == -1) {
        printf("There was an error while making the connection to the remote socket\n");
    }

    // recieve the data from socket
    char server_respond[256];
    recv(network_socket, &server_respond, sizeof(server_respond), 0);

    // print out the server's respond
    printf("the server sent the data : %s \n", server_respond);

    // close the socket
    close(network_socket);
    return 0;
}
