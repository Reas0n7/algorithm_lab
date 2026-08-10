#ifndef STACK_H
#define STACK_H

#ifdef __cplusplus
extern "C" {
#endif

//sequence stack
typedef struct Seq_Stack {
    int *data;
    int top;
    int capacity;
}Seq_Stack;
Seq_Stack *seq_stack_create(int capacity);
int seq_stack_is_empty(const Seq_Stack *s);
int seq_stack_is_full(const Seq_Stack *s);
int seq_stack_push(Seq_Stack *s, int value);
int seq_stack_pop(Seq_Stack *s, int *out);
int seq_stack_top(Seq_Stack *s, int *out);
void seq_stack_destroy(Seq_Stack *s);
void seq_stack_traverse(Seq_Stack *s);


//link stack
typedef struct Link_Stack_Node {
    int data;
    struct Link_Stack_Node *next;
}Link_Stack_Node;

typedef struct Link_Stack {
    Link_Stack_Node *top;
    int size;
}Link_Stack;
Link_Stack *link_stack_create();
int link_stack_is_empty(Link_Stack *s);
void link_stack_push(Link_Stack *s, int value);
int link_stack_pop(Link_Stack *s, int *out);
void link_stack_destroy(Link_Stack *s);
void link_stack_traverse(Link_Stack *s);






#ifdef __cplusplus
}
#endif

#endif