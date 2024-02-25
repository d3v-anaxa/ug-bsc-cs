#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 4096
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }
    char *source_file = argv[1];
    char *destination_file = argv[2];
    int src_fd = open(source_file, O_RDONLY);
    if (src_fd < 0) {
        perror("Error opening source file");
        return 1;
    }
    int dest_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (dest_fd < 0) {
        perror("Error opening destination file");
        close(src_fd);
        return 1;
    }
    char buffer[BUF_SIZE];
    ssize_t bytes_read, bytes_written;
    while ((bytes_read = read(src_fd, buffer, BUF_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination file");
            close(src_fd);
            close(dest_fd);
            return 1;
        }
    }
    if (bytes_read < 0) {
        perror("Error reading from source file");
        close(src_fd);
        close(dest_fd);
        return 1;
    }
    close(src_fd);
    close(dest_fd);
    printf("File copied successfully.\n");
    return 0;
}
