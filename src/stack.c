#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//sequence stack
Seq_Stack *seq_stack_create(int capacity)
{
    if (capacity <= 0) {
        return NULL;
    }
    Seq_Stack *s = (Seq_Stack*)malloc(sizeof(Seq_Stack));
    if (s == NULL) {
        printf("memory alloction failed\n");
        return NULL;
    }
    s->capacity = capacity;
    s->top = -1;
    s->data = (int*)malloc(capacity * sizeof(int));
    if (s->data == NULL) {
        printf("memory allocation failed\n");
        free(s);
        return NULL;
    }
    return s;
}


int seq_stack_is_empty(const Seq_Stack *s)
{
    return s->top == -1;
}


int seq_stack_is_full(const Seq_Stack *s)
{
    return s->top == s->capacity - 1;
}


int seq_stack_push(Seq_Stack *s, int value)
{
    if (seq_stack_is_full(s)) {
        printf("stack is full\n");
        return 0;
    }
    s->data[++s->top] = value;
    return 1;
}


int seq_stack_pop(Seq_Stack *s, int *out)
{
    if (seq_stack_is_empty(s)) {
        printf("stack is empty\n");
        return 0;
    }
    if (out == NULL) {
        return 0;
    }
    *out = s->data[s->top];
    s->top--;
    return 1;
}


int seq_stack_top(Seq_Stack *s, int *out)
{
    if (seq_stack_is_empty(s)) {
        printf("stack is empty\n");
        return 0;
    }
    if (out == NULL) {
        return 0;
    }
    *out = s->data[s->top];
    return 1;
}

void seq_stack_destroy(Seq_Stack *s)
{
    if (s == NULL) {
        return;
    }
    free(s->data);
    free(s);
}

void seq_stack_traverse(Seq_Stack *s)
{
    if (s == NULL) {
        printf("stack is NULL\n");
        return;
    }
    if (seq_stack_is_empty(s)) {
        printf("stack is empty\n");
        return;
    }
    printf("stack content (top -> bottom)\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}




//link stack
Link_Stack *link_stack_create()
{
    Link_Stack *s = (Link_Stack*)malloc(sizeof(Link_Stack));
    if (s == NULL) {
        printf("memory allocation failed\n");
        return NULL;
    }
    s->size = 0;
    s->top = NULL;
    return s;
}

int link_stack_is_empty(Link_Stack *s)
{
    return s->size == 0;
}

void link_stack_push(Link_Stack *s, int value)
{
    Link_Stack_Node *new_node = (Link_Stack_Node*)malloc(sizeof(Link_Stack_Node));
    if (new_node == NULL) {
        printf("memory allocation failed\n");
        return;
    }
    s->size++;
    new_node->next = s->top;
    s->top = new_node;
    s->top->data = value;
}

int link_stack_pop(Link_Stack *s, int *out)
{
    if (out == NULL) {
        return 0;
    }
    if (link_stack_is_empty(s)) {
        printf("stack is empty\n");
        return 0;
    }
    Link_Stack_Node *removed = s->top;
    *out = removed->data;
    s->top = removed->next;
    s->size--;
    free(removed);
    return 1;
}

void link_stack_destroy(Link_Stack *s)
{
    if (s == NULL) {
        return;
    }
    Link_Stack_Node *current = s->top;
    while (current != NULL) {
        Link_Stack_Node *next = current->next;
        free(current);
        current = next;
    }
    free(s);
}

void link_stack_traverse(Link_Stack *s)
{
    if (s == NULL) {
        printf("stack is NULL\n");
        return;
    }
    if (link_stack_is_empty(s)) {
        return;
    }
    printf("stack content (top -> bottom)\n");
    for (Link_Stack_Node *current = s->top; current != NULL; current = current->next) {
        printf("%d ", current->data);
    }
    printf("\n");
}
