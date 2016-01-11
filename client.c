#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
int main()
{
    /*Create a socket*/
    int network_socket=socket(AF_INET, SOCK_STREAM,0);
    struct sockaddr_in server_address;
    server_address.sin_family=AF_INET;
    server_address.sin_port=htons(9002);
    server_address.sin_addr.s_addr=INADDR_ANY;
    
    int connection_status=connect(network_socket, &server_address, sizeof(server_address));
   if(connection_status==-1)
    {
        printf("Error making a connection on Clientside");
    }

    /*Server's response*/
    char server_resp[256];
    recv(network_socket,&server_resp,sizeof(server_resp),0);
    
    /*Servers Response Print*/
    printf("\n Message from Server: %s",server_resp);
    close(network_socket);
    return 0; 
}
