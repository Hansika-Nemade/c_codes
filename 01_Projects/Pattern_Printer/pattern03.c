
/**
* @file: pattern04.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>


/*
*  FUNCTION NAME : pattern03()
*                       5	 4	3	 2	1
*	                      5	 4	3	 2	1
*	                      5	 4	3	 2	1
*	                      5	 4	3	 2	1
*	                      5	 4	3	 2	1
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern03(void)
{
    int ole = 1, ile = 1;

    int num1 = 5;

    for(ole = 1 ; ole <= 5 ; ole++)
    {
      for(ile = 1 ; ile <= 5 ; ile++)
      {
        printf("%d   ",num1);          // 3 spaces
        num1--;
      }

      ile = 1;
      num1 = 5;
      printf("\n");
    }

    return;
}

