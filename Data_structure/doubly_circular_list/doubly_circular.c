
// Headers
#include<stdio.h>
#include<stdlib.h>
#include"doubly_circular.h"

// Node structure
struct node
{
    P_node_t  p_prev;
    int data;
    P_node_t  p_next;
};   

/*
 *                                              OPERATIONS 
 *                                        *)  CREATE LIST
 *                                        *)  add Node at end
 *                                        *)  add Node at front
 *                                        *)  add Node at bottom    (at specified position)
 *                                        *)  remove Node at end
 *                                        *)  remove Node at front
 *                                        *)  remove Node at bottom  (at specified position)
 *                                        *)  searching data
 *                                        *)  update data
 *                                        *)  merging two lists
 *                                        *)  reverse list 
 *                                        *)  Display list
 *                                        *)  destroy list
 */


//                         /*  HELPER FUNCTIONS */
void* Xmalloc(int size)
{
    void* node = malloc(size);    

    if(node == NULL)
    {
        fprintf(stderr , "ERROR: Out of Memory\n");
        return(NULL);
    }

    return(node);
}

static void destroyList(P_node_t head)
{
    P_node_t   current = NULL;
    P_node_t   delete_node = NULL;

    current = head->p_next;

    while(current != head)
    {
        delete_node = current;
        current = current->p_next;

        free(delete_node);        // destroying node
        delete_node = NULL;
    }

    free(head);
    head = NULL;
}

static int mergeList(P_node_t list_a , P_node_t list_b)
{
    P_node_t  current = NULL;
    P_node_t  b_last_node = NULL;

    if(list_a == list_b)
    {
       fprintf(stderr , "ERROR: you have given same list twice\n");
       return(FAILURE);
    }

    current = list_b->p_next;
    while(current->p_next != list_b )
    {
        current = current->p_next;
    }

    b_last_node = current;          // noting the address of last node of list b

    // reaching till last node of list 1
    current = list_a->p_next;
    while(current->p_next != list_a)
    {
        current = current->p_next;
    }

    current->p_next = list_b->p_next;       // joining link of last node of list a to first node of list b
    list_b->p_next->p_prev = current;       // joining link of first node of list b to last node of list a
    b_last_node->p_next = list_a;           // joining link of last node of list b to the head node of list a
    list_a->p_prev = b_last_node;           // joining link of head node of list a to the last node of list b

    free(list_b);
    list_b = NULL;

    return(SUCCESS);
}


//                          /* INTERFACE FUNCTIONS */
extern P_node_t create_list(void)
{
    P_node_t  list = NULL;

    list =  Xmalloc(SIZE_NODE);

    if(list == NULL)
    {
        fprintf( stderr, "ERROR: Failed to create List\n");
        return(NULL);
    }

    list->p_prev = list;
    list->data = 0;
    list->p_next = list;

    fprintf(stdout , "SUCCESS: List created successfully\n");
    return(list);
}

extern int add_node_at_end(P_node_t head , int data)
{
    P_node_t new_node = NULL;
    P_node_t current = NULL;

    new_node = (P_node_t) Xmalloc(SIZE_NODE);

    if(new_node == NULL)
    {
        fprintf(stderr , "ERROR: Failed to a create node\n");
        return(FAILURE);
    }

    if(head == NULL)
    {
        fprintf(stderr , "ERROR: List is not present\n");
        return(FAILURE);
    }

    // entering data
    new_node->p_prev = NULL;
    new_node->data   = data;
    new_node->p_next = NULL;

    current = head->p_next;

    while(current->p_next != head)
    {
       current = current->p_next;
    }

    current->p_next->p_prev = new_node;          // joining previous link of head node to new_node
    new_node->p_next = head;                     // joining new node to head node
    current->p_next = new_node;                 // inserting new node at end 
    new_node->p_prev = current;                 // joining previous link of new node to last node

    fprintf(stdout , "SUCCESS: data is successfully added at end\n");
    return(SUCCESS);
}

