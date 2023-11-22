/**
* @file: pattern08.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>


/*
*  FUNCTION NAME : pattern08()
*                       A
*	                      B	  B
*	                      C	  C	  C
*	                      D	  D	  D	  D
*	                      E	  E	  E	  E	  E
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern08(void)
{
  char char_A = 'A';
  int ole = 1, ile = 1;

  for(ole = 1 ; ole <= 5 ; ole++)
  {
    for(ile = 1 ; ile <= 5 ; ile++)
    {
      if(ile <= ole)
        printf("%c   ",char_A);        // 3 spaces

    }

    ile = 1;
    char_A++;
    printf("\n");
  }

  return;
}


