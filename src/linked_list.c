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


void append_node(struct ListNode **head, int val){
    struct ListNode *node = NewListNode(val);
    struct ListNode *temp = *head;
    if(temp==NULL){
        prepend_node(head,val);
        return;
    }
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next = node;

}

void behead_node(struct ListNode **head){
    struct ListNode *temp = *head;
    *head = temp->next;
    free(temp);
}

void insert_node(struct ListNode **head, int index, int val){
    if (index==0){
        prepend_node(head,val);
        return;
    }
   
    struct ListNode *node = NewListNode(val);
    int i = 0;
    struct ListNode *temp = *head;
    while(i<index-1){
        if(temp == NULL){
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

int length_node(struct ListNode **head){
    int len = 0;
    struct ListNode *temp = *head;
    while(temp !=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void pop_node(struct ListNode **head){
    struct ListNode *temp = *head;\
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next = NULL;
    free(temp->next);
}

void prepend_node(struct ListNode **head, int val){
    struct ListNode *node = NewListNode(val);
    node->next = *head;
    *head = node;
    
}

void print_node(struct ListNode **head){
    struct ListNode *temp = *head;
    while (temp != NULL){
        printf("%d -> " , temp->value);
        temp = temp->next;
    }
    printf("NULL\n");

}

void remove_node(struct ListNode **head, int index){
    if (index==0){
        behead_node(head);
        return;
    }
   
    int i = 0;
    struct ListNode *temp = *head;
    while(i<index-1){
        if(temp == NULL){
            printf("ERROR: Index out of bounds");
            exit(1);
        }
        temp = temp->next;
        i++;
    }
    struct ListNode *rep = temp->next;

    temp->next = rep->next;
    free(rep);
    
}
// struct ListNode reverse_node(struct ListNode **head)
// {

// }

void reverse_node(struct ListNode **head){
    struct ListNode *prev = NULL;
    struct ListNode *itr = *head;
    struct ListNode *cur = *head;
   
    while (itr!= NULL){
        itr = itr->next;
        cur->next = prev;
        prev = cur;
        cur = itr;
    }
    
    *head = prev;
}
