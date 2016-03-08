#include<stdlib.h>
#include <stdio.h>

int global_var;
int global_initialized_var = 5;

void function(){
  int stack_var; //
  printf("the stack-var is at %p\n", &stack_var);
}

int main(){
  int stack_var;
  printf("the main's stack-var is at %p\n", &stack_var);

  static int bss;
  static int static_main_int = 2;
  int *heap_var_ptr;

  heap_var_ptr = (int *) malloc(4);

  //these are in the data seg
  printf("in the data is global _initialized %p\n", & global_initialized_var);
  printf("static initialized var %p\n", &static_main_int);

  //in the bss
  printf("in the bss are the bss %p\n", &bss);

  // in the heap
  printf("in the heap is my heap_var_ptr %p\n", heap_var_ptr); 

  //in the stack
  printf("in the stack of main %p\n", stack_var);
}
