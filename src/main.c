
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "search.h"
#include "sort.h"

int *random_array(int length, int min, int max) {
  srand(time(0));
  int *arr = (int *)malloc(length * sizeof(int));
  unsigned int seed = time(0);
  for (int i = 0; i < length; i++) {
    int random_number = rand() % (max - min + 1) + min;
    arr[i] = random_number;
  }
  return arr;
}

int *sorted_asc_array(int length) {
  int *arr = (int *)malloc(length * sizeof(int));
  for (int i = 0; i < length; i++) {
    arr[i] = i;
  }
  return arr;
}

void print_array(int *arr, int length) {
  printf("[");
  for (int i = 0; i < length; i++) {
    if (i == length - 1) {
      printf("%d", arr[i]);
      break;
    }
    printf("%d, ", arr[i]);
  }
  printf("]\n");
}

void time_bubble_sort(int max_n) {
  printf("\nTiming Bubble Sort: \n");
  unsigned int seed = time(0);
  for (int i = 10; i < max_n; i *= 5) {
    int *arr = random_array(i, -i * 5, i * 5);
    clock_t t;
    t = clock();
    bubble_sort_ascend(arr, i);
    t = clock() - t;
    double time_elapased = ((double)t) / CLOCKS_PER_SEC;
    printf("%-5d => %.2f s\n", i, time_elapased);
    free(arr);
  }
  printf("\n");
}

void time_quicksort(int max_n) {
  printf("\nTiming QuickSort w/ Pivot = Start: \n");
  unsigned int seed = time(0);
  for (int i = 10; i < max_n; i *= 10) {
    int *arr = random_array(i, -i * 10, i * 10);
    clock_t t;
    t = clock();
    quick_sort_ascend(arr, 0, i);
    t = clock() - t;
    double time_elapased = ((double)t) / CLOCKS_PER_SEC;
    printf("%-5d => %.2f s\n", i, time_elapased);
    free(arr);
  }
  printf("\n");
}

void print_timer(char *header, clock_t t, int n) {
  double time_elapased = ((double)t) / CLOCKS_PER_SEC;
  printf("%-3s [%d] => %.2f s\n", header, n, time_elapased);
}

void test_searches(int max_n) {
  printf("\nTiming Searches: \n");
  for (int i = 10; i < max_n; i *= 10) {
    int *arr = sorted_asc_array(max_n);
    bubble_sort_ascend(arr, i);
    int target = rand() % (i * 10 - 0 + 1) + 0;
    clock_t t1;
    clock_t t2;
    clock_t t3;

    t1 = clock();
    slow_search(arr, target, i);
    t1 = clock() - t1;

    print_timer("SS", t1, i);

    t2 = clock();
    slow_search_ascend(arr, target, i);
    t2 = clock() - t2;
    print_timer("SSO", t2, i);

    t3 = clock();
    binary_search_ascend(arr, target, i);
    t3 = clock() - t3;
    print_timer("BS", t3, i);

    printf("\n");

    free(arr);
  }
}

int main() {

  int MAX_N = 100000000;
  time_bubble_sort(MAX_N / 1000);
  test_searches(MAX_N);
  time_quicksort(MAX_N);

  return 0;
}
