/**
* @file: pattern11.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern11()
*                       *
*	                      *	  *
*	                      *	  *	  *
*	                      *	  *	  *	  *
*	                      *	  *	  *
*	                      *	  *
*	                      *
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern11(void) 
{
  int ole = 1, ile = 1;
  int space = 7;

  for(ole = 1 ; ole <= 7 ; ole++)
  {

    for(ile = 1  ; ile <= 4 ; ile++)
    {
      if(ile <= ole && ile <= space)
      {
        printf("*   ");                   // 3 spaces
      } 
      else
      {
        printf("    ");                   // 4 spaces
      }
      
    }

    //printf("end");
    ile = 1;
    space--;
    
    
    printf("\n");
  }

  return;
}
