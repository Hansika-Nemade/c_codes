/**
* @file: pattern45.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern45()
*					                 1	
*				               1		  2
*			             1			2	      3
*		           1			2			  3       4
*	          			2				3	      4        
*		            			3			  4        
*			             			  4	       
*				               		   
*					                 
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern45(void)
{
  int ole = 1, ile = 1;
  int num1 = 1, num = 1, space = 3; 

  while(ole <= 7)
  {
    while(ile <= 4)
    {
      if(ile <= space)
      {
        printf("    ");                      // 4 spaces
      }
      else
      {
        printf("%d      ",num1);            // 6 spaces
        num1++;
      }

      ile++;

    }

    ile = 1;
    if(ole>3)
    {
      space++;
      num++;
      num1=num;
    }
    else
    {
      space--;
      num1=1;
    }

    ole++;
    printf("\n");
  }

  return;
}

