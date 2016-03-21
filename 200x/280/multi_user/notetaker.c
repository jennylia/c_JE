#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "hacking.h"

void usage(char *prog_name, char *filename){
  printf("Usage: %s <data to add to %s>\n", prog_name, filename);
  exit(0);
}

void fatal(char*); // defined in hacking
void *ec_malloc(unsigned int);

int main(int argc, char* argv[]){
  int userid, fd;
  char *buffer, *datafile;

  buffer = (char *) ec_malloc (100);
  datafile = (char *) ec_malloc(20);
  strcpy(datafile, "/var/notes");

  if (argc < 2){
    usage(argv[0], datafile);
  }

  strcpy(buffer, argv[1]); // copy into buffer
  printf("Debug buffer @ %p: %s\n", buffer, buffer);
  printf("Debug datafile @ %p: %s\n", datafile, datafile);

  //opening the file
  fd = open(datafile, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR| S_IWUSR);
  if (fd == -1)
    fatal ("in main while opening the file, cannot create a fd\n");

  userid = getuid(); //what's your real id

  if (write(fd, &userid, 4) == - 1)
    fatal("in main() while writting \n");

  if (write(fd, buffer, strlen(buffer)) == -1)
    fatal("cannot write buffer");

  write(fd, "\n", 1); // Terminating line
  //closing

  if (close(fd) == -1)
    fatal("canot close");

  printf("saved the note!");
  free(buffer);
  free(datafile);

}
