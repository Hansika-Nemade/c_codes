/**
* @file: client_header.h
* @brief:  header file including all header of patterns
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 15 October 2023 (sunday)
*/


#include<stdio.h>
#include "pattern_header_01.h"
#include "pattern_header_02.h"
#include "pattern_header_03.h"
#include "pattern_header_04.h"
#include "pattern_header_05.h"

// Array Of Function Pointers
void (*pattern_functions[50])(void) = {	pattern01, pattern02, pattern03, pattern04, pattern05,
										pattern06, pattern07, pattern08, pattern09, pattern10,
                                        pattern11, pattern12, pattern13, pattern14, pattern15,
										pattern16, pattern17, pattern18, pattern19, pattern20,
										pattern21, pattern22, pattern23, pattern24, pattern25,
										pattern26, pattern27, pattern28, pattern29, pattern30,
										pattern31, pattern32, pattern33, pattern34, pattern35,
										pattern36, pattern37, pattern38, pattern39, pattern40,
										pattern41, pattern42, pattern43, pattern44, pattern45,
										pattern46, pattern47, pattern48, pattern49, pattern50
									};

// functions
/*
*  FUNCTION NAME : call_patterns()
*                     this function will print the pattern 
* 
*  PARAMETERS :  
*                1) int :    user will pass no. 
* 
*  RETURNS :
*                void :
*/
void call_patterns(int input_value)
{
   if(input_value < 1 || input_value > 50)
   {
      printf("ERROR: Such Pattern Does not exists\n\n");
   }
   else
   {
      pattern_functions[input_value - 1]();
   }

}

