#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *meminfo_file = fopen("/proc/meminfo", "r");
    if (meminfo_file == NULL) {
        perror("Failed to open /proc/meminfo");
        return 1;
    }
    printf("Memory Information:\n");
    char line[256];
    while (fgets(line, sizeof(line), meminfo_file) != NULL) {
        printf("%s", line);
    }
    fclose(meminfo_file);
    return 0;
}
