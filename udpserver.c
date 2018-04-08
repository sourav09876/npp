#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
int main(int argc ,char* argv[])
{
 int s = socket(AF_INET,SOCK_DGRAM,0);
 struct sockaddr_in sadd;
 sadd.sin_family = AF_INET;
 sadd.sin_addr.s_addr = htonl(INADDR_ANY);
 sadd.sin_port = htons(1999);
 socklen_t slen = sizeof(sadd);
 bind(s,(struct sockaddr*) &sadd,slen);
 printf("Server connected!\n");
 listen(s,1);
 struct sockaddr_in cadd;
 socklen_t clen = sizeof(cadd);
 printf("Client connected!\n");
 while(1)
 {
  char b[1024];
  recvfrom(s,b,sizeof(b),0,(struct sockaddr*) &cadd,&clen);
  printf("Message : %s",b);
  break;
 }
close(s);
return 0;
}
