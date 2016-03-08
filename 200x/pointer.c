#include<stdio.h>
#include<string.h>

int main(){
  char str_a[20]; // 20 element array
  strcpy(str_a, "Hello World\n");
  char* pointer_a = str_a;

  char* pointer2 = pointer_a + 2;
  printf(pointer2);
  strcpy(pointer2, "you people\n");
  printf(pointer_a);
  return 0;
}
