 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 #include "sort.h"

 void bubble_sort_ascend(int arr[], int arr_length){
    int swaps = 1;
    while(swaps > 0){
        swaps = 0;
        for (int i = 0; i < arr_length-1; i++){
            
            if(arr[i] > arr[i+1]){
                int temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
                swaps = 1;
            }
        }
        
    }
}

void bubble_sort_descend(int arr[], int arr_length){
    int swaps = 1;
    while(swaps > 0){
        swaps = 0;
        for (int i = 0; i < arr_length-1; i++){
            
            if(arr[i] < arr[i+1]){
                int temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
                swaps = 1;
            }
        }
        
    }
}

int get_pivot_ascend(int arr[], int start, int end) {
    int pivot = arr[start];
    int left_wall = start;

    for(int i = start + 1; i < end; i++) {
        if (arr[i] < pivot) {
            int temp = arr[i];
            arr[i] = arr[left_wall];
            arr[left_wall] = temp;
            left_wall += 1;
        }
    }

    int temp = pivot;
    pivot = arr[left_wall];
    arr[left_wall] = temp;

    return left_wall;
}

int get_pivot_descend(int arr[], int start, int end) {
    int pivot = arr[start];
    int left_wall = start;

    for(int i = start + 1; i < end; i++) {
        if (arr[i] > pivot) {
            int temp = arr[i];
            arr[i] = arr[left_wall];
            arr[left_wall] = temp;
            left_wall += 1;
        }
    }

    int temp = pivot;
    pivot = arr[left_wall];
    arr[left_wall] = temp;

    return left_wall;
}



void quick_sort_ascend(int arr[], int start, int end) {
    if(start < end) {
        int pivot_i = get_pivot_ascend(arr, start, end);
        quick_sort_ascend(arr, start, pivot_i);
        quick_sort_ascend(arr, pivot_i + 1, end);
    }

    return;
}


void quick_sort_descend(int arr[], int start, int end) {
    if(start < end) {
        int pivot_i = get_pivot_descend(arr, start, end);
        quick_sort_descend(arr, start, pivot_i);
        quick_sort_descend(arr, pivot_i + 1, end);
    }

    return;
}


