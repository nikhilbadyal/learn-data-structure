#include<stdlib.h>
#include<stdexcept>
#include<stdio.h>
struct Stack{
    int data;
    struct Stack * next ;
};
typedef struct Stack Stack;
Stack *push(Stack * , int );
Stack * pop(Stack *);
int peek(Stack *);
void display(Stack *);

Stack * push(Stack *TOP , int value)
{
    Stack *temp = (Stack * ) malloc(sizeof(Stack));
    temp->data = value;
    temp->next = nullptr;
    if(TOP != nullptr)
    {
        temp->next = TOP;
    }
    TOP = temp;
    return TOP ;
}
Stack *pop(Stack *TOP)
{
    if(TOP == nullptr)
    {
        printf("Under flow \n");
        return TOP;
    }
    Stack *temp = TOP;
    TOP = TOP->next ;
    free(temp);
    return TOP ;
}
int peek(Stack *TOP )
{
    if(TOP == nullptr)
    {
        printf("Under flow \n");
        return -1;
    }
    return TOP->data;

}
void display(Stack *TOP)
{
    if(TOP== NULL)
    {
        printf("Stack empty.");
        return ;
    }
    Stack * temp = TOP;
    while(temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next ;
    }
    return ;
}
