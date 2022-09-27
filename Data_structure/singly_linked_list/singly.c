//Headers
#include<stdio.h>
#include<stdlib.h>

#include"singly.h"


// Struct definition
//Node structure
struct node
{
    int  data;  
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
 *                                        *)  Display list 
 *                                        *)  reverse list
 *                                        *)  destroy list
 */

//                                        /*     HELPER FUNCTIONS    */

/*
 *  FUNCTION NAME : Xmalloc()
 *                  it allocates memory block 
 * 
 *  PARAMETERS :  
 *                1) int :  takes  size of block to be allocated
 * 
 *  RETURNS :
 *                void*  : returns address of allocated block
 *                         returns NULL if block is not allocated 
 */
static void*  Xmalloc(int  size)
{
    void* p = malloc(size) ;

    if(p == NULL)
    {
        fprintf(stderr, "ERROR: OUT OF MEMORY\n");
        return(NULL);
    }

    return(p);
}

static  void  destroyList(P_node_t head)
{
    P_node_t  current = NULL;
    P_node_t  delete  = NULL;

    if(head == NULL)
    {
        fprintf(stderr , "ERROR: list is not present\n");
        return;
    }

    current = head->p_next;

    while(current != NULL)
    {
        delete = current;
        current = delete->p_next;
        free(delete);
    }

    free(head);
} 


//                                          /*   INTERFACE FUNCTIONS  */

/*
 *  FUNCTION NAME :  create_list()
 *                    it creates a head node of the list
 * 
 *  PARAMETERS :     void
 * 
 *  RETURNS :        P_node_t   (pointer to struct node)
 *                     returns address of head node
 *                     returns NULL  if list is not created
 */

extern P_node_t  create_list(void)
{
    P_node_t  list = (P_node_t) Xmalloc(SIZE_NODE);

    if(list == NULL)
    {
        fprintf(stderr, "ERROR: Failed to create list\n");
        return(NULL);
    }

    list->data = 0;
    list->p_next = NULL;

    fprintf(stdout , "SUCCESS: List successfully created\n");
    return(list);
}

/*
 *  FUNCTION NAME :  add_node_at_end()   
 *                   it add node at end of the list
 *  
 *  PARAMETERS :    
 *                 1) P_node_t  :  takes address of the head node of the list 
 *                 2) int       :  takes data  which has to insert at end of list
 * 
 *  RETURNS :     
 *                 int :  returns 0 (SUCCESS) if node is successfully added at end
 *                        returns 1 (FAILURE) if node is failed to add at end
 */

extern  int   add_node_at_end(P_node_t head , int data)
{
    P_node_t current = NULL;
    P_node_t p = (P_node_t) Xmalloc(SIZE_NODE);

    current = head;

    if(p == NULL)
    {
        fprintf(stderr, "ERROR: Failed to create node\n");
        return(FAILURE);
    }

    // Entering data in new node
    p->data = data;
    p->p_next = NULL;
    
    //    checking for the last node
    while(current->p_next != NULL)
    {
        current = current->p_next;
    }
 
    // adding node at last in list
    current->p_next = p;

    fprintf(stdout, "SUCCESS: Node is successfully added at end\n");
    return(SUCCESS);
}

/*
 *  FUNCTION NAME :   add_node_at_front()
 *                    it add node at the front of the list
 * 
 *  PARAMETERS :  
 *                   1) P_node_t  :  takes address of the head node of the list
 *                   2) int       :  takes data which has to insert front of the list
 *  
 *  RETURNS :
 *                   int : returns 0 (SUCCESS) if node is successfully added at front
 *                         returns 1 (FAILURE) if node is failed to add at front
 */

extern int add_node_at_front(P_node_t head , int data)
{
    P_node_t p = (P_node_t) Xmalloc(SIZE_NODE);

    if(p == NULL)
    {
        fprintf(stderr, "ERROR: Failed to create node\n");
        return(FAILURE);
    }

    // Entering data in new node
    p->data = data;
    p->p_next = head->p_next;

    // adding node in list
    head->p_next = p;

    fprintf(stdout , "SUCCESS: Node is Successfully added at front\n");
    return(SUCCESS);
}


/*
 *  FUNCTION NAME :  add_node_at_position()
 *                   it add node in between at provided position
 *  
 *  PARAMETERS :    
 *                 1) P_node_t  :  takes address of the head node of the list 
 *                 2) int       :  takes data  which has to insert at position
 *                 3) int       :  takes position at which node has to add
 * 
 *  RETURNS :     
 *                 int :  returns 0 (SUCCESS) if node is successfully added at position
 *                        returns 1 (FAILURE) if node is failed to add 
 */

