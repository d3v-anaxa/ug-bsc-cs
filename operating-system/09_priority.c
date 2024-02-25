#include <stdio.h>
struct Process {
    int pid; // Process ID
    int priority; // Priority of the process
    int burst_time; // Burst time
};
void sortByPriority(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_priority_index = i;
        for (int j = i + 1; j < n; j++) {
            if (processes[j].priority < processes[max_priority_index].priority) {
                max_priority_index = j;
            }
        }
        struct Process temp = processes[i];
        processes[i] = processes[max_priority_index];
        processes[max_priority_index] = temp;
    }
}
void priorityScheduling(struct Process processes[], int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int completion_time[n]; // Completion time of each process
    int waiting_time[n]; // Waiting time of each process
    int turnaround_time[n]; // Turnaround time of each process
    sortByPriority(processes, n);
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
    printf("%-12s | %-12s | %-12s | %-12s | %-12s | %-12s\n", "Process", "Priority", "Burst Time", "Completion Time", "Waiting Time", "Turnaround Time");
    for (int i = 0; i < n; i++) {
        printf("%-12d | %-12d | %-12d | %-12d | %-12d | %-12d\n", processes[i].pid, processes[i].priority, processes[i].burst_time,
               completion_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i + 1;
    }
    printf("\nNon-preemptive Priority Scheduling:\n");
    priorityScheduling(processes, n);
    return 0;
}
