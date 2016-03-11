#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

void usage(char *prog_name, char *file_name){
  printf("Usage: %s <data to add to %s>\n", prog_name, file_name);
  exit(0);
}

void fatal (char *); // function for fatal errors
void *ec_malloc(unsigned int); // error checked malloc we saw earlier

int main(int argc, char *argv[]){

  int fd; // file descripter
  char *buffer, *datafile;

  buffer = (char *) ec_malloc(100);
  datafile = (char *) ec_malloc(20);
  strcpy(datafile, "/tmp/notes");

  if (argc < 2)
    usage(argv[0], datafile); //so the argv[0] is prog_name
  
  strcpy(buffer, argv[1]); // copy into the buffer

  printf("DEBUG, buffer @%p: \' %s \'\n", buffer, buffer);
  printf("DEBUG, datafile @%p \' %s \'\n", datafile, datafile);

  strncat(buffer, "\n", 1);//add a new line

  //open file
  fd = open(datafile, O_WRONLY|O_CREAT| O_APPEND, S_IRUSR|S_IWUSR);
  if (fd == -1){
    fatal("in main() while opening file");
  } 
  printf("yay, we opened, fd is %d\n", fd);

  //write some data
  if (write(fd, buffer, strlen(buffer)) == -1)
    fatal("in main() while writting buffer to file");

  if(close(fd) == -1)
    fatal("in main() while closing the file");

  printf("Note has been saved.\n");
  free(buffer);
  free(datafile);
}


void *ec_malloc(unsigned int size){
  void *ptr;
  ptr = malloc(size);
  if (ptr == NULL)
    fatal("in ec_malloc() on memory allocation");
  return ptr;
}

void fatal (char *message){
  char error_message[100];

  strcpy(error_message, "FATAL error!");
  strncat(error_message, message, 83);
  perror(error_message);
  exit(-1);
}
