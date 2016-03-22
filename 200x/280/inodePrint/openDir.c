#include <fcntl.h>
#include <stdio.h>
int main(){
  FILE *fp;
  char buff[255];
  fp = fopen("/home/x/x5n8/hack/200x/280/rand/toOpen", "r");


  fgets(buff, 255, (FILE*) fp);
  printf("here: %x\n", buff);

  fgets(buff, 255, (FILE*) fp);
  printf("here: %x\n", buff);

  fclose(fp);

  printf("hello world\n");
}
