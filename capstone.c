#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<pthread.h>
#define PORT 8080
void *handle_client(void *client_socket)
{
int sock = *(int *)client_socket;
char buffer[1024]= {0};
read(sock,buffer,1024);
send(sock,"hello from server",strlen("hello from server"),0);
close(sock);
free(client_socket);
return NULL;
}

