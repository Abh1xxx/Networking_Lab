#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
void main()
{
    int client;
    char buffer[1024];
    struct sockaddr_in servaddr,clientaddr;
    client=socket(AF_INET,SOCK_STREAM,0);
    servaddr.sin_port=htons(1028);
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    servaddr.sin_family=(AF_INET);

    connect(client,(struct sockaddr*)&servaddr,sizeof(servaddr));

    while(1)
    {
        printf("enter data : ");
        scanf("%s",buffer);
        send(client,buffer,strlen(buffer),0);
        int n=read(client,buffer,1024);
        buffer[n]='\0';
        printf("\n recived data : %s",buffer);


    }

}