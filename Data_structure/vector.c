//Headers
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

//    global variables
int **pp_array = NULL;
unsigned long long int  size = 0;
int * p_vec = NULL;

// function declarations
int* create_arr(void);
int* add_element(int* list , int data);
int* remove_element(int* list);
void sort_at_position(int* p_arr, int pos);
void sort_arr(int* p_arr);
void print_vec(int* list);
int* destroy(int* list);


// ENTRY POINT OF MAIN FUNCTION
int main(void)
{
   p_vec = create_arr();

   //  adding elements in arr
   for(int i=0 ; i < 10 ; i++)
   {
      p_vec = add_element(p_vec, rand());
   }
   print_vec(p_vec);
   
   //   removing some elements in arr
   p_vec = remove_element(p_vec);
   p_vec = remove_element(p_vec);
   p_vec = remove_element(p_vec);
   print_vec(p_vec);

   //   sorting the arr
   sort_arr(p_vec);
   printf("arr is sorted");
   print_vec(p_vec);

   // deleting arr
   p_vec = destroy(p_vec);
   print_vec(p_vec);

   exit(0);
}


int* create_arr(void)
{
   int* p = NULL;

   p = (int*) malloc(sizeof(int));
   assert(p != NULL);
   memset(p , 0, sizeof(int));  
   *p = 0;
   return(p);
}

int* add_element(int* list , int data)
{
   list = realloc(list , (size+1) * sizeof(int));
   assert(list != NULL);
   
   list[size] = data;
   size++;
   printf("data successfully added\n");
   return(list);
}


int* remove_element(int* list )
{
   list = realloc(list , (size-1) * sizeof(int));
   assert(list != NULL);

   size--;
   printf("data removed successfully \n");
   return(list);
}

void sort_at_position(int* p_arr, int pos)
{
   int key = 0;
   int i = 0;

   key = p_arr[pos];

   for( i =(pos-1) ; i >= 0 ; i--)
   {
      if(p_arr[i] > key)
      {
        p_arr[i+1] = p_arr[i];

      }

      if(p_arr[i] < key)
      {
         break;
      }
   }

   p_arr[i+1] = key;
}

void sort_arr(int* p_arr)
{
   assert(p_arr != NULL);

   for(int pos = 1; pos < size ; pos++ )
   {
      sort_at_position(p_arr, pos);
   }
}

void print_vec(int* list)
{
   if(list == NULL)
   {
      printf("List not present\n");
      return;
   }

   printf("\n");
   for(int index = 0; index < size ; index++)
   {
      printf("p_vec[%d] = %d\n", index, p_vec[index]);
   }
   printf("\n");
   return;
}

int* destroy(int* list)
{
   free(list);
   list = NULL;
   return(NULL);
}




