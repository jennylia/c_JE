#include<stdio.h>

int main(){
  int i;

  char char_arr[3] = {'a', 'b', 'c'};
  int int_arr[3] = {1,2,3};

  void *c_p = (void*) char_arr;
  void *i_p = (void*) int_arr;

  for (i = 0; i < 3; i ++){
    printf("interger loop pointer %p, contains %d\n", i_p, *((int * ) i_p));
    i_p = (void*) ((int * ) i_p + 1); 
  }
  for (i = 0; i < 3; i ++){
    printf("char loop pointer %p, contains %c\n", c_p, *((char * )c_p));
    c_p++;
  }
}
