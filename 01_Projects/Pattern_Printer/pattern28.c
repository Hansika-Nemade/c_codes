/**
* @file: pattern28.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern28()
*	     1	2	 3	4	 5	6	 7	8 	9
*		      1	 2	3	 4	5	 6	7		
*			       1	2	 3	4	 5		
*				        1	 2	3		
*					         1 	
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern28(void)
{
  int ole = 1, ile = 1;
  int num1 = 1, space = 9, i = 0;

  while(ole <= 5)
  {
    while(ile <= space)
    {
      if(ile <= i)
      {
        printf("    ");
      }
      else
      {
        printf("%d   ",num1);
        num1++;
      }
      ile++;
    }

    ile = 1;
    space--;
    i++;

    num1 = 1;
    ole++;  

    printf("\n");
  }

  return;
}

