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
Seq_Queue *seq_queue_create(int capacity);
int seq_queue_is_empty(Seq_Queue *sq);
int seq_queue_is_full(Seq_Queue *sq);
int seq_queue_enqueue(Seq_Queue *sq, int value);
int seq_queue_dequeue(Seq_Queue *sq, int *out);
int seq_queue_front(Seq_Queue *sq, int *out);
void seq_queue_destroy(Seq_Queue *sq);

//circular queue
typedef struct Circ_Queue {
    int *data;
    int capacity;
    int front;
    int rear;
}Circ_Queue;
Circ_Queue *circ_queue_create(int capacity);
int circ_queue_is_empty(Circ_Queue *cq);
int circ_queue_is_full(Circ_Queue *cq);
int circ_queue_enqueue(Circ_Queue *cq, int value);
int circ_queue_dequeue(Circ_Queue *cq, int *out);
int circ_queue_front(Circ_Queue *cq, int *out);
void circ_queue_destroy(Circ_Queue *cq);




//priority queue
//priority queue in array
typedef struct Pri_Queue_Array {
    int *data;
    int size;
    int capacity;
}Pri_Queue_Array;
Pri_Queue_Array *pri_queue_array_create(int capacity);
int pri_queue_array_is_empty(Pri_Queue_Array *pq);
int pri_queue_array_is_full(Pri_Queue_Array *pq);
int pri_queue_array_enqueue(Pri_Queue_Array *pq, int value);
int pri_queue_array_dequeue(Pri_Queue_Array *pq, int *out);
int pri_queue_array_peek(Pri_Queue_Array *pq, int *out);
void pri_queue_array_destroy(Pri_Queue_Array *pq);

//priority queue in link list
typedef struct Pri_Queue_Link_Node {
    int data;
    struct Pri_Queue_Link_Node *next;
}Pri_Queue_Link_Node;

typedef struct Pri_Queue_Link {
    Pri_Queue_Link_Node *head;
    int size;
}Pri_Queue_Link;
Pri_Queue_Link *pri_queue_link_create();
int pri_queue_link_is_empty(Pri_Queue_Link *pq);
int pri_queue_link_enqueue(Pri_Queue_Link *pq, int value);
int pri_queue_link_dequeue(Pri_Queue_Link *pq, int *out);
int pri_queue_link_peek(Pri_Queue_Link *pq, int *out);
void pri_queue_link_destroy(Pri_Queue_Link *pq);








#ifdef __cplusplus
}
#endif

#endif