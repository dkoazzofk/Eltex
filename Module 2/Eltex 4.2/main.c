#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGHT 128

typedef struct {
    int value;
    int priority;
}PQElemet;

typedef struct {
    PQElemet* elements;
    int size;
    int capacity;
}PriorityQueue;

void initqueue(PriorityQueue* pq, int capacity){
    pq->elements = (PQElemet*)malloc(sizeof(PQElemet) * capacity);
    pq->size = 0;
    pq->capacity = capacity;
}

void insert(PriorityQueue* pq, int value, int priority){
    if (pq->size >= pq->capacity){
        printf("Queue is full.");
        return;
    }
    pq->elements[pq->size].value = value;
    pq->elements[pq->size].priority = priority;
    pq->size++;

    for (int i = pq->size - 1; i > 0; i--){
        if (pq->elements[i].priority > pq->elements[i - 1].priority){
            PQElemet temp = pq->elements[i];
            pq->elements[i] = pq->elements[i - 1];
            pq->elements[i - 1] = temp;
        } else {
            break;
        }
    }
}

PQElemet extractMax(PriorityQueue* pq){
    if (pq->size == 0){
        printf("Queue is empty");
        PQElemet empty = {0, 0};
        return empty;
    }
    
    PQElemet max = pq->elements[0];

    for (int i = 1; i < pq->size; i++){
        pq->elements[i - 1] = pq->elements[i];
    }

    pq->size--;

    return max;
}

int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

void freeQueue(PriorityQueue* pq) {
    free(pq->elements);
}

int main() {
    PriorityQueue pq;
    initqueue(&pq, 10);

    insert(&pq, 4, 0);
    insert(&pq, 5, 2);
    insert(&pq, 10, 5);
    insert(&pq, 3, 24);
    insert(&pq, 7, 3);

    while (!isEmpty(&pq)) {
        PQElemet max = extractMax(&pq);
        printf("Value: %d, Priority: %d\n", max.value, max.priority);
    }

    freeQueue(&pq);
    return 0;
}