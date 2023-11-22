/**
* @file: pattern14.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern14()
*                     D
*			            C	  D
*		          B	  C	  D
*	        A   B	  C	  D
*		          B	  C	  D
*			            C	  D
*				              D  
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern14(void)
{
  int ole = 1, ile = 1, space = 3;
  int asciiD = 68, ascii = 68;

  //    terminating condition
  while(ole <= 7)
  {
    while(ile <= 4)
    {
      if(ile <= space)
      {
        printf("    ");                     // 4 spaces
      }
      else
      {
        printf("%c   ",asciiD);              // 3 spaces
        asciiD++;
      }
      ile++;
    }

    ile = 1;

    if(ole > 3)
    {
      space++;
      ascii++;
    }
    else
    {
      space--;
      ascii--;
    }

    asciiD = ascii;
    ole++;      //incrementing condition
    printf("\n");
  }

  return;
}

