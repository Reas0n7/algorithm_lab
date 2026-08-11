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

















