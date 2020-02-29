/* 
  Created 2/16/20 - Alexandra Stefan
  
  Reads k lists into an array of linked lists, 
  sorts the lists using insertion sort, 
  turns the array into a min-Heap using bottom-up and then
  merges the lists by reapeating until the heap is empty:
   - remove_min from heap and insert it at the end of result list.
  
  Notes: 
  1. the heap array keeps data starting at index 0.
  2. After you implement YOUR WORK (to merge the k lists), 
  the result sorted list (called sorted) will be destroyed (and all it's nodes freed)
  and thus all the memory should be freed. (But you will have to free 
  the dummy nodes of the k lists yoruself).
  However since the merge is not yet implemented and the list 'sorted' is 
  empty, the nodes from the k lists are NOT freed and so until you finish 
  your code this project has memory leaks. 
  After you finish your part there should not be any memory leaks.   
 */
 
/* compile: 
gcc merge_k_client.c merge_k.c list.c
run:
./a.out < data4.txt

Valgrind:
gcc -g merge_k_client.c merge_k.c list.c
run:
valgrind --leak-check=full ./a.out < data4.txt
 * 
 */

#include <stdlib.h>
#include <stdio.h>

#include "merge_k.h"   // heap.h includes list.h


void read_k_lists(int k, nodePT arrL[k]) {
   int i,t,N;
   printf("Enter %d lists in the format: list size (N) and then N integers", k);
   for (i = 0; i<k; i++) {
      scanf("%d", &N);
      nodePT L = build_list_N(N);
      arrL[i] = L; // copy memory address stored in L;
      print_list_pointer(L); // check list was read correctly
   }
}


int main()   {
   int k, i,t,N;
   
   printf("Enter the number of lists, k = ");
   scanf("%d", &k);
   
   nodePT heap[k];
   read_k_lists(k,heap);
   
   printf("\n\nSorting each linked list: \n");
   for(i=0; i<k; i++){
      print_list_pointer(heap[i]);
      sort_list(heap[i]);
      printf("Sorted list:");
      print_list_pointer(heap[i]);
   }
   
   printf("\nConstructing the Heap (turns the array into a heap using bottom up) ...\n");
   make_heap(k, heap);

   printf("\nMerging ...\n");   
   nodePT sorted = merge_k(k, heap);

   printf("\n\nSorted result list is:");   
   print_list_pointer(sorted);
   destroy_list(sorted);   
   
   return 0;
}
