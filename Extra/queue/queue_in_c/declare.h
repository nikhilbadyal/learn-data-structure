#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define sizee 400
//const int size = 100;

typedef struct {
    int stackArray[sizee];
	int head ;
	int tail ;

}Queue;
void enQueue(Queue *, int );
void deQueue(Queue *);
void peek(const Queue *);
bool isEmpty(const Queue *);
bool isFull(const Queue *);
void display(const Queue *);

