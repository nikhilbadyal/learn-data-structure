#include"declareC.h"
bool isEmpty(Stack * s)
{
    if(s->top == -1)
        return true;
    return false;
}

bool isFull(Stack * s)
{
    if(s->top == size-1)
        return true;
    return false;
}

void push(Stack * s,int x)
{
   // printf("Hello\n");
   // printf("%d ",s->top );
    if(!isFull(s))
    {
        s->top += 1;
        s->stackArray[s->top]  = x;
        return ;
    }
    else{
        printf("Overflow.\n ");
        exit(0);
    }
}

void pop(Stack *s )
{
    if(!isEmpty(s))
    {
        printf("Underflow.\n");
        return ;
    }
    s->top -= 1;
}

void peek(Stack *s)
{
    if(!isEmpty(s))
    {
        printf("%d\n", s->stackArray[s->top]);

    }
}

void display(Stack *s)
{
    if(!isEmpty(s))
    {
        for(int i = s->top ; i >= 0 ; --i)
        {
            printf("%d ", s->stackArray[i]);
        }
        printf("\n");
    }
}
