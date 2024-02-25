#include <stdio.h>
#define MAX_PROCESSES 10
struct Process {
    int pid; // Process ID
    int burst_time; // Burst time
};
void sortByBurstTime(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}
void sjf(struct Process processes[], int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int completion_time[MAX_PROCESSES]; // Completion time of each process
    int waiting_time[MAX_PROCESSES]; // Waiting time of each process
    int turnaround_time[MAX_PROCESSES]; // Turnaround time of each process
    sortByBurstTime(processes, n);
    completion_time[0] = processes[0].burst_time;
    waiting_time[0] = 0;
    turnaround_time[0] = completion_time[0];
    for (int i = 1; i < n; i++) {
        completion_time[i] = completion_time[i - 1] + processes[i].burst_time;
        waiting_time[i] = completion_time[i - 1];
        turnaround_time[i] = completion_time[i];
    }
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }
    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;
    printf("Process\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, completion_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i + 1;
    }
    printf("\nSJF Scheduling:\n");
    sjf(processes, n);
    return 0;
}
