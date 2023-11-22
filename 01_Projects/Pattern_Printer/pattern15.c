/**
* @file: pattern15.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern15()
*				                    3
*			                   2	3
*		                  1  2	3
*	                 0  1	 2	3
*		                  1	 2	3
*			                   2	3
*				                    3                    
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern15(void)
{
  int ole = 1, ile = 1;
  int num1 = 3, num = 3, space = 3;
           
  //   terminating condition
  while(ole <= 7)
  {
    while(ile <= 4)
    {
      if(ile <= space)
      {
        printf("    ");
      }
      else
      {
        printf("%d   ",num1);
        num1++;
      }
      ile++;
    }

    ile = 1;

    if(ole > 3)
    {
      space++;
      num++;
    }
    else
    {
      space--;
      num--;
    }

    num1 = num;
    ole++;         //incrementing condition
    printf("\n");

  }

  return;
}

