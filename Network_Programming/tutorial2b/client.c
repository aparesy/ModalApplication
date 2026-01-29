#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    while(1){
        printf("Send:");
        char s[100000];
        int x=scanf("%s", s);
        struct sockaddr_in ip4addr;
        ip4addr.sin_family=AF_INET;
        ip4addr.sin_port=htons(atoi(argv[2])); // Todo : replace with parameter
        struct in_addr ad;
        inet_pton(AF_INET, argv[1], &ad.s_addr);
        ip4addr.sin_addr=ad;
        // Maybe zero ip4addr.sin_zero idk
        const struct sockaddr* sa = (struct sockaddr*)&ip4addr;        
        if (x==0){
            printf("Error, input didnt work");
            break;
        }
        else{
            int y=sendto(sockfd, s, strlen(s), 0, sa, sizeof(*sa));
            if (y==0) printf("Error, failed to send\n");
            printf("\n");
        }
    }
    return 0;
}