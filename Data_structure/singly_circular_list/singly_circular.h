
#pragma   once
#define   SUCCESS   0
#define   FAILURE   1

#define   SIZE_NODE    (sizeof(node_t))


// Struct decleration
struct node;   

//  Typedefs
typedef    struct node      node_t;
typedef    struct node*     P_node_t;  
typedef    struct node**    PP_node_t;

//       List creation function
extern   P_node_t  create_list(void);

//       inserting data functions
extern  int  add_node_at_end(P_node_t head, int data);
extern  int  add_node_at_front(P_node_t head , int data);
extern  int  add_node_at_position(P_node_t head , int data , int position);

//       Removing data functions
extern  int  remove_node_at_end(P_node_t head );
extern  int  remove_node_at_front(P_node_t head);
extern  int  remove_node_at_position(P_node_t head , int position);

//       searching data function
extern  int  searching_node(P_node_t head , int data);

//       updating data function
extern  int  update_data(P_node_t head , int pos , int new_data);
 
//       Merging two list function
extern  int  merge_lists(PP_node_t list_a , PP_node_t list_b);

//       List printing function
extern  void  print_list(P_node_t head);

//       length of  list
extern int   length(P_node_t head);

//        reverse list
extern void  reverse_list(P_node_t head);

//        destroying function
extern  P_node_t   destroy_list(PP_node_t head);  


