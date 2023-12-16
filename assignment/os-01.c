/*
   Write program to implement FCFS scheduling algorithm
*/

/* ALGO
1. Initialize:
1.1 Set the current time to 0.
1.2 Create a queue to hold the processes.
2. Input:
2.1 Receive a list of processes with their arrival times and burst times.
2.2 Sort the processes based on their arrival times.
3. Execution:
3.1 While there are processes in the queue:
3.2 Dequeue the process from the front of the queue.
3.3 Execute the process until completion.
3.4 Update the current time to reflect the completion of the process.
4. Output:
4.1 Display the turnaround time and waiting time for each process.
4.2 Calculate and display the average turnaround time and average waiting time.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int JOB_COUNT = 0;
typedef struct Job {
    int PID, AT, BT, CT, TAT, WT;
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
    printf("[FCFS CPU SCHEDULING]\n");
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
        arr[i].CT = -1;
        arr[i].WT = -1;
        arr[i].TAT = -1;
    }
}

void display(Job arr[]){
    printf("%-8s%-12s%-12s%-12s%-12s%-12s\n", "PID", "AT (ms)", "BT (ms)", "CT (ms)", "TAT (ms)", "WT (ms)");
    for(int i = 0; i < JOB_COUNT; i++){
        printf("PS%-6d%-12d%-12d%-12d%-12d%-12d\n", arr[i].PID, arr[i].AT, arr[i].BT, arr[i].CT, arr[i].TAT, arr[i].WT);
    }
}

void sort(Job arr[]){
    Job tmp;
    for(int i = 0; i < JOB_COUNT; i++){
        for(int j = i; j < JOB_COUNT; j++){
            if(arr[i].AT <= arr[j].AT) continue;
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
[FCFS CPU SCHEDULING]
[PS1] Enter arrival time : 1
[PS1] Enter Burst time : 5
[PS2] Enter arrival time : 1
[PS2] Enter Burst time : 4
[PS3] Enter arrival time : 1
[PS3] Enter Burst time : 3
[PS4] Enter arrival time : 5
[PS4] Enter Burst time : 6
[PS5] Enter arrival time : 0
[PS5] Enter Burst time : 3
PID     AT (ms)     BT (ms)     CT (ms)     TAT (ms)    WT (ms)
PS5     0           3           3           3           0
PS2     1           4           7           6           2
PS3     1           3           10          9           6
PS1     1           5           15          14          9
PS4     5           6           21          16          10
Avg. WT : 5.40 ms
Avg. TAT : 9.60 ms
*/

/* OUTPUT
Enter job count : 4
[FCFS CPU SCHEDULING]
[PS1] Enter arrival time : 0
[PS1] Enter Burst time : 4
[PS2] Enter arrival time : 1
[PS2] Enter Burst time : 4
[PS3] Enter arrival time : 0
[PS3] Enter Burst time : 2
[PS4] Enter arrival time : 1
[PS4] Enter Burst time : 5
PID     AT (ms)     BT (ms)     CT (ms)     TAT (ms)    WT (ms)
PS1     0           4           4           4           0
PS3     0           2           6           6           4
PS2     1           4           10          9           5
PS4     1           5           15          14          9
Avg. WT : 4.50 ms
Avg. TAT : 8.25 ms
*/
