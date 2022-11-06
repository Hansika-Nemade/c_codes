//Headers
#include<stdio.h>
#include<stdlib.h>

#include"doubly.h"


// Struct definition
//    Node structure
struct node
{
    P_node_t  p_prev;
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
 *                                        *)  merging two lists
 *                                        *)  searching data
 *                                        *)  length of list
 *                                        *)  update data
 *                                        *)  reverse data
 *                                        *)  Display list
 *                                        *)  destroy list
 */


//                              /*  HELPER FUNCTION  */

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

static void destroyList(P_node_t head_)
{
    P_node_t delete = NULL;
    P_node_t current = NULL;

    current = head_->p_next;

    while(current != NULL)
    {
        delete = current;
        current = current->p_next;
        free(delete);
    }

    free(head_); 
}



//                          /*  INTERFACE FUNCTIONS  */

extern P_node_t  create_list(void)
{
    P_node_t  list = (P_node_t) Xmalloc(SIZE_NODE);

    if(list == NULL)
    {
        fprintf(stderr, "ERROR: Failed to create list\n");
        return(NULL);
    }
    
    list->p_prev = NULL;
    list->data = 0;
    list->p_next = NULL;

    fprintf(stdout , "SUCCESS: List successfully created\n");
    return(list);
}

extern int add_node_at_end(P_node_t head , int data)
{
    P_node_t  current = NULL;
    P_node_t  new_node = (P_node_t) Xmalloc(SIZE_NODE);

    if(new_node == NULL)
    {
        fprintf(stderr , "ERROR: Failed to create a node\n");
        return(FAILURE);
    }

    current = head;

    while(current->p_next != NULL)
    {
        current = current->p_next;
    }

    current->p_next = new_node;  // adding node at last
    new_node->data  = data;       // inserting data
    new_node->p_next = NULL;  
    new_node->p_prev  = current;    // joining link from new node to last node

    fprintf(stdout , "SUCCESS: data is successfully added at end\n");
    return(SUCCESS);
}

extern int add_node_at_front(P_node_t head , int data)
{
    P_node_t new_node = (P_node_t) Xmalloc(SIZE_NODE);

    if(new_node == NULL)
    {
        fprintf(stderr , "ERROR: Failed to create a node\n");
        return(FAILURE);
    }

    new_node->p_next = head->p_next;     // connecting new node to first node  
    new_node->p_prev = head;             // connecting new node to head
    head->p_next->p_prev = new_node;     // adding new node in front
    head->p_next  = new_node;            // connecting head node to new node 

    new_node->data = data;      // inserting data

    fprintf(stdout , "SUCCESS: data is successfully added at front\n");
    return(SUCCESS);
}

extern int add_node_at_position(P_node_t head , int data , int position )
{
    P_node_t new_node = (P_node_t) Xmalloc(SIZE_NODE);
    P_node_t current = NULL;

    if(new_node == NULL)
    {
        fprintf(stderr , "ERROR: Failed to create a node\n");
        return(FAILURE);
    }
    // inserting data in new node
    new_node->data = data;
    new_node->p_prev = NULL;
    new_node->p_next = NULL;

    current = head;

    for(int le = 0; le < (position-1) ; le++)
    {
        if(current->p_next == NULL)
        {
            current->p_next = new_node;
            new_node->p_prev = current;
            fprintf(stdout , "SUCCESS: %d data is successfully added but not at provided position\n", new_node->data);
            return(SUCCESS);
        }
        current = current->p_next;
    }

    new_node->p_prev = current;                    // connecting new node to position-1th position node
    new_node->p_next = current->p_next;            // adding node to the position
    current->p_next  = new_node;                   // connecting current node(position-1th node) to new node
    new_node->p_next->p_prev = new_node;           // connecting new node to next node

    fprintf(stdout , "SUCCESS: %d data is successfully added at %d position\n", new_node->data , position);        
    return(SUCCESS);
}

extern int remove_node_at_end(P_node_t head )
{
    P_node_t current = NULL;
    P_node_t remove = NULL;

    int removed_data = 0;

    current = head;

    if(head->p_next == NULL) 
    {
		fprintf(stderr, "ERROR: List is Not Present \n");
		return(FAILURE);
	}
   
    while(current->p_next->p_next != NULL)
    {
        current = current->p_next;
    }

    remove = current->p_next;
    current->p_next = NULL;
    free(remove);
    
    fprintf(stdout , "SUCCESS: data is successfully removed from end\n");
    return(SUCCESS);
}


extern int remove_node_at_front(P_node_t head)
{
    P_node_t current = NULL;
    P_node_t removed_node = NULL;
    int removed_data = 0;
    
    if(head->p_next == NULL)
    {
        fprintf(stderr , "ERROR: List is not present\n");
        return(FAILURE);
    }

    removed_node = head->p_next;
    removed_data = removed_node->data;
    
    current = head;

    current->p_next = removed_node->p_next;    //  linking head node to the second node (removing link of front node from head side)
    current->p_next->p_prev = current;         // linking second node to head node  (removing node from front)

    free(removed_node);   //deleting front node

    fprintf(stdout , "SUCCESS: data is successfully removed from front\n");
    return(SUCCESS);
}

