/**
* @file: pattern13.c
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 14 October 2023 (saturday)
*/


#include<stdio.h>
#include<stdlib.h>

/*
*  FUNCTION NAME : pattern13()
*                       1
*	                      2   1
*	                      1	  2	  3
*	                      4	  3	  2	 1
*	                      1	  2	  3	 4	 5
*                       4   3   2   1
*                       1   2   3
*                       2   1
*                       1
* 
*  PARAMETERS :  
*                1) void :
* 
*  RETURNS :
*                void :
*/


//Entry point of function
void pattern13(void)
{
   int ole=1,ile=1;
    int num1=1,sub_row=1;

  //  terminating condition
  while(ole<=9)
  {
    while(ile<=sub_row)
    {
        printf("%d   ",num1);
        if((ole % 2) == 0)
          num1--;
        else
          num1++;
          
        ile++;
    }
    ile=1;

    if(ole>4)
    {
      sub_row--;
    }
    else
    {
      sub_row++;
    }

    if((ole % 2) != 0)
       num1 = sub_row;
    else
       num1=1;


    ole++;   //incrementing condition
    printf("\n");
  }

  return;
}

