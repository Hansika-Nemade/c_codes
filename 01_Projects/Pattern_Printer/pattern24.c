/**
* @file: pattern24.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern24()
* 					      A		
*				      C	  B	  A			
*			    E	  D	  C	  B	  A		
*		  G	  F	  E	  D	  C	  B	  A
*	I	  H	  G	  F	  E	  D	  C	  B 	A
*  
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern24(void)
{
  int ole = 1, ile = 1;
  int asciiA = 65, ascii = 65, space = 4, i = 5;

  while(ole <= 5)
  {
    while(ile <= i)
    {
      if(ile <= space)
      {
        printf("    ");
      }
      else
      {
        printf("%c   ",asciiA);
        asciiA--;
      }
      ile++;
    }

    ascii = ascii+2;
    asciiA = ascii; 

    ile = 1;

    space--; 

    i++;
    ole++;       //incrementing condition
    printf("\n");
  }

  return;
}
