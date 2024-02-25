#include <stdio.h>
#define MAX_PROCESSES 10
struct Process {
    int pid; // Process ID
    int burst_time; // Burst time
    int remaining_time; // Remaining burst time
};
void roundRobin(struct Process processes[], int n, int time_quantum) {
    int remaining_processes = n;
    int current_time = 0;
    while (remaining_processes > 0) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time <= 0) {
                continue;
            }
            int execution_time = (processes[i].remaining_time < time_quantum) ? processes[i].remaining_time : time_quantum;
            current_time += execution_time;
            processes[i].remaining_time -= execution_time;
            printf("Process %d is executed for %d units. Current time: %d\n", processes[i].pid, execution_time, current_time);
            if (processes[i].remaining_time <= 0) {
                remaining_processes--;
            }
        }
    }
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int time_quantum;
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);
    struct Process processes[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].pid = i + 1;
    }
    printf("\nRound Robin Scheduling:\n");
    roundRobin(processes, n, time_quantum);
    return 0;
}
