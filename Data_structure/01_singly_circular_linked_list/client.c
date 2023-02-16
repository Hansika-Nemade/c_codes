// Headers
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"list.h"


int main(void)
{
    list_t list  = NULL;
    list_t list1 = NULL;
    list_t list2 = NULL;
    list_t reversed_list = NULL;
    list_t concat_list = NULL;
    list_t sorted_list = NULL;
    list_t merged_list = NULL;

    list = create_list();
    assert(list != NULL);
    show_list(list, "After creation\nlist:");
    
    //                insert_start
    for(int data = 0; data < 5; data++)
        assert(insert_start(list, data) == success); 
    show_list(list, "After insert_start\nlist:"); 
    
    //                insert_end
    for(int data = 5; data < 10; data++)
        assert(insert_end(list, data) == success); 
    show_list(list, "After insert_end\nlist:");

    assert(insert_after(list, 99, 100) == list_data_not_found); 
    assert(insert_before(list, 69, 200) == list_data_not_found); 
    
    //                insert_after
    assert(insert_after(list, 0, 100) == success);
    show_list(list, "Afteter insert_after\nlist:"); 

    //               insert_before
    assert(insert_before(list, 0, 200) == success);  
    show_list(list, "After insert_before\nlist:");


    //                get_length
    len_t length = 0;
    length = get_length(list);
    printf("length of the list : %d\n\n",length);

    //                get_end
    data_t data = 0; 
    assert(get_end(list, &data) == success); 
    printf("Last data of List : %d\n", data); 
    show_list(list, "After get_end\nlist:"); 

    //                get_start
    data = 0; 
    assert(get_start(list, &data) == success); 
    printf("Start data of list : %d\n", data); 
    show_list(list, "After get_start\nlist:"); 

    //               pop_start
    data = 0; 
    assert(pop_start(list, &data) == success); 
    printf("Poped Data:%d\n", data); 
    show_list(list, "\tAfter pop_start\nlist:"); 

    //               pop_end
    data = 0; 
    assert(pop_end(list, &data) == success); 
    printf("Poped Data:%d\n", data); 
    show_list(list, "\tAfter pop_end\nlist:");

    //              remove_start
    assert(remove_start(list) == success); 
    show_list(list, "\t\tAfter removing start\nlist:"); 

    //              remove_end
    assert(remove_end(list) == success); 
    show_list(list, "\t\tAfter removing end\nlist:"); 
    
    //              remove_data
    assert(remove_data(list, -20) == list_data_not_found); 
    assert(remove_data(list, 0) == success);
    show_list(list, "\t\tAfter removing data\nlist:");
    
    //              get_length
    printf("Length = %d\n", get_length(list));   
    assert(is_list_empty(list) == false);

    //              find_data
    assert(find_data(list, 2) == true);
    assert(find_data(list, -20) == false);

    //              reverse_list_imm
    show_list(list, "\t\tbefore immutable reversed\nlist:");
    reversed_list = reverse_list_imm(list);
    show_list(reversed_list, "\t\tafter reversed list (immutable)\nreversed_list:");

    //              reverse_list_m
    show_list(list, "\t\tbefore mutable reversed\nlist:");
    assert(reverse_list_m(list) == success);
    show_list(list, "\t\tafter mutable reversed\nlist:");
    
    list1 = create_list();

    for(int data = 10; data < 90; data+=10)
        assert(insert_start(list1, data) == success); 
    show_list(list1, "After insert_start in list1:\nlist1:");
    
    //              concat_list_imm
    show_list(list , "\t\tbefore concat list (immutable)\nlist:");
    show_list(list1, "list1:");
    concat_list = concat_list_imm(list1, list);
    show_list(concat_list, "\t\tafter concat (immutable version)\nconcat_list:");

    //              concat_list_m
    show_list(list , "\t\tbefore concat list (mutable)\nlist:");
    show_list(list1, "list1:"); 
    assert(concat_list_m(list1, &list) == success);
    show_list(list1, "\t\tafter concat list (mutable version)\nlist1:");
    assert(list == NULL);

    //                sort_list_imm
    show_list(list1, "\t\tbefore sort (immutable)\nlist1:");
    sorted_list = sort_list_imm(list1);
    show_list(sorted_list, "\t\tsorted list (immutable version)\nsorted_list:");

    //                sort_list_m
    show_list(list1, "\t\tbefore sort (mutable version\nlist1:");
    assert(sort_list_m(list1) == success);
    show_list(list1, "\t\tsorted list (mutable version)\nlist1:");

    list2 = create_list();

    for(int data = 5; data < 90; data+=10)
        assert(insert_end(list2, data) == success); 
    show_list(list2, "After insert_start in list2:\nlist2:");

    //                merge_lists
    show_list(list1, "\t\tbefore merging list\nlist1:");
    show_list(list2, "list2:");
    merged_list = merge_lists(list1, list2);
    show_list(merged_list, "\t\tafter merging lists\nmerged_list:");

    //                destroy_list
    assert(destroy_list(&list1) == success);
    assert(list1 == NULL);

    assert(destroy_list(&list2) == success);
    assert(list2 == NULL);

    printf("end");
    return(EXIT_SUCCESS);
}