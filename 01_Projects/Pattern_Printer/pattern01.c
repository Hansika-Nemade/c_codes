
/**
* @file: pattern01.c
* @brief:  
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/

 
#include<stdio.h>
#include<stdlib.h>


/*
*  FUNCTION NAME : pattern01()
*                       *	*	*	*	*
*	                     *	*	*	*	*
*	                     *	*	*	*	*
*	                     *	*	*	*	*
*	                     *	*	*	*	*
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


// Entry point function
void pattern01(void)
{
   int ole = 1, ile = 1;

    for(ole = 1 ; ole <= 5 ; ole++)
    {
       for(ile = 1 ; ile <= 5 ; ile++)
       {
         printf("*   ");         // 3 spaces
       }
 
       ile = 1;
       printf("\n");
    }  

    return ;
}

