//Headers
#include<stdio.h>
#include<stdlib.h>

//function Decleration
void fun1(void);
void fun2(void);
void fun3(void);
void fun4(void);
void fun5(void);

// fun pointers decleration
void (*fptr1) (void) = NULL;
void (*fptr2) (void) = NULL;
void (*fptr3) (void) = NULL;
void (*fptr4) (void) = NULL;
void (*fptr5) (void) = NULL;



// array of function pointer decleration
void (*arr[5]) (void) ;

// pointer to array of pointer to function
void (*(*parr)[5]) (void) = &arr;

int main(void)
{
   fptr1 = fun1;
   fptr2 = fun2;
   fptr3 = fun3;
   fptr4 = fun4;
   fptr5 = fun5;

   /*arr[0] = fptr1;
   arr[1] = fptr2;
   arr[2] = fptr3;
   arr[3] = fptr4;
   arr[4] = fptr5;*/ 

   arr[0] = fun1;
   arr[1] = fun2;
   arr[2] = fun3;
   arr[3] = fun4;
   arr[4] = fun5;

   printf("%p\n", &arr);
   printf("%p\n\n", parr);

   for(int i=0 ; i < 5 ; i++)
   {
       (*parr)[i] ();    // accessing by pointer to array of pointer
   }
}

void fun1(void) 
{
    printf("\nIn func1 function\n");
    printf("Exiting func1 function\n");
}

void fun2(void)
{
    printf("\nIn func2 function\n");
    printf("Exiting func2 function\n");
}
 
void fun3(void)
{
    printf("\nIn func3 function\n");
    printf("Exiting func3 function\n");
}

void fun4(void)
{
    printf("\nIn func4 function\n");
    printf("Exiting func4 function\n");
}

void fun5(void)
{
    printf("\nIn func5 function\n");
    printf("Exiting func5 function\n");
}

