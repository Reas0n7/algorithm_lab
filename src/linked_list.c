#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/*
singly linked list
*/
SLL_Node *sll_create_node(int value)
{
    SLL_Node *new_node = (SLL_Node*)malloc(sizeof(SLL_Node));
    if (new_node == NULL) {
        printf("memory allocation failed\n");
        return NULL;
    }
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void sll_traverse(SLL_Node *head)
{
    if (head == NULL) {
        printf("singly linked list is empty\n");
        return;
    }
    SLL_Node *current = head;
    printf("singly linked list content\n");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

//1 -> 2 -> ... -> n -> NULL
SLL_Node *sll_create_list(int n)
{
    if (n < 1) {
        return NULL;
    }
    SLL_Node *head = sll_create_node(1);
    SLL_Node *tail = head;
    for (int i = 2; i <= n; i++) {
        SLL_Node *new_node = sll_create_node(i);
        tail->next = new_node;
        tail = new_node;
    }
    return head;
}

SLL_Node *sll_insert_head(SLL_Node *head, int value)
{
    SLL_Node *new_node = sll_create_node(value);
    new_node->next = head;
    return new_node;
}

SLL_Node *sll_insert_tail(SLL_Node *head, int value)
{
    SLL_Node *new_node = sll_create_node(value);
    if (head == NULL) {
        return new_node;
    }
    SLL_Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

void sll_insert_after(SLL_Node *prev_node, int value)
{
    if (prev_node == NULL) {
        printf("predecessor node cannot be null\n");
        return;
    }
    SLL_Node *new_node = sll_create_node(value);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

SLL_Node *sll_delete_head(SLL_Node *head)
{
    if (head == NULL) {
        return NULL;
    }
    SLL_Node *removed = head;
    head = head->next;
    free(removed);
    return head;
}

SLL_Node *sll_delete_tail(SLL_Node *head)
{
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    SLL_Node *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

SLL_Node *sll_delete_value(SLL_Node *head, int value)
{
    if (head != NULL && head->data == value) {
        SLL_Node *removed = head;
        head = head->next;
        free(removed);
    }
    if (head == NULL) {
        return NULL;
    }
    SLL_Node *current = head;
    while (current->next != NULL) {
        if (current->next->data == value) {
            SLL_Node *removed = current->next;
            current->next = removed->next;
            free(removed);
        } else {
            current = current->next;
        }
    }
    return head;
}

void sll_destroy(SLL_Node *head)
{
    while (head != NULL) {
        SLL_Node *next = head->next;
        free(head);
        head = next;
    }
}

//doubly linked list
DLL_Node *dll_create_node(int value)
{
    DLL_Node *new_node = (DLL_Node*)malloc(sizeof(DLL_Node));
    if (new_node == NULL) {
        printf("memory allocation failed\n");
        return NULL;
    }
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void dll_traverse(DLL_Node *head)
{
    if (head == NULL) {
        printf("doubly linked list is empty\n");
        return;
    }
    DLL_Node *current = head;
    printf("doubly linked list content\n");
    printf("NULL <- ");
    while (current->next != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("%d ", current->data);
    printf("-> NULL\n");
}

void dll_traverse_reverse(DLL_Node *tail)
{
    if (tail == NULL) {
        printf("doubly linked list is empty\n");
        return;
    }
    DLL_Node *currnet = tail;
    printf("doubly linked list reverse content\n");
    printf("NULL <- ");
    while (currnet->prev != NULL) {
        printf("%d <-> ", currnet->data);
        currnet = currnet->prev;
    }
    printf("%d ", currnet->data);
    printf("-> NULL\n");
}

//NULL <- 1 <-> 2 <-> ... <-> n -> NULL
DLL_Node *dll_create_list(int n)
{
    if (n <= 0) {
        return NULL;
    }
    DLL_Node *head = dll_create_node(1);
    DLL_Node *tail = head;
    for (int i = 2; i <= n; i++) {
        DLL_Node *new_node = dll_create_node(i);
        new_node->prev = tail;
        new_node->next = NULL;
        tail->next = new_node;
        tail = new_node;
    }
    return head;
}

DLL_Node *dll_insert_head(DLL_Node *head, int value)
{
    DLL_Node *new_node = dll_create_node(value);
    if (head == NULL) {
        head = new_node;
        return head;
    }
    head->prev = new_node;
    new_node->next = head;
    head = new_node;
    return head;
}

DLL_Node *dll_insert_tail(DLL_Node *head, int value)
{
    DLL_Node *new_node = dll_create_node(value);
    if (head == NULL) {
        head = new_node;
        return head;
    }
    DLL_Node *tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
    return head;
}

void dll_insert_after(DLL_Node *prev_node, int value)
{
    if (prev_node == NULL) {
        printf("predecessor node cannot be null\n");
        return;
    }
    DLL_Node *new_node = dll_create_node(value);
    new_node->data = value;
    new_node->next = prev_node->next;
    new_node->prev = prev_node;
    if (prev_node->next != NULL) {
        prev_node->next->prev = new_node;
    }
    prev_node->next = new_node;
}

void dll_delete_node(DLL_Node **head, DLL_Node *delete)
{
    if (*head == NULL || delete == NULL) {
        return;
    }
    if (*head == delete) {
        *head = delete->next;
    }
    if (delete->next != NULL) {
        delete->next->prev = delete->prev;
    }
    if (delete->prev != NULL) {
        delete->prev->next = delete->next;
    }
    free(delete);
}

void dll_delete_value(DLL_Node **head, int value)
{
    DLL_Node *current = *head;
    while (current->next != NULL) {
        if (current->data == value) {
            dll_delete_node(head, current);
            continue;
        }
        current = current->next;
    }
}

void dll_destroy(DLL_Node *head)
{
    while (head != NULL) {
        DLL_Node *next = head->next;
        free(head);
        head = next;
    }
}

//circular linked list
CLL_Node *cll_create_node(int value)
{
    CLL_Node *new_node = (CLL_Node*)malloc(sizeof(CLL_Node));
    if (new_node == NULL) {
        printf("memory allocation failed\n");
        return NULL;
    }
    new_node->data = value;
    new_node->next = new_node;
    return new_node;
}

void cll_traverse(CLL_Node *head)
{
    if (head == NULL) {
        printf("circular linked list is empyt\n");
        return;
    }
    CLL_Node *current = head;
    printf("circular linked list content\n");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("head_node\n");
}

CLL_Node *cll_create_list(int n)
{
    if (n <= 0) {
        return NULL;
    }
    CLL_Node *head = cll_create_node(1);
    CLL_Node *tail = head;
    for (int i = 2; i <= n; i++) {
        CLL_Node *new_node = cll_create_node(i);
        tail->next = new_node;
        tail = new_node;
    }
    tail->next = head;
    return head;
}

void cll_insert_after(CLL_Node *prev_node, int value)
{
    if (prev_node == NULL) {
        printf("predecessor node cannot be null\n");
        return;
    }
    CLL_Node *new_node = cll_create_node(value);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

CLL_Node *cll_delete_value(CLL_Node *head, int value)
{
    if (head == NULL) {
        printf("circular linked list is empyt\n");
        return NULL;
    }
    if (head->next == head) {
        if (head->data == value) {
            free(head);
            return NULL;
        }
        return head;
    }
    CLL_Node *tail = head;
    while (tail->next == head) {
        tail = tail->next;
    }
    while (head->data == value) {
        CLL_Node *removed = head;
        head = head->next;
        tail->next = head;
        free(removed);
        if (head->next == head) {
            if (head->data == value) {
                free(head);
                return NULL;
            }
            return head;
        }
    }
    CLL_Node *current = head;
    while (current->next != head) {
        if (current->next->data == value) {
            CLL_Node *removed = current->next;
            current->next = removed->next;
            free(removed);
        } else {
            current = current->next;
        }
    }
    return head;

}

void cll_destroy(CLL_Node *head)
{
    while (head != NULL) {
        CLL_Node *next = head->next;
        free(head);
        head = next;
    }
}

//circular doubly linked list
CDLL_Node *cdll_create_node(int value)
{
    CDLL_Node *new_node = (CDLL_Node*)malloc(sizeof(CDLL_Node));
    if (new_node == NULL) {
        printf("memory alloction failed\n");
        return NULL;
    }
    new_node->data = value;
    new_node->prev = new_node;
    new_node->next = new_node;
    return new_node;
}

void cdll_traverse(CDLL_Node *head)
{
    if (head == NULL) {
        printf("circular doubly linked list is empyt\n");
        return;
    }
    CDLL_Node *current = head;
    printf("circular doubly linked list content\n");
    do {
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != head);
    printf("head_node\n");
}

CDLL_Node *cdll_create_list(int n)
{
    if (n <= 0) {
        return NULL;
    }
    CDLL_Node *head = cdll_create_node(1);
    CDLL_Node *tail = head;
    for (int i = 2; i <= n; i++) {
        CDLL_Node *new_node = cdll_create_node(i);
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    tail->next = head;
    head->prev = tail;
    return head;
}

void cdll_insert_after(CDLL_Node *prev_node, int value)  
{  
    if (prev_node == NULL) {  
        printf("predecessor node cannot be null\n");  
        return;  
    }  
    CDLL_Node *new_node = cdll_create_node(value);  
    if (new_node == NULL) {  
        return;  
    }  
    new_node->prev = prev_node;  
    new_node->next = prev_node->next;  
    prev_node->next->prev = new_node;  
    prev_node->next = new_node;  
}  
 
void cdll_delete_node(CDLL_Node **head, CDLL_Node *delete)  
{  
    if (*head == NULL || delete == NULL) {  
        return;  
    }  
    if ((*head)->next == *head) {  
        if (*head == delete) {  
            free(*head);  
            *head = NULL;  
        }  
        return;  
    }  
    if (*head == delete) {  
        *head = delete->next;  
    }  
    delete->prev->next = delete->next;  
    delete->next->prev = delete->prev;  
    free(delete);  
}  
 
void cdll_delete_value(CDLL_Node **head, int value)  
{  
    if (*head == NULL) {  
        return;  
    }  
    while ((*head)->data == value) {  
        cdll_delete_node(head, *head);  
        if (*head == NULL) {  
            return;  
        }  
    }  
    CDLL_Node *current = *head;  
    while (current->next != *head) {  
        if (current->next->data == value) {  
            CDLL_Node *removed = current->next;  
            current->next = removed->next;  
            removed->next->prev = current;  
            free(removed);  
        } else {  
            current = current->next;  
        }  
    }  
} 

void cdll_destroy(CDLL_Node *head)
{
    while (head != NULL) {
        CDLL_Node *next = head->next;
        free(head);
        head = next;
    }
}
