/*
   Write program to implement Non-preemptive scheduling algorithm
 */

/* ALGO
1. Initialize an empty ready queue to hold processes.
2. For each process in the input queue:
2.1 Read and store process details such as process ID, burst time, and priority.
2.2 Enqueue the process into the ready queue.
3. Sort the ready queue based on the priority of the processes in descending order. (Process with the highest priority will be at the front of the queue.)
4. Initialize the total waiting time and turnaround time to zero.
5. For each process in the ready queue:
5.1 Dequeue the process from the ready queue.
5.2 Execute the process for its burst time.
5.3 Calculate waiting time and turnaround time for the process.
5.4 Update the total waiting time and total turnaround time.
6. Calculate the average waiting time and average turnaround time:
6.1 Average Waiting Time = Total Waiting Time / Number of Processes
6.2 Average Turnaround Time = Total Turnaround Time / Number of Processes
7. Display the average waiting time and average turnaround time.
8. End.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int JOB_COUNT = 0;
typedef struct Job {
    int PID, AT, BT, CT, TAT, WT, Priority;
} Job;

void create_and_get_table(Job[]);
void set_at_bt_rands(Job[]);
void set_at_bt_man(Job[]);
void display(Job[]);
void sort(Job[]);
void set_wt(Job[]);
void set_tat(Job[]);
void set_ct(Job[]);
float get_avg_wt(Job[]);
float get_avg_tat(Job[]);
void get_gantt_chart(Job[]);

int test_1(){
    srand(time(0));
    printf("Enter job count : ");
    scanf("%d", &JOB_COUNT);
    Job arr[JOB_COUNT];
    printf("[NON-PREEMPTIVE PRIORITY CPU SCHEDULING]\n");
    create_and_get_table(arr);
    return 0;
}

void create_and_get_table(Job arr[]){
    set_at_bt_man(arr);
    sort(arr);
    set_wt(arr);
    set_tat(arr);
    set_ct(arr);
    display(arr);
    printf("Avg. WT : %.2lf ms\n", get_avg_wt(arr));
    printf("Avg. TAT : %.2lf ms\n", get_avg_tat(arr));
}

void set_at_bt_rands(Job arr[]){
    for(int i = 0; i < JOB_COUNT; i++){
        arr[i].PID = i+1;
        arr[i].AT = rand() % 10;
        arr[i].BT = rand() % 20;
        arr[i].CT = -1;
        arr[i].WT = -1;
        arr[i].TAT = -1;
    }
}

void set_at_bt_man(Job arr[]){
    int tmp;
    for(int i = 0; i < JOB_COUNT; i++){
        arr[i].PID = i+1;
        printf("[PS%d] Enter arrival time : ", arr[i].PID);
        scanf("%d", &tmp);
        arr[i].AT = tmp;
        printf("[PS%d] Enter Burst time : ", arr[i].PID);
        scanf("%d", &tmp);
        arr[i].BT = tmp;
        printf("[PS%d] Enter Priority : ", arr[i].PID);
        scanf("%d", &tmp);
        arr[i].Priority = tmp;
        arr[i].CT = -1;
        arr[i].WT = -1;
        arr[i].TAT = -1;
    }
}

void display(Job arr[]){
    printf("%-8s%-12s%-12s%-12s%-12s%-12s%-12s\n", "PID", "Priority" ,"AT (ms)", "BT (ms)", "CT (ms)", "TAT (ms)", "WT (ms)");
    for(int i = 0; i < JOB_COUNT; i++){
        printf("PS%-6d%-12d%-12d%-12d%-12d%-12d%-12d\n", arr[i].PID, arr[i].Priority, arr[i].AT, arr[i].BT, arr[i].CT, arr[i].TAT, arr[i].WT);
    }
}

void sort(Job arr[]){
    Job tmp;
    for(int i = 0; i < JOB_COUNT; i++){
        for(int j = i; j < JOB_COUNT; j++){
            if(arr[i].AT < arr[j].AT) continue;
            if(arr[i].AT == arr[j].AT && arr[i].Priority <= arr[j].Priority) continue;
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
}

void set_wt(Job arr[]){
    int timeline = 0;
    for(int i = 0; i < JOB_COUNT; i++){
        if(timeline <= arr[i].AT){
            timeline = arr[i].AT + arr[i].BT;
            arr[i].WT = 0;
        } else {
            arr[i].WT = timeline - arr[i].AT;
            timeline += arr[i].BT;
        }
    }
}

void set_tat(Job arr[]){
    for(int i = 0; i < JOB_COUNT; i++){
        arr[i].TAT = arr[i].WT + arr[i].BT;
    }
}

void set_ct(Job arr[]){
    for(int i = 0; i < JOB_COUNT; i++){
        arr[i].CT = arr[i].TAT + arr[i].AT;
    }
}

float get_avg_wt(Job arr[]){
    float res = 0;
    for(int i = 0; i < JOB_COUNT; i++)
        res += arr[i].WT;
    res = res / JOB_COUNT;
    return res;
}

float get_avg_tat(Job arr[]){
    float res = 0;
    for(int i = 0; i < JOB_COUNT; i++)
        res += arr[i].TAT;
    res = res / JOB_COUNT;
    return res;
}

int main(void){
    return test_1();
}

/* OUTPUT
Enter job count : 5
[NON-PREEMPTIVE PRIORITY CPU SCHEDULING]
[PS1] Enter arrival time : 0
[PS1] Enter Burst time : 4
[PS1] Enter Priority : 4
[PS2] Enter arrival time : 0
[PS2] Enter Burst time : 10
[PS2] Enter Priority : 2
[PS3] Enter arrival time : 1
[PS3] Enter Burst time : 4
[PS3] Enter Priority : 1
[PS4] Enter arrival time : 1
[PS4] Enter Burst time : 1
[PS4] Enter Priority : 4
[PS5] Enter arrival time : 0
[PS5] Enter Burst time : 1
[PS5] Enter Priority : 3
PID     Priority    AT (ms)     BT (ms)     CT (ms)     TAT (ms)    WT (ms)
PS2     2           0           10          10          10          0
PS5     3           0           1           11          11          10
PS1     4           0           4           15          15          11
PS3     1           1           4           19          18          14
PS4     4           1           1           20          19          18
Avg. WT : 10.60 ms
Avg. TAT : 14.60 ms
*/

/* OUTPUT
Enter job count : 3
[NON-PREEMPTIVE PRIORITY CPU SCHEDULING]
[PS1] Enter arrival time : 0
[PS1] Enter Burst time : 5
[PS1] Enter Priority : 1
[PS2] Enter arrival time : 0
[PS2] Enter Burst time : 2
[PS2] Enter Priority : 2
[PS3] Enter arrival time : 0
[PS3] Enter Burst time : 10
[PS3] Enter Priority : 3
PID     Priority    AT (ms)     BT (ms)     CT (ms)     TAT (ms)    WT (ms)
PS1     1           0           5           5           5           0
PS2     2           0           2           7           7           5
PS3     3           0           10          17          17          7
Avg. WT : 4.00 ms
Avg. TAT : 9.67 ms
*/
