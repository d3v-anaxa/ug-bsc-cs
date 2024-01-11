#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANGE 10

typedef struct Stack {
    int length;
    int top;
    int *arr;
}   Stack; 

void init(Stack **st, const int size){
   Stack *tmp = (Stack*) malloc(sizeof(Stack));
   tmp->length = size;
   tmp->top = -1;
   tmp->arr = malloc(sizeof(int)*size);
   *st = tmp;
}

void destroy(Stack **st){
    Stack *tmp = *st;
    *st = 0x0;
    free(tmp->arr);
    free(tmp);
}

void push(Stack *st, int val){
    if(st->top == st->length - 1){
        printf("STACK OVERFLOW!\n");
    }   else {
        ++(st->top);
       st->arr[st->top] = val;
       printf("%12s %4d\n", "[PUSHED] ", val);
    }
}

void pop(Stack *st){
    if(st->top < 0){
        printf("STACK UNDERFLOW!\n");
    }   else {
        printf("%12s %4d\n", "[POPPED] ", st->arr[st->top]);
        (st->top)--;
    }
}

void display(Stack *st){
    printf("List : ");
    int i = 0; 
    while(i <= st->top){
        printf(" %4d", st->arr[i]);
        i++;
    }   printf("\n");
}

void test(){
    srand(time(0));
    Stack *st = 0x0;
    init(&st, RANGE);
    for (int i = 0; i < RANGE; i++)
        rand() % 2 ? push(st, rand() % RANGE - (RANGE/2)) : pop(st);
    display(st);
    destroy(&st);
}

int main(void){
    test();
    return 0;
}
