//HEADERS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

struct S1
{
   int x ;
   int y;
   int z;
};

void built_in_datatype(void);
void arr_of_built_in_datatype(void);
void arr_of_pointers_to_built_in_datatype(void);

void user_defined_datatype(void);
void arr_of_user_defined_datatype(void);
void arr_of_pointers_to_user_defined_datatype(void);


//  ENTRY POINT OF MAIN FUNCTION
int main(void)
{
    built_in_datatype();
    arr_of_built_in_datatype();
    arr_of_pointers_to_built_in_datatype();

    user_defined_datatype();
    arr_of_user_defined_datatype();
    arr_of_pointers_to_user_defined_datatype();
    exit(0);
}

void built_in_datatype(void)
{
    int *p = NULL;

    p = (int*) malloc(sizeof(int));
    assert(p != NULL);

    memset(p , 0 , sizeof(int));
    *p = 500;

    printf("built in data type function\n");
    printf(" p = %p\n" , p);
    printf("*p = %d\n\n", *p);

    free(p);
    p = NULL;
}

void arr_of_built_in_datatype(void)
{
    int *p = NULL;
    int arr_size = 5;

    p =  (int*) malloc(arr_size * sizeof(int));
    assert(p != NULL);

    memset(p , 0 , arr_size * sizeof(int));

    printf("array of built in datatype\n");
    
   //                               /* METHOD 1 */
    printf("method 1:\n");
    for(int index = 0 ; index < arr_size ; index++)
    {
        *(p+ index) = (index+1) * 10;
    }

    for(int index = 0; index < arr_size ; index++)
    {
        printf("p[%d] = %d\n", index , *(p + index));
    }

    //                            /* METHOD 2 */
    printf("\nmethod 2:\n");
    for(int index = 0; index < arr_size ; index++)
    {
        p[index] = (index+1) * 100;
    }

    for(int index = 0 ; index < arr_size ; index++)
    {
        printf("p[%d] = %d\n", index , p[index]);
    }
    printf("\n");

    free(p);
    p = NULL;
}

void arr_of_pointers_to_built_in_datatype(void)
{
    int arr_size = 5;
    int **pp = NULL;
    int *p = NULL;

    pp = (int**) malloc(arr_size * sizeof(int*));
    assert(pp != NULL);
    memset(pp , 0 , sizeof(arr_size * sizeof(int*)));

    for(int index = 0 ; index < arr_size ; index++)
    {
        p = malloc(sizeof(int));
        assert(p != NULL);

        pp[index] = p;        // *(pp + index)
        *p = (index+1) * 5;     
    }

    printf("array of pointers to built in data type\n");

    for(int index = 0; index < arr_size ; index++)
    {
        printf(" *(pp[index]) = %d\n", *(pp[index]));
    }

    printf("\n");

    for(int index = 0; index < arr_size ; index++)
    {
        free(pp[index]);
        pp[index] = NULL;
    }

    free(pp);
    pp = NULL;
}

void user_defined_datatype(void)
{
    struct S1 *p = NULL;
    int a = 3000;

    p =  malloc(sizeof(struct S1));
    assert(p != NULL);

    memset(p , 0 , sizeof(struct S1));

    p->x = 500;
    p->y = 600;
    p->z = 700;

    /*       this is another method need type casting  
    *(p + 0 ) = 100;
    *(p + 1 ) = 200;
    *(p + 2 ) = 300;
    ((struct S1 *) p )->y = 9000;
    */

    printf("content of p = %p\n", p);
    printf("p->x = %d\n",   p->x );
    printf("p->y = %d\n",   p->y );
    printf("p->z = %d\n\n", p->z );

    free(p);
    p = NULL;
}

void arr_of_user_defined_datatype(void)
{
    int arr_size = 5;
    
    struct S1 (*p)[5] = NULL;

    p = (struct S1 (*)[]) malloc(arr_size * sizeof(struct S1));
    assert(p != NULL);

    memset(p , 0 , arr_size * sizeof(struct S1));

    for(int index = 0; index < arr_size ; index++)
    {
        p[index]->x = (index+1) * 2;
        p[index]->y = (index+1) * 3;
        p[index]->z = (index+1) * 4;
    }

    printf("array of user defined data type\n");
    printf("\t\tMethod 1:\n");

    for(int index = 0; index < arr_size ; index++)
    {
        printf("p[index]->x = %d\n", p[index]->x);
        printf("p[index]->y = %d\n", p[index]->y);
        printf("p[index]->z = %d\n\n", p[index]->z); 
    }

        
     
    struct S1 *p1 = NULL;

    p1 = (struct S1*) malloc(arr_size * sizeof(struct S1));

    for(int index = 0; index < arr_size ; index++)
    {
        p1[index].x = (index+1) * 6;
        p1[index].y = (index+1) * 7;
        p1[index].z = (index+1) * 8;
    }
         
    printf("\t\tMethod 2:\n");

    for(int index = 0; index < arr_size ; index++)
    {
        printf("p[index].x = %d\n", p1[index].x);
        printf("p[index].y = %d\n", p1[index].y);
        printf("p[index].z = %d\n\n", p1[index].z); 
    }
    
    
    free(p);
    p = NULL;
}

void arr_of_pointers_to_user_defined_datatype(void)
{
    int arr_size = 5;

    struct S1 **pp = NULL;
    struct S1 *p = NULL;

    pp = (struct S1 **) malloc(arr_size * sizeof(struct S1*));
    assert(pp != NULL);

    memset(pp , 0, sizeof(arr_size * sizeof(struct S1*)));

    for(int index = 0; index < arr_size ; index++)
    {
        p = (struct S1*) malloc(sizeof(struct S1));

        p->x = (index+1) * 11;
        p->y = (index+1) * 12;
        p->z = (index+1) * 13;

        pp[index] = p;
    }

    printf("array of pointers to user defined data type\n");

    for(int index = 0; index < arr_size ; index++)
    {
        printf("pp[index]->x = %d\n", pp[index]->x);
        printf("pp[index]->y = %d\n", pp[index]->y);
        printf("pp[index]->z = %d\n\n", pp[index]->z); 
    }


    for(int index = 0; index < arr_size ; index++)
    {
        free(pp[index]);
        pp[index] = NULL;
    }

    free(pp);
    pp = NULL;
}


