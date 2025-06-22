#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

int main() {
    struct stat statbuf;
    char dirpath[256];

    getcwd(dirpath, sizeof(dirpath));  // Get current working directory
    DIR *dir = opendir(dirpath);       // Open current directory

    if (dir == NULL) {
        perror("opendir failed");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (stat(entry->d_name, &statbuf) == -1) {
            perror("stat failed");
            continue;
        }

        printf("File Name: %s\n", entry->d_name);
        printf("Is Directory: %d\n", S_ISDIR(statbuf.st_mode));
        printf("Size: %ld bytes\n", statbuf.st_size);
        printf("Last Modified: %ld\n", statbuf.st_mtime);
        printf("Last Accessed: %ld\n", statbuf.st_atime);
        printf("Device: %ld\n", statbuf.st_dev);
        printf("Inode: %ld\n\n", statbuf.st_ino);
    }

    closedir(dir);
    return 0;
}
