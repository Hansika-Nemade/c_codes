/**
* @file: pattern23.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern23()
* 					       A		
*				       A	 B	 A			
*			     A	 B	 C	 B	 A	
*		   A	 B	 C	 D	 C	 B	 A	
*	  A	 B	 C	 D	 E	 D	 C	 B	 A
*
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern23(void)
{
  int ole = 1, ile = 1;
  int asciiA = 64;
  int space = 4, i = 5;

  while(ole <= 5)
  { 
    while(ile <= i)
    {
      if(ile <= space)
      {
        printf("    ");     // 4 spaces
      }
      else
      {
        if(ile > 5)
        {
          asciiA--;
          printf("%c   ",asciiA);
        }
        else
        {
          asciiA++;
          printf("%c   ",asciiA); 
        }
      }
      ile++;     // incrementing condition
    }

    asciiA = 64;
    ile = 1;
    space--;
    i++;
    ole++;       //incrementing condition
    printf("\n");
  }

  return;
}
