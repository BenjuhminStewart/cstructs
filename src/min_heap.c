#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include "min_heap.h"

struct  MinHeap *NewMinHeap(){
    struct MinHeap *pq = malloc(sizeof(struct MinHeap));
    pq->values = malloc(sizeof(int) * STARTING_CAPACITY_MIN_HEAP);
    pq->capacity = STARTING_CAPACITY_MIN_HEAP;
    pq->length = 0;
    return pq;
}


void bubble_up_min_heap(struct MinHeap *pq){
    int parent = get_parent_min_heap(pq,pq->length-1);
    int i = pq->length-1;

    while(parent < pq->length && pq->values[i] < pq->values[parent]){
        int temp = pq->values[parent];
        pq->values[parent] = pq->values[i];
        pq->values[i] = temp;
        i = parent;
        parent = get_parent_min_heap(pq,i);
    }

}

int get_left_min_heap(struct MinHeap *pq, int i){
    return 2 * i + 1;
}

int get_min(struct MinHeap *pq){
    return pq->values[0];
}

int get_parent_min_heap(struct MinHeap *pq, int i){
    return (i - 1) / 2;
}

int get_right_min_heap(struct MinHeap *pq, int i){
    return 2 * i + 2;
}

int get_smallest_child(struct MinHeap *pq, int left, int right){
    if (pq->values[left] > pq->values[right]){
        return right;
    }
    return left;
}

void offer_min_heap(struct MinHeap *pq, int val){
    if (pq->length == pq->capacity) {
        pq->capacity *= 2;
        pq->values = realloc(pq->values, sizeof(int) * pq->capacity);
    }
    pq->values[pq->length] = val;
    pq->length++;
    bubble_up_min_heap(pq);
}

/*while current<child:swap(currernt,biggest child)*/
int poll_min_heap(struct MinHeap *pq) {
    int smallest = pq->values[0];
    int temp = pq->values[pq->length - 1];
    pq->values[0] = temp;
    pq->values[pq->length - 1] = -1;
    pq->length--;
    sink_down_min_heap(pq);
    return smallest;
}

/*Preorder Traversal Printing*/
void print_min_heap(struct MinHeap *pq){
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

void sink_down_min_heap(struct MinHeap *pq){
    int parent = 0;
    int left = get_left_min_heap(pq,parent);
    int right = get_right_min_heap(pq,parent);
    int smallest_child = get_smallest_child(pq, left, right);


    while(right < pq->length && pq->values[parent] > pq->values[smallest_child]){
        
        int temp = pq->values[parent];
        pq->values[parent] = pq->values[smallest_child];
        pq->values[smallest_child] = temp;

        parent = smallest_child;
        left = get_left_min_heap(pq,parent);
        right = get_right_min_heap(pq,parent);
        smallest_child = get_smallest_child(pq, left, right);
    }
}
