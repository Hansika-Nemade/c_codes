
//  Headers
#include<stdio.h>
#include<stdlib.h>

#include"singly_circular.h"


/*  Node structure */
//  struct definition
struct node
{
      int     data; 
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

//                                      /* HELPER FUNCTIONS */
static  void* Xmalloc(int size)
{
  void* p = malloc(size);

  if(p == NULL)
  {
    fprintf(stderr , "ERROR: Out of memory\n");
    return(NULL);
  }

  return(p);
}

static void  destroyList(P_node_t head)
{
  P_node_t  current = NULL;
  P_node_t  delete_node = NULL;

  current = head->p_next;

  while(current != head)
  {
    delete_node = current;
    current = current->p_next;
 
    free(delete_node);            // destroying  node
    delete_node = NULL;
  }

  free(head);
  head = NULL;
}

static int mergeList(P_node_t list_a , P_node_t list_b)
{
  P_node_t current = NULL;
  P_node_t b_last_node = NULL;

  if(list_a == list_b)
  {
    fprintf(stderr , "ERROR: you have given same list twice\n");
    return(FAILURE);
  }
  
  current = list_b->p_next;
  while(current->p_next != list_b)
  {
    current = current->p_next;
  }

  b_last_node = current;                // noting the address of last node of list b

  current = list_a->p_next;
  while(current->p_next != list_a)
  {
    current = current->p_next;
  }

  current->p_next = list_b->p_next;    // merging the lists (joining list b at the last of list a)
  b_last_node->p_next = list_a;        // joining the last node link to head node 

  free(list_b);
  list_b = NULL;

  return(SUCCESS);
}

//                                        /* INTERFACE FUNCTIONS */

extern P_node_t create_list(void)
{
   P_node_t node = (P_node_t) Xmalloc(SIZE_NODE);
 
   if(node == NULL)
   {
     fprintf(stderr , "ERROR: Out of memory\n");
     return(NULL);
   }
   
   node->data = 0;
   node->p_next = node;

   fprintf(stdout , "SUCCESS: List created successfully created\n");
   return(node);
} 

extern int add_node_at_end(P_node_t head , int data)
{
   P_node_t new_node = NULL;
   P_node_t current = NULL;
   P_node_t first_node = NULL;

   new_node = (P_node_t) Xmalloc(SIZE_NODE);

   if(new_node == NULL)
   {
     fprintf(stderr , "ERROR: Failed to create node\n");
     return(FAILURE);
   }

   if(head == NULL)
   {
     fprintf(stderr , "ERROR: List not present\n");
     return(FAILURE);
   }
  
  // entering data
   new_node->data = data;
   new_node->p_next = NULL;
   
   current = head->p_next;

  // inserting data at end
  while(current->p_next != head)
  {
    current = current->p_next;
  }

  current->p_next = new_node;      // inserting new node at end
  new_node->p_next = head;         // joining link of new node to head node

  fprintf(stdout , "SUCCESS: Data is successfully added at end\n");
  return(SUCCESS);
}

extern int add_node_at_front(P_node_t head , int data)
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
  
  // entering data
  new_node->data = data;
  new_node->p_next = NULL;

  // inserting at front
  new_node->p_next = head->p_next;            // joining link of new node to first node
  head->p_next = new_node;                    // joining link of head node to new node

  fprintf(stdout , "SUCCESS: Data is successfully added at front\n");
  return(SUCCESS);
}

extern int add_node_at_position(P_node_t head , int data, int position)
{
  P_node_t   new_node = NULL;
  P_node_t   current = NULL;
  
  new_node = (P_node_t) Xmalloc(SIZE_NODE);

  if(new_node == NULL)
  {
    fprintf(stderr , "ERROR: Failed to create node\n");
    return(FAILURE);
  }

  if(head == NULL)
  {
    fprintf(stderr , "SUCCESS: List is not present\n");
    return(FAILURE);
  }

  //entering data
  new_node->data = data;
  new_node->p_next = NULL;

  current = head;
  
  // reaching till position-1th position
  for(int i = 0; i < (position-1) ; i++) 
  {
    if(current->p_next == head)
    {
      current->p_next = new_node;           // joining link of last node to new node
      new_node->p_next = head ;             // joining link of new node to head node
      fprintf(stdout , "SUCCESS: %d data is successfully added but not at provided position\n", new_node->data);
      return(SUCCESS);
    }
    current = current->p_next;
  }

  // inserting data at position
  new_node->p_next = current->p_next;        // joining link of new node to position th node
  current->p_next = new_node;                // joining link of position-1th node to new node

  fprintf(stdout , "SUCCESS: %d Data is successfully added at %d position\n", new_node->data, position);
  return(SUCCESS);
}

