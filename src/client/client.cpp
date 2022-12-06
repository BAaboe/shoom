#include <cstdlib>
#include <iostream>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define PORT 1234

using namespace std;

char* srecv(int fd){
    char size[512] = {0};
    ssize_t recvd = recv(fd, size, 512, 0);
    int isize = atoi(size);
    char *buf = new char[isize];
    recvd = recv(fd, buf, isize, 0);

    return buf;
}


int main(int argc, char *argv[]){

    
    struct  sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    socklen_t server_info_len = sizeof(server_addr);


    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0){
        perror("socket");
        return -1;
    }

    cout << "Connecting" << endl;
    
    if(inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr.s_addr)<=0){
        perror("host");
        return -1;
    }

    int cfd = connect(sock, (struct sockaddr*) &server_addr, server_info_len);
    if(cfd < 0){
        perror("connect");
        return -1;
    }

    char *buf = srecv(sock);
    
    cout << buf << endl;

    delete [] buf;


    close(cfd);

    return 0;
}