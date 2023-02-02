//Headers
#include<stdio.h>
#include<stdlib.h>

int  arr[3][3][3][3][3][3][3][3][3][3][3][3];
int value = 1;

//Entry point of function 
int main(void)
{

    /*      arr[3][3][3][3][3][3][3][3][3][3][3][3]
                |  |  |  |  |  |  |  |  |  |  |  |
                |  |  |  |  |  |  |  |  |  |  |  |
                |  |  |  |  |  |  |  |  |  |  |  |
                |  |  |  |  |  |  |  |  |  |  |  |> 3 elements of type integer
                |  |  |  |  |  |  |  |  |  |  |> 3 elements of 1D array
                |  |  |  |  |  |  |  |  |  |> 3 elements of 2D array
                |  |  |  |  |  |  |  |  |> 3 elements of 3D array
                |  |  |  |  |  |  |  |> 3 elements of 4D array
                |  |  |  |  |  |  |> 3 elements of 5D array
                |  |  |  |  |  |> 3 elements of 6D array
                |  |  |  |  |> 3 elements of 7D array
                |  |  |  |> 3 elements of 8D array
                |  |  |> 3 elements of 9D array
                |  |> 3 elements of 10D array
arr is an array |> 3 elements of 11D array
    

        total no of elements : 531,441
      
   */
  
  /*               Memory representation till 5D
    |                                                                                                                                                                                                                                                                                                                                   5                                                                                                                                                                                                                                                                                                                                   5                                                                                                                                                                                                                                                                                                                                   |
    |                                                                                                           4                                                                                                           4                                                                                                           |                                                                                                           4                                                                                                           4                                                                                                           |                                                                                                           4                                                                                                           4                                                                                                           |
    |                                   3                                   3                                   |                                   3                                   3                                   |                                   3                                   3                                   |                                   3                                   3                                   |                                   3                                   3                                   |                                   3                                   3                                   |                                   3                                   3                                   |                                   3                                   3                                   |                                   3                                   3                                   |
    |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           |           | 
    |ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|ooo|
           

    */

   /*
            formula:  Base Address + Index1 * size of 11D array
                                   + Index2 * size of 10D array
                                   + Index3 * size of 9D array
                                   + Index4 * size of 8D array
                                   + Index5 * size of 7D array
                                   + Index6 * size of 6D array
                                   + Index7 * size of 5D array
                                   + Index8 * size of 4D array
                                   + Index9 * size of 3D array
                                   + Index10 * size of 2D array
                                   + Index11 * size of 1D array
                                   + Index12 * size of element
   */

    
    // Entering values in array

      for(int index12 = 0 ; index12 < 3 ; index12++)
      {
        for(int index11 = 0 ; index11 < 3 ; index11++)
        {
          for(int index10 = 0 ; index10 < 3 ; index10++)
          {
            for(int index9 = 0 ; index9 < 3 ; index9++)
            {
              for(int index8 = 0 ; index8 < 3 ; index8++)
              {
                for(int index7 = 0 ; index7 < 3 ; index7++)
                {
                  for(int index6 = 0 ; index6 < 3 ; index6++)
                  {
                    for(int index5 = 0 ; index5 < 3 ; index5++)
                    {
                      for(int index4 = 0 ; index4 < 3 ; index4++)
                      {
                        for(int index3 = 0 ; index3 < 3 ; index3++)
                        {
                          for(int index2 = 0 ; index2 < 3 ; index2++)
                          {
                            for(int index1 = 0 ; index1 < 3 ; index1++)
                            {
                               arr[index12][index11][index10][index9][index8][index7][index6][index5][index4][index3][index2][index1] = value;
                               value++;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }


    //    Printing array

    for(int index12 = 0 ; index12 < 3 ; index12++)
    {
        for(int index11 = 0 ; index11 < 3 ; index11++)
        {
          for(int index10 = 0 ; index10 < 3 ; index10++)
          {
            for(int index9 = 0 ; index9 < 3 ; index9++)
            {
              for(int index8 = 0 ; index8 < 3 ; index8++)
              {
                for(int index7 = 0 ; index7 < 3 ; index7++)
                {
                  for(int index6 = 0 ; index6 < 3 ; index6++)
                  {
                    for(int index5 = 0 ; index5 < 3 ; index5++)
                    {
                      for(int index4 = 0 ; index4 < 3 ; index4++)
                      {
                        for(int index3 = 0 ; index3 < 3 ; index3++)
                        {
                          for(int index2 = 0 ; index2 < 3 ; index2++)
                          {
                            for(int index1 = 0 ; index1 < 3 ; index1++)
                            {
 printf("arr[%d][%d][%d][%d][%d][%d][%d][%d][%d][%d][%d][%d] = %d\n", index12,index11,index10,index9,index8,index7,index6,index5,index4,index3,index2,index1, arr[index12][index11][index10][index9][index8][index7][index6][index5][index4][index3][index2][index1]);                        
                            }
                            printf("\n");
                          }
                          printf("\n");
                        }
                        printf("\n");
                      }
                      printf("\n");
                    }
                    printf("\n");
                  }
                  printf("\n");
                }
                printf("\n");
              }
              printf("\n");
            }
            printf("\n");
          }
          printf("\n");
        }
        
      }

      printf("end\n");


    exit(0);
}
