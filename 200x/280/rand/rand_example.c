#include <stdio.h>
#include <stdlib.h>

int main(){
  int i;
  srand(0);
  printf("random value\n");
  for (i = 0; i < 5; i ++)
    printf("%d\n", rand());

}
