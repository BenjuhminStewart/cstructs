
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "max_heap.h"
#include "min_heap.h"


void test_max_heap(){
  struct MaxHeap *pq = NewMaxHeap();
  offer_max_heap(pq,12);
  offer_max_heap(pq,0);
  offer_max_heap(pq,1);
  offer_max_heap(pq,2);
  offer_max_heap(pq,21);
  offer_max_heap(pq,13);
  offer_max_heap(pq,69);
  offer_max_heap(pq,420);
  offer_max_heap(pq,3);
  offer_max_heap(pq,100);

  print_max_heap(pq);

  int largest = poll_max_heap(pq);
  printf("poll_max_heaped: %d\n", largest);
  print_max_heap(pq);

  largest = poll_max_heap(pq);
  printf("poll_max_heaped: %d\n", largest);
  print_max_heap(pq);

  free(pq);
}

void test_min_heap(){
  struct MinHeap *pq = NewMinHeap();
  offer_min_heap(pq,12);
  offer_min_heap(pq,0);
  offer_min_heap(pq,1);
  offer_min_heap(pq,2);
  offer_min_heap(pq,21);
  offer_min_heap(pq,13);
  offer_min_heap(pq,69);
  offer_min_heap(pq,420);
  offer_min_heap(pq,3);
  offer_min_heap(pq,100);

  print_min_heap(pq);

  int smallest = poll_min_heap(pq);
  printf("poll_min_heaped: %d\n", smallest);
  print_min_heap(pq);

  smallest = poll_min_heap(pq);
  printf("poll_min_heaped: %d\n", smallest);
  print_min_heap(pq);

  free(pq);
}

int main() {
  // test_array_list();
  // test_linked_list();
  test_max_heap();
  printf("\n\n");
  test_min_heap();
  return 0;
}
