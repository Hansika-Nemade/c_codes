/**
* @file: pattern41.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern41()
*					                 *	
*				               *		   *
*			             *				       *
*		           *						           *
*	         *								               *
*		           *						           *
*			             *				       *
*				               *		   *
*					                 *
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern41(void)
{
  int ole = 1, ile = 1;
  int space = 5, space2 = 5;

  while(ole <= 9)
  {
    while(ile <= 9)
    {
      if(ile == space || ile == space2)
      {
        printf("*   ");               // 3 spaces
      }
      else
      {
        printf("    ");              // 4 spaces 
      }

      ile++; 

    }

    ile = 1;
    if(ole > 4)
    {
      space++;
      space2--;
    }
    else
    {
      space--;
      space2++;
    }

    ole++;
    printf("\n");
  }

  return;
}
