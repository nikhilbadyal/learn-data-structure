#include"declare.h"

bool Stack::isEmpty()
{
    if(top == -1)
        return true;
    return false;
}

void Stack::push(int x)
{
	top = top + 1;
	stackVector.push_back(x);
}

void Stack::pop()
{
    if(isEmpty())
    {
        std::cerr<<"Underflow.\n";
        return ;
    }
    stackVector.pop_back();
}

void Stack::peek()
{
    if(!isEmpty())
    {
        std::vector<int>::iterator itr;
       // itr = stackVector.rbegin();
        std::cout<<stackVector.back();
    }
}
void Stack::display()
{
    if(!isEmpty())
    {
       /* for(const int & i : stackVector)
        {
            std::cout<<i<<" ";
        }*/
        for(auto i = stackVector.rbegin() ; i != stackVector.rend() ; ++i)
        {
            cout<<*i<<" ";
        }
        std::cout<<std::endl;
    }
}


