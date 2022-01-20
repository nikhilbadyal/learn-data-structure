#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define Max 50
#include<limits.h>
struct Tree{
    int data;
    struct Tree *left;
    struct Tree *right;
};
typedef struct Tree treep;

//Tree functions
treep * getNode(int );
void insert(treep ** , int );
bool search(treep ** , int );
int minRecursion(treep ** );
int maxRecursion(treep **);
int maxLoop(treep **);
int minLoop(treep **);
int findHeight(treep **);
void levelTraverse(treep **);
void inOrderTraversal(const treep * );
void preOrderTraversal(const treep * );
void postOrderTraversal(const treep * );
bool isSubTreeLesser(const treep *, int );
bool isSubTreeGreater(const treep *, int );
bool isBST(const treep *);
bool isBSTUtility(const treep *,int , int );
bool is_BST(const treep * );


struct Queue{
    int front ;
    int rear;
    treep * data[50];
};
typedef struct Queue  queuep;

// Stack functions
void enQueue(queuep * , treep * );
treep* deQueue(queuep *  );
bool checkEmpty(queuep* );

void enQueue(queuep  *q, treep*   value )
{
    if((q)->rear  == Max -1){
        fprintf(stderr, "%s", "Queue empty!\n");
        return ;
    }
  //  printf("Here\n");
   // printf("front %d ",q->front);
  //  printf("front %d ",q->rear);
    if((q)->front == -1 && (q)->rear == -1){
        //printf("Here\n");
        (q)->front = (q)->rear = 0;
    }
    else{
        (q)->rear = (q)->rear +1;
    }
    (q)->data[(q)->rear] = value;
}
treep * deQueue(queuep *q)
{
    if((q)->front  ==  -1 ||(q)->front > (q)->rear )
    {
        printf("Underflow.\n");
       // fprintf(stderr, "%s", "Queue empty!\n");
    }
   // printf("%d",q->front);
    treep * value = (q)->data[(q)->front];
    (q)->front++;
    if((q)->front > (q)->rear)
        (q)->front = (q)->rear = -1;
    return value;
}
bool checkEmpty(queuep * q)
{
    if((q)->front == -1 && (q)->rear == -1)
        return true;
    return false;
}



treep * getNode(int data)
{
    treep * temp = (treep *)malloc(sizeof(treep));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}/*
treep * createTree()
{
    char ch = 'y';
    treep *rootp;
    do{
        int data;
        printf("Enter data to store in tree.\n");
        scanf("%d",&data);
        *rootp = getNode(value);

        printf("More ?");
        scanf("%d ",&ch);
    }while(ch != 'n');
    return rootp;
}*/
void insert(treep **rootp , int value)
{
    if(*rootp == NULL)
    {
        *rootp = getNode(value);
        return ;
    }
    if(value>(*rootp)->data)
    {
       // printf("Graeter\n");
        insert(&(*rootp)->right,value);
    }
    else{
        insert(&(*rootp)->left,value);
    }
    return;
}
bool search(treep **rootp, int value)
{
    if(*rootp == NULL) return false;
    if((*rootp)->data == value) return true;
    if((*rootp)->data > value) {return search(&(*rootp)->left,value);}
    if((*rootp)->data < value) {return search(&(*rootp)->right,value);}
    return false;
}
int maxRecursion(treep **rootp)
{
    if((*rootp)->right == NULL) return (*rootp)->data;
    maxRecursion(&(*rootp)->right);
}
int minRecursion(treep **rootp)
{
    if((*rootp)->left == NULL) return (*rootp)->data;
    minRecursion(&(*rootp)->left);
}
int maxLoop(treep **rootp)
{
    if((*rootp) == NULL)
    {
        fprintf(stderr, "%s", "Tree empty!\n");
    }
    treep *temp = *rootp;
    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}
int minLoop(treep **rootp)
{
    if((*rootp) == NULL)
    {
        fprintf(stderr, "%s", "Tree empty!\n");
    }
    treep *temp = *rootp;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}
int findHeight(treep **rootp)
{
    if(*rootp == NULL) return 0;
    int left = findHeight(&(*rootp)->left);
   // printf("Left %d\n",left);
    int right = findHeight(&(*rootp)->right);
   // printf("Right %d\n",left);
    return max(left,right)+1;
}
void levelTraverse(treep **rootp)
{
    if((*rootp) == NULL)
    {
        fprintf(stderr, "%s", "Tree empty!\n");
    }
    queuep  q = {.front = -1 , .rear = -1};
    treep *temp = *rootp;

 //   printf("front %d ",q.front);
    enQueue(&q,*rootp);
 //   printf("front %d ",q.front);
   // temp = deQueue(&q);
  //  printf("%d ",temp->data);

    while(!checkEmpty(&q))
    {
        temp = deQueue(&q);
        printf("%d ",temp->data);
        if(temp->left != NULL)
            enQueue(&q,temp->left);
        if(temp->right != NULL)
            enQueue(&q,temp->right);

    }
}
void preOrderTraversal(const treep * rootp)
{
    if(rootp == NULL)
    {
        return ;
    }
    printf("%d ",rootp->data);
    preOrderTraversal(rootp->left);
    preOrderTraversal(rootp->right);
}
void postOrderTraversal(const treep * rootp)
{
    if(rootp == NULL)
    {
        return ;
    }
    preOrderTraversal(rootp->left);
    preOrderTraversal(rootp->right);
    printf("%d ",rootp->data);
}
void inOrderTraversal(const treep * rootp)
{
    if(rootp == NULL)
    {
        return ;
    }
    preOrderTraversal(rootp->left);
    printf("%d ",rootp->data);
    preOrderTraversal(rootp->right);
}
bool isSubTreeGreater(const treep *rootp, int data )
{
    if(rootp == NULL) return true;
    if(data < rootp->data &&  isSubTreeGreater(rootp->right, data ) && isSubTreeGreater(rootp->left , data))
       return true;
    else
       return false;
}
bool isSubTreeLesser(const treep *rootp, int data )
{
    if(rootp == NULL) return true;
    if(data > rootp->data &&  isSubTreeLesser(rootp->right, data ) && isSubTreeLesser(rootp->left , data))
       return true;
    else
       return false;
}
bool isBST(const treep *rootp)
{
    if(rootp == NULL) return true;
    if(isSubTreeLesser( rootp->left, rootp->data ) && isSubTreeGreater( rootp->right,rootp->data ) && isBST(rootp->left) && isBST(rootp->right ) )
        return true;
    return false;
}
bool isBSTUtility(const treep *root,int minValue , int maxValue)
{
    if(root == NULL) return true;
    if(root-> data > minValue && root->data < maxValue && isBSTUtility(root->left,minValue , root->data) && isBSTUtility(root->right, root->data,maxValue ) )
        return true;
    else
        return false;
}
bool is_BST(const treep * rootp)
{
    return isBSTUtility(rootp , INT_MIN , INT_MAX );
}
