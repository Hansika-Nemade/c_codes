/**
* @file: pattern05.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>


/*
*  FUNCTION NAME : pattern05()
*                        1	 1	 1	 1	 1
*	                     A	 B	 C	 D	 E
*	                     * 	 *	 *	 *	 *
*	                     A	 B	 C	 D	 E
*	                     1	 1	 1	 1	 1
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern05(void)
{
    int ole = 1, ile = 1;
    char char_A = 'A';

    for(ole = 1 ; ole <= 5 ; ole++) 
    {
       for(ile = 1 ; ile <= 5 ; ile++)
       {
            if(ole == 1 || ole == 5)
                printf("1   ");
            else if(ole == 3)
                printf("*   ");
            else
                printf("%c   ",char_A);   // 3 spaces

                char_A++;
       }

       ile = 1;
       char_A = 'A';
      printf("\n");
    }

    return;
}
