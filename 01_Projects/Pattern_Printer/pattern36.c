/**
* @file: pattern36.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern36()
*					                A
*				              B		    B
* 			          C		 		        C
* 		        D		 		 		            D
*	        E		 		 		 		                E
*  
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern36(void)
{
  int ole = 1, ile = 1;
  int asciiA = 65, space = 5, space2 = 5;

  while(ole <= 5)
  {
    while(ile <= 9)
    {
      if(ile == space || ile == space2)
      {
        printf("%c   ",asciiA);
      }
      else
      {
        printf("    ");
      }
      ile++;
    }
    ile = 1;

    space2++;
    asciiA++;
    space--;

    ole++;       
    printf("\n");
  }

  return;
}
