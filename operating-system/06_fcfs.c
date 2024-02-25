#include <stdio.h>
struct Process {
    int pid; // Process ID
    int arrival_time; // Arrival time
    int burst_time; // Burst time
};
void calculateWaitingTime(struct Process processes[], int n, int waiting_time[]) {
    waiting_time[0] = 0; // Waiting time for first process is 0
    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + processes[i - 1].burst_time;
    }
}
void calculateTurnaroundTime(struct Process processes[], int n, int waiting_time[], int turnaround_time[]) {
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + processes[i].burst_time;
    }
}
void calculateAverageTimes(struct Process processes[], int n) {
    int waiting_time[n], turnaround_time[n];
    calculateWaitingTime(processes, n, waiting_time);
    calculateTurnaroundTime(processes, n, waiting_time, turnaround_time);
    int total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }
    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}
void displayProcessDetails(struct Process processes[], int n) {
    printf("Process\tArrival Time\tBurst Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time);
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
    }
    printf("\nProcess details:\n");
    displayProcessDetails(processes, n);
    printf("\nAverage Waiting Time and Turnaround Time:\n");
    calculateAverageTimes(processes, n);
    return 0;
}
