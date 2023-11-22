/**
* @file: pattern16.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern16()
*					             * 
*				           *	 *
* 			       *	 *	 *
* 		     *	 *	 *	 * 
*	     *	 *	 *	 *	 *
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern16(void)
{
  int ole = 1, ile = 1;

  //   terminating condition
  for(ole = 5 ; ole <= 5 && ole > 0 ; ole--)
  {
    for(ile = 1 ; ile <= 5 ; ile++)
    {
      if(ile >= ole)
      {
        printf("*   ");   // 3 space
      }
      else
      {
        printf("    ");   // 4 space
      }
      
    }
    ile = 1;
    printf("\n");
  }

  return;
}

