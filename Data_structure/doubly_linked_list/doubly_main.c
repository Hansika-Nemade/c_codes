//Headers
#include<stdio.h>
#include<stdlib.h>
#include"doubly.c"

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
    print_list(list2); 
    
    remove_node_at_front(list1);
    remove_node_at_end(list1);
    print_list(list1);

    remove_node_at_position(list1 , 7);
    print_list(list1);

    add_node_at_position(list1 , 22 , 7);
    print_list(list1);

    searching_node(list1 , 3);

    length(list1);

    update_data(list1 , 5 , 100);
    print_list(list1);

    merge_lists(list1 , list2);
    list2 = NULL;
    print_list(list1);

    reverse_list(list1);
    print_list(list1);

    destroy_list(&list1);

    print_list(list1);
      
    printf("\nend\n");
    
    exit(0);
}
