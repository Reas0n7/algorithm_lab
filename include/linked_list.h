#ifndef LINKED_LIST_H
#define LINKED_LIST_H


#ifdef __cplusplus
extern "C" {
#endif

//singly linked list
typedef struct SLL_Node {
    int data;
    struct SLL_Node *next;
}SLL_Node;
SLL_Node *sll_create_node(int value);
void sll_traverse(SLL_Node *head);
SLL_Node *sll_create_list(int n);
SLL_Node *sll_insert_head(SLL_Node *head, int value);
SLL_Node *sll_insert_tail(SLL_Node *head, int value);
void sll_insert_after(SLL_Node *prevNode, int value);
SLL_Node *sll_delete_head(SLL_Node *head);
SLL_Node *sll_delete_tail(SLL_Node *head);
SLL_Node *sll_delete_value(SLL_Node *head, int value);
void sll_destroy(SLL_Node *head);

//doubly linked list
typedef struct DLL_Node {
    int data;
    struct DLL_Node *prev;
    struct DLL_Node *next;
}DLL_Node;
DLL_Node *dll_create_node(int value);
void dll_traverse(DLL_Node *head);
void dll_traverse_reverse(DLL_Node *tail);
DLL_Node *dll_create_list(int n);
DLL_Node *dll_insert_head(DLL_Node *head, int value);
DLL_Node *dll_insert_tail(DLL_Node *head, int value);
void dll_insert_after(DLL_Node *prev_node, int value);
void dll_delete_node(DLL_Node **head, DLL_Node *delete);
void dll_delete_value(DLL_Node **head, int value);
void dll_destroy(DLL_Node *head);

//circular linked list
typedef struct CLL_Node {
    int data;
    struct CLL_Node *next;
}CLL_Node;
CLL_Node *cll_create_node(int value);
void cll_traverse(CLL_Node *head);
CLL_Node *cll_create_list(int n);
void cll_insert_after(CLL_Node *prev_node, int value);
CLL_Node *cll_delete_value(CLL_Node *head, int value);
void cll_destroy(CLL_Node *head);

//circular doubly linked list
typedef struct CDLL_Node {
    int data;
    struct CDLL_Node *prev;
    struct CDLL_Node *next;
}CDLL_Node;
CDLL_Node *cdll_create_node(int value);
void cdll_traverse(CDLL_Node *head);
CDLL_Node *cdll_create_list(int n);
void cdll_insert_after(CDLL_Node *prev_node, int value);  
void cdll_delete_node(CDLL_Node **head, CDLL_Node *delete);  
void cdll_delete_value(CDLL_Node **head, int value);
void cdll_destroy(CDLL_Node *head);
  
  
  
#ifdef __cplusplus  
}  
#endif  
  
#endif 
