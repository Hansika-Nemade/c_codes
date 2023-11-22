/**
* @file: pattern43.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern43() 
*					                 E	
*				               D		   D
*			             C				       C
*		           B						           B
*	         A								               A
*		           B						           B
*			             C				       C
*				               D		   D 
*					                 E
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern43(void)
{
  int ole = 1, ile = 1;
  int asciiE = 69, space = 5, space2 = 5;

  while(ole <= 9)
  {
    while(ile <= 9)
    {
      if(ile == space || ile == space2)
      {
        printf("%c   ",asciiE);       // 3 spaces
      }
      else
      {
        printf("    ");        // 4 spaces
      }
      ile++;
    }

    ile = 1;
    if(ole > 4)
    {
      space++;
      asciiE++;
      space2--;
    }
    else
    {
      space--;
      asciiE--;
      space2++;
    }

    ole++;    
    printf("\n");
  }

  return;
}