extern int remove_node_at_end(P_node_t head)
{
  P_node_t current = NULL;
  P_node_t delete = NULL;

  if(head == NULL)
  {
    fprintf(stderr , "ERROR: List is not present\n");
    return(FAILURE);
  }

  current = head->p_next;
  
  // reaching to the second last node
  while(current->p_next->p_next != head)
  {
    current = current->p_next;
  }

  delete = current->p_next;
  current->p_next = delete->p_next;        // joining link of second last node to head node

  free(delete);         // removing data 
  delete = NULL;

  fprintf(stdout , "SUCCESS: data is successfully removed from end\n");
  return(SUCCESS);
}

extern int remove_node_at_front(P_node_t head)
{
  P_node_t delete = NULL;
  int      removed_data = 0;

  if(head == NULL)
  {
    fprintf(stderr , "ERROR: List is not present\n");
    return(FAILURE);
  }

  delete = head->p_next;
  removed_data = delete->data;
  head->p_next = delete->p_next;      // joining link of head node to the second node

  free(delete);      // removing front data
  delete = NULL;

  fprintf(stdout , "SUCCESS: data is successfully removed from front\n");
  return(SUCCESS);
}


extern int remove_node_at_position(P_node_t head, int position)
{
  P_node_t current = NULL;
  P_node_t delete = NULL;
  int      removed_data = 0;

  if(head == NULL)
  {
    fprintf(stderr , "ERROR: List is not present\n");
    return(FAILURE);
  }
  
  current = head->p_next;

  //   reaching till position-1th position
  for(int i = 1; i < (position-1) ; i++)
  {
    if(current->p_next == head)
   {
      fprintf(stderr , "ERROR: provided position is not present in list\n");
      return(FAILURE);
   }

   current = current->p_next;
  }
  
  delete = current->p_next;
  removed_data = delete->data;
  current->p_next = delete->p_next;     // joining link of position-1th node to position+1th node

  free(delete);       // removing data of position
  delete = NULL;

  fprintf(stdout , "SUCCESS: %d data is successfully removed at %d position\n", removed_data, position);
  return(SUCCESS);
}

extern int searching_node(P_node_t head , int data)
{
  P_node_t current = NULL;
  int      position = 1;

  if(head == NULL)
  {
    fprintf(stderr , "ERROR: List is not present\n");
    return(FAILURE);
  }

  current = head->p_next;
  
  // node is searching
  while(current->data != data)
  {
    current = current->p_next;
    position++;
  }

  fprintf(stdout , "SUCCESS: %d data is found at %d position\n\n", data , position);
  return(position);
}

extern int update_data(P_node_t head , int position , int new_data)
{
  P_node_t current = NULL;

  if(head == NULL)
  {
    fprintf(stderr , "ERROR: list is not found\n");
    return(FAILURE);
  }

  current = head->p_next;

  // reaching till given position
  for(int i = 1; i < position ; i++)
  {
    if(current->p_next == head)
    {
      fprintf(stderr , "ERROR: data is not present till provided position\n\n");
      return(FAILURE);
    }

    current = current->p_next;
  }

  current->data = new_data;      // updating data

  fprintf(stdout , "SUCCESS: %d data is successfully updated at %d position\n\n", current->data , position);
  return(SUCCESS);
}

extern int merge_lists(PP_node_t p_list_a , PP_node_t p_list_b)
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

   Error = mergeList(*p_list_a , *p_list_b);       // function call for merging list

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
  P_node_t current = NULL;
  int length = 1;

  if(head == NULL)
  {
    fprintf(stderr , "ERROR: list is not present\n");
    return(FAILURE);
  }

  current = head->p_next;

  while(current->p_next != head)
  {
    current = current->p_next;
    length++;
  }

  fprintf(stdout , "SUCCESS: %d is the length of the list\n", length);
  return(length);
}

extern void reverse_list(P_node_t head)
{
  P_node_t current = NULL;
  P_node_t last_node = NULL;
  P_node_t first_node = NULL;

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

  last_node = current;
  first_node = head->p_next;

  current = NULL;
  
  current = head->p_next;

  while(current != last_node)
  {
    head->p_next = current->p_next;
    current->p_next = last_node->p_next;
    last_node->p_next = current;
    current = head->p_next;
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

  printf("{start}->");
  while(print != head)
  {
    printf("{%d}->", print->data);     // printing data
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
  
  destroyList(*p_head);    // function for destroying list
  *p_head = NULL;

  fprintf(stdout , "SUCCESS: List is destroyed successfully \n\n");
  return(*p_head);
}
