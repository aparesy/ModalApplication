#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main2(int argc, char *argv[]){
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    printf("Send:");
    char s[100000];
    int x=scanf("%s", s);
    struct sockaddr_in ip4addr;
    ip4addr.sin_family=AF_INET;
    ip4addr.sin_port=htons(atoi(argv[2])); 
    struct in_addr ad;
    inet_pton(AF_INET, argv[1], &ad.s_addr);
    const struct sockaddr* sa = (struct sockaddr*)&ip4addr;        
    if (x==0){
        printf("Error, input didnt work");
    }
    else{
        int y=sendto(sockfd, s, strlen(s), 0, sa, sizeof(*sa));
        if (y==-1){
            printf("Failed to send\n");
            return -1;
        }
        printf("\n");
        printf("Read back : ");
        char buf[10000];
        struct sockaddr* from=malloc(sizeof(struct sockaddr*));
        socklen_t* fromlen=malloc(sizeof(socklen_t));
        recvfrom(sockfd,buf, sizeof(buf), 0, from, fromlen);
        printf("\n");
    }
    return 0;
}