extern int add_node_at_front(P_node_t head, int data)
{
    P_node_t new_node = NULL;
    
    new_node = (P_node_t) Xmalloc(SIZE_NODE);

    if(new_node == NULL)
    {
        fprintf(stderr , "ERROR: Failed to create node\n");
        return(FAILURE);
    }

    if(head == NULL)
    {
        fprintf(stderr , "ERROR: List is not present\n");
        return(FAILURE);
    }

    //   entering data
    new_node->p_prev = NULL;
    new_node->data = data;
    new_node->p_next = NULL;

    // inserting at front
    new_node->p_next = head->p_next;          // joining link of new node and the first node
    new_node->p_next->p_prev = new_node;          // joining link of first node and new node
    head->p_next  = new_node;                 // inserting node at front
    new_node->p_prev = head;                  // joining link of new node and head node

    fprintf(stdout , "SUCCESS: data is successfully added at front\n");
    return(SUCCESS);
}

extern int add_node_at_position(P_node_t head , int data , int position)
{
    P_node_t new_node = NULL;
    P_node_t current  = NULL;

    new_node = (P_node_t) Xmalloc(SIZE_NODE);

    if(new_node == NULL)
    {
        fprintf(stderr , "ERROR: Failed to create node\n");
        return(FAILURE);
    }

    if(head == NULL)
    {
        fprintf(stderr , "ERROR: List not found\n");
        return(FAILURE);
    }

    // entering data
    new_node->p_prev = NULL;
    new_node->data  = data; 
    new_node->p_next = NULL;

    current = head;

    for(int i = 0; i < (position-1) ; i++)
    {
        if(current->p_next == head)
        {
            current->p_next->p_prev = new_node;       // joining previous link of head node to new node
            new_node->p_next = current->p_next;       // joining link of new node to head node
            current->p_next  = new_node;              // joining link of last node to new node
            fprintf(stdout , "SUCCESS: %d data is successfully added but not at provided position\n", new_node->data);
            return(SUCCESS);
        }
        current = current->p_next;
    }

    new_node->p_next = current->p_next;          // joining link of new node to  position node
    new_node->p_prev = current;                  // joining link of new node to  position-1th node
    current->p_next->p_prev = new_node;          // joining link of position node to new node
    current->p_next = new_node;                  // inserting node at position

    fprintf(stdout , "SUCCESS: %d data is successfully added at %d position\n", new_node->data, position);
    return(SUCCESS);
}

extern int remove_node_at_end(P_node_t head)
{
    P_node_t current = NULL;
    P_node_t remove  = NULL;
    int      removed_data = 0;

    if(head == NULL)
    {
        fprintf(stderr , "ERROR: List not present\n");
        return(FAILURE);
    }

    current = head->p_next;

    while(current->p_next->p_next != head)
    {
        current = current->p_next;
    }
    
    remove = current->p_next;
    removed_data = remove->data;

    current->p_next = remove->p_next;               // joining link of second last node to head node
    current->p_next->p_prev = current;              // joining link of head to second last node 

    free(remove);              // removing last node
    remove = NULL;

    fprintf(stderr , "SUCCESS: data is successfully removed from end\n");
    return(SUCCESS);
}

extern int remove_node_at_front(P_node_t head)
{
    P_node_t remove = NULL;
    int      removed_data = 0;

    if(head == NULL)
    {
        fprintf(stderr , "ERROR: list is not present\n");
        return(FAILURE);
    }

    remove = head->p_next;
    removed_data = remove->data;

    head->p_next = remove->p_next;           // joining link of head node to second node  
    remove->p_next->p_prev = head;           // joining previous link of second node to head node

    free(remove);         // removing first node
    remove = NULL;

    fprintf(stdout , "SUCCESS: data is successfully removed from front\n");
    return(SUCCESS);
}

extern int remove_node_at_position(P_node_t head , int position)
{
    P_node_t current = NULL;
    P_node_t remove  = NULL;
    int      removed_data = 0;

    if(head == NULL)
    {
        fprintf(stderr , "ERROR: List not present\n");
        return(FAILURE);
    }

    current = head->p_next;

    // reaching till position-1
    for(int i = 1; i < (position-1) ; i++)
    {
        if(current->p_next == head)
        {
            fprintf(stderr , "ERROR: provided position is not available\n");
            return(FAILURE);
        }

        current = current->p_next;
    }

    remove = current->p_next;
    removed_data = remove->data;

    current->p_next = remove->p_next;           //joining link of position-1th node to position+1th node
    remove->p_next->p_prev = current;           // joining link of position+1th node to position-1th node

    free(remove);           // removing position th node
    remove = NULL;

    fprintf(stdout , "SUCCESS: %d data is removed from %d position\n", removed_data, position);
    return(SUCCESS);
}