extern int add_node_at_position(P_node_t head, int data, int position)
{
    P_node_t current = NULL;
    P_node_t p = (P_node_t) Xmalloc(SIZE_NODE);

    if(p == NULL)
    {
        fprintf(stderr, "ERROR: Failed to create node\n");
        return(FAILURE);
    }

    //Entering data in new node
    p->data = data;
    p->p_next = NULL;

    current = head;
    
    // loop to reach at position
    for(int le = 0; le < (position-1) ; le++)
    {
        if(current->p_next == NULL)
        {
            current->p_next = p;
            fprintf(stdout , "SUCCESS: %d data is successfully added but not at provided position\n", p->data);
            return(SUCCESS);
        }

        current = current->p_next;

    }
    
    // adding node in list
    p->p_next = current->p_next;
    current->p_next = p;

    fprintf(stdout , "success: %d data is successfully added at %d position\n", p->data, position);
    return(SUCCESS);
}

/*
 *  FUNCTION NAME :  remove_node_at_end()
 *                   it removes node from end of the list.
 *  
 *  PARAMETERS :    
 *                 1) P_node_t  :  takes address of the head node of the list 
 * 
 *  RETURNS :     
 *                 int :  returns 0 (SUCCESS) if node is successfully removed form end
 *                        returns 1 (FAILURE) if node is failed to remove from end
 */

extern int remove_node_at_end(P_node_t head)
{
    P_node_t current = NULL;
    P_node_t delete_node = NULL;
    int  removed_data = 0;
    
    current = head;

    if(head->p_next == NULL) {
		fprintf(stderr, "ERROR: List is Not Present \n");
		return(FAILURE);
	}

    //  reaching till last node
    while(current->p_next->p_next != NULL)
    {
        current = current->p_next;
    }

    delete_node = current->p_next;
    current->p_next = NULL;
    removed_data = delete_node->data;

    // removing node 
    free(delete_node);

    fprintf(stdout , "SUCCESS: Last node is successfully removed\n");
    return(SUCCESS);

}

/*
 *  FUNCTION NAME :  remove_node_at_front()
 *                   it remove node from the front of the list
 *  
 *  PARAMETERS :    
 *                 1) P_node_t  :  takes address of the head node of the list 
 * 
 *  RETURNS :     
 *                 int :  returns 0 (SUCCESS) if node is successfull removed from front
 *                        returns 1 (FAILURE) if node is failed to remove from front
 */

extern int remove_node_at_front(P_node_t head)
{
    P_node_t delete_node = NULL;
    int    removed_data = 0;

    delete_node = head->p_next;
    if(delete_node == NULL) 
    {
		fprintf(stderr, "ERROR: List is Not Present For Insertion\n");
		return(FAILURE);
	}

    head->p_next = delete_node->p_next;
    removed_data = delete_node->data;

    // removing node
    free(delete_node);

    fprintf(stdout , "SUCCESS: front node is successfully removed\n");
    return(SUCCESS);
}

/*
 *  FUNCTION NAME :  remove_node_at_position()
 *                   it removes node at provided position
 *  
 *  PARAMETERS :    
 *                 1) P_node_t  :  takes address of the head node of the list 
 *                 2) int       :  take position from node has to remove
 * 
 *  RETURNS :     
 *                 int :  returns 0 (SUCCESS) if node is successfully removed at position
 *                        returns 1 (FAILURE) if node is failed to remove node from position
 */

extern int remove_node_at_position(P_node_t head , int position)
{
    P_node_t delete_node = NULL;
    P_node_t current = NULL;
    int removed_data = 0;

    current = head;

    for(int le = 0; le < (position-1) ; le++)
    {
        if(current->p_next == NULL)
        {
           fprintf(stderr , "ERROR: Provided position is not available\n");
           return(FAILURE);
        }

        current = current->p_next;
    }

    delete_node = current->p_next;

    current->p_next = delete_node->p_next;
    removed_data = delete_node->data;
    free(delete_node);
    
    fprintf(stdout , "SUCCESS: %d data is remove from %d position\n", removed_data, position);
    return(SUCCESS);
}

/*
 *  FUNCTION NAME :  serching()
 *                   it searches the given value in list
 *  
 *  PARAMETERS :    
 *                 1) P_node_t  :  takes address of the head node of the list 
 *                 2) int       :  takes the value which has to be searched
 * 
 *  RETURNS :     
 *                 int :  returns position at which data is found
 *                        returns 1 (FAILURE) if data is not found
 */

