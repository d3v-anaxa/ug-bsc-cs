#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    pid_t pid;
    pid = fork(); // Create a new process
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) { // Child process
        printf("Child process executing...\n");
        
        char *args[] = {"lsmem", "--json", NULL};
        execvp(args[0], args);
        fprintf(stderr, "Execution failed\n");
        return 1;
    } else { // Parent process
        printf("Parent process executing...\n");
        wait(NULL);
        printf("Child process finished\n");
        
        printf("Parent process executing different code...\n");
        char *args[] = {"uptime","-p", NULL};
        execvp(args[0], args);
        
        fprintf(stderr, "Execution failed\n");
        return 1;
    }
    return 0;
}
