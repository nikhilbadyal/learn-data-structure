#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<iostream>
//#include<cstdlib>
//using namespace std;
#define size 6
typedef struct Node node;
struct Node {
    int data;
     node* next;

};
typedef struct {
    node * arr[size];
    int matrix[size][size];

}Graph;
node * insertAtEnd(node* ,int );
node* insert_front(node* head,int );
void print_same(node* );
void insert(node **  , int );
void printArray(int arr[][8] );
void enterEdge(int arr[][8]);
void outDegree(node **);
void inDegreeArray(node ** , int * );
void inDegree(node **);
void topologicalSort(Graph*, int *);




node * insertAtEnd(node* head1,int x)
{
    node * temp1= head1;
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
	temp->next = NULL;
	while(temp1->next!=NULL)
    {
       temp1= temp1->next;
    }
    temp1->next = temp;
    return (head1);

}

node* insert_front(node* head,int x)
{
	node* temp = ( node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;
	if(head!=NULL) temp->next = head;
	head = temp;
    return head;
}
void print_same(node* head)
{
	node *temp = head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void insert(node ** head , int x)
{
    if(*head == NULL)
    {
        *head = insert_front(*head , x);
        return ;
    }
    else{
        *head = insertAtEnd(*head , x);
    }
}
void enterEdge(int arr[][8])
{
    int temp1, temp2;
    char ch = 'y';
    while(ch == 'y')
    {
        printf("Enter edges sequence wise \n");
        scanf("%d %d",&temp1, &temp2);
        arr[temp1-1][temp2-1]  = 1;
        printf("Enter y to enter data \n");
       // scanf("%c",&ch);
        std::cin>>ch;
    }

}
void printArray(int arr[][8] )
{
    for(int i = 0 ; i< size ; ++i)
    {
        for(int j = 0 ; j < size ; ++j)
        {
            if(arr[i][j] != INT_MAX)
            {
                printf("%d ",j+1);
            }
        }
        printf("\n");
    }
}
void outDegree(node **arr)
{
    int temp;
    printf("Enter vertex whose out degree you want to find out.\n");
    scanf("%d",&temp);
    if(temp>=size+1)
    {
        std::cout<<"Wrong input return .\n";
        return;
    }
    node * head = arr[temp-1];
    int i =0;
    while(head!=NULL)
    {
        head = head->next;
        i++;
    }
    printf("%d\n",i);
}

void inDegree(node ** arr)
{
    int temp;
    printf("Enter vertex whose in degree you want to find out.\n");
    scanf("%d",&temp);
    if(temp>=size+1)
    {
        std::cout<<"Wrong input return .\n";
        return;
    }
    int count  =0;
    for(int i =0 ; i< size ; ++i)
    {
        node * head = arr[i];
        while(head!=NULL)
        {
            if(head->data== temp)
            {
                count++;
            }
            head = head->next;
        }
    }
    printf("%d\n",count);
}

void inDegreeArray(node ** arr,int *indegreeArray)
{
    for(int j = 0 ;  j < size ; ++j)
    {
        int count  =0;
        for(int i =0 ; i< size ; ++i)
        {
            node * head = arr[i];
            while(head!=NULL)
            {
                if(head->data== j+1)
                {
                    count++;
                }
                head = head->next;
            }
        }
        indegreeArray[j] = count;
    }
}

void topologicalSort(Graph * g, int *topo)
{
    int indegreeArray[size];
    inDegreeArray(g->arr,indegreeArray);
    int count = 0 ;
    int k =0 ;
    for(int j = 0 ; j < size ; ++j)
    {
        int flag = 1;
        for(int i = 0 ; i < size; ++i )
        {
            if(indegreeArray[i] == 0)
            {
                flag = 0;
                count++;
                topo[k] = i+1; ++k;
                node * head = g->arr[i];
                while(head!=NULL)
                {
                    int pos = head->data;
                    indegreeArray[pos-1] -= 1;
                    head = head->next;
                }
                indegreeArray[i] = INT_MAX;
            }


        }
        if(flag && count != size)
        {
            printf("Ops! cyclic graph .\n");
            return ;
        }
    }
}
int main()
{
    Graph g;
    for(int i = 0 ; i < size ; ++i)
    {
        g.arr[i] = NULL;
    }
    insert(&g.arr[2],4);
    insert(&g.arr[3],2);
    insert(&g.arr[4],1);
    insert(&g.arr[4],2);
    insert(&g.arr[5],1);
    insert(&g.arr[5],3);

//   while(1){ outDegree(g.arr);}
  // while(1){inDegree(g.arr);}
    int topo[size];
    topologicalSort(&g,topo);
  // int indegreeArray[size];
  // inDegreeArray(g.arr,indegreeArray);
    for(int i = 0 ; i < size ;++i)
    {
       std::cout<<topo[i]<<" ";
    }

 /*   for(int i = 0 ; i < size ; ++i)
    {
        print_same(g.arr[i]);
    }
    for(int i = 0 ; i < size ; ++i)
    {
        for(int j = 0 ; j < size ; ++j)
        {
            g.matrix[i][j] = INT_MAX;
        }

    }
    enterEdge(g.matrix);
    printArray(g.matrix);*/
    return 0;
}
