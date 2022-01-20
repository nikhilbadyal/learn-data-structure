#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define sizee 400

typedef struct {
    Vertex stackArray[sizee];
	int head   ;
	int tail   ;

}Queue;
void enQueue(Queue *, Vertex  );
Vertex deQueue(Queue *);
void peek(const Queue *);
bool isEmpty(const Queue *);
bool isFull(const Queue *);
void display(const Queue *);
