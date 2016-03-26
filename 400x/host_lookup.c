#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <netdb.h>

int main(int argc, char *argv[]){
  struct hostent *host_info;
  struct in_addr *address;

  if (argc < 2){
    printf(" you must enter a valide host name\n");
    exit(1);
  }
  host_info = gethostbyname(argv[1]);
  if (host_info == NULL){
    printf("Couldn't look it up\n");
  } else {
    address = (struct in_add *) (host_info -> h_addr);
    printf(" %s has address %s \n", argv[1], inet_ntoa (*address)); 
  }
}
