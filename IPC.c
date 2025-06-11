#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    char msg[] = "Hello World";
    char buf[50];
    pipe(fd);

    if (fork() > 0) {
        close(fd[0]); // Close read end in parent
        write(fd[1], msg, sizeof(msg));
        close(fd[1]);
    } else {
        close(fd[1]); // Close write end in child
        int n = read(fd[0], buf, sizeof(buf));
        write(1, buf, n); // Write to stdout
        close(fd[0]);
    }
    return 0;
}
