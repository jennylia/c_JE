#include <stdio.h>

int main(){
  char a = 'a';
  printf("%d\n",sizeof(a));
  char *pt_a = &a;
  printf("%d\n",sizeof(pt_a));

  return 0;
}
