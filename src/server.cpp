#include <iostrem>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 1234


int csend(char* msg){
    int size = strlen(msg);
    
    ssize_t ret = send(cfd, size, 1024);
}

int main(){
    // createsocket struct
	struct sockaddr_in server_info = {0};
	server_info.sin_family = AF_INET;
    server_info.sin_port = htnos(PORT);

    struct sockaddr client_info = {0};

    socklen_t server_info_len = sizeof(server_info);
    socklen_t client_info_len = sizeof(client_info);

    // create socket
    int sfd = socket(AF_INET, SOCK_STREAM, 0);

    if(0 > sfd){
        perror("socket");
        return -1;
    }

    //bind
    if(0 > bind(sfd, (struct sockaddr*)server_info, server_info_len)){
        perror("bind");
        return -1;
    }

    //listen
    if(0 > listen(sfd, 1)){
        perror("listen");
        return -1;
    }
   
   std::cout << "listening... " << std::endl;

   //accept
   int cfd = accept(sfd, &client_infom &client_info_len);
   if(0 > cfd){
       perror("accept")
   }

   std::cout << "Get connection: " << std:endl;

    csend("yoyo");
    
    return 0;
}
