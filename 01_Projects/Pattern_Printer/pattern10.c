/**
* @file: pattern10.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern10()
*                       5   4   3   2   1
*                       5   4   3   2
*                       5   4   3
*                       5   4
*                       5
* 
*  PARAMETERS :  
*                1) void : 
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern10(void)
{
  int ole = 0, ile = 1;
  int num1 = 5;

  for(ole = 5 ; ole <= 5 && ole > 0; ole--)
  { 

    for(ile = 1 ; ile <= 5 ; ile++)
    {
      if(ile <= ole)
      {
        printf("%d   ",num1);           // 3 spaces
        num1--; 
      }
      else
      {
        printf("    ");             // 4 spaces
      }
      
    }

    //printf("end");
    ile = 1;
    num1 = 5;

    printf("\n");

  }

  return;
}
