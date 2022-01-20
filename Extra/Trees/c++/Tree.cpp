#include<bits/stdc++.h>
using namespace std;

#define COUNT 10

struct Node{
    Node * left ;
    Node * right ;
    Node * parent;
    int info;
};
class Tree{
private:
    Node * root ;
    void insert(Node * node, int info){
        if(info >= node->info){
            if(node->right != nullptr){
                insert(node->right,info);
            }else{
                node->right = create_node(info,node);
            }

        }else{
            if(node->left != nullptr){
                 insert(node->left,info);
            }else{
                node->left = create_node(info,node);
            }
        }
    }

    void print(Node * node){
        if(node != nullptr){
            print(node->left);
            cout<<node->info<<"  ";
            print(node->right);
        }
    }

    void pre_order_walk(Node *node){
        if(node != nullptr){
            cout<<node->info<<"  ";
            pre_order_walk(node->left);
            pre_order_walk(node->right);
        }
    }

    void post_order_walk(Node * node){
        if(node != nullptr){
            post_order_walk(node->left);
            post_order_walk(node->right);
            cout<<node->info<<"  ";
        }
    }

    void print2D(Node * node , int space){
        if (node == NULL)
            return;
        space += COUNT;
        print2D(node->right, space);
        cout<<endl;
        for (int i = COUNT; i < space; i++)
            cout<<" ";
        cout<<node->info<<"\n";
        print2D(node->left, space);
    }

    void  print_parent(Node * node){
        if(node != nullptr){
            print_parent(node->left);
            if(node->parent ==  nullptr){
                cout<<"-1   ";
                cout<<node->info<<endl;
            }else{
                cout<<node->parent->info<<"  ";
                cout<<node->info<<endl;
            }
            print_parent(node->right);
        }
    }

    Node * search(Node * node , int value){
        cnt++;
        if(node == nullptr || node->info == value){
            return node;
        }
        if(node->info > value){
            return search(node->left,value);
        }else{
            return search(node->right,value);
        }
    }

    Node* iterative_search(Node * node , int value){
        Node * temp = node;
        while(temp != nullptr && temp->info != value){
            if(node->info > value){
                temp = temp->left;
            }else{
                temp = temp->right;
            }
        }
        return temp;
    }
public:
    int cnt=  0 ;
    Tree(){
        root = nullptr;
    }

    bool is_empty(){
        return root==nullptr;
    }

    Node* create_node(int info,Node * node );
    void insert(int info);
    void print();
    void pre_order_walk();
    void post_order_walk();
    void print2D();
    void print_parent();
    Node * search(int value);
    Node * iterative_search(int value);
};
Node * Tree::iterative_search(int value){
    return iterative_search(root,value);
}
Node* Tree::search(int value){
    return search(root,value);
}
 void Tree::print_parent(){
     print_parent(root);
 }
void Tree::print2D(){
    print2D(root,0);
}
void Tree::post_order_walk(){
    post_order_walk(root);
}

void Tree::pre_order_walk(){
    pre_order_walk(root);
}
void Tree::print(){
    print(root);
}

Node * Tree::create_node(int info,Node * parent_node){
    Node * new_node = new Node;
    new_node->info = info;
    new_node->left = nullptr;
    new_node->right = nullptr ;
    new_node->parent = parent_node;

    return new_node;
}
void Tree::insert(int info){
    if(root!=  nullptr){
        insert(root , info);
    }else{
        root = create_node(info,nullptr);
    }
}


int main(){
    Tree Tree_obj;
    int i = 0 ;
    while( i < 10){
        int a = rand() % 1000 + i++;
        cout<<a<<"  ";
        Tree_obj.insert(a);
    }
  /*  cout<<endl;
    cout<<"InOrder Walk"<<endl;
    Tree_obj.print();
    cout<<endl;
    cout<<"PreOrder Walk"<<endl;
    Tree_obj.pre_order_walk();
    cout<<endl;
    cout<<"PostOrder Walk"<<endl;
    Tree_obj.post_order_walk();
    cout<<endl;
    //Tree_obj.print2D();
     cout<<endl; cout<<endl; cout<<endl; cout<<endl;
    Tree_obj.print_parent();
    cout<<Tree_obj.iterative_search(234);

    cout<<Tree_obj.min_node()->info;
    cout<<Tree_obj.max_node()->info;
    Tree_obj.print();
    cout<<endl;
    cout<<Tree_obj.successor()->info;
    cout<<endl;cout<<endl;cout<<endl;
    cout << Tree_obj.successor_with_parent_node()->info;

     cout<<endl;cout<<endl;cout<<endl;
    cout << Tree_obj.successor()->info;
    Tree_obj.print();
    cout<<endl;
    cout<<endl;
    cout<<endl;cout<<endl;cout<<endl;
    Tree_obj.delete_node();
    Tree_obj.print();
    */

    return 0;
}
