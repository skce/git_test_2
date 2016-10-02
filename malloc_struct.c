#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_STR_COUNT (5)
#define MAX_STR_CAPACITY (63 + 1)

typedef struct _my_struct{
    int capacity;
    char **pp_str;
} my_struct;

void print_strings(my_struct *p_struct){
    int idx = 0;
    for(idx = 0; idx < MAX_STR_COUNT; idx++){
        printf("%s\n", p_struct->pp_str[idx]);
    }
}

void set_strings(my_struct *p_struct){
    char arr[5][64] = {"Hello", "what", "when", "where", "how"};
	int idx = 0;
	for(idx = 0; idx < MAX_STR_COUNT; idx++){
	    strncpy(p_struct->pp_str[idx], arr[idx], MAX_STR_CAPACITY);
	}
}

void init_struct(my_struct **pp_struct){
    int idx = 0; 
	*pp_struct = malloc(sizeof(my_struct));
	
	(*pp_struct)->capacity = MAX_STR_COUNT;
	(*pp_struct)->pp_str = malloc(sizeof(char *) * MAX_STR_COUNT);
	
	for(idx = 0; idx < MAX_STR_COUNT; idx++){
	    (*pp_struct)->pp_str[idx] = malloc(sizeof(char) * MAX_STR_CAPACITY);
	}
	
}

void destroy_ds(my_struct **pp_struct){
    int idx;
    for(idx = 0; idx < MAX_STR_COUNT; idx++){
        free((*pp_struct)->pp_str[idx]);
        (*pp_struct)->pp_str[idx] = NULL;
    }
    free((*pp_struct)->pp_str);
    (*pp_struct)->pp_str = NULL;
    free((*pp_struct));
    *pp_struct = NULL;
}

int main() {
	my_struct *p_struct = NULL;
	printf("========= BEGIN: %p %p\n", sbrk(0), p_struct);
	init_struct(&p_struct);
	printf("========= ALLOC: %p %p\n", sbrk(0), p_struct);
	set_strings(p_struct);
	print_strings(p_struct);
	destroy_ds(&p_struct);
	printf("========= END: %p %p\n", sbrk(0), p_struct);
	return 0;
}
