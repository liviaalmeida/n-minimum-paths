#include <stdio.h>
#include <stdlib.h>
#include "queue_stack.h"

queue_ * new_queue (int n)
{
    queue_ *q;
    q = (queue_*)malloc(sizeof(queue_));
    q->data = (item*)malloc(n*sizeof(item));
    q->first = 1;
    q->last = q->first;
    return q;
}

int empty_queue (queue_ q)
{
    return (q.first == q.last);
}

void put_in_queue (int x, int m, queue_ *q)
{
    if (q->last % m + 1 == q->first)
    {
        return;
    }
    else
    {
        item *n;
        n = (item*)malloc(sizeof(item));
        n->key = x;
        q->data[q->last-1] = *n;
        q->last = q->last % m + 1;
    }
}

int remove_from_queue (int m, queue_ *q)
{
    int x;
    if (empty_queue(*q))
    {
        return;
    }
    else
    {
        x = q->data[q->first-1].key;
        q->first = q->first % m + 1;
    }
    return x;
}

void delete_queue (queue_ *q)
{
	free(q->data);
	free(q);
}

stack_ * new_stack (int n)
{
    stack_ *s;
    s = (stack_*)malloc(sizeof(stack_));
    s->top = 0;
    s->data = (item*)malloc(n*sizeof(item));
    return s;
}

int empty_stack (stack_ s)
{
    return (s.top == 0);
}

void push (int x, int m, stack_ *s)
{
    if (s->top == m)
    {
        return;
    }
    else
    {
        item *n;
        n = (item*)malloc(sizeof(item));
        n->key = x;
        s->top++;
        s->data[s->top-1] = *n;
    }
}

int pop (int m, stack_ *s)
{
    int x;
    if(empty_stack(*s))
    {
        return -1;
    }
    else
    {
        x = s->data[s->top-1].key;
        s->top--;
    }
    return x;
}

void delete_stack (stack_ *s)
{
	free(s->data);
	free(s);
}