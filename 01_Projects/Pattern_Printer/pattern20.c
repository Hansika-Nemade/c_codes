/**
* @file: pattern20.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern20()
*                       D
*	                      D	  C 
*	                      D	  C  	B
*	                      D	  C	  B	  A
*	                      D	  C	  B	
*	                      D	  C	
*	                      D
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern20(void)
{

  int ole = 1, ile = 1, space = 1;
  int  ascii_D = 68;

  for(ole = 1 ; ole <= 7 ; ole++)
  {
    for(ile = 1 ; ile <= 4 ; ile++)
    {
      if(ile <= space)
      {
        printf("%c   ", ascii_D);  // 3 spaces
        ascii_D--;   
      }
      else
      {
        printf("    ");   // 4 spaces
      }
      
    }

    ile = 1;
    if(ole > 3)
    {
        space--;
    }
    else
    {
       space++;
    }
    ascii_D = 68; 
     
    printf("\n");

  } 

  return;
}

