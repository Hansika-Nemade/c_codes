/**
* @file: pattern29.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern29()
*	      E	 E	E	 E	E	 E	E	 E	E
*		       D	D	 D	D	 D	D	 D		
*			        C	 C	C	 C	C		 
*				         B	B	 B		
*					          A	
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern29(void)
{
  int ole = 1, ile = 1;
  int asciiE = 69, space = 0, i = 9;

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
        printf("%c   ",asciiE);
      }
      ile++;
    }

    ile = 1;

    asciiE--;
    space++;
    i--;

    ole++;  
    printf("\n");
  }

  return;
}
