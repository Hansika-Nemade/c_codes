/**
* @file: pattern07.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>


/*
*  FUNCTION NAME : pattern07()
*                       1
*                       1   2
*                       1   2   3
*                       1   2   3   4
*                       1   2   3   4   5
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern07(void)
{
  int ole = 1, ile = 1;
  int num1 = 1;

  for(ole = 1 ; ole <= 5 ; ole++)
  {
    for(ile = 1 ; ile <= 5 ; ile++)
    {
      if(ile <= ole)
        printf("%d   ",num1);              // 3 spaces
      
      num1++;
      
    }

    num1 = 1;
    ile = 1;

    printf("\n");
  }

  return;
}
