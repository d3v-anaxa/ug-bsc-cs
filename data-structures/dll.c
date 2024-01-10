#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

typedef int T;

typedef struct dll_node{
    T val;
    struct dll_node *prev, *next;
}   dll_node;

dll_node* createNode(T val, dll_node *prev, dll_node *next){
    dll_node *tmp = (dll_node*) malloc(sizeof(dll_node));
    if(tmp){
        tmp->val = val;
        tmp->prev = prev;
        tmp->next = next;
    }   return tmp;
}

void addH(dll_node **head, T val){
    dll_node *tmp = createNode(val, 0x0, *head);
    *head = tmp;
}

void addT(dll_node **head, T val){
    if(*head == 0x0){
        dll_node *tmp = createNode(val, *head, 0x0);
        *head = tmp;
    }   else if ((*head)->next == 0x0) {
        dll_node *tmp = createNode(val, *head, 0x0);
        (*head)->next = tmp;
    }   else {
        addT(&((*head)->next), val);
    }
}

void rmH(dll_node **head){
    if (*head == 0x0) {
        printf("No elements to remove!\n");
    }   else {
        dll_node *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}

void rmT(dll_node **head){
    dll_node *curr = *head,
             *prev = curr;
    if (curr == 0x0) {
        printf("No elements to remove!\n");
    }   else if (curr->next == 0x0){
        *head = 0x0;
        free(curr);
    }   else {
        while(curr->next){
            prev = curr;
            curr = curr->next;
        }   prev->next = 0x0;
        free(curr);
    }
}

void clean(dll_node **head){
    dll_node *curr = *head,
             *prev = 0x0;
    if (!curr) return;
    while(curr){
        prev = curr;
        curr = curr->next;
        free(prev);
    }   *head = 0x0;
}

void display(dll_node *head){
    dll_node *curr = head;
    if(!curr){
        printf("No elements!\n");
    }   else {
        printf("List : ");
        while(curr){
            printf("%4d", curr->val);
            curr = curr->next;
        }   printf("\n");
    }
}

int main(void){
    srand(time(0));
    dll_node *dll = 0x0;
    for(int i = 0; i < SIZE; i++) {
        i%2 == 0 ? addH(&dll, rand() % SIZE - (SIZE/2)) : addT(&dll, rand() % SIZE - (SIZE/2));
    }
    display(dll);
    for(int i = 0; i < SIZE; i++) {
        i%2 == 0 ? rmH(&dll) : rmT(&dll);
    }
    display(dll);
    clean(&dll);
    return 0;
}
