#ifndef PRIORITYQUEUE_PRIORITYQ_H
#define PRIORITYQUEUE_PRIORITYQ_H

#include <iostream>

struct node{
    int value;
    node* left = nullptr;
    node* right = nullptr;
};

struct priorityQueue{
    node** queue;
    int dim;
};

priorityQueue* init(int dim);
void enqueue(priorityQueue& pq, int value, int priority);
int dequeue(priorityQueue& pq);
void print(priorityQueue& pq);
void dealloc(priorityQueue& pq);

#endif 
