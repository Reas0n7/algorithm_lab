#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//sequence queue
Seq_Queue *seq_queue_create(int capacity)
{
    if (capacity <= 0) {
        return NULL;
    }
    Seq_Queue *sq = (Seq_Queue*)malloc(sizeof(Seq_Queue));
    if (sq == NULL) {
        printf("memory allocation failed\n");
        return NULL;
    }
    sq->capacity = capacity;
    sq->data = (int*)malloc((sq->capacity) * sizeof(int));
    if (sq->data == NULL) {
        printf("memory allocation failed\n");
        free(sq);
        return NULL;
    }
    sq->front = 0;
    sq->rear = 0;
    return sq;
}

int seq_queue_is_empty(Seq_Queue *sq)
{
    return sq->front == sq->rear;
}

int seq_queue_is_full(Seq_Queue *sq)
{
    return sq->rear == sq->capacity;
}

int seq_queue_enqueue(Seq_Queue *sq, int value)
{
    if (seq_queue_is_full(sq)) {
        printf("queue is full\n");
        return 0;
    }
    sq->data[sq->rear++] = value;
    return 1; 
}

int seq_queue_dequeue(Seq_Queue *sq, int *out)
{
    if (out == NULL) {
        return 0;
    }
    if (seq_queue_is_empty(sq)) {
        printf("queue is empty\n");
        return 0;
    }
    *out = sq->data[sq->front];
    sq->front++;
    return 1;
}

int seq_queue_front(Seq_Queue *sq, int *out)
{
    if (out == NULL) {
        return 0;
    }
    if (seq_queue_is_empty(sq)) {
        printf("queue is empty\n");
        return 0;
    }
    *out = sq->data[sq->front];
    return 1;
}

void seq_queue_destroy(Seq_Queue *sq)
{
    if (sq == NULL) {
        return;
    }
    free(sq->data);
    free(sq);
}

//circular queue
Circ_Queue *circ_queue_create(int capacity)
{
    if (capacity <= 0) {
        return NULL;
    }
    Circ_Queue *cq = (Circ_Queue*)malloc(sizeof(Circ_Queue));
    if (cq == NULL) {
        printf("memory allocation failed\n");
        return NULL;
    }
    cq->capacity = capacity;
    cq->data = (int*)malloc((cq->capacity) * sizeof(int));
    if (cq->data == NULL) {
        printf("memory allocation failed\n");
        free(cq);
        return NULL;
    }
    cq->front = 0;
    cq->rear = 0;
    return cq;
}

int circ_queue_is_empty(Circ_Queue *cq)
{
    return cq->front == cq->rear;
}

int circ_queue_is_full(Circ_Queue *cq)
{
    return cq->front == (cq->rear + 1) % cq->capacity;
}

int circ_queue_enqueue(Circ_Queue *cq, int value)
{
    
    if (circ_queue_is_full(cq)) {
        printf("queue is full\n");
        return 0;
    }
    cq->data[cq->rear] = value;
    cq->rear = (cq->rear + 1) % cq->capacity;
    return 1;
}

int circ_queue_dequeue(Circ_Queue *cq, int *out)
{
    if (out == NULL) {
        return 0;
    }
    if (circ_queue_is_empty(cq)) {
        printf("queue is empty\n");
        return 0;
    }
    *out = cq->data[cq->front];
    cq->front = (cq->front + 1) % cq->capacity;
    return 1;
}

int circ_queue_front(Circ_Queue *cq, int *out)
{
    if (out == NULL) {
        return 0;
    }
    if (circ_queue_is_empty(cq)) {
        printf("queue is empty\n");
        return 0;
    }
    *out = cq->data[cq->front];
    return 1;
}

void circ_queue_destroy(Circ_Queue *cq)
{
    if (cq == NULL) {
        return;
    }
    free(cq->data);
    free(cq);
}

//priority queue
//priority queue in array
Pri_Queue_Array *pri_queue_array_create(int capacity)
{
    if (capacity <= 0) {
        return NULL;
    }
    Pri_Queue_Array *pq = (Pri_Queue_Array*)malloc(sizeof(Pri_Queue_Array));
    if (pq == NULL) {
        printf("memory allocation failed\n");
        return NULL;
    }
    pq->capacity = capacity;
    pq->data = (int*)malloc((pq->capacity) * sizeof(int));
    if (pq->data == NULL) {
        printf("memory allocation failed\n");
        free(pq);
        return NULL;
    }
    pq->size = 0;
    return pq;
}

