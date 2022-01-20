#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<errno.h>
#define size 100

typedef struct {
    int stackArray[size];
	int top1 ;
	int top2 ;
	int mid ;

}Stack;
void push1(Stack *, int );
void push2(Stack *, int );
void pop1(Stack *);
void pop2(Stack *);
void peek1(Stack *);
void peek2(Stack *);
bool isEmpty1(Stack *);
bool isEmpty2(Stack *);
bool isFull1(Stack *);
bool isFull2(Stack *);
void display1(Stack *);
void display2(Stack *);
bool totalEmpty(Stack * );
bool totalFull(Stack * );
