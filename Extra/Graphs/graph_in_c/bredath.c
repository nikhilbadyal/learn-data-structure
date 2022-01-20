#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define size 7
int time ;
typedef struct Vertexx Vertex ;
struct Vertexx{
    int data ;
    char *  color;
    int distance;
    Vertex  * parent ;
    Vertex  * next;
};

typedef struct {
    Vertex vertex[size];

}Graph ;

#include"queueC.h"
Vertex * insertAtEnd(Vertex* head1,int x);
Vertex* insert_front(Vertex* head,int x);
void print_same(Vertex * head);
void insert(Graph * g ,int vert ,  int x);
void BFS(Graph *);
void DFP(Graph *);


Vertex * insertAtEnd(Vertex* head1,int x)
{
    Vertex * temp1= head1;
    Vertex* temp = (Vertex*)malloc(sizeof(Vertex));
    temp->data = x;
	temp->next = NULL;
	while(temp1->next!=NULL)
    {
       temp1= temp1->next;
    }
    temp1->next = temp;
    return (head1);

}

Vertex* insert_front(Vertex* head,int x)
{
	Vertex* temp = ( Vertex*)malloc(sizeof(Vertex));
    temp->data = x;
    temp->next = NULL;
	if(head!=NULL) temp->next = head;
	head = temp;
    return head;
}

void print_same(Vertex * head)
{
	Vertex *temp = head;
	printf("List is :\n");
	while(temp!=NULL)
	{
		printf("  %d",temp->data);
		temp = temp->next;
	}
	printf("\n");
}


void insert(Graph * g ,int vert ,  int x)
{
    if(g->vertex[vert].next == NULL)
    {
        g->vertex[vert].next = insert_front(g->vertex[vert].next , x);
        return ;
    }
    else{
        g->vertex[vert].next = insertAtEnd(g->vertex[vert].next , x);
        return ;
    }
}
void printPath(Graph * g , Vertex * x , Vertex *  y)
{
    if(x == y)
    {
        printf("%d ",x);
        return;
    }
    else if(g->vertex[x->data].parent ==NULL)
    {
        printf("No path exist .\n");
    }
    else{
       // printPath(g,,)
    }

}
void BFS(Graph *g)
{
    int pos =  4;
    for(int i = 0 ; i < size ; ++i)
    {
        g->vertex[i].color = "white";
        g->vertex[i].distance = INT_MAX;
        g->vertex[i].parent = NULL;
        g->vertex[i].data = i;
        Vertex *temp = g->vertex[i].next;
        while(temp!=NULL)
        {
            temp->color = "white";
            temp = temp->next;
        }
    }
    g->vertex[pos].color = "gray";
    g->vertex[pos].distance = 0;
    g->vertex[pos].parent = NULL;
    Queue q = { .head  = 0 , .tail = 0 };
    enQueue(&q,g->vertex[pos]);

    while(!isEmpty(&q))
    {
        Vertex v = deQueue(&q);
        Vertex  *temp1 = v.next ;
        while( temp1 != NULL)
        {
            if(g->vertex[temp1->data].color == "white")
            {
                temp1->distance = v.distance + 1;
                temp1->parent = &v;
                temp1->color = "gray";
                g->vertex[temp1->data].distance = temp1->distance;
                g->vertex[temp1->data].parent = temp1->parent;
                enQueue(&q,g->vertex[temp1->data]);
                g->vertex[temp1->data].color = "gray";


            }
            temp1 = temp1->next;
        }
        v.color = "black";
    }
    int j =  0 ;
    while(j!=size)
    {
        if(g->vertex[j].distance == INT_MAX)
        {
            printf("Through %d there exist no possible path.\n",j);
        }
        else{
            printf("%d %d \n",j,g->vertex[j].distance);
        }
        ++j;

    }
    printPath(g,&(g->vertex[4]),&g->vertex[2]);
}
void DFS(Graph *g)
{
    for(int i = 0 ; i < size ; ++i)
    {
        g->vertex[i].color = "white";
        g->vertex[i].parent = NULL;
    }
    time = 0 ;
    while(g->vertex[i].next != NULL)
    {
        if(g->vertex[i].)
    }

}
int main()
{
    Graph g;
    for(int i = 0 ; i < size ; ++i)
    {
        g.vertex[i].next = NULL;
    }
    insert(&g,0,1);
    insert(&g,0,6);
    //print_same(g.vertex[0].next);
    insert(&g,1,2);
    //print_same(g.vertex[1].next);
    insert(&g,2,4);
    insert(&g,2,3);
    //print_same(g.vertex[2].next);
    insert(&g,3,4);
    //print_same(g.vertex[3].next);
    insert(&g,4,1);
    //print_same(g.vertex[4].next);
    insert(&g,5,4);
    //print_same(g.vertex[5].next);
    insert(&g,5,3);
    //print_same(g.vertex[5].next);
    insert(&g,6,4);
    //print_same(g.vertex[5].next);
    BFS(&g);
    return 0;
}