extern int searching(P_node_t head , int value)
{
    P_node_t current = NULL;
    int  pos = 1;

    current = head->p_next;

    while( current != NULL)
    {
       if(current->data == value)
       {
           fprintf(stdout , "SUCCESS: %d data is found at %d position\n", current->data, pos);
           return(pos);
       }

       pos++;
       current = current->p_next;
    }

    fprintf(stderr , "ERROR: %d data is not found \n", value);
    return(FAILURE);
}

/*
 *  FUNCTION NAME :  update_data()
 *                   it updates new data at the provided position
 *  
 *  PARAMETERS :    
 *                 1) P_node_t  :  takes address of the head node of the list 
 *                 2) int       :  takes position of node at which data has to update
 * 
 *  RETURNS :     
 *                 int :  returns 0 (SUCCESS) if data is successfully updated
 *                        returns 1 (FAILURE) if position not present or not found
 */
extern  int  update_data(P_node_t head , int pos , int new_data)
{
    P_node_t  current = NULL;

    current = head;

    for(int le = 0; le < pos ; le++)
    {
        // position not found
        if(current->p_next == NULL)
        {
            fprintf(stderr , "ERROR: position not found\n");
            return(FAILURE);
        }
        current = current->p_next;
    }

    // updating data
    current->data = new_data;

    fprintf(stdout , "SUCCESS: data is successfully updated\n");
    return(SUCCESS);
}

/*
 *  FUNCTION NAME :  merge_lists()
 *                   it merges two lists
 *  
 *  PARAMETERS :    
 *                 1) P_node_t  :  takes address of the head node of list1
 *                 2) P_node_t  :  takes address of the head node of list2 
 * 
 *                NOTE:
 *                 value passed to parameters 1  should be the list which comes first
 *                 value passed to parameters 2  should be the list which going to merged in another list
 *  RETURNS :     
 *                 int :  returns 0 (SUCCESS) if lists is merged successfully
 *                        returns 1 (FAILURE) if failed to merged  , list 1 not found , list 2 not found
 */

extern int merge_lists(P_node_t list_a , P_node_t list_b)
{
    P_node_t current = NULL;

    if(list_a == list_b)
    {
        fprintf(stderr , "ERROR: you have given the same list twice\n\n"  );
        return(FAILURE);
    }

    if(list_a == NULL)
    {
       fprintf(stderr , "ERROR: list1 is not present\n");
       return(FAILURE);
    }

    if(list_b == NULL)
    {
       fprintf(stderr , "ERROR: list2 is not present\n");
       return(FAILURE);
    }

    current = list_a;

    while(current->p_next != NULL)
    {
        current = current->p_next;
    }

    //   merging the lists
    current->p_next = list_b->p_next;
    free(list_b);
   
    list_b = NULL;
    fprintf(stdout , "SUCCESS: lists are successfully merged\n");
    return(SUCCESS);
}

/*
 *  FUNCTION NAME :  print_list()
 *                   it displays the data of list
 *  
 *  PARAMETERS :    
 *                 1) P_node_t  :  takes address of the head node of the list 
 * 
 *  RETURNS :      void
 */

extern void print_list(P_node_t head)
{
    P_node_t print = NULL;

    if(head == NULL)
    {
       fprintf(stderr , "ERROR: list is not present\n");
       return;
    }

    print = head->p_next;

    printf("{start}->");
    while(print != NULL)
    {
        printf("[%d]->", print->data);
        print = print->p_next;
    }
    printf("{end}\n\n");
    return;
}

extern void reverse_list(P_node_t head)
{
    P_node_t last = NULL;
    P_node_t current = NULL;
    P_node_t first = NULL;

    if(head == NULL)
    {
       fprintf(stderr , "ERROR: list is not present\n");
       return;
    }

    current = head;

    while(current->p_next != NULL)
    {
        current = current->p_next;
    }

    last = current;
    first = head->p_next;

    while(first != last)
    {
       head->p_next  = first->p_next; // breaking link of first node from head node
       first->p_next = last->p_next;  // inserting first node after the last node
       last->p_next  = first;         // connecting last node to next node(just inserted first node)
       first = head->p_next;          // setting next node to first node
    }
    
    fprintf(stdout , "SUCCESS: list reversed successfully\n");
    return;
} 

extern P_node_t destroy_list(PP_node_t p_head)
{
    if(p_head == NULL)
    {
        fprintf(stderr , "ERROR: list is not found\n");
        return(NULL);
    }

    if(*p_head == NULL)
    {
        fprintf(stderr , "ERROR: list not present\n");
        return(NULL);
    }

    destroyList(*p_head);  // destroying list

    *p_head = NULL;
    fprintf(stdout , "SUCCESS: list destroyed successfully\n");
    return(NULL);
}

