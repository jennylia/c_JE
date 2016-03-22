#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "hacking.h"

#define FILENAME "/var/notes"
int print_notes(int, int, char*);
int find_user_note(int, int); // see in file for a note for user
int search_note(char *, char*); // search for keyword function
void fatal (char*); // Fata error handler

int main(int argc, char* argv[]){
  int userid, printing = 1, fd;
  char searchstring[100];

  if (argc>1)
    strcpy(searchstring, argv[1]);
  else
    searchstring[0] = 0;  //search string is empty

  userid = getuid();
  fd = open(FILENAME, O_RDONLY); // open the file for read only
  if (f == -1)
    fatal("in main() while opening file for reading");

  while(printing)
    printing = print_notes(f, userid, searchstring);

  printf("-------- [end of note data] ------- \n");
  close(fd);
}

int print_notes(int fd, int uid, char* searchstring){
  int note_length;
  char byte =0, note_buffer[100];

  note_length = find_user_note(fd, uid);
  if (note_length == -1)
    return 0;

  read(fd, note_buffer, note_length);
  note_buffer[note_length] = 0;

  if (search_note(note_buffer, searchstring))
    printf(note_buffer);
  return 1;
}

int find_user_note(int fd, int user_uid){
  int note_uid = -1;
  unsigned char byte;
  int length;

  while(note_uid != user_uid){
    if (read(fd, &note_uid, 4) != 4){
      return -1; // cannot read 4 butes    
    }

    if (read(fd, &byte, 1)!= 1)
      return -1;

  }
}
