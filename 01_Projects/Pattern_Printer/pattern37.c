/**
* @file: pattern37.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern37() 
*					              1
*				            2		    2
* 			        3		   3		    3
* 		      4		    4		    4		    4
*	      5		    5		   5		    5		    5
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern37(void)
{
  int ole = 1, ile = 1;
  int num1 = 1, space = 4;

  while(ole <= 5)
  {
    while(ile <= 5)
    {
      if(ile <= space)
      {
        printf("    ");       // 4 spaces
      }
      else
      {
        printf("%d      ",num1);         // 6 spaces
      }

      ile++;
    }
    ile = 1;

    num1++;
    space--;

    ole++;     
    printf("\n");
  }

  return;
}

