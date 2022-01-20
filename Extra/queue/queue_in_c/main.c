#include<stdio.h>
#include "queueC.h"


int main()
{
    Queue s = { .head  = 0 , .tail = 0 };
   // display(&s);
    //deQueue(&s);
    enQueue(&s,13); 
   // enQueue(&s,14);
    //peek(&s);
    enQueue(&s,15);
    enQueue(&s,19);
    //peek(&s);
    //deQueue(&s);
    //peek(&s);
    enQueue(&s,16);
    display(&s);
    //peek(&s);
    return 0;
}
