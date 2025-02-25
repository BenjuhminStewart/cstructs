#include <stdio.h>
#include <stdlib.h>

#include "search.h"

int slow_search(int *arr, int target, int arr_length){
    for(int i = 0; i < arr_length; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int slow_search_ascend(int *arr, int target, int arr_length){
    for(int i = 0; i < arr_length; i++){
        if(arr[i]>target) {
            return -1;
        }
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int slow_search_descend(int *arr, int target, int arr_length){
    for(int i = 0; i < arr_length; i++){
        if(arr[i]<target) {
            return -1;
        }
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int binary_search_ascend(int *arr, int target, int arr_length) {
    if(target < arr[0] || target > arr[arr_length-1]) return -1;
    int left = 0;
    int right =  arr_length;
    while(left <= right){
        int middle = left + ((right - left) / 2);
        if(target < arr[middle]){
            right = middle - 1;
            continue;
        }
        if(target > arr[middle]){
            left = middle + 1;
            continue;
        }
        return middle;
    }
    return -1;
}

int binary_search_descend(int *arr, int target, int arr_length){
    if(target > arr[0] || target < arr[arr_length-1]) return -1;
    int left = 0;
    int right =  arr_length;
    while(left <= right){
        int middle = left + ((right - left) / 2);
        if(target > arr[middle]){
            right = middle - 1;
            continue;
        }
        if(target < arr[middle]){
            left = middle + 1;
            continue;
        }
        return middle;
    }
    return -1;

}


