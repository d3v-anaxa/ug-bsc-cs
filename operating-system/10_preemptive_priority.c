#include <stdio.h>
struct Process {
    int pid; // Process ID
    int priority; // Priority of the process
    int arrival_time; // Arrival time
    int burst_time; // Burst time
    int remaining_time; // Remaining burst time
};
void sortByPriority(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}
void preemptivePriorityScheduling(struct Process processes[], int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int completion_time[n]; // Completion time of each process
    int turnaround_time[n]; // Turnaround time of each process
    sortByPriority(processes, n);
    for (int i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time;
    }
    int current_time = 0;
    int completed_processes = 0;
    while (completed_processes < n) {
        int min_priority_index = -1;
        int min_priority = 99999; // Assigning a high value initially
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0 && processes[i].priority < min_priority && processes[i].arrival_time <= current_time) {
                min_priority = processes[i].priority;
                min_priority_index = i;
            }
        }
        if (min_priority_index == -1) {
            current_time++;
            continue;
        }
        processes[min_priority_index].remaining_time--;
        current_time++;
        if (processes[min_priority_index].remaining_time == 0) {
            completion_time[min_priority_index] = current_time;
            turnaround_time[min_priority_index] = current_time - processes[min_priority_index].arrival_time;
            total_waiting_time += turnaround_time[min_priority_index] - processes[min_priority_index].burst_time;
            total_turnaround_time += turnaround_time[min_priority_index];
            completed_processes++;
        }
    }
    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;
    printf("Process\tPriority\tBurst Time\tCompletion Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].priority, processes[i].burst_time,
               completion_time[i], turnaround_time[i]);
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
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i + 1;
    }
    printf("\nPreemptive Priority Scheduling:\n");
    preemptivePriorityScheduling(processes, n);
    return 0;
}
