#include "array_list.c"
#include <stdio.h>

void test_array_list() {
  struct ArrayList *list = NewArrayList();
  int n = 10;
  int i = 0;
  for (i = 0; i < n; i++) {
    push(list, i);
  }
  updateAt(list, n - 2, 69);

  int popped = pop(list);
  printf("Popped: %d\n", popped);
  print(list);
  free(list);
}

int main() {
  test_array_list();
  return 0;
}
