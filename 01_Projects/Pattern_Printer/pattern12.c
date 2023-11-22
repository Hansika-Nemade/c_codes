/**
* @file: pattern12.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern12()
*                       D
*	                      C	  D
*	                      B	  C	  D
*	                      A	  B	  C	  D
*	                      B	  C	  D	
*	                      C	  D	
*	                      D
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern12(void)
{
  int ole = 1, ile = 1;
  char ascii_D = 'D';
  int space = 68;
  int sub_row = 1;

  while(ole <= 7)
  {
    while(ile <= sub_row)
    {
      printf("%c   ",ascii_D);
      ascii_D++;
      ile++;
    }

    ile = 1;

    if(ole > 3)
    {
      space++;
      sub_row--;
    }
    else
    {
      space--;
      sub_row++;
    }

    ascii_D = space;
    ole++;          //incrementing condition
    printf("\n");
  }

  return;
}

