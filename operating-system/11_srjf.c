#include <stdio.h>
struct Process {
    int pid; // Process ID
    int arrival_time; // Arrival time
    int burst_time; // Burst time
    int remaining_time; // Remaining burst time
    int completion_time; // Completion time
    int turnaround_time; // Turnaround time
    int waiting_time; // Waiting time
};
void srjf(struct Process processes[], int n) {
    int current_time = 0;
    int completed_processes = 0;
    int min_remaining_time, min_remaining_time_index;
    while (completed_processes < n) {
        min_remaining_time = 99999;
        min_remaining_time_index = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time < min_remaining_time && processes[i].remaining_time > 0) {
                min_remaining_time = processes[i].remaining_time;
                min_remaining_time_index = i;
            }
        }
        if (min_remaining_time_index == -1) {
            current_time++;
            continue;
        }
        processes[min_remaining_time_index].remaining_time--;
        current_time++;
        if (processes[min_remaining_time_index].remaining_time == 0) {
            completed_processes++;
            processes[min_remaining_time_index].completion_time = current_time;
            processes[min_remaining_time_index].turnaround_time = processes[min_remaining_time_index].completion_time - processes[min_remaining_time_index].arrival_time;
            processes[min_remaining_time_index].waiting_time = processes[min_remaining_time_index].turnaround_time - processes[min_remaining_time_index].burst_time;
        }
    }
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time,
               processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }
    printf("\nSRJF Scheduling:\n");
    srjf(processes, n);
    return 0;
}