extern int searching_node(P_node_t head , int data)
{
    P_node_t current = NULL;
    int      position = 1;

    if(head == NULL)
    {
        fprintf(stderr, "ERROR: List not present\n");
        return(FAILURE);
    }

    current = head->p_next;

    //  searching data
    while(current->data != data)
    {
       current = current->p_next;
       position++;
    }
 
    fprintf(stdout , "SUCCESS: %d data is found at %d position\n", data, position);
    return(position);
}

extern int update_data(P_node_t head , int position , int new_data)
{
    P_node_t  current = NULL;

    if(head == NULL)
    {
        fprintf(stderr , "ERROR: list is not present\n");
        return(FAILURE);
    }

    current = head->p_next;

    //  reaching till position
    for(int i = 1; i < position ; i++)
    {
        if(current->p_next == head)
        {
           fprintf(stderr , "ERROR: data is not present till provided position\n\n");
           return(FAILURE); 
        }
        current = current->p_next;
    }

    current->data = new_data;           // updating data

    fprintf(stdout , "SUCCESS: %d data is successfully updated at %d position\n\n", current->data , position);
    return(SUCCESS);
}

extern  int   merge_lists(PP_node_t p_list_a , PP_node_t p_list_b)
{
    int Error = 0;

    if(p_list_a == NULL)
    {
       fprintf(stderr , "ERROR: first list is not present\n");
       return(FAILURE);
    }

    if(p_list_b == NULL)
    {
       fprintf(stderr , "ERROR: second list is not present\n");
       return(FAILURE);
    }

    Error = mergeList(*p_list_a , *p_list_b);      // function call for merging list

    if(Error == FAILURE)
    {
       return(FAILURE);
    }
    
    *p_list_b = NULL;

    fprintf(stdout , "SUCCESS: list merged successfully \n");
    return(SUCCESS);
}

extern int length(P_node_t head)
{
    P_node_t  current = NULL;
    int       length = 0;

    if(head == NULL)
    {
        fprintf(stderr , "ERROR: List is not present\n");
        return(FAILURE);
    }

    current = head;

    //    counting length
    while(current->p_next != head)
    {
        current = current->p_next;
        length++;
    }

    fprintf(stdout , "SUCCESS: %d is the length of the list\n\n", length);
    return(length);
}

extern void reverse_list(P_node_t head)
{
   P_node_t  current = NULL;
   P_node_t  first  = NULL;
   P_node_t  last   = NULL;

   if(head == NULL)
   {
       fprintf(stderr , "ERROR: List is not present\n");
       return;
   }

   current = head->p_next;

   while(current->p_next != head)
   {
       current = current->p_next;
   }

   last = current;
   first = head->p_next;

   while(first != last)
   {
       //      removing first node from list
       head->p_next = first->p_next;            // joining link of  head node to  second node
       head->p_next->p_prev = head;             // joining link of  second node to head node

       //       inserting the first node after last node
       first->p_next = last->p_next;            // joining link of first node to the next of last node 
       first->p_next->p_prev = first;           // joining link of next of last node to first node
       last->p_next = first;                    // joining link of last node to first node 
       first->p_prev = last;                    // joining link of first to last node

       first = head->p_next;                    // changing first node
   }

   fprintf(stdout , "SUCCESS: List reversed successfully\n");
   return;
}

extern void print_list(P_node_t head)
{
  P_node_t  print = NULL;
   
  if(head == NULL)
  {
    fprintf(stderr , "ERROR: List is not present\n");
    return;
  }
   
  print = head->p_next;

  printf("{start}<->");
  while(print != head)
  {
    printf("{%d}<->", print->data);       // printing data
    print = print->p_next;
  }
  printf("{head}\n\n");
  
}

extern P_node_t destroy_list(PP_node_t p_head)
{
   if(p_head == NULL)
  {
    fprintf(stderr , "ERROR: List is not found\n");
    return(NULL);
  }

  if(*p_head == NULL)
  {
    fprintf(stderr , "ERROR; List is not found\n");
    return(NULL);
  } 

  destroyList(*p_head);     //function call for destroying list
  *p_head = NULL;

  fprintf(stdout , "SUCCESS: List destroyed successfully\n");
  return(NULL);
}