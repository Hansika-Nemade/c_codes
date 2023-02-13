// Headers
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define TRUE  1

// function declaration 
int* allocate_arr(int size);
void sort(int* p_arr, int N);
void  merge_sort(int* p_arr, int p, int r);
void  merge(int* p_arr, int p, int q, int r);
void  output_arr(int* p_arr, int N, const char* msg);
void  release_arr(int** pp_arr);

// Entry point of main function
int main(int argc, char* argv[])
{
   if(argc != 2)
    {
        fprintf(stderr, "Usage Error: Correct Usage %s nr_elements", argv[0]);
        exit(EXIT_FAILURE);
    }

    int N = 0;
    int* p_arr = NULL;

    N = atoi(argv[1]);
    assert(N > 0);

    p_arr = allocate_arr(N);

    output_arr(p_arr, N, "before sort\n");
    sort(p_arr, N);
    output_arr(p_arr, N, "after sort\n");
    release_arr(&p_arr);

    exit(EXIT_SUCCESS);
}

int* allocate_arr(int size)
{
    int* p_arr = NULL;

    p_arr = (int*) malloc(size * sizeof(int));
    assert(p_arr != NULL);

    for(int le = 0; le < size ; le++)
    {
      p_arr[le] = rand();
    }

    return(p_arr);
}

void sort(int* p_arr, int N)
{
    merge_sort(p_arr, 0, N-1);
}

void  merge_sort(int* p_arr, int p, int r)
{
    int q = 0;

    if(p < r)
    {
        q = (p+r)/2;

        merge_sort(p_arr, p, q);
        merge_sort(p_arr, q+1, r);

        merge(p_arr, p, q, r);
    }
}
void  merge(int* p_arr, int p, int q, int r)
{
    int* p_arr1 = NULL;
    int  N1 = 0;

    int* p_arr2 = NULL;
    int  N2 = 0;

    N1 = q-p+1;
    N2 = r-q;

    p_arr1 = (int*) malloc(N1 * sizeof(int));
    p_arr2 = (int*) malloc(N2 * sizeof(int));
    assert(p_arr1 != NULL && p_arr2 != NULL);

    
    for(int le = 0; le < N1 ; le++)
    {
        p_arr1[le] = p_arr[p + le];
    }

    for(int le = 0; le < N2 ; le++)
    {
       p_arr2[le] = p_arr[q+1 + le];
    }

    //output_arr(p_arr1 , N1, "subarray 1: ");
    //output_arr(p_arr2 , N2, "subarray 2: ");

    int i = 0;
    int j = 0;
    int k = 0;

    
    while(TRUE)
    {
        if(p_arr1[i] <= p_arr2[j])
        {
           p_arr[p+k] = p_arr1[i];
           i++;
           k++;

           if(i == N1)
           {
              while(j < N2)
              {
                p_arr[p+k] = p_arr2[j];
                j++;
                k++;
              }
              break;
           }
        }
        else
        {
           p_arr[p+k] = p_arr2[j];
           j++;
           k++;

           if(j == N2)
           {
              while(i < N1)
              {
                p_arr[p+k] = p_arr1[i];
                i++;
                k++;
              }
              break;
           }
        }
    }

    free(p_arr1);
    p_arr1 = NULL;

    free(p_arr2);
    p_arr2 = NULL;

    return;
}

void output_arr(int* p_arr, int N, const char* msg)
{
    puts(msg);

    for(int le = 0; le < N ; le++)
    {
        printf("p_arr[%d] = %d\n", le, p_arr[le]);
    }

    return;
}

void  release_arr(int** pp_arr)
{
   int *p_arr = *pp_arr;

   free(p_arr);
   *pp_arr = NULL;
   p_arr = NULL;

   return;
}