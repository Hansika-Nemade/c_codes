/**
* @file: pattern32.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern32()
*					                *
*				              *		    *
* 			          *		 		        *
* 		        *		 		 		            *
*	        *		 		 		 		                *
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern32(void)
{
  int ole = 1, ile = 1;
  int space = 4, space2 = 5;

  while(ole <= 5)
  {
    while(ile <= 9)
    {
      if(ile <= space)
      {
        printf("    ");
      }
      else if(ile == (space + 1) || ile == space2)
      {
        printf("*   ");
      }
      else
      {
        printf("    ");
      }
      ile++;
    }

    ile = 1;

    space2++;
    space--;
  
    ole++;
    printf("\n");
  }

  return;
}
