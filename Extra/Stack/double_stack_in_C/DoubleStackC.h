#include"declareDoubleStackC.h"

bool totalFull(Stack *s)
{
    if(s->top1 + s->top2 == size -1  )
        return true;
    return false;
}

bool totalEmpty(Stack *s)
{
    if(s->top1 == -1 && s->top2 == size -1  )
        return true;
    return false;
}

bool isEmpty1(Stack * s)
{
    if(s->top1 == -1)
        return true;
    return false;
}

bool isFull1(Stack * s)
{
    if(s->top1 == size-1)
        return true;
    return false;
}

void push1(Stack * s,int x)
{
   // printf("Hello\n");
   // printf("%d ",s->top1 );
    if(!totalFull(s))
    {
        s->top1 += 1;
        s->stackArray[s->top1]  = x;
        return ;
    }
    else{
        printf("Overflow.\n ");
        exit(0);
    }
}

void pop1(Stack *s )
{
    if(!totalEmpty(s))
    {
        printf("Underflow.\n");
        return ;
    }
    s->top1 -= 1;
}

void peek1(Stack *s)
{
    if(!totalEmpty(s))
    {
        printf("%d\n", s->stackArray[s->top1]);

    }
}

void display1(Stack *s)
{
    if(!totalEmpty(s))
    {
        for(int i = s->top1 ; i >= 0 ; --i)
        {
            printf("%d ", s->stackArray[i]);
        }
        printf("\n");
    }

}



bool isEmpty2(Stack * s)
{
    if(s->top2 == -1)
        return true;
    return false;
}

bool isFull2(Stack * s)
{
    if(s->top2 == size-1)
        return true;
    return false;
}

void push2(Stack * s,int x)
{
   // printf("Hello\n");
   // printf("%d ",s->top2 );
    if(!totalFull(s))
    {
        s->top2 += 1;
        s->stackArray[s->top2]  = x;
        return ;
    }
    else{
        printf("Overflow.\n ");
        exit(0);
    }
}

void pop2(Stack *s )
{
    if(!totalEmpty(s))
    {
        printf("Underflow.\n");
        return ;
    }
    s->top2 -= 1;
}

void peek2(Stack *s)
{
    if(!totalEmpty(s))
    {
        printf("%d\n", s->stackArray[s->top2]);

    }
}

void display2(Stack *s)
{
    if(!totalEmpty(s))
    {
        for(int i = s->top2 ; i >= size-1 ; ++i)
        {
            printf("%d ", s->stackArray[i]);
        }
        printf("\n");
    }
}


