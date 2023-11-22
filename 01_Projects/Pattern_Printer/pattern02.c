
/**
* @file: pattern01.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>


/*
*  FUNCTION NAME : pattern02()
*                       A	A	A	A	A
*	                    B	B	B	B	B
*	                    C	C	C	C	C
*	                    D	D	D	D	D
*	                    E	E	E	E	E
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


// Entry point function
void pattern02(void)
{

    int ole = 1, ile = 1;
    int asciiA = 65;

    for(ole =1; ole <= 5 ; ole++)
    {
        for(ile =1 ; ile <= 5 ; ile++)
        {
           printf("%c   ",asciiA);     // 3 spaces
        }

        ile=1;
        asciiA++;            
        printf("\n");
    }

    return;
}
