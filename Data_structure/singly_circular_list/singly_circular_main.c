
//Headers
#include<stdio.h>
#include<stdlib.h>
#include"singly_circular.c"

P_node_t  list1;
P_node_t  list2;

// Entry point of main function
int main(void)
{
    list1 = create_list(); 
    list2 = create_list();
  
    if(list1 == NULL)
    {
        return(0);
    }

    if(list2 == NULL)
    {
        return(0);
    }

    add_node_at_end(list1 , 10);
    add_node_at_end(list1 , 20);
    add_node_at_end(list1 , 30);
    add_node_at_end(list1 , 40);
    add_node_at_end(list1 , 50);
    add_node_at_position(list1 , 121 , 3 );
    add_node_at_end(list1 , 60);
    add_node_at_end(list1 , 70);
    add_node_at_end(list1 , 80);
    add_node_at_position(list1 , 111 , 50);
    add_node_at_end(list1 , 90);
    add_node_at_end(list1 , 100);

    print_list(list1);

    add_node_at_front(list2 , 110); 
    add_node_at_front(list2 , 120);
    add_node_at_front(list2 , 130);
    add_node_at_front(list2 , 140);
    add_node_at_front(list2 , 150);
    add_node_at_position(list2 , 343 , 30 );
    add_node_at_front(list2 , 160);
    add_node_at_front(list2 , 170);
    add_node_at_front(list2 , 180);
    add_node_at_position(list2 , 613 , 50);
    add_node_at_front(list2 , 190);
    add_node_at_front(list2 , 200);
    add_node_at_position(list2, 1000, 1);
    print_list(list2);

    searching_node(list2 , 110);

    remove_node_at_end(list2);
    remove_node_at_end(list2);
    remove_node_at_end(list2);
    remove_node_at_end(list2);

    print_list(list2);

    print_list(list1);
    
    remove_node_at_front(list1);
    remove_node_at_front(list1);
    remove_node_at_front(list1);
    remove_node_at_front(list1);
 
    print_list(list1);

    update_data(list1 , 5 , 999);
    update_data(list2 , 45, 2000);
    print_list(list1);

    printf("LIST 1 :\n");
    print_list(list1);

    printf("LIST 2 :\n");
    print_list(list2);

    merge_lists(&list1 , &list2);
    print_list(list1);

    reverse_list(list1);
    print_list(list1);

    length(list1);


    destroy_list(&list2);
    print_list(list2);

    destroy_list(&list1);

    exit(0);
}