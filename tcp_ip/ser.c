#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
void main()
{
    int serv,client,len;
    char buffer[1024];
    struct sockaddr_in servaddr, clientaddr;
    serv=socket(AF_INET,SOCK_STREAM,0);
    servaddr.sin_port=htons(1028);
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    servaddr.sin_family=(AF_INET);

    bind(serv,(struct sockaddr*)&servaddr , sizeof(servaddr));
    listen(serv,3);
    client=accept(serv,(struct sockaddr*)&clientaddr , &len);

    while(1)
    {
        int n=read(client,buffer,1024);
        buffer[n]='\0';
        printf("recieved message : %s",buffer);
        printf("\nenter message to sent : ");
        scanf("%s",buffer);
        send(client,buffer,strlen(buffer),0);
    }
}