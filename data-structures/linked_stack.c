#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

typedef struct Stack {
    int val;
    struct Stack *next;
}   Stack;

void push(Stack **top, int val){
    Stack *tmp = (Stack*) malloc(sizeof(Stack));
    if (tmp){
        tmp->val = val;
        tmp->next = *top;
        *top = tmp;
        printf("%-10s%4d\n", "[INSERTED]", val);
    }
}

int pop(Stack **top){
    Stack *tmp = *top;
    int val = 0;
    if (!tmp){
        printf("%-10s\n", "![EMPTY STACK]");
    }   else {
        val = tmp->val;
        *top = tmp->next;
        free(tmp); 
        printf("%-10s%4d\n", "[POP]", val);
    }   return val;
}

void display(Stack *st){
    if (!st){
        printf("%-10s\n", "![EMPTY STACK]");
    }   else {
        printf("%-10s", "List :");
        while(st){
            printf("%4d", st->val);
            st = st->next;
        }   printf("\n");
    }
}

void clean(Stack **top){
    Stack *curr = *top,
          *prev = 0x0;
    while(curr){
        prev = curr;
        curr = curr->next;
        free(prev);
    }   *top = 0x0;
    printf("%-10s\n", "[STACK DESTROYED]");
}

void test(void){
    srand(time(0));
    Stack *st = 0x0;
    display(st);
    for (int i = 0 ; i < SIZE; i++){
        if (rand() % 2) {
            push(&st, rand() % SIZE);
        }   else {
            pop(&st);
        }   display(st);
    }   clean(&st);
}

int main(void){
    test();
    return 0;
}
