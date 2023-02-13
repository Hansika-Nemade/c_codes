//Headers
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// function declaration
int* allocate_arr(int N);
void sort(int* p_arr, int N);
int partition(int* p_arr, int p, int r);
void quick_sort(int* p_arr, int p, int r);
void output_arr(int* p_arr, int N, const char* msg);
void Release_arr(int** pp_arr);

// Entry point of main function
int main(int argc, char* argv[])
{
    int N = 0;
    int* p_arr = NULL;

    if(argc != 2)
    {
        fprintf(stderr, "Usage Error: Correct Usage %s nr_elements", argv[0]);
        exit(EXIT_FAILURE);
    }

    N = atoi(argv[1]);


    p_arr = allocate_arr(N);
    output_arr(p_arr, N, "array before sort :");
    sort(p_arr, N);
    output_arr(p_arr, N, "array after sort :");
    Release_arr(&p_arr);

    exit(EXIT_SUCCESS);
}

int* allocate_arr(int N)
{
   int* p_arr = NULL;

   p_arr = (int*) malloc(N * sizeof(int));
   assert(p_arr != NULL);

   for(int i = 0; i<N ; i++)
   {
     p_arr[i] = rand();
   }

   return(p_arr);
}

void sort(int* p_arr, int N)
{
    quick_sort(p_arr, 0, N-1);
}

int partition(int* p_arr, int p, int r)
{
    int pivot = p_arr[r] ;

    int i = p-1;
    int j = 0;
    int tmp = 0;

    for(j = p ; j < r ; j++)
    {
       if(p_arr[j] < pivot)
       {
          i++;
          tmp = p_arr[i];
          p_arr[i] = p_arr[j];
          p_arr[j] = tmp; 
       }

    }

    p_arr[r] = p_arr[i+1];
    p_arr[i+1] = pivot;

    return(i+1);
}

void quick_sort(int* p_arr, int p, int r)
{
    int q = 0;


    if(p < r)
    {
       q = partition(p_arr, p, r);
       quick_sort(p_arr, p, q-1);
       quick_sort(p_arr, q+1, r);
    }
}

void output_arr(int* p_arr, int N, const char* msg)
{
    puts(msg);

    for(int i = 0; i<N ; i++)
    {
        printf("p_arr[%d] = %d\n", i, p_arr[i]);
    }

    return;
}

void Release_arr(int** pp_arr)
{
    int* p_arr = *pp_arr;

    free(p_arr);
    p_arr = NULL;
    *pp_arr = NULL;

    return;
}

