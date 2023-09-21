//Headers
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define  OUT  0
#define  IN   1

// global vairables
FILE* fptr = NULL;
char buffer[100] ;

// function decleration
int word_count(char* s);

// ENTRY POINT OF MAIN FUNCTION
int main(int argc, char* argv[])
{
    int word = 0;

    if(argc != 2)
    {
        printf("error\n");
        return(0);
    }

    fptr = fopen(argv[1] , "r"); 
     
    fread(buffer , 1, 100, fptr);
    
    printf(" data = %s \n\n", buffer);

    word = word_count(buffer);

    printf("word count of file 'file1.txt' = %d ", word);
    
    
    fclose(fptr);
    fptr = NULL;

}

int word_count(char* s)
{
    int word_count = 0;
    int line_count = 0;
    int state = OUT;

    
    printf("\nin word_count function\n");

    for(int i = 0; s[i] != '\0' ; i++)
    {
        if(state == OUT && !isspace(s[i]))
        {
            state = IN;
            word_count++;
        }
        else if(state == IN && isspace(s[i]))
        {
            state = OUT;
        }
    }

    return(word_count);
}

