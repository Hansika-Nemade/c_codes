//Headers
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"list.h"



/*
 *                                      INTERFACE FUNCTIONS       
*/


list_t create_list(void)
{
   list_t list = NULL;

   list = get_node(0);

   if(list == NULL)
   {
      fprintf(stderr, "ERROR: list is not created\n");
      return(NULL);
   }

   list->next = list;
   list->prev = list;

   return(list);    
}
 
 status_t  insert_start(list_t list, data_t data)
 {
   p_node_t new_node = NULL;

   new_node = get_node(data);
   if(new_node == NULL)
   {
      return(failure);
   }

   generic_insert(list, new_node, list->next);
   return(success);
 }

 status_t  insert_end(list_t list, data_t data)
 {
   p_node_t new_node = NULL;

   new_node = get_node(data);
   if(new_node == NULL)
   {
      return(failure);
   }

   generic_insert(list->prev, new_node, list);
   return(success);
 }

 status_t  insert_after(list_t list, data_t e_data, data_t data)
 {
   p_node_t new_node = NULL;
   p_node_t p_run = NULL;

   new_node = get_node(data);

   p_run = search_node(list, e_data);
   if(p_run == NULL)
   {
      return(list_data_not_found);
   }

   generic_insert(p_run, new_node, p_run->next);
   return(success);
 }  
          
 status_t  insert_before(list_t list, data_t e_data, data_t data)
 {
   p_node_t new_node = NULL;
   p_node_t p_run = NULL;

   new_node = get_node(data);

   p_run = search_node(list, e_data);
   if(p_run == NULL)
   {
      return(list_data_not_found);
   }

   generic_insert(p_run->prev, new_node, p_run);
   return(success);
 }

 status_t  get_start(list_t list, data_t* p_data)      // p_data - pointer to data_t
 {
   if(list->next == list)
   {
      return(list_empty);
   }

   *p_data = list->next->data;
   return(success);
 }

 status_t  get_end(list_t list, data_t* p_data)
 {
   if(list->next == list)
   {
      return(list_empty);
   }

   *p_data = list->prev->data;
   return(success);
 }  

 status_t  pop_start(list_t list, data_t* p_data)
 {
   if(list->next == list)
   {
      return(list_empty);
   }

   *p_data = list->next->data;
   generic_delete(list->next);

   return(success);
 }
 status_t  pop_end(list_t list, data_t* p_data)
 {
   if(list->next == list)
   {
      return(list_empty);
   }

   *p_data = list->prev->data;
   generic_delete(list->prev);

   return(success);
 }

 status_t  remove_start(list_t list)
 {
   if(list->next == list)
   {
      return(list_empty);
   }

   generic_delete(list->next);

   return(success);
 }

 status_t  remove_end(list_t list)
 {
   if(list->next == list)
   {
      return(list_empty);
   }

   generic_delete(list->prev);

   return(success);
 }

 status_t  remove_data(list_t list, data_t data)
 {
   p_node_t e_node = NULL;

   if(list->next == list)
   {
      return(list_empty);
   }

   e_node = search_node(list, data);

   if(e_node == NULL)
   {
      return(list_data_not_found);
   }

   generic_delete(e_node);

   return(success);
 }

 bool  is_list_empty(list_t list)
 {
   if(list->next == list)
   {
      return(true);
   }

   return(false);
 }

 len_t get_length(list_t list)
 {
   len_t length = 0;
   p_node_t p_run = NULL;

   p_run = list->next;
   while(p_run != list)
   {
      length++;
      p_run = p_run->next;
   }

   return(length);
 }

 bool  find_data(list_t list, data_t data)
 {
   p_node_t search = NULL;

   search = search_node(list, data);

   return(search != NULL);
 }

 void  show_list(list_t list, const char* msg)
 {
   p_node_t p_run = NULL;
   puts(msg);

   p_run = list->next;
   printf("[start]<->");
   while(p_run != list)
   {
      printf("[%d]<->", p_run->data);
      p_run = p_run->next;
   }
   printf("[end]\n\n");

   return;
 }

 status_t  destroy_list(p_list_t p_list)
 {
   p_node_t p_run = NULL;
   p_node_t list = NULL;
   p_node_t delete = NULL;

   list = *p_list;
   p_run = list->next;
   while(p_run != list)
   {
      delete = p_run;
      p_run = p_run->next;
      free(delete);
   }

   free(list);
   list = NULL;

   *p_list = NULL;

   return(success);
 }

 list_t sort_list_imm(list_t list)
 {
   p_node_t sorted_list = NULL;
   data_t* array = NULL;
   size_t  size  = 0;

   to_array(list, &array, &size);

   sort(array, size);

   sorted_list = to_list(array, size);

   return(sorted_list);
 }

 status_t sort_list_m(list_t list)
 {
   p_node_t p_run = NULL;
   data_t* array = NULL;
   size_t  size  = 0;
   data_t  index = 0;

   to_array(list, &array, &size);

   sort(array, size);

   p_run = list->next;
   while(p_run != list)
   {
      p_run->data = array[index];
      index++;
      p_run = p_run->next;
   }

   return(success);
 }

 list_t concat_list_imm(list_t list1, list_t list2)
 {
   list_t new_list = NULL;
   p_node_t p_run = NULL;

   new_list = create_list();
   
   p_run = list1->next;
   while(p_run != list1)
   {
      insert_end(new_list, p_run->data);
      p_run = p_run->next;
   }

   p_run = list2->next;
   while(p_run != list2)
   {
      insert_end(new_list, p_run->data);
      p_run = p_run->next;
   }

   return(new_list);
 }

 status_t concat_list_m(list_t list1, p_list_t p_list2)
 {
   p_node_t p_run = NULL;
   p_node_t list2 = *p_list2;

   if(list2 == NULL)
   {
      return(success);
   }
   
   // connecting list1 and list2
   list1->prev->next = list2->next;    //joining list1 last node to first node of list2
   list2->next->prev = list1->prev;    //joining list2 first node to last node of list1
   list1->prev = list2->prev;          //joining head node of list1 to last node of list2
   list2->prev->next = list1;          //joining last node of list2 to head node of list1

   free(list2);     // deleting head node of list2
   list2 = NULL;
   *p_list2 = NULL;
   
   return(success);
 }

 list_t merge_lists(list_t list1, list_t list2)
 {
   p_node_t p_run1 = NULL;
   p_node_t p_run2 = NULL;
   list_t   merged_list = NULL;

   merged_list = create_list();

   p_run1 = list1->next;
   p_run2 = list2->next;

   while(true)
   {
      if(p_run1 == list1)
      {
        while(p_run2 != list2)
        {
          insert_end(merged_list, p_run2->data);
          p_run2 = p_run2->next;
        }
        break;
      }

      if(p_run2 == list2)
      {
        while(p_run1 != list1)
        {
          insert_end(merged_list, p_run1->data);
          p_run1 = p_run1->next;
        }
        break;
      }

      if(p_run1->data <= p_run2->data)
      {
         insert_end(merged_list, p_run1->data);
         p_run1 = p_run1->next;
      }
      else
      {
         insert_end(merged_list, p_run2->data);
         p_run2 = p_run2->next;
      }
   }

   return(merged_list);
 }

 list_t  reverse_list_imm(list_t list)
 {
   list_t reversed_list = NULL;
   p_node_t p_run = NULL;

   reversed_list = create_list();

   p_run = list->prev;
   while(p_run != list)
   {
      insert_end(reversed_list, p_run->data);
      p_run = p_run->prev;
   }

   return(reversed_list);
 }

 status_t reverse_list_m(list_t list)
 {
   p_node_t p_first_node = NULL;
   p_node_t p_last_node = NULL;
   p_node_t current_node = NULL;
   
   p_last_node = list->prev;
   p_first_node = list->next;

   while(list->next != p_last_node)
   {
      current_node = list->next;      // node which has to move after p_last_node

      current_node->prev->next = current_node->next;    //joining head node to next of current_node
      current_node->next->prev = current_node->prev;    //joining next of current_node to head node

      // inserting current node after p_last_node
      current_node->prev = p_last_node;                 //joining current_node to p_last_node
      current_node->next = p_last_node->next;           //joining current_node to next of p_last_node

      p_last_node->next->prev = current_node;           //joining next of p_last_node to current_node
      p_last_node->next = current_node;                 //joining p_last_node to current_node
      
   }

   return(success);
 }

 

