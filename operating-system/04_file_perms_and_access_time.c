#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    char *filename = argv[1];
    struct stat fileStat;
    if (stat(filename, &fileStat) < 0) {
        perror("Error in stat");
        return 1;
    }
    printf("File Details for: %s\n", filename);
    printf("File Size: %ld bytes\n", fileStat.st_size);
    printf("Owner ID: %d\n", fileStat.st_uid);
    printf("Group ID: %d\n", fileStat.st_gid);
    struct passwd *pw = getpwuid(fileStat.st_uid);
    if (pw != NULL) {
        printf("Owner Name: %s\n", pw->pw_name);
    } else {
        printf("Owner Name: Unknown\n");
    }
    struct group *gr = getgrgid(fileStat.st_gid);
    if (gr != NULL) {
        printf("Group Name: %s\n", gr->gr_name);
    } else {
        printf("Group Name: Unknown\n");
    }
    printf("File Permissions: ");
    printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf((fileStat.st_mode & S_IXOTH) ? "x\n" : "-\n");
    printf("Last Access Time: %s", ctime(&fileStat.st_atime));
    return 0;
}
