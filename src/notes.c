#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>

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

// (IPv6 only--see struct sockaddr_in and struct in_addr for IPv4)
struct in6_addr {
    unsigned char s6_addr;
};

// (IPv6 only--see struct sockaddr_in and struct in_addr for IPv4)
struct sockaddr_in6 {
    u_int16_t sin6_family; // IPv6
    u_int16_t sin6_port; // Port number
    u_int16_t sin6_flowinfo;
    struct in6_addr sin6_addr;
    u_int32_t sin6_scope_id;
};

struct sockaddr_storage {
    sa_family_t ss_family; // address family

    // all this is padding
    char __ss_pad1[_SS_PAD1SIZE];
    int64_t __ss_align;
    char __ss_pad2[_SS_PAD2SIZE];
};

struct sockaddr_in sa;
struct sockaddr_in6 sa6;

inet_pton(AF_INET, "10.12.110.56", &(sa.sin_addr)); // IPv4
inet_pton(AF_INET6, "2001:db8:63b3:1::3490", &(sa6.sin6_addr)); // IPv6


int main(void) {
    // TODO
    printf("Network Programming!\n");
}
