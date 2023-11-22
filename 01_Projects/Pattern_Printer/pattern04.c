
/**
* @file: pattern04.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>


/*
*  FUNCTION NAME : pattern04()
*                       E	E	E	E	E
*	                     D	D	D	D	D
*	                     C 	C	C	C	C
*	                     B	B	B	B	B
*	                     A	A	A	A	A
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern04(void)
{
    int ole = 1, ile = 1;
    char char_E = 'E';

    for(ole = 1 ; ole <= 5 ; ole++) 
    {
       for(ile = 1 ; ile <= 5 ; ile++)
       {
          printf("%c   ",char_E);   // 3 spaces
       }

       ile = 1;
       char_E--;
      printf("\n");
    }

    return;
}
