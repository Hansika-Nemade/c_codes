/**
* @file: pattern26.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern26()
*	       *	*	 *	*	 *	*	 *	*	 *
*		        *	 *	*	 *	*	 *	*		
*			         *	*	 *	*	 *		
*				          *	 *	*		
*					           *	
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern26(void)
{
  int ole = 1, ile = 1, space = 0, space2 = 9;

  //   terminating condition
  while(ole <= 5)
  {
    while(ile <= space2)
    {
      if(ile <= space)
      {
        printf("    ");
      }
      else
      {
        printf("*   ");
      }

      ile++;
    }

    ile = 1;
    space++;
    space2--;
    ole++;
 
    printf("\n");
  }

  return;
}
