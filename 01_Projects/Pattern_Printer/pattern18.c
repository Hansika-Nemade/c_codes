/**
* @file: pattern18.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern18()
*                       1
*				             2	2
* 			          3	 3	3
* 		         4	4	 4	4
*	         5   5	5	 5	5
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void : 
*/


//Entry point of function
void pattern18(void)
{
  int ole = 0, ile = 1;
  int num1 = 1;

  //   terminating condition
  for(ole = 5 ; ole <= 5 && ole > 0 ; ole--)
  {
    for(ile = 1 ; ile <= 5 ; ile++)
    {
      if(ile >= ole)
        printf("%d   ", num1);  // 3 spaces
      else
        printf("    ");   // 4 spaces

    }
    ile = 1;
    num1++;
    printf("\n");
  }

  return;
}

