
#ifndef LIST_H
#define	LIST_H

struct node {
    int data;
    struct node * next;
};

typedef struct node * nodePT; // pointer to node type

// Builds and returns a list with integers read from standard input.
// Stops reading with a non-integer is entered (when scanf fails to read one int)
struct node * build_list_of_ints();

// Builds and returns a list with integers read from standard input.
struct node * build_list_N(int N);

// Builds a list with integers fro the array arr
struct node * array_2_list(int arr[], int sz);
    
/* Creates a new node, that contains the value specified in the argument, 
 * and that points to next_in. 
 */
struct node * new_node(int value_in, struct node * next_in);

/*  Note that these functions may not have all the security checks.
E.g. not all the functions reading and setting members of a node pointer, 
check that the node is not NULL  */


/*  --------  LIST  */
// List implementation uses a DUMMY NODE

// Creates and returns an empty list.
struct node * new_list();

void destroy_list(struct node * Ld);

// Iterates through list and counts nodes.
int compute_length(struct node * Ld);  

// Inserts new_node to the specified list, at the position right after
// the node called "previous".
void insert_node(struct node * previous, struct node * new_node);

void print_list_vert(struct node * my_list);

void print_list_horiz(struct node * my_list);

void print_list_pointer(struct node * my_list);

   

#endif	/* LIST_H */

