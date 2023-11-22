/**
* @file: pattern06.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>


/*
*  FUNCTION NAME : pattern06()
*                       *
*	                      *	  *
*	                      *	  *	  *
*	                      *	  *	  *	  *
*	                      *	  *	  *	  *	  *
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern06(void)
{
  int ole = 1, ile = 1;

  for(ole = 1 ; ole <= 5 ; ole++)
  {
    for(ile = 1 ; ile <= 5 ; ile++)
    {
      if(ile <= ole)
        printf("*   ");         // 3 spaces
      
    } 

    ile = 1;
    printf("\n");
  }

  return;
}
