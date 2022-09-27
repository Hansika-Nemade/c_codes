// Headers
#include<stdio.h>
#include<stdlib.h>
#include"doubly_circular.c"


P_node_t list1 = NULL;
P_node_t list2 = NULL;

//Entry point of main function
int main(void)
{  

    
    list1 = create_list();
    list2 = create_list();

    if(list1 == NULL ) 
    {
        printf("ERROR: list1 is not created\n");
        return(0);
    }
  
    if(list2 == NULL)
    {
        printf("ERROR: list2 is not created\n");
        return(0);
    }
     
    
    add_node_at_end(list1 , 0);
    add_node_at_end(list1 , 1);
    add_node_at_end(list1 , 2);
    add_node_at_end(list1 , 3);
    add_node_at_end(list1 , 4);
    add_node_at_end(list1 , 5);
    add_node_at_front(list1 , -1);
    add_node_at_front(list1 , -2);
    add_node_at_front(list1 , -3);
    add_node_at_front(list1 , -4);
    add_node_at_front(list1 , -5);
    add_node_at_position(list1, 99 , 6);
    add_node_at_position(list1 , 45, 22);
    add_node_at_position(list1 , 501, 1);
    add_node_at_position(list1 , 502, 2);
    print_list(list1);

    add_node_at_end(list2 , 100);
    add_node_at_end(list2 , 120);
    add_node_at_end(list2 , 130);
    add_node_at_end(list2 , 140);
    add_node_at_end(list2 , 150);
    add_node_at_end(list2 , 160);
    add_node_at_front(list2 , 170);
    add_node_at_front(list2 , 180);
    add_node_at_front(list2 , 190);
    add_node_at_front(list2 , 200);
    add_node_at_position(list2 , 301, 11);
    add_node_at_position(list2 , 302, 12);
    add_node_at_position(list2 , 303, 13);
    add_node_at_position(list2 , 304, 14);
    add_node_at_position(list2 , 305 , 1);
    print_list(list2); 

    update_data(list2 , 1 , 306);
    print_list(list2);

    remove_node_at_front(list1);
    remove_node_at_front(list1);
    remove_node_at_end(list1);
    print_list(list1);

    length(list1);

    reverse_list(list1);
    print_list(list1);

    remove_node_at_position(list2, 12);
    remove_node_at_position(list2, 12);
    remove_node_at_front(list2);
    remove_node_at_end(list2);
    remove_node_at_end(list2);
    print_list(list2);

    length(list2);

    merge_lists(&list1 , &list2);
    print_list(list1);

    length(list1);

    destroy_list(&list2);
    destroy_list(&list1);

    exit(0);
}