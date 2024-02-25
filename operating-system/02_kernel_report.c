#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *kernel_version_file = fopen("/proc/version", "r");
    if (kernel_version_file == NULL) {
        perror("Failed to open /proc/version");
        return 1;
    }
    char kernel_version[256];
    if (fgets(kernel_version, sizeof(kernel_version), kernel_version_file) != NULL) {
        printf("Kernel Version: %s", kernel_version);
    } else {
        printf("Failed to read kernel version\n");
    }
    fclose(kernel_version_file);
    FILE *cpu_info_file = fopen("/proc/cpuinfo", "r");
    if (cpu_info_file == NULL) {
        perror("Failed to open /proc/cpuinfo");
        return 1;
    }
    printf("\nCPU Information:\n");
    char line[256];
    while (fgets(line, sizeof(line), cpu_info_file) != NULL) {
        printf("%s", line);
    }
    fclose(cpu_info_file);
    return 0;
}
