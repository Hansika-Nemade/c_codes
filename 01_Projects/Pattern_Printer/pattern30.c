/**
* @file: pattern30.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern30()
*	    I	 I	I	 I	I	 I	I	 I	I
*		     G	G  G	G	 G	G	 G		
*			      E	 E	E	 E	E		
*				       C	C	 C		
*					        A	
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern30(void)
{
  int ole = 1, ile = 1; 
  int asciiI = 73, space = 0, i = 9;
  
  while(ole <= 5)
  {
    while(ile <= 9)
    {
      if(ile <= space || ile > i)
      {
        printf("    ");
      }
      else
      {
        printf("%c   ",asciiI);
      }
      ile++;
    }

    ile = 1;
    asciiI = asciiI - 2;
    space++;

    i--;
    ole++;     

    printf("\n");
  }

  return;
}

