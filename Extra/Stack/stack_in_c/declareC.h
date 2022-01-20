#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<errno.h>
#define size 100

typedef struct {
    int stackArray[size];
	int top ;

}Stack;
void push(Stack *, int );
void pop(Stack *);
void peek(Stack *);
bool isEmpty(Stack *);
bool isFull(Stack *);
void display(Stack *);

