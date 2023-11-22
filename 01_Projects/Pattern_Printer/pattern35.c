/**
* @file: pattern35.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern35()
*					                  1
*				                2		    2
* 			            3		 		       3
* 		           4		 		 		        4
*	           5		 		 		 		            5
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern35(void)
{
  int ole = 1, ile = 1;
  int num1 = 1, space = 5, space2 = 5;

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

    space2++;
    num1++;
    space--;

    ole++;      
    printf("\n");
  }

  return;
}

