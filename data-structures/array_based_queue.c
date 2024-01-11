#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

typedef struct Queue {
    int length, top;
    int *arr;
}   Queue;

void init(Queue **que, int length){
    Queue *tmp = (Queue*) malloc(sizeof(Queue));
    int *arr =(int*) calloc(sizeof(int), length);
    if (!*que){
        tmp->length = length;
        tmp->top = -1;
        tmp->arr = arr;
        *que = tmp;
        printf("%-10s\n", "[STACK INIT]");
    }   else {
        printf("%-10s\n", "![STACK BUSY]");
        free(tmp);
        free(arr);
    }
}

void destroy(Queue **que){
    Queue *tmp = *que;
    if (!tmp){
        printf("%-10s\n", "![STACK CLEAN]");
    }   else{
        free(tmp->arr);
        free(tmp);
        *que = 0x0;
    }
}

void enqueue(Queue *que, int val){
    if (!que){
        printf("![QUEUE NOT INITIATED]\n");
    }   else {
        if(que->top == que->length - 1){
            printf("%-10s\n", "![STACK OVERFLOW]");
        }   else{
            que->top += 1;
            que->arr[que->top] = val;
            printf("%-10s%4d\n", "[ENQUEUE]", val);
        }
    }
}

int dequeue(Queue *que){
    int val = 0;
    if (!que){
        printf("![QUEUE NOT INITIATED]\n");
    }   else{
        if (que->top == -1){
            printf("%-10s\n", "![QUEUE EMPTY]");
        }   else{
            val = que->arr[0];
            for(int i = 1; i <= que->top; i++){
                que->arr[i-1] = que->arr[i];
            }   que->top -= 1;
            printf("%-10s%4d\n", "[DEQUEUE]", val);
        }
    }   return 0;
}

void display(Queue *que){
    int top = que->top;
    if (top == -1){
        printf("%-10s\n", "[EMPTY QUEUE]");
    }   else{
        printf("%-10s", "List :");
        while(top >= 0){
            printf("%4d", que->arr[top]);
            --top;
        }   printf("\n");
    }
}

void test(){
    srand(time(0));
    Queue *que = 0x0;
    init(&que, SIZE);
    init(&que, SIZE);
    for (int i = 0; i < 50;i++){
        if (rand()%2){
            enqueue(que, rand() % SIZE);
        }   else{
            dequeue(que);
        }   display(que);
    }
    destroy(&que);
    destroy(&que);
}

int main(void){
    test();
    return 0;
 }
