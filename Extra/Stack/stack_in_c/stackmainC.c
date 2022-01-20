#include<stdio.h>
#include "stackC.h"


int main()
{
    Stack s = {.top = -1};
    s.top = -1;
    display(&s);
    pop(&s);
    push(&s,13);
    push(&s,14);
    push(&s,15 );
    push(&s,16);
    display(&s);
    peek(&s);
    return 0;
}
