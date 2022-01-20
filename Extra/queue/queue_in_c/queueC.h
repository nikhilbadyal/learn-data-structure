#include"declareC.h"

bool isEmpty(const Queue * s)
{
   if(s->head  == s->tail )
        return true;
    return false;
}

bool isFull(const Queue * s)
{
    if(s->head == s->tail + 1 || sizee == 1)
        return true;
    return false;
}

void enQueue(Queue * s,int x)
{
    if(!isFull(s))
    {
        s->stackArray[s->tail]  = x;
        if(s->tail ==  sizee-1)
        {
            s->tail = 0;
        }
        else{
            s->tail += 1;
        }
    }
    else{
        printf("Overflow.\n ");
        exit(0);
    }
}

void deQueue(Queue *s )
{
    if(isEmpty(s))
    {
        printf("Underflow.\n");
        exit(0);
    }
    if(s->head == sizee -1 )
    {
        s->head = 1;
    }
    else{
        s->head += 1;
    }
}

void peek(const Queue *s)
{
    if(!isEmpty(s))
    {
       printf("%d\n", s->stackArray[s->head]);
    }
}

void display(const Queue *s)
{
    int temp = s->head ;
    if(!isEmpty(s))
    {
        while(temp!= s->tail)
        {
            printf("%d ",s->stackArray[temp++]);
            if(temp == sizee -1  )
            {
                printf("%d ",s->stackArray[temp]);
                temp = 0;
            }

        }
        printf("\n");
        return ;
    }
//    printf("Hello,\n");

}


