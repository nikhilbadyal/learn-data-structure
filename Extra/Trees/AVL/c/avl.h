#include<stdio.h>
#include<stdlib.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define COUNT 10

typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;
typedef struct AvlNode Tree;
int count = 0 ;
struct AvlNode{
    int data;
    AvlTree left;
    AvlTree right;
    int height;
};

AvlTree makeEmpty(AvlTree );
Position find(AvlTree , int);
Position findMax(AvlTree );
Position findMin(AvlTree );
AvlTree Insert(AvlTree , int );
AvlTree delete(AvlTree , int  );
int retrive(Position );
static Position singleRotateLeft(Position );
static Position singleRotateRight(Position );
static Position doubleRotateLeft(Position );
static Position doubleRotateRight(Position );
void print2D(AvlTree root);
void print2DUtil(AvlTree root, int space);



static int height(Position P)
{
    if(P == NULL)
        return -1;
    else
        return P->height;
}
static Position singleRotateRight(Position unbalancedNode)
{
    Position newBalancedNode;
    newBalancedNode = unbalancedNode->right;
    unbalancedNode->right = newBalancedNode->left;
    newBalancedNode->left = unbalancedNode;

    unbalancedNode->height = max(height(unbalancedNode->right),height(unbalancedNode->left)) +1;
    newBalancedNode->height = max(height(newBalancedNode->right),unbalancedNode->height) +1;

    return newBalancedNode;
}

static Position singleRotateLeft(Position unbalancedNode)
{
    Position newBalancedNode;
    newBalancedNode = unbalancedNode->left;
    unbalancedNode->left = newBalancedNode->right;
    newBalancedNode->right = unbalancedNode;

    unbalancedNode->height = max(height(unbalancedNode->left),height(unbalancedNode->right)) +1;
    newBalancedNode->height = max(height(newBalancedNode->left),unbalancedNode->height) +1;

    return newBalancedNode;
}

static Position  doubleRotateLeft(Position unbalancedNode)
{
    unbalancedNode->left = singleRotateRight(unbalancedNode->left);
    return singleRotateLeft(unbalancedNode);
}

static Position doubleRotateRight(Position unbalancedNode)
{
    unbalancedNode->right = singleRotateRight(unbalancedNode->right);
    return singleRotateRight(unbalancedNode);
}


AvlTree Insert(AvlTree T, int x)
{
    count++;
   // printf("\n%d comparing with  ",count);
    if(T == NULL)
    {
        //if(x == 6 ) printf("NULL True %d \n",count);
        T = (AvlTree)malloc(sizeof(Tree));
        if(T == NULL)
        {
            printf("Error allocating memory .\n");
            exit(0);
        }
        else{
            T->data = x;
            T->left = NULL;
            T->right = NULL;
            T->height = 0 ;
        }
    }
    else if( x > T->data)
    {
      //  if(x == 6 ) printf("Greater True %d \n",T->data);
        T->right = Insert(T->right , x);
        int temp1 = height(T->left) ;
        int temp2 = height(T->right) ;
        printf("%d %d ",temp1,temp2);
        if(temp2- temp1 == 2)
        {
            printf("Hello,\n");
            if(x > T->right->data)
            {
                T = singleRotateRight(T);
            }
            else{
                T = doubleRotateRight(T);
            }
        }
    }
    else if(x < T->data)
    {
       // if(x == 6 ) printf("Smaller True %d \n",T->data);
        T->left = Insert(T->left , x);
        int temp1 = height(T->left) ;
        int temp2 = height(T->right) ;
        printf("%d %d ",temp1,temp2);
        if(temp1- temp2 == 2)
        {
            printf("Hello,\n");
            if(x > T->left->data)
            {
                T = singleRotateLeft(T);
            }
            else{
                T = doubleRotateLeft(T);
            }
        }
    }
    T->height = max(height(T->left ),height(T->right))+1;

    return T;
}

void print2DUtil(AvlTree root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(AvlTree root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}
