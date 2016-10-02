#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int data;
    struct _node *p_next;
} node;

node *create_node(int data){
    node *p_new_node = malloc(sizeof(node));
    p_new_node->data = data;
    p_new_node->p_next = NULL;
    return p_new_node;
}

void print_list(node *p_head){
    while(NULL != p_head){
        printf("%d ", p_head->data);
        p_head = p_head->p_next;
    }
    printf("\n");
}

void add_node(node **pp_head, int data){
    node *p_new_node = create_node(data);
    node *p_node = NULL;
    if(NULL == (*pp_head)){
        (*pp_head) = p_new_node;
    }
    else{
        p_node = (*pp_head);
        while(NULL != p_node->p_next){
            p_node = p_node->p_next;
        }
        p_node->p_next = p_new_node;
    }
}

void delete_node(node **pp_head, int data){
    node *p_node = NULL;
    node *p_temp = NULL;
    if(NULL == (*pp_head))
        return;
    p_node = (*pp_head);
    if(data == p_node->data){
        (*pp_head) = p_node->p_next;
        free(p_node);
        p_node = NULL;
    }
    while((NULL != p_node) && (NULL != p_node->p_next)){
        if(p_node->p_next->data == data){
            p_temp = p_node->p_next->p_next;
            free(p_node->p_next);
            p_node->p_next = p_temp;
        }
        p_node = p_node->p_next;
    }
}

int main() {
    node *p_head = NULL;
    int a[] = {1, 5, 11, 9, 22, 13, 99, 65, 45};
    int count = sizeof(a)/sizeof(a[0]);
    int idx = 0;
    for(idx = 0; idx < count; idx++){
        add_node(&p_head, a[idx]);
    }
    print_list(p_head);
    for(idx = count-1; idx >= 0; idx--){
        delete_node(&p_head, a[idx]);
        print_list(p_head);
    }
    
	return 0;
}