/*
 *                                     HELPER FUNCTION
*/
 
 static p_node_t get_node(data_t data)
 {
    p_node_t  new_node = NULL;

    new_node = (p_node_t)malloc(NODE_SIZE);

    if(new_node == NULL)
    {
        fprintf(stderr, "ERROR:fatal: out of virtual memory\n");
        return(NULL);
    }

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return(new_node);
 }

 static void  generic_insert(p_node_t p_start, p_node_t p_mid, p_node_t p_end)
 {
    p_mid->prev = p_start;
    p_mid->next = p_end;

    p_start->next = p_mid;
    p_end->prev = p_mid; 
 }

 static p_node_t search_node(list_t list, data_t s_data)
 {
   p_node_t p_run = NULL;

   p_run = list->next;
   while(p_run != list)
   {
      if(p_run->data == s_data)
      {
         return(p_run);
      }
      p_run = p_run->next; 
   }

   return(NULL);
 }

 static void  generic_delete(p_node_t p_delete)
 {
   p_delete->prev->next = p_delete->next;
   p_delete->next->prev = p_delete->prev;

   free(p_delete);
   p_delete = NULL;

   return;
 } 

 static void to_array(list_t list, data_t** p_array, size_t* p_size)
 {
   data_t* arr = NULL;
   len_t length = 0;
   p_node_t p_run = NULL;
   int index = 0;

   length = get_length(list);
   *p_size = length;

   arr = (data_t*)malloc(length * sizeof(data_t));
   
   p_run = list->next;
   while(p_run != list)
   {
      arr[index] = p_run->data;
      index++;
      p_run = p_run->next;
   }

   *p_array = arr;

   return;
 }

 static list_t to_list(data_t* p_array, size_t size)
 {
   list_t arr_list = NULL;

   arr_list = create_list();

   for(int i = 0; i < size ; i++)
   {
      insert_end(arr_list, p_array[i]);
   }

   return(arr_list);
 }

 static void sort(data_t* arr, size_t size)
 {
   quick_sort(arr, 0, size-1);
 } 

 static void quick_sort(data_t* arr, int start_index, int end_index)
 {
   int mid = 0;

   if(start_index < end_index)
   {
      mid = partition(arr, start_index, end_index);
      quick_sort(arr, start_index, mid-1);
      quick_sort(arr, mid+1, end_index);
   }
 }


 static int  partition(data_t* arr, int start_index, int end_index)
 {
   int pivot = arr[end_index];
   /*
      i = represents that elements from start of array till ith index is less than pivot
   */
   int i = start_index-1;
   int j = start_index;
   int tmp = 0;

   for(j = start_index ; j < end_index ; j++)
   {
      if(arr[j] < pivot)
      {
         i++;
         tmp = arr[i];
         arr[i] = arr[j];
         arr[j] = tmp;
      }
   }

   arr[end_index] = arr[i+1];
   arr[i+1] = pivot;

   return(i+1);
 }

