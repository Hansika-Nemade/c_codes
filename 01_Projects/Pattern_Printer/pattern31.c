/**
* @file: pattern31.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern31()
*	      *								                *
*		        *						            *
* 			        *		 		        *
* 				          * 	 	  *
*					              *
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern31(void)
{
  int ole = 1, ile = 1;
  int space = 1, space2 = 9;

  while(ole <= 5)
  {
    while(ile <= 9)
    {
      if(ile == space || ile == space2)
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
    space2--;
    space++;

    ole++;
    printf("\n");
  }

  return;
}
