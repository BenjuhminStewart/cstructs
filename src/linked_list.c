#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

struct ListNode *NewListNode(int val){
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->value = val;
    node->next = NULL;
    return node;
}


void append(struct ListNode **head, int val){
    struct ListNode *node = NewListNode(val);
    struct ListNode *temp = *head;
    if(temp==NULL){
        prepend(head,val);
        return;
    }
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next = node;

}

void behead(struct ListNode **head){

}

void insert(struct ListNode **head, int val, int index){
    if (index==0){
        prepend(head,val);
        return;
    }
   
    struct ListNode *node = NewListNode(val);
    int i = 0;
    struct ListNode *temp = *head;
    while(i<index-1){
        if(temp != NULL){
            printf("ERROR: Index out of bounds");
            free (node);
            exit(1);
        }
        temp = temp->next;
        i++;
    }
    node->next = temp->next;
    temp->next = node;
}

void pop(struct ListNode **head){

}

void prepend(struct ListNode **head, int val){
    struct ListNode *node = NewListNode(val);
    struct ListNode *temp = *head;
    node->next = temp;
    head = node;
}

void print(struct ListNode **head){
    struct ListNode *temp = *head;
    while (temp->next != NULL){
        printf("%d -> " , temp->value);
    }
    printf("NULL\n");

}

void removeNode(struct ListNode **head, int index){

}
