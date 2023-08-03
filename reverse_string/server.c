#include<stdio.h>
#include <unistd.h>
#include<string.h>
#include <netinet/in.h>
 #include <arpa/inet.h>

int main()
{
int server,client;
char buffer[1024];
char s[1024];
int l;
int PORT=1026;
struct sockaddr_in servaddr,clientaddr;
int addrlen = sizeof(clientaddr);
server=socket(AF_INET,SOCK_STREAM,0);
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
servaddr.sin_port = htons( PORT );
int b=bind(server,(struct sockaddr*)&servaddr,sizeof(servaddr));
listen(server,3);
client=accept(server,(struct sockaddr*)&clientaddr,&addrlen);
printf("connected");
while(1)
{
  int n= read(client,buffer,1023);
  buffer[n]='\0';
  printf("received : %s\n",buffer);
  l=strlen(buffer);
  if (strcmp(buffer,"stop")==0)
  break;
  int c=0;
  while(l!=0)
  {
    l--;
    s[c]=buffer[l];
    c++;
  }
  s[c]='\0';
  send(client,s,strlen(s),0);
}
	
	
}
