#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
  char *s; //getting a string
  int *i; // for int
  int mem_size; //arg size
  int size;
  
  if (argc<2){
    mem_size = 20;
  }else{
    size = atoi(argv[1]);
    if (size > 20){
      printf("that's kinda big, I'm setting it to 20\n");
      mem_size = 20;
    }else{
      mem_size = size;
    }
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

  printf("attempting to create a messy pointer on purpose!\n");
  int** j;
  j = &i;
  printf("j is at %p with val of %p\n", &j, *j);

  int***k;
  k = & j;
  printf("k is at %p with val of %p\n", &k, *k);

  int ****l;
  l = & k;
  printf("l is at %p with val of %p\n", &l, *l);

  printf("try to manipulate i\n");
  **k = (int *) 2;
  printf("i is %d\n", i);

  ***l = (int * ) 3;
  printf("i is %d\n", i);
}
