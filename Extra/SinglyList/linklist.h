#include"declare.h"
struct Node* create_list(Node* head)
{
    int num,i;
    while(i)
    {
        printf("Enter data.\n");
        scanf("%d",&num);
        if(head==NULL)
        {
            head = (struct Node *)malloc(sizeof(struct Node));
            head->data = num;
            head->next = NULL; // nexts the address field to NULL
            temp = head;
        }
        else{struct Node* temp1 = (struct Node *)malloc(sizeof(struct Node));
        temp1->data = num;      // nexts the num field of fnNode with num
        temp1->next = NULL; // nexts the address field of fnNode with NULL

        temp->next = temp1; // nexts previous Node i.e. tmp to the fnNode
        temp = temp->next;
        }
        printf("Enter 1 to enter more.\n");
        scanf("%d",&i);
    }

    return head;
}
void print_same(struct Node* head)
{
	struct Node *temp = head;
	printf("List is :\n");
	while(temp!=NULL)
	{
		printf("  %d",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void reverse_print(struct Node* head)
   {
	if(head==NULL) return;
	reverse_print(head->next);
	printf("  %d",head->data);
	return ;
    }
void size(struct Node* head)
{
    int i =0;
    while(head!=NULL)
	{
	    head = head->next;
		i++;
	}
	printf("%d",i);
}
bool equality(struct Node*head1,struct Node*head2)
{
    while(head1!=NULL && head2!= NULL)
	{
	    if(head1->data!=head2->data){ return false;}
	    head1 = head1->next;
	    head2 = head2->next;
	}
	return (head1 ==NULL && head2 == NULL);
}
bool search_sorted(struct Node* head, int x)
{
    struct Node* current = head;  // Initialize current
    while (current != NULL)
    {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}
void split(Node* source, Node** frontsp, Node** backsp)
{
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontsp = source;
    *backsp = slow->next;
    slow->next = NULL;
}
Node * merge_sorted(Node * headd1, Node* headd2)
{
    Node *s;
    Node *new_head=NULL;
    if(headd1->data>=headd2->data)
    {
       s = headd2;
        headd2 = s->next;
    }
    else{
             s = headd1;
        headd1 = s->next;
        }
    new_head = s;

    while(headd1!=NULL && headd2!=NULL)
    {
        if(headd1->data>=headd2->data)  //big
        {
            s->next= headd2;
            s = headd2;
            headd2 = headd2->next;
        }
        else  {//small
                s->next = headd1;    // s->next = head2;
            s = headd1;   // s = head2;
            headd1 = headd1->next;

    }
    }
    if(headd1==NULL) s->next = headd2;
    if(headd2==NULL) s->next = headd1;
 //  print_same(new_head);
    return new_head;
}
Node * merge_sort(Node * head)
{
    Node * temp = head;
    Node * a ;
    Node * b;

    if ((temp == NULL) || (temp->next == NULL)) {
        return head;}
    split(head,&a,&b);
    a = merge_sort(a);
    b = merge_sort(b);
    head = merge_sorted(a,b);
    return head;
}
bool search_unsorted(Node* head, int x)
{
    head = merge_sort(head);
    return search_sorted(head,x);
}
void append_list(Node* head1,struct Node* head2)
{
    Node *temp=head1;
    while(temp->next!=NULL) {temp = temp->next;}
    temp->next = head2;
    print_same(head1);
}
Node* delete_nth(Node* head,int n)
{
	int i;
	Node* temp1 = head;
	if(n==1)
	{
		head=head->next;
		return head;
	}
	for(i=0;i<n-2;i++)
	{
		temp1 = temp1->next;
	}
	Node* temp2 = temp1->next;
	temp1->next=temp2->next;
	free(temp2);
	return head;
}
struct Node* delete_front(struct Node* head)
{
		head=head->next;
		return head;
}
struct Node* delete_last(struct Node* head)
{
	struct Node* temp1 = head;
	while(temp1->next->next!=NULL)
	{
		temp1 = temp1->next;
	}
	struct Node* temp2 = temp1->next;
	temp1->next=temp2->next;
	free(temp2);
	return head;
}
bool ascend(struct Node* head){
    while(head!=NULL && head->next != NULL)
    {
        if(head->data>head->next->data) {return true;} //NOt Ascend
        head = head->next;
    }
    return false;

}
bool descend(struct Node * head){
    while(head!=NULL && head->next != NULL)
    {
        if(head->data<head->next->data) {return true;} //NOt DEScend
        head = head->next;
    }
    return false;

}
void is_sorted(struct Node* head)
{
    if(ascend(head))
    { if(descend(head))
       {
        printf("Array unordered.\n");
        }
        else{printf("Array in Descending order.");}
    }
    else{
        printf("Array in Ascending order.");
    }
}
struct Node* insert_front(struct Node* head,int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
//	*(temp).data = x;
    temp->data = x;
    temp->next = NULL;
  //  temp->next = head;
//	*(temp).next = NULL;
	if(head!=NULL) temp->next = head;
	head = temp;
//  temp-> = x;
    return head;
}
Node* insert_n(Node* head,int data,int position)
{
	int i;
	Node* temp1 = (Node*)malloc(sizeof(Node));
	temp1->data=data;
	temp1->next = NULL;
	if(position==1)
	{
		temp1->next = head;

		head = temp1;
		return head;
	}
	Node* temp2 = head;
	for(i=0;i<position-2;i++)
	{
		temp2= temp2->next;
	}
	temp1->next =temp2->next;
	//if(temp2->next == NULL)// printf("yes");
	temp2->next = temp1;
//	if(temp1->next == NULL)// printf("not");
	return (head);
}
Node * insertAtEnd(Node* head1,int x)
{
    Node * temp1= head1;
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
	temp->next = NULL;
	while(temp1->next!=NULL)
    {
       temp1= temp1->next;
    }
    temp1->next = temp;
    return (head1);

}
Node * remove_dup(Node * head)
{
    if(head == NULL) { printf("List Empty."); return head; }
    Node * temp = head;
    Node *temp1 = NULL;
    while(temp->next !=NULL)
    {
        if(temp->data == temp->next->data)
        {
            temp1 = temp->next->next;
            free(temp->next);
            temp->next = temp1;
        }
        else{

            temp = temp->next;
        }
    }
    print_same(head);
    return head;
}
Node * moveLtoF(Node * head)
{
    Node * temp1= head;
    Node * temp2= head->next;
    Node * temp3 = head;
    while(temp2->next!=NULL)
    {
        temp2= temp2->next;
        temp1= temp1->next;
    }
    head = temp2;
    temp2->next = temp3;
    temp1->next =  NULL;
    print_same(head);
    return head;
}
Node * del_alt(Node * head)
{
    Node *temp = head;
    Node *temp1 = head->next;
    while(temp!=NULL && temp1!=NULL)
    {
        temp->next = temp1->next;
        free(temp1);

        temp= temp->next;
        if(temp!=NULL)
        {
            temp1= temp->next;
        }
    }
    return head;
}
Node * moveFtoL(Node * head)
{
    Node * temp1 = head;
    Node * temp2 = head->next;
    while(temp1->next!=NULL)
    {
        temp1= temp1->next;

    }
    temp1->next = head;
    head = temp2;
    temp1->next->next =NULL;
    return head;
}
void rotate(Node* head)
{
    int n,i;
    printf("Enter key value:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        head = moveFtoL(head);
    }
    print_same(head);
}
void  del_list(Node* head)
{
    if(head==NULL) return ;
	del_list(head->next);
	free(head);
	printf("List deleted.");

}/*
Node *recursion(Node *head) {
    Node *temp1 = (Node*)malloc(sizeof(Node));
    Node *temp2 = (Node*)malloc(sizeof(Node));

    if (head->next   == NULL) {
        return head;
    }
    else {
        temp1 =recursion(head->next);
        temp2 =head->next;
        temp2->next = head;
        head->next = NULL;
    }
    return temp1;
};*/
struct Node* recursion(struct Node* head){
    if(head->next == NULL){

        return head;
    }
    struct Node* newHead = recursion(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}
bool not_equal(struct Node * head1,struct Node * head2)
{
    return !equality(head1,head2);
}
void deleteByValue(Node * head , int value )
{
    print_same(head);
    Node * temp= head;
    while(temp->next->data != value)
    {
        temp = temp->next;
    }
    Node * temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
    print_same(head);
}

/*
Node* insert_beg(Node* head,int x)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = x;
	temp->next = NULL;
	if(head!=NULL) temp->next = head;
	head = temp;
	print_same(head);
	return head;
}

Node* delete(Node* head,int n)
{
   // n=1;
	int i;
	Node* temp1 = head;
	if(n==1)
	{
		head=head->next;
		return head;
	}
	for(i=0;i<n-2;i++)
	{
		temp1 = temp1->next;
	}

	Node* temp2 = temp1->next;
	temp1->next=temp2->next;
	free(temp2);
	return head;
}*/
