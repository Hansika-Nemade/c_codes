/**
* @file: pattern33.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h> 

/*
*  FUNCTION NAME : pattern33()
*	              5		 		 		 		                 5
* 		              4		 		 		             4
* 			                3		 		         3
*				                    2		     2
*					                       1
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern33(void)
{
  int ole = 1, ile = 1;
  int num1 = 5, space = 1, space2 = 9;

  while(ole <= 5)
  {
    while(ile <= 9)
    {
      if(ile == space || ile == space2)
      {
        printf("%d   ",num1); 
      }
      else
      {
        printf("    ");
      }
      ile++;
    }

    ile = 1;

    num1--;
    space2--;
    space++;

    ole++;
    printf("\n");
  }

  return;
}

