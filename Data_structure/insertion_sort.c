//Headers
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


//  function declerations
int* get_arr(int N);    
void input_arr(int* p_arr, int N);
void sort_arr(int* p_arr, int N);
void display_arr(int* p_arr, int N);
void release_arr(int **pp_arr );

void insert_sort_at_position(int* p_arr, int N);

// ENTRY POINT OF MAIN FUNCTION
int main(void)
{
    int* arr = NULL;
    int N = 0;

    /*if(argc != 2)
    {
        printf("UsageError:%s no_of_elements\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    N = atoi(argv[1]);



    if(N <= 0 )
    {
        printf("ERROR: bad size for no. of elements\n");
        exit(EXIT_FAILURE);
    }*/

   printf("Enter the no. of element\n");
   scanf(" %d", &N);

   printf("the no is %d\n" , N);

    arr = get_arr(N);

    input_arr(arr , N);

    printf("unsorted array:\n");
    display_arr(arr , N);

    sort_arr(arr , N);

    printf("\nsorted array:\n");
    display_arr(arr , N);

    release_arr(&arr);

    exit(0);
}

 
int* get_arr(int N)
{
    int* p = NULL;

    p = (int*) malloc(N * sizeof(int));
    assert(p != NULL);

    memset(p , 0, N * sizeof(int));
    
    return(p);
}


void input_arr(int* p_arr , int N)
{
   assert(p_arr != NULL);

   for(int i = 0; i < (N-1) ; i++)
   {
       p_arr[i] = rand();
   }

   p_arr[N-1] = -22;

}

void sort_arr(int* p_arr , int N)
{
    assert(p_arr != NULL);

    for( int i = 2; i <= N ; i++)
    {
        insert_sort_at_position(p_arr , i);
    }

}

void display_arr(int* p_arr, int N)
{
    assert(p_arr != NULL);

    for(int i = 0; i < N ; i++)
    {
        printf("p_arr[%d] = %d\n", i, p_arr[i]);
    }
}

void release_arr(int** pp_arr)
{
   assert(pp_arr != NULL);

   free(* pp_arr);
   *pp_arr = NULL;
}

void insert_sort_at_position(int* p_arr , int N)
{
    int key = p_arr[N-1];
    int i = 0;

    assert(p_arr != NULL);

    for( i = N-2 ;  i > -1 && key < p_arr[i]  ;  i--)
    {
       p_arr[i+1] = p_arr[i];
    }

    p_arr[i+1] = key;
}


