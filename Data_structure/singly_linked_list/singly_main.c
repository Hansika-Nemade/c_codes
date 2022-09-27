//Headers
#include<stdio.h>
#include<stdlib.h>
#include"singly.c"


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
    add_node_at_position(list1 , 121 , 100 );
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
    add_node_at_position(list2 , 343 , 66 );
    add_node_at_front(list2 , 160);
    add_node_at_front(list2 , 170);
    add_node_at_front(list2 , 180);
    add_node_at_position(list2 , 613 , 50);
    add_node_at_front(list2 , 190);
    add_node_at_front(list2 , 200);

    print_list(list2);

    remove_node_at_end(list2);
    remove_node_at_end(list2);
    remove_node_at_end(list2);
    remove_node_at_end(list2);

    print_list(list1);

    remove_node_at_front(list1);
    remove_node_at_front(list1);
    remove_node_at_front(list1);
    remove_node_at_front(list1);
 
    print_list(list1);

    remove_node_at_position(list1 , 5);
    print_list(list1);

    searching(list1 , 50);

    update_data(list1 , 22 , 999);

    merge_lists(list1 , list2);
    list2 = NULL;

    print_list(list1);
    
    reverse_list(list1);
    
    print_list(list1);

    update_data(list1 , 2 , 999);
    print_list(list1);

    add_node_at_front(list1 , 1000);
    add_node_at_end(list1 , 50);
    add_node_at_position(list1 , 100 , 5);

    destroy_list(&list1);
    print_list(list1);

    printf("end\n");
    exit(0);
}