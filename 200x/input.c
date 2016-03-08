#include<stdio.h>
#include<string.h>

int main(){
  char message[10];
  int  i;
  int *count;

  strcpy(message, "Hello World!");
  printf("repeat how many times?\b");

  scanf("%d", count);

  for (i = 0; i < *count; i ++){
    printf("%3d - %s\n", i, message);
  }

}
