#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_list.h"

struct ArrayList *NewArrayList() {
  struct ArrayList *list = malloc(sizeof(struct ArrayList));
  list->data = malloc(sizeof(int) * STARTING_CAPACITY);
  list->current_size = 0;
  list->current_capacity = STARTING_CAPACITY;
  return list;
}

int push(struct ArrayList *list, int value) {
  if (list->current_size == list->current_capacity) {
    list->current_capacity *= 2;
    list->data = realloc(list->data, sizeof(int) * list->current_capacity);
  }
  list->data[list->current_size++] = value;
  return list->data[list->current_size - 1];
}

int pop_val(struct ArrayList *list) {
  if (list->current_size == 0) {
    printf("ERROR: Trying to pop from a list with no elements\n");
    exit(1);
  }

  int value = list->data[--list->current_size];
  // remove the last element
  list->data[list->current_size] = 0;
  return value;
}

void print(struct ArrayList *list) {
  printf("[");
  for (int i = 0; i < list->current_size; i++) {
    if (i < list->current_size - 1) {
      printf("%d, ", list->data[i]);
    } else {
      printf("%d", list->data[i]);
    }
  }
  printf("]\n");
}

void updateAt(struct ArrayList *list, int index, int value) {
  if (index >= list->current_size) {
    printf("ERROR: Index %d out of bounds for size: %d", index,
           list->current_size);
    exit(1);
  }

  list->data[index] = value;
}
