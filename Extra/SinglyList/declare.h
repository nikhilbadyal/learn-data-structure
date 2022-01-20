#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
int dat̥a;
struct Node* next;
}*temp1,*temp,*head;
typedef struct Node Node;

struct Node* create_list(struct Node* head);
void print_same(struct Node* head);
void reverse_print(struct Node* head);
void size(struct Node* head);
bool equality(struct Node*head1,struct Node*head2);
bool search_sorted(struct Node* head, int x);
void split(Node* source, Node** frontsp, Node** backsp);
Node * merge_sorted(Node * headd1, Node* headd2);
Node * merge_sort(Node * head);
bool search_unsorted(Node* head, int x);
void append_list(Node* head1,struct Node* head2);
Node* delete_nth(Node* head,int n);
struct Node* delete_front(struct Node* head);
struct Node* delete_last(struct Node* head);
bool ascend(struct Node* head);
bool descend(struct Node * head);
void is_sorted(struct Node* head);
struct Node* insert_front(struct Node* head,int x);
Node* insert_n(Node* head,int data,int position);
Node * insertAtEnd(Node* head1,int x);
Node * remove_dup(Node * head);
Node * moveLtoF(Node * head);
Node * del_alt(Node * head);
Node * moveFtoL(Node * head);
void rotate(Node* head);
void  del_list(Node* head);
struct Node* recursion(struct Node* head);
bool not_equal(struct Node * head1,struct Node * head2);
void deleteByValue(Node * head , int value );
