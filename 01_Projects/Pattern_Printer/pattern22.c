/**
* @file: pattern22.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern22()
* 					             A		
*				             B	 A	 B			
*			           C	 B	 A	 B	 C		
*		         D	 C	 B	 A	 B	 C	 D		
*	       E	 D	 C	 B	 A	 B	 C	 D	 E
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern22(void)
{
  int ole = 1, ile = 1;
  int ascii_A = 65, asciiA = 65, asciiB = 66;
  int space = 4, sub_col = 5;

  for(ole = 1 ; ole <= 5; ole++)
  {
    for(ile = 1 ; ile <= sub_col ; ile++)
    {
      if(ile <= space)
      {
        printf("    ");       //4 spaces
      }
      else   
      {
        if(ascii_A < 65)
        {
          printf("%c   ",asciiB);      //3 spaces
          asciiB++;
        }
        else
        {
          printf("%c   ",ascii_A);     //3 spaces
          ascii_A--; 
        }
      }
    }
    ile = 1;

    asciiB = 66;
    asciiA++;

    ascii_A = asciiA;
    space--;
    sub_col++;
    printf("\n");
  }

  return;
}

