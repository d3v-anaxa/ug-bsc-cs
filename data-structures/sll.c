#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 20

typedef int T;
typedef struct sll_node {
    T val;
    struct sll_node *next;
} sll_node;

bool isEmpty(sll_node *head){
    return head == 0x0;
}

void add_to_head(sll_node **head, T value){
    sll_node *tmp = (sll_node*) malloc(sizeof(sll_node));
    if (tmp == 0x0) 
        return;
    else {
        tmp->val = value;
        tmp->next = *head;
        *head = tmp;
    }
}

void add_to_tail(sll_node **head, T value){
    sll_node *tmp = (sll_node*) malloc(sizeof(sll_node));
    if (tmp == 0x0) return;
    tmp->val = value;
    tmp->next = 0x0;
    if(isEmpty(*head)){
        *head = tmp;
    } else {
        sll_node *ptr = *head;
        while(ptr->next != 0x0)
            ptr = ptr->next;
        ptr->next = tmp;
    }
}

void rm_from_head(sll_node **head){
    if(isEmpty(*head))
        return;
    else {
        sll_node *ptr = *head;
        *head = (*head)->next;
        free(ptr);
    }
}

void rm_from_tail(sll_node **head){
    if(isEmpty(*head))
        return;
    else if(isEmpty((*head)->next)) {
        free(*head);
        *head = 0x0;
    } else {
        sll_node *curr = *head,
                 *prev = 0x0;
        while (curr->next != 0x0){
            prev = curr;
            curr = curr->next;
        }   prev->next = 0x0;
        free(curr);
    }
}

void reverse(sll_node **head){
    sll_node *curr = *head,
             *next = 0x0,
             *prev  = 0x0;
    while (curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }   *head = prev;
}

void clean(sll_node **head){
    sll_node *curr = *head,
             *prev = 0x0;
    while(curr){
        prev = curr;
        curr = curr->next;
        free(prev);
    }   *head = 0x0;
}

void display(sll_node **head){
    sll_node *curr = *head;
    if (isEmpty(*head)) {
        printf("No elements!\n");
    } else {
        printf("List elements : ");
        while(curr){
            printf(" %3d", curr->val);
            curr = curr->next;
        }   printf("\n");
    }
}

int menu(){
    int x = 0;
    printf("Singly linked list...\n");
    printf("1. add to head\n");
    printf("2. add to tail\n");
    printf("3. remove from head\n");
    printf("4. remove from tail\n");
    printf("5. clean list\n");
    printf("6. reverese list\n");
    printf("7. display\n");
    printf("[any other number to exit!]\n");
    printf("Enter choice : ");
    scanf("%d", &x);
    return x;
}

bool execute(sll_node head){
}

int test_1(){
    bool cont = true;
    sll_node *head = 0x0;
    T data;
    do {
        switch(menu()){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                add_to_head(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                add_to_tail(&head, data);
                break;
            case 3:
                rm_from_head(&head);
                break;
            case 4:
                rm_from_head(&head);
                break;
            case 5:
                clean(&head);
                break;
            case 6:
                reverse(&head);
                break;
            case 7:
                display(&head);
                break;
            default:
                printf("Exiting!!\n");
                cont = false;
                break;
        }
    } while(cont);
    clean(&head);
    return 0;
}

int test_2(){
    sll_node *head = 0x0;
    for (int i = 0; i < MAX; i++){
        add_to_tail(&head, i*i);
        add_to_head(&head, i*i);
        display(&head);
    }
    for (int i = 0; i < MAX; i++){
        rm_from_tail(&head);
        rm_from_head(&head);
        display(&head);
    }
    clean(&head);
    return 0;
}

int main(void){
    return test_2();
}
