/**
* @file: pattern21.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern21()
* 					              *			
*				              *	  *	  *			
*			            *	  *	  *	  *	  *		
*		          *	  *   *	  *	  *	  *	  *		
*	        *	  *	  *	  *	  *	  *	  *	  *	  *
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern21(void) 
{
  int ole = 1, ile = 1;
  int space = 4, i = 5;

  for(ole = 1 ; ole <= 5 ; ole++)
  {
    for(ile = 1 ; ile <= i ; ile++)
    {
      if(ile <= space)
      {
        printf("    ");    // 4 spaces
      }
      else
      {
        printf("*   ");   // 3 spaces
      }
    }

    ile = 1;
    space--;
    i++;

    printf("\n"); 
  }

  return;
}

