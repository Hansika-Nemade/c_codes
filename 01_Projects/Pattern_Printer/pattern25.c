/**
* @file: pattern25.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h> 

/*
*  FUNCTION NAME : pattern25()
* 					      1
*				      3	  3	  3
*			    5	  5	  5	  5	  5
*		  7	  7	  7	  7	  7	  7	  7
*	9 	9	  9	  9	  9	  9	  9	  9	  9 
* 
*  PARAMETERS :  
*                1) void : 
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern25(void)
{
  int ole = 1, ile = 1;
  int num1 = 1, space = 4, i = 5;

  while(ole <= 5)
  {
    while(ile <= i)
    {
      if(ile <= space)
      {
        printf("    ");
      }
      else
      {
        printf("%d   ",num1);
      }
      ile++;
    }

    ile = 1;
    num1 = num1 + 2;

    space--;
    i++;
    ole++; 

    printf("\n");
  }

  return;
}
