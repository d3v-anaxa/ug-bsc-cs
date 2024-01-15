#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define SIZE 20

typedef struct queue_node {
    int val;
    struct queue_node *next;
}   queue_node;

typedef struct Queue {
    int length;
    struct queue_node *head, *tail;
}   Queue;

bool is_active(Queue *que){
    return que != 0x0;
}

bool is_dead(Queue *que){
    return que == 0x0;
}

void init(Queue **que){
    bool state = is_dead(*que);
    if (state){
        Queue *tmp = (Queue*) malloc(sizeof(Queue));
        if(tmp){
            tmp->head = 0x0;
            tmp->tail = 0x0;
            tmp->length = 0;
        }   *que = tmp;
    }   printf("%-10s\n", state ? "[QUEUE INIT]" : "![QUEUE ACTIVE]");
}

void destroy(Queue **que){
    bool state = is_active(*que);
    if(state){
        Queue *tmp = *que;
        queue_node *prev = 0x0,
                   *curr = tmp->head;
        tmp->head = 0x0;
        tmp->tail = 0x0;
        while(curr){
            prev = curr;
            curr = curr->next;
            free(prev);
        }   *que = 0x0;
        free(tmp);
    }   printf("%-10s\n", state ? "[QUEUE DESTROYED]" : "![QUEUE DEAD]" );
}

void enqueue(Queue **que, int val){
    if(is_dead(*que)) return;
    Queue *curr = *que;
    queue_node *tmp = (queue_node*) malloc(sizeof(queue_node));
    if(tmp){
        tmp->val = val;
        tmp->next = 0x0;
    }
    if (curr->length == 0){
        curr->head = tmp;
    }   else{
        curr->tail->next = tmp;
    }   curr->tail = tmp;
    curr->length += 1;
    printf("%-10s%4d\n", "[ENQUEUE]", val);
}

void dequeue(Queue **que){
    if(is_dead(*que)) return;
    queue_node *tmp = (*que)->head;
    if (tmp == 0x0){
        printf("%-10s\n", "![EMPTY QUEUE]"); 
    }   else if (tmp->next == 0x0){
        printf("%-10s%4d\n", "[DEQUEUE]", tmp->val);
        (*que)->head = 0x0;
        (*que)->tail = 0x0;
        (*que)->length -= 1;
        free(tmp);
    }   else{
        printf("%-10s%4d\n", "[DEQUEUE]", tmp->val);
        (*que)->head = tmp->next;
        free(tmp);
    }
}

void display(Queue *que){
    if(is_dead(que) || que->head == 0x0){
        printf("%-10s\n", "![EMPTY QUEUE]");
    }   else {
        printf("QUEUE [%d] :  ", que->length);
        queue_node *curr = que->head;
        while(curr){
            printf("%4d", curr->val);
            curr = curr->next;
        }   printf("\n");
    }
}

void test(){
    Queue *que = 0x0;
    init(&que);
    init(&que);
    for(int j = 0; j < SIZE;j++){
        rand() % 2 == 0 ? enqueue(&que, rand() % SIZE) : dequeue(&que);
        display(que);
    }
    destroy(&que);
    destroy(&que);
}

int main(void){
    test();
    return 0;
}
