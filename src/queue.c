#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//sequence queue
Seq_Queue *seq_queue_create(int capacity)
{
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













//circular queue






//priority queue

















