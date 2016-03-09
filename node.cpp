#include <stdio.h>

struct s_node
{
    struct s_node *next;
    struct s_node *reference; //points to another node -- random node
};

typedef struct s_node S;

void duplicate_node(struct s_node *node){
    S* new_node = new(S);
    new_node->next = node->next;
    node->next = new_node;
    new_node->reference = NULL;
}

struct s_node *duplicate_list(struct s_node *list) {
    //Create a linked list with duplicate nodes in between each original node
    //a -> a' -> b -> b' -> c -> c' -> d -> d'-> end  
    S *curr = list;
    while(curr) {
       duplicate_node(curr);
       curr = curr->next->next; //a->a'->b    
    }

    //set reference pointers in all the duplicate nodes
    curr = list; 
    while(curr) { 
        curr->next->reference = curr->reference->next; 
        curr = curr->next->next;
    }
    
    //Split new nodes into new list, remove duplicate nodes in original
    curr = list;
    S *dup = list->next; //dup = a'
    S* curr_dup = dup;
    while(curr) {
        curr->next = curr->next->next; //a -> b     
        
        if (curr_dup->next != NULL){
            curr_dup->next = curr_dup->next->next;
        }
                      
        curr = curr->next;
        curr_dup = curr_dup->next;
    }
    //now we have:
    //list = a -> b -> c -> d ->end
    //dup =  a'-> b'-> c'-> d'->end
	return dup;
}

