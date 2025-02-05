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
    // prepend_node(&list,i);
    append_node(&list,i);
  }
  // insert_node(&list,0,-1);  
  // //-1,0,1,2,3,4,5,6,7,8,9
  // print_node(&list);

  // insert_node(&list,length_node(&list),21);
  // //-1,0,1,2,3,4,5,6,7,8,9,21
  // print_node(&list);

  // insert_node(&list,6,69);
  // //-1,0,1,2,3,4,69,5,6,7,8,9,21
  // print_node(&list);

  // insert_node(&list,69,420);
  // //-1,0,1,2,3,4,69,5,6,7,8,9,21

  print_node(&list);
  printf("length of linkedlist is: %d\n", length_node(&list));
 
  // behead_node(&list);
  // pop_node(&list);
  // remove_node(&list,6);
  reverse_node(&list);
  print_node(&list);
  printf("length of linkedlist is: %d\n", length_node(&list));
  
  prepend_node(&list,10);
  print_node(&list);
  printf("length of linkedlist is: %d\n", length_node(&list));
  free(list);

}

int main() {
  // test_array_list();
  test_linked_list();
  return 0;
}