int pri_queue_array_is_empty(Pri_Queue_Array *pq)
{
    return pq->size == 0;
}

int pri_queue_array_is_full(Pri_Queue_Array *pq)
{
    return pq->size == pq->capacity;
}

int pri_queue_array_enqueue(Pri_Queue_Array *pq, int value)
{
    if (pri_queue_array_is_full(pq)) {
        printf("queue is full\n");
        return 0;
    }
    pq->data[pq->size++] = value;
    return 1;
}

int pri_queue_array_dequeue(Pri_Queue_Array *pq, int *out)
{
    if (out == NULL) {
        return 0;
    }
    if (pri_queue_array_is_empty(pq)) {
        printf("queue is empty\n");
        return 0;
    }
    int max_idx = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->data[i] > pq->data[max_idx]) {
            max_idx = i;
        }
    }
    *out = pq->data[max_idx];
    pq->data[max_idx] = pq->data[pq->size - 1];
    pq->size--;
    return 1;
}

int pri_queue_array_peek(Pri_Queue_Array *pq, int *out)
{
    if (out == NULL) {
        return 0;
    }
    if (pri_queue_array_is_empty(pq)) {
        printf("queue is empty\n");
        return 0;
    }
    int max_idx = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->data[i] > pq->data[max_idx]) {
            max_idx = i;
        }
    }
    *out = pq->data[max_idx];
    return 1;
}

void pri_queue_array_destroy(Pri_Queue_Array *pq)
{
    if (pq == NULL) {
        return;
    }
    free(pq->data);
    free(pq);
}

//priority queue in link list
Pri_Queue_Link *pri_queue_link_create()
{
    Pri_Queue_Link *pq = (Pri_Queue_Link*)malloc(sizeof(Pri_Queue_Link));
    if (pq == NULL) {
        printf("memory allocation failed\n");
        return NULL;
    }
    pq->size = 0;
    pq->head = (Pri_Queue_Link_Node*)malloc(sizeof(Pri_Queue_Link_Node));
    if (pq->head == NULL) {
        printf("memory allocation failed\n");
        free(pq);
        return NULL;
    }
    pq->head->next = NULL;
    return pq;

}

int pri_queue_link_is_empty(Pri_Queue_Link *pq)
{
    return pq->size == 0;
}

int pri_queue_link_enqueue(Pri_Queue_Link *pq, int value)
{
    Pri_Queue_Link_Node *new_node = (Pri_Queue_Link_Node*)malloc(sizeof(Pri_Queue_Link_Node));
    if (new_node == NULL) {
        printf("memory allocation failed\n");
        return 0;
    }
    new_node->data = value;
    Pri_Queue_Link_Node *current = pq->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->next = NULL;
    pq->size++;
    return 1;
}

int pri_queue_link_dequeue(Pri_Queue_Link *pq, int *out)
{
    if (pq == NULL || out == NULL) {
        return 0;
    }
    if (pri_queue_link_is_empty(pq)) {
        printf("queue is empty\n");
        return 0;
    }
    Pri_Queue_Link_Node *prev = pq->head;
    Pri_Queue_Link_Node *max_prev = pq->head;
    Pri_Queue_Link_Node *current = pq->head->next;
    int max_value = current->data;
    while (current != NULL) {
        if (current->data > max_value) {
            max_value = current->data;
            max_prev = prev;
        }
        prev = current;
        current = current->next;
    }
    Pri_Queue_Link_Node *max_node = max_prev->next;
    *out = max_node->data;
    max_prev->next = max_node->next;
    free(max_node);
    pq->size--;
    return 1;
}

int pri_queue_link_peek(Pri_Queue_Link *pq, int *out)
{
    if (out == NULL) {
        return 0;
    }
    if (pri_queue_link_is_empty(pq)) {
        printf("queue is empty\n");
        return 0;
    }
    Pri_Queue_Link_Node *current = pq->head->next;
    int max_value = current->data;
    while (current != NULL) {
        if (current->data > max_value) {
            max_value = current->data;
        }
        current = current->next;
    }
    *out = max_value;
    return 1;
}

void pri_queue_link_destroy(Pri_Queue_Link *pq)
{
    if (pq == NULL) {
        return;
    }
    Pri_Queue_Link_Node *current = pq->head;
    while (current != NULL) {
        Pri_Queue_Link_Node *next = current->next;
        free(current);
        current = next;
    }
    free(pq);
}




