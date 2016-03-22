#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <string.h>

int main (int argc, char *argv[])
{
    struct stat fileStat;
    int fd=0;
    if ( ( fd = open (argv[1] , O_RDONLY) ) == -1){
        perror ( "open " );
        exit (1) ;
    }

    if(fstat(fd, &fileStat)<0) return 1;

    printf("Information for %s\n",argv[1]);
    printf("---------------------------\n");
    printf("File Size: \t\t%d bytes\n",fileStat.st_size);
    printf("Number of Links: \t%d\n",fileStat.st_nlink);
    printf("File inode: \t\t%d\n",fileStat.st_ino);

    return 0;
}
