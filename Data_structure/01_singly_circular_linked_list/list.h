#ifndef _LIST_H
#define _LIST_H

#include<stdbool.h>

#define  success    1
#define  failure    0
#define  list_data_not_found  2
#define  list_empty           3      
#define  NODE_SIZE      (sizeof(struct node))
            

typedef   int   data_t;          //type of data stored in list
typedef   int   status_t;        //Success status of function
typedef   int   len_t;           //length of the list 

typedef   struct node   node_t;          // data type  of node 
typedef   struct node*  p_node_t;        //   pointer to node
typedef   p_node_t      list_t;         //   represents the list 
typedef   struct node** p_list_t;       //   pointer to pointer to node or pointer to list

struct node
{
    data_t   data;      // data
    p_node_t next;      // next link
};



//                       /* INTERFACE FUNCTION */
 list_t create_list(void);
 
 status_t  insert_start(list_t list, data_t data);
 status_t  insert_end(list_t list, data_t data);
 status_t  insert_after(list_t list, data_t e_data, data_t data);              // e_data - existing data
 status_t  insert_before(list_t list, data_t e_data, data_t data);

 status_t  get_start(list_t list, data_t* p_data);                           // p_data - pointer to data_t
 status_t  get_end(list_t list, data_t* p_data);                             
 status_t  pop_start(list_t list, data_t* p_data);
 status_t  pop_end(list_t list, data_t* p_data);

 status_t  remove_start(list_t list);
 status_t  remove_end(list_t list);
 status_t  remove_data(list_t list, data_t data);

 bool  is_list_empty(list_t list);
 len_t get_length(list_t list);
 bool  find_data(list_t list, data_t data);

 void  show_list(list_t list, const char* msg);
 status_t  destroy_list(p_list_t p_list);

 list_t sort_list_imm(list_t list);
 status_t sort_list_m(list_t list);

 list_t concat_list_imm(list_t list1, list_t list2);
 status_t concat_list_m(list_t list1, p_list_t list2);

 list_t merge_lists(list_t list1, list_t list2);

 list_t  reverse_list_imm(list_t list);
 status_t reverse_list_m(list_t list);


//                       /* HELPER FUNCTIONS */
 static p_node_t get_node(data_t data);
 static p_node_t get_p_prev(list_t list, p_node_t node);
 static void  generic_insert(p_node_t p_start, p_node_t p_mid, p_node_t p_end);
 static void  generic_delete(list_t list, p_node_t p_delete);              
 static p_node_t search_node(list_t list, data_t data);  
 static void  to_array(list_t list, data_t** p_array, size_t* p_size);
 static list_t to_list(data_t* p_array, size_t size); 
 static void sort(data_t* arr, size_t size); 
 static void quick_sort(data_t* arr, int start_index, int end_index);
 static int  partition(data_t* arr, int start_index, int end_index);      

#endif 