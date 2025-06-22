#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 1000

int main() {
    int fd1, fd2, n;
    char buff[BUFF_SIZE];

    fd1=open("testfile.txt",O_RDONLY);
    n=read(fd1,buff,BUFF_SIZE);
    fd2=open("thinkhardonly.txt",O_WRONLY|O_CREAT );
    write(fd2,buff,n);
    close(fd1);
    close(fd2);
}