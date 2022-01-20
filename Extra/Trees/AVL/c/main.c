#include<stdio.h>
#include<stdlib.h>
#include "avl.h"

int main()
{
    AvlTree T= NULL;
    T = Insert(T,5);
    T = Insert(T,2);
    T = Insert(T,8);
    T = Insert(T,1);
    T = Insert(T,4);
    T = Insert(T,7);
    T = Insert(T,3);

    return 0;
}
