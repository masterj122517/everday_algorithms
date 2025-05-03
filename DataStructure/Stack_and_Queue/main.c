// stack
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack* s)
{
    s->top = -1;
}

int isEmptyStack(Stack* s)
{
    return s->top == -1;
}

int isFullStack(Stack* s)
{
    return s->top == MAX_SIZE - 1;
}

void push(Stack* s, int value)
{
    if (isFullStack(s))
        return;
    s->data[++(s->top)] = value;
}

int pop(Stack* s)
{
    if (isEmptyStack(s))
        return -1;
    return s->data[(s->top)--];
}

int peek(Stack* s)
{
    if (isEmptyStack(s))
        return -1;
    return s->data[s->top];
}

// queue

#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int data[MAX_SIZE];
    int front, rear, size;
} Queue;

void initQueue(Queue* q)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isEmptyQueue(Queue* q)
{
    return q->size == 0;
}

int isFullQueue(Queue* q)
{
    return q->size == MAX_SIZE;
}

void enqueue(Queue* q, int value)
{
    if (isFullQueue(q))
        return;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = value;
    q->size++;
}

int dequeue(Queue* q)
{
    if (isEmptyQueue(q))
        return -1;
    int val = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return val;
}

int frontQueue(Queue* q)
{
    if (isEmptyQueue(q))
        return -1;
    return q->data[q->front];
}