extern int remove_node_at_position(P_node_t head , int position)
{
    P_node_t current = NULL;
    P_node_t remove_node = NULL;
    int removed_data = 0;

    if(head->p_next == NULL)
    {
        fprintf(stderr , "ERROR: list not present\n");
        return(FAILURE);
    }

    current = head;

    for(int le = 0; le < (position-1) ; le++)
    {
        if(current->p_next == NULL)
        {
            fprintf(stderr , "ERROR: provided position is not present\n");
            return(FAILURE);
        }
        current = current->p_next;
    }

    remove_node = current->p_next;
    removed_data = remove_node->data;

    remove_node->p_next->p_prev = current;  // joining link of position+1th node to current node
    current->p_next = remove_node->p_next;  // joining current node to position+1th node

    free(remove_node);   // deleting position node

    fprintf(stdout , "SUCCESS: %d data is removed from %d position\n" , removed_data, position);
    return(SUCCESS);
}

extern int merge_lists(P_node_t list_a , P_node_t list_b)
{
    P_node_t  current = NULL;

    if(list_a == list_b)
    {
        fprintf(stderr , "ERROR: you have given same list twice\n\n");
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

    current = list_a->p_next;
    // finding last node of list_a
    while(current->p_next != NULL)
    {
        current = current->p_next;
    }

    // merging lists
    list_b->p_next->p_prev = current;
    current->p_next = list_b->p_next;

    free(list_b);
    list_b = NULL;

    fprintf(stdout , "SUCCESS: lists are successfully merged\n");
    return(SUCCESS);
}

extern int searching_node(P_node_t head , int data)
{
    P_node_t current = NULL;
    int    pos = 0;

    if(head == NULL)
    {
        fprintf(stderr , "ERROR: list not present\n");
        return(FAILURE);
    } 

    current = head->p_next;
     
    // searching data and position
    while(current != NULL)     
    {
        pos++;
    
        if(current->data == data)
        {
           fprintf(stdout , "SUCCESS: %d data is founded at %d position\n\n", current->data, pos) ;
           return(pos);
        }

        current = current->p_next;
    }

    fprintf(stderr , "ERROR: %d data is not found \n", data);
    return(FAILURE);
}

extern int length(P_node_t head)
{
    P_node_t current = NULL;
    int position = 0;

    if(head == NULL)
    {
        fprintf(stderr , "ERROR: list is not present\n");
        return(0);
    }

    current = head;

    while(current->p_next != NULL)
    {
       current = current->p_next; 
       position++;                  // counting number of nodes
    }

    fprintf(stdout , "SUCCESS: length of the list is %d \n\n", position);
    return(position);
}

extern int update_data(P_node_t head , int pos , int new_data)
{
    P_node_t current = NULL;

    if(head == NULL)
    {
        fprintf(stderr , "ERROR: list is not present\n");
        return(FAILURE);
    }

    current = head;
    
    //finding position
    for(int le = 0; le < pos ; le++)
    {
        if(current->p_next == NULL)
        {
            fprintf(stderr , "ERROR: position not found\n");
            return(FAILURE);
        }
        current = current->p_next;
    }

    current->data = new_data;   //updating data

    fprintf(stdout , "SUCCESS: %d data is successfully updated at %d position\n", current->data, pos);
    return(SUCCESS);
}


extern void reverse_list(P_node_t head)
{
    P_node_t current = NULL;
    P_node_t first   = NULL;
    P_node_t last    = NULL;

    if(head == NULL)
    {
        fprintf(stderr , "ERROR: List not present\n");
        return;
    }

    first = head->p_next;
    current = head->p_next;

    while(current->p_next != NULL)
    {
        current = current->p_next;
    }

    last = current;
    while(first != last)
    {
        head->p_next = first->p_next;                    // breaking link of first node to head node
        first->p_next->p_prev = first->p_prev;           // joining head node to node next to first node
        first->p_next = last->p_next;                    // inserting node next to last node 
        first->p_prev = last;                            // joining link of first node to last node
        last->p_next = first;                            // joining link of last node  to first node

        first = head->p_next;                            // changing first
    }

    fprintf(stdout , "SUCCESS: list reversed successfully\n");
    return;
}
extern void print_list(P_node_t head)
{
    P_node_t print = NULL;

    if(head == NULL )
    {
        fprintf(stderr , "ERROR: list not present\n");
        return;
    }
 
    print = head->p_next;

    printf("{start}->");
    while(print != NULL)
    {
       printf("{%d}<->", print->data);
       print = print->p_next;
    }
    printf("{end}\n\n");
    return;
}


extern P_node_t destroy_list(PP_node_t p_head)
{
    if(p_head == NULL)
    {
        fprintf(stderr , "ERROR: list not found\n");
        return(NULL);
    }

    if(*p_head == NULL)
    {
        fprintf(stderr , "ERROR: list not present\n");
        return(NULL);
    }

    destroyList(*p_head);   // destroying list

    *p_head = NULL;
    fprintf(stdout , "SUCCESS: list destroyed successfully\n");
    return(NULL);
}
