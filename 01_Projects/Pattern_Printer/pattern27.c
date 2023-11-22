/**
* @file: pattern27.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern27()
*	    A	  B	  C	  D	  E	  F	  G	  H	  I
*		      A	  B	  C	  D	  E	  F	  G		
*			        A	  B	  C	  D	  E		
*				          A	  B	  C		
*					            A	
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern27(void)
{
  int ole = 1, ile = 1;
  int ascii_A = 65, space = 9, i = 0;

  //    terminating condition
  while(ole <= 5)
  {
    while(ile <= space)
    {
      if(ile <= i)
      {
        printf("    ");
      }
      else
      {
        printf("%c   ",ascii_A);
        ascii_A++;
      }
      ile++;
    }

    ile = 1;

    space--;
    i++;

    ascii_A = 65;
    ole++;            //incrementing condition

    printf("\n");
  }
}

