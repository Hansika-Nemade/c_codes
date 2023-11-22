/**
* @file: pattern17.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern17()
*                       *	 *	*	 *	*
*	 	                       *	*	 *	*
*	 	 	                        *	 *	*
*				                         *	*
*					                          *
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern17(void)
{
  int ile = 1;

  //   terminating condition
  for(int ole = 1 ; ole <= 5  ; ole++)
  {
    for(int ile = 1 ; ile <= 5 ; ile++)
    {
      if(ile >= ole)
        printf("*   ");   // 3 spaces
      else
        printf("    ");   // 4 spaces
      
    }
    ile = 1;
    printf("\n");
  }

  return;
}

