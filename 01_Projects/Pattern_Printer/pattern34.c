/**
* @file: pattern34.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern34() 
* 	            E		 		 		 		                  E
* 		              D		 		 		              D
* 			                C		 		          C
*				                    B		      B
*					                       A
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern34(void)
{
  int ole = 1, ile = 1;
  int asciiE = 69, space = 1, space2 = 9;

  while(ole <= 5)
  {
    while(ile <= 9)
    {
      if(ile == space || ile == space2)
      {
        printf("%c   ",asciiE);
      }
      else
      {
        printf("    ");
      }
      ile++;
    }
    ile = 1;

    asciiE--;
    space2--;
    space++;

    ole++;
    printf("\n");
  }

  return;
}

