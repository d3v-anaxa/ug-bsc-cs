/*
   Write program to implement Non-preemptive scheduling algorithm
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum {
    JOB_COUNT = 5
};

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
    Job arr[JOB_COUNT];
    printf("[NON-PREEMPTIVE PRIORITY CPU SCHEDULING]\n");
    create_and_get_table(arr);
    // get_gantt_chart(arr);
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

// TODO: FIX
void get_gantt_chart(Job arr[]){
    int _t = 0;
    printf("Gantt chart :\n");
    for(int i = 0 ; i < JOB_COUNT; i++){
        _t = arr[i].BT * 100 / arr[JOB_COUNT - 1].CT;
        printf(">\033[47;30;01m%s%*d\033[00;00m", "PS", -_t, arr[i].PID );
    }   printf("\n");
}

int main(void){
    return test_1();
}

/* OUTPUT
   [FCFS CPU SCHEDULING]
   PID     AT (ms)     BT (ms)     CT (ms)     TAT (ms)    WT (ms)     
   PS3     0           5           5           5           0           
   PS8     0           5           10          10          5           
   PS4     4           14          24          20          6           
   PS7     5           5           29          24          19          
   PS10    6           9           38          32          23          
   PS9     7           10          48          41          31          
   PS1     7           1           49          42          41          
   PS2     8           18          67          59          41          
   PS6     8           12          79          71          59          
   PS5     9           8           87          78          70          
   Avg. WT : 29.50 ms
   Avg. TAT : 38.20 ms
*/   

/* OUTPUT
   [FCFS CPU SCHEDULING]
   PID     AT (ms)     BT (ms)     CT (ms)     TAT (ms)    WT (ms)     
   PS5     0           8           8           8           0           
   PS1     1           16          24          23          7           
   PS7     2           4           28          26          22          
   PS6     4           12          40          36          24          
   PS4     4           16          56          52          36          
   PS2     5           11          67          62          51          
   PS9     6           0           67          61          61          
   PS8     7           9           76          69          60          
   PS3     8           10          86          78          68          
   PS10    9           10          96          87          77          
   Avg. WT : 40.60 ms
   Avg. TAT : 50.20 
*/
