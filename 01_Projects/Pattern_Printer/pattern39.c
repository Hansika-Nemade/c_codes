/**
* @file: pattern39.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern39()
*	                E		  D		  C		  B		  A
* 		               D		 C		 B		 A
* 			                C		  B		  A
*				                   B		 A
* 					                  A
* 
*  PARAMETERS :  
*                1) void :
*  
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern39(void)
{
  int ole = 1, ile = 1;
  int asciiE = 69, ascii = 69, space = 0;

  while(ole <= 5)
  {
    while(ile <= 5)
    {
      if(ile <= space)
      {
        printf("    ");         // 4spaces
      }
      else
      {
        printf("%c      ",asciiE);       // 6 spaces
        asciiE--;
      }

      ile++;
    }

    ascii--;
    asciiE = ascii;
    ile = 1;

    space++;

    ole++; 
    printf("\n");
  }

  return;
}

