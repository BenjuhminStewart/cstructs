// #include "array_list.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

// void test_array_list() {
//   struct ArrayList *list = NewArrayList();
//   int n = 10;
//   int i = 0;
//   for (i = 0; i < n; i++) {
//     push(list, i);
//   }
//   updateAt(list, n - 2, 69);

//   int popped = pop(list);
//   printf("Popped: %d\n", popped);
//   print(list);
//   free(list);
// }

void test_linked_list() {
  struct ListNode *list = NULL;
  int n = 10;
  for(int i=0; i<n; i++){
    prepend(&list,i);
  }
  print(&list);
}

int main() {
  // test_array_list();
  test_linked_list();
  return 0;
}
