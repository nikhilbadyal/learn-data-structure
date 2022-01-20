#include<iostream>
#include "stackCpp.h"


int main()
{
    Stack s;
   // s.display();
    s.pop();
    s.push(13);
    s.push(14);
    s.push(15);
    s.push(16);
    s.display();
    s.peek();
    return 0;
}
