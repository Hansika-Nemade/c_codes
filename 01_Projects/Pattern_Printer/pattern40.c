/**
* @file: pattern40.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern40()
*	                     5		 5		 5		 5		  5
* 		                    4		  4		  4		  4
* 			                     3		 3		 3
*				                        2		  2
* 					                       1	
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern40(void)
{
  int ole = 1, ile = 1;
  int num1 = 5, space = 0;

  while(ole <= 5)
  {
    while(ile <= 5)
    {
      if(ile <= space)
      {
        printf("    ");                 // 4 spaces
      }
      else
      {
        printf("%d      ",num1);        // 6 spaces 
      }

      ile++;
    }

    num1--;
    ile = 1;

    space++;

    ole++;  
    printf("\n");
  }

  return;
}
