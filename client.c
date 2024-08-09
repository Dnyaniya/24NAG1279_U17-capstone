#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#define PORT 8080
int main()
{
int sock=0;
struct sockaddr_in serv_addr;
char *hello = "hello from client";
char buffer[1024]={0};
if((sock = socket(AF_INET,SOCK,STREAM,0))<0)
{
printf("\n socket creation error \n");
return -1;
}
serv_addr.sin_family = AF_INET;
serv_addr.sin_port = htons(PORT);
if(inet_pton(AF_INET,"127.0.0.1",&serv_addr.sin_addr)<=0)
{
printf("\nconnection fail \n");
return -1;
}
send(sock,hello,strlen(hello),0);
printf("hello message sent\n");
read(sock,buffer,1024);
printf("%s\n",buffer);
close(sock);
return 0;
}
