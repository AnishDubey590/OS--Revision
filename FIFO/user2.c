#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    char *fifo1 = "/tmp/fifo1";  // Reader from user1
    char *fifo2 = "/tmp/fifo2";  // Writer to user1
    mkfifo(fifo1, 0666);
    mkfifo(fifo2, 0666);

    char write_buf[80], read_buf[80];

    while (1) {
        // Read from user1
        int fd_r = open(fifo1, O_RDONLY);
        read(fd_r, read_buf, sizeof(read_buf));
        printf("user1: %s\n", read_buf);
        close(fd_r);

        // Write to user1
        int fd_w = open(fifo2, O_WRONLY);
        fgets(write_buf, sizeof(write_buf), stdin);
        write(fd_w, write_buf, strlen(write_buf) + 1);
        close(fd_w);
    }
    return 0;
}
