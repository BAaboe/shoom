#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>



#define PORT 1234

//plz work

ssize_t ssend(char* msg, int cfd){
    unsigned int size = sizeof(msg);
    char sizeChar[512] {};
    strcpy(sizeChar,std::to_string(size).c_str());
    ssize_t ret = send(cfd, sizeChar, 512, 0);
    ret = send(cfd, msg, size, 0);
    
    return ret;
}

int main(){
    // createsocket struct
	struct sockaddr_in server_info = {0};
	server_info.sin_family = AF_INET;
    server_info.sin_port = htons(PORT);

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
    if(0 > bind(sfd, (struct sockaddr*)&server_info, server_info_len)){
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
   int cfd = accept(sfd, &client_info, &client_info_len);
   if(0 > cfd){
       perror("accept");
   }


   std::cout << "Got connection: " << std::endl;

   ssize_t ret = ssend("yoyo", cfd);
    
   return 0;
}
