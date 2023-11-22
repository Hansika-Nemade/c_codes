/**
* @file: pattern46.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern46()
*                          *	  *	   *	  *	   *	  *	   *	  *	   *	  *	   *	  *	   *
*  	                       *	  *	   *	  *	   *	  *		      *	   *	  *	   *	  *	   *
*	                         *	  *	   *	  *	   *				           *	  *	   *	  * 	 *
* 	                       *	  *	   *	  *						                  *	   *	  *	   *
* 	                       *	  *	   *								                       *	  *	   *
* 	                       *	  *										                              *	   *
* 	                       *												                                   *
* 
*  PARAMETERS :  
*                1) void : 
* 
*  RETURNS :
*                void :
*/

 
//Entry point of function
void pattern46(void)
{
  int ole = 1, ile = 1;
  int space = 6, space2 = 8;

  //   terminating condition
  while(ole <= 7)
  {
    while(ile <= 13)
    {
      if(ile <= space && ile >= space2)
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

    space2--;
    space++;

    ole++;
    printf("\n");
    
  }
}

