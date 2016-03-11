#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
  char *s; //getting a string
  int *i; // for int
  int mem_size = 20; //arg size
  int size;
  
  if (argc >= 2){
    mem_size = atoi(argv[1]);
  /*  if (size > mem_size){
      printf("that's kinda big, I'm setting it to %d\n", mem_size);
    }else{
      mem_size = size;
    }*/
  }

  printf("I just allocated %d butes of memory on the heap for you\n", mem_size);


  s = (char*) malloc(mem_size);
  if (s == NULL){
    printf("too full\n");
    exit(-1);
  }

  strcpy(s, "tis the season");

  printf("s (%p), --> '%s' \n", s, s); // char pointers are a bit different

  
  printf("BTW I'm just gonna put your argument into somewhere in the heap too\n");
  i = (int*) malloc(4);
  *i = size;

  printf("i (%p), --> '%d' \n", i, *i); // 
  free(s);

  printf("I reallocate some stuffi\n");
  s = (char*) malloc(mem_size);

  strcpy(s, "Again tis the season");

  printf("s (%p), --> '%s' \n", s, s); // char pointers are a bit different


  free(s);
  free(i);
}
