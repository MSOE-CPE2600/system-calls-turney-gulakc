/************************************************************************
 * Christian Gulak
 * Lab 9
 * CPE2600
 ************************************************************************/
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct stat file_stat;
    if (stat(argv[1], &file_stat) == -1) {
        perror("Error getting file info");
        return 1;
    }

    // File type
    printf("File Type: ");
    if (S_ISREG(file_stat.st_mode)) printf("Regular\n");
    else printf("Other\n");

    // File permissions
    printf("Permissions: ");
    printf("%c", (file_stat.st_mode & S_IRUSR) ? 'r' : '-');
    printf("%c", (file_stat.st_mode & S_IWUSR) ? 'w' : '-');
    printf("%c", (file_stat.st_mode & S_IXUSR) ? 'x' : '-');
    printf("%c", (file_stat.st_mode & S_IRGRP) ? 'r' : '-');
    printf("%c", (file_stat.st_mode & S_IWGRP) ? 'w' : '-');
    printf("%c", (file_stat.st_mode & S_IXGRP) ? 'x' : '-');
    printf("%c", (file_stat.st_mode & S_IROTH) ? 'r' : '-');
    printf("%c", (file_stat.st_mode & S_IWOTH) ? 'w' : '-');
    printf("%c\n", (file_stat.st_mode & S_IXOTH) ? 'x' : '-');

    // File owner
    printf("Owner UID: %d\n", file_stat.st_uid);

    // File size
    printf("Size: %ld bytes\n", file_stat.st_size);

    // Last modified time
    char time_buf[64];
    struct tm *tm_info = localtime(&file_stat.st_mtime);
    strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Last Modified: %s\n", time_buf);

    return 0;
}
