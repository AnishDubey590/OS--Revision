#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    char *fifo1 = "/tmp/fifo1";  // Writer to user2
    char *fifo2 = "/tmp/fifo2";  // Reader from user2
    mkfifo(fifo1, 0666);
    mkfifo(fifo2, 0666);

    char write_buf[80], read_buf[80];

    while (1) {
        // Write to user2
        int fd_w = open(fifo1, O_WRONLY);
        fgets(write_buf, sizeof(write_buf), stdin);
        write(fd_w, write_buf, strlen(write_buf) + 1);
        close(fd_w);

        // Read from user2
        int fd_r = open(fifo2, O_RDONLY);
        read(fd_r, read_buf, sizeof(read_buf));
        printf("user2: %s\n", read_buf);
        close(fd_r);
    }
    return 0;
}
