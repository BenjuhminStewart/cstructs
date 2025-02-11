#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include "max_heap.h"

struct  MaxHeap *NewMaxHeap(){
    struct MaxHeap *pq = malloc(sizeof(struct MaxHeap));
    pq->values = malloc(sizeof(int) * STARTING_CAPACITY_MAX_HEAP);
    pq->capacity = STARTING_CAPACITY_MAX_HEAP;
    pq->length = 0;
    return pq;
}

int get_biggest_child(struct MaxHeap *pq, int left, int right){
    if (pq->values[left] < pq->values[right]){
        return right;
    }
    return left;
}

void bubble_up_max_heap(struct MaxHeap *pq){
    int parent = get_parent_max_heap(pq,pq->length-1);
    int i = pq->length-1;

    while(pq->values[i] > pq->values[parent]){
        int temp = pq->values[parent];
        pq->values[parent] = pq->values[i];
        pq->values[i] = temp;
        i = parent;
        parent = get_parent_max_heap(pq,i);
    }

}

int get_left_max_heap(struct MaxHeap *pq, int i){
    return 2 * i + 1;
}

int get_max(struct MaxHeap *pq){
    return pq->values[0];
}

int get_parent_max_heap(struct MaxHeap *pq, int i){
    return (i - 1) / 2;
}

int get_right_max_heap(struct MaxHeap *pq, int i){
    return 2 * i + 2;
}

void offer_max_heap(struct MaxHeap *pq, int val){
    if (pq->length == pq->capacity) {
        pq->capacity *= 2;
        pq->values = realloc(pq->values, sizeof(int) * pq->capacity);
    }
    pq->values[pq->length] = val;
    pq->length++;
    bubble_up_max_heap(pq);
}

/*while current<child:swap(currernt,biggest child)*/
int poll_max_heap(struct MaxHeap *pq) {
    int largest = pq->values[0];
    int temp = pq->values[pq->length - 1];
    pq->values[0] = temp;
    pq->values[pq->length - 1] = -1;
    pq->length--;

    sink_down_max_heap(pq);
    return largest;
}

/*Preorder Traversal Printing*/
void print_max_heap(struct MaxHeap *pq){
    printf("[");
    for(int i=0; i < pq->length; i++){
        if(i==pq->length-1){
            printf("%d",pq->values[i]);
            continue;
        }
        printf("%d, ",pq->values[i]);
    }
    printf("]\n");

}

void sink_down_max_heap(struct MaxHeap *pq){
    int parent = 0;
    int left = get_left_max_heap(pq,parent);
    int right = get_right_max_heap(pq,parent);
    int biggest_child = get_biggest_child(pq, left, right);

    while(right < pq->length && pq->values[parent] < pq->values[biggest_child]){
        int temp = pq->values[parent];
        pq->values[parent] = pq->values[biggest_child];
        pq->values[biggest_child] = temp;

        parent = biggest_child;
        left = get_left_max_heap(pq,parent);
        right = get_right_max_heap(pq,parent);
        biggest_child = get_biggest_child(pq, left, right);
    }
}
