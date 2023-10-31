#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    bool operator;
    struct Node* next;
} Node;

void display(Node* head){
    if(head == 0x0) return;
    display(head->next);
    printf((head->operator ? " %c" : " %d"), head->val);
}

int len(Node* head){
    if(head == 0x0) return 0;
    return 1 + len(head->next);
}

void clean(Node* stack){
    if (stack == 0x0) return;
    clean(stack->next);
    free(stack);
}

Node* push(Node* head, int val, bool is_op){
    Node* _t = (Node*) malloc(sizeof(Node));
    if (!_t) return head;
    _t->val = val;
    _t->operator = is_op;
    _t->next = head;
    return _t;
}

Node* pop( Node* head, int *ptr){
    if (head == 0x0) return head;
    *ptr = head->val;
    Node* _t = head->next;
    free(head);
    return _t;
}

void eval( Node** head, char op){
    int *A, *B,
        _t = 0;
    *head = pop(*head, A);
    *head = pop(*head, B);
    switch(op){
        case '+':
            _t = *B + *A;
            break;
        case '-':
            _t = *B - *A;
            break;
        case '*':
            _t = *B * *A;
            break;
        case '/':
            _t = *B / *A;
            break;
    }
    *head = push(*head, _t, false);
}

int main(void){
    Node* record = 0x0;
    Node* stack = 0x0;
    int val;
    bool op;
    char ch, cont;

    do {
        op = false;
        if (len(stack) >= 2){
            printf("IS operator?[y/n] : ");
            scanf("%c", &ch);
            if(ch == 'y') 
                op = true;
            getchar();
        }

        if(op){
            printf("Enter operator : ");
            ch = getchar();
            getchar();
            val = (int)ch;
            eval(&stack, ch);
        } else {
            printf("Enter integer: ");
            scanf("%d", &val);
            getchar();
            stack = push(stack, val, op);
        }
        record = push(record, val, op);
        printf("stack : ");
        display(stack);
        printf("\n");

        printf("Want to continue?[y/n] : ");
        scanf("%c", &cont);
        getchar();
    } while (cont != 'n');

    printf("records : ");
    display(record);
    printf("\n");

    clean(record);
    clean(stack);

    return 0;
}
