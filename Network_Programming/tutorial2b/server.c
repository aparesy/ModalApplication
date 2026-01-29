#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>

int server(int argc, char *argv[]){
    // Create the socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // Now bind to the wanted address
    struct sockaddr_in ip4addr;
    ip4addr.sin_family=AF_INET;
    ip4addr.sin_port=htons(atoi(argv[1]));
    if (inet_pton(AF_INET, "127.0.0.0", &ip4addr.sin_addr)){
        printf("Error while entering address\n");
    }
    const struct sockaddr* sa = (struct sockaddr*)&ip4addr; 
    bind(sockfd, sa, sizeof(*sa));

    // Now receive a message
    char buf[10000];
    struct sockaddr* from=malloc(sizeof(struct sockaddr*));
    socklen_t *fromlen=malloc(sizeof(socklen_t));
    int x=recvfrom(sockfd,buf,sizeof(buf),0,from,fromlen);

    if (x==-1){
        printf("Received wrong\n");
    }

    //Print it and send it back
    printf("%s\n", buf);
    sendto(sockfd, buf, sizeof(buf), 0, from, sizeof(*from));

    return 0;
}