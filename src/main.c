#include <stdio.h>
#include <stdint.h>

// socket address information
struct sockaddr {
    unsigned sa_family; // socket family : IPv4 or IPv6
    char sa_data[14]; // protocol address
};

// address information
struct addrinfo {
    int ai_flags;
    int ai_family; // IPv4 or IPv6
    int ai_socktype; // SOCK_STREAM or SOCK_DGRAM
    int ai_protocol; // TCP or UDP
    size_t ai_addrlen;
    struct sockaddr *ai_addr;
    char *ai_canonname;
    struct addrinfo *ai_next;
};

// (IPv4 only--see struct in6_addr for IPv6)
// Internet address
struct in_addr {
    uint32_t s_addr;
};

// (IPv4 only--see struct sockaddr_in6 for IPv6)
// Socket address internet
struct sockaddr_in {
    short int sin_family;
    unsigned short int sin_port; // port number
    struct in_addr sin_addr; // internet address
    unsigned char sin_zero[8];
};


int main(void) {
    printf("Network Programming!\n");
}
