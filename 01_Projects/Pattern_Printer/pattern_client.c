/**
* @file: pattern_client.c
* @brief:  client file
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 15 October 2023 (sunday)
*/

// Header
#include <stdio.h>
#include <stdlib.h>

#include "client_header.h"


int user_input = 0;

// Entry Point Function
int main(int argc, char** argv)
{
	printf("Enter Pattern No = ");
	scanf("%d", &user_input);

	call_patterns(user_input);

	exit(0);
}


