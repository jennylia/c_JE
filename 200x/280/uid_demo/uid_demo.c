#include <stdio.h>

int main(){
  printf("real uid: %d\n", getuid());
  printf("effecitve uid: %d\n", geteuid());
}
