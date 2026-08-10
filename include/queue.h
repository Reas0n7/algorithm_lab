#ifndef QUEUE_H
#define QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

//sequence queue
typedef struct Seq_Queue {
    int *data;
    int capacity;
    int front;
    int rear;
}Seq_Queue;


//circular queue
typedef struct Circ_Queue {
    int *data;
    int capacity;
    int front;
    int rear;
}Circ_Queue;




//priority queue
typedef struct PQ_Array {
    int *data;
    int size;
    int capacity;
}PQ_Array;


typedef struct PQ_Link_Node {
    int* data;
    struct PQ_Link_Node *next;
}PQ_Link_Node;

typedef struct PQ_Link {
    PQ_Link_Node *head;
    int size;
}PQ_Link;

#ifdef __cplusplus
}
#endif

#endif