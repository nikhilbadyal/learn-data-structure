#include<iostream>
#include"ddeclare.h"
using namespace std;


int main(){
    Node *head = nullptr;
    head = Node::create_list(head);
    Node::print(head);
    Node::reversePrint(head);
    Node::size(head);
     head =  Node::mergeSort(head);
    Node::print(head);
    cout<< Node::isAscending(head)<<endl;
    cout<< Node::isDescending(head)<<endl;
    cout<< Node::isSorted(head)<<endl;
     Node::insertAtN(head, 3134, 2);
     Node::print(head);
     Node::insertAtN(head, 4, 5);
    Node::delAlternative(head);
    Node::print(head);

    std::cout << "Done" << '\n';
    return 0 ;
}
