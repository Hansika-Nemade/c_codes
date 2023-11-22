/**
* @file: pattern09.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern09()
*                        A	 A	 A	 A	 A
*	                       B	 B	 B	 B
*	                       C	 C	 C
*	                       D	 D
*	                       E
*  
*  PARAMETERS :  
*                1) void : 
*  
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern09(void)
{
  int ole = 1, ile = 1;
  int ascii_A = 65;
  
  for(ole = 5 ; ole <= 5 && ole > 0 ; ole--)
  {
    for(ile = 1 ; ile <= 5 ; ile++)
    {
      if(ile <= ole)
        printf("%c   ",ascii_A);            // 3 spaces
      else
        printf("   ");                   // 4 spaces
    } 

    ile = 1;
    ascii_A++;
    printf("\n");
  }

  return;
}

