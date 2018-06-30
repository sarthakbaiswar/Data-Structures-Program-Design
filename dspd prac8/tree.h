#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define maxsize 50
#define minval -999
#define NDT -1

struct treeNode 
{
    int data;
    struct treeNode *lchild;
    struct treeNode *rchild;
};
typedef struct treeNode tNode;
typedef tNode* tree;


int getLChild(int list[], int len, int ndx)
{
        int ele;
        if((2*ndx+1) > len)
            return len;
        
        return (2*ndx+1);
}

int getRChild(int list[], int len, int ndx)
{
    int ele;
    if((2*ndx+2) > len)
        return len;
   
    return (2*ndx+2);
}

tree buildTree(int list[], int len, int ndx)
{
    tree temp = NULL;
    if(list[ndx] != NDT)
    {
        temp = (tree) calloc(1, sizeof(tree));
        temp->lchild = buildTree(list,len, getLChild(list, len, ndx));
        temp->data = list[ndx];
        temp->rchild = buildTree(list,len, getRChild(list, len, ndx));
    }
return temp;
}

void preOrderT(tree root)
{
    if(root != NULL) 
    {
        printf("%4d[%lu]", root->data,(uintptr_t)root);
        preOrderT(root->lchild);
        preOrderT(root->rchild);
    }
}

void inOrderT(tree root)
{
    if(root != NULL)
    {
        inOrderT(root->lchild);
        printf("%4d[%lu]", root->data,(uintptr_t)root);
        inOrderT(root->rchild);
    }
}

void postOrderT(tree root)
{
    if(root != NULL) 
    {
        postOrderT(root->lchild);
        postOrderT(root->rchild);
        printf("%4d[%lu]", root->data,(uintptr_t)root);
    }
}

int lengthList(int list[])
{
    int i = 0;
    while(list[i] != minval)
        i = i + 1;
    return i-1;
}

int allParentBT(tree root)
{
    if(root == NULL ||(root->lchild == NULL && root->rchild == NULL))
        return 0;
    printf("%4d",root->data);
    
    return ( allParentBT(root->lchild) + allParentBT(root->rchild) + 1 );
}

int LeafsBT(tree root)
{
    if(root == NULL)
        return 0;
    if(root->lchild == NULL && root->rchild == NULL)
    {
        printf("%4d", root->data);
        return 1;
    }
    
    return LeafsBT(root->lchild) + LeafsBT(root->rchild);
}

int height(tree root)
{
    int leftH,rightH;
    if(root==NULL)
        return 0;
    if(root->lchild == NULL && root->rchild == NULL)
        return 0;
     
    leftH=height(root->lchild);
    
    rightH=height(root->rchild);
    
    if(leftH>rightH)
        return leftH+1;
     
   return rightH+1;
 }

int ParentwithtwoChildren(tree root)
{
    int count;
    if(root==NULL)
        return 0;
    if(root->lchild == NULL || root->rchild == NULL)
        return 0;
    
    printf("%4d",root->data);
    return ( ParentwithtwoChildren(root->lchild) +ParentwithtwoChildren(root->rchild)+ 1 );
}

int LocateInBT(tree root,int key)
{
    if(root==NULL)
        return 0;
    if(key!=root->data)
    {
        LocateInBT(root->lchild,key);
        LocateInBT(root->rchild,key);
    }
    else 
    {   
        printf("Key %d is found is given Tree\n",key);
        return 0;
    }
    return 1;
}

void validity (int list[],int len)
{
    int tag;
    for(int i=0;i<len;i++)
    {
        int j=len-1-i;
        
        
        if(list[0]==-1)
        {
            printf("Root is not present, invalid tree\n");
            exit(1);
        }
        
        if(list[(j-1)/2]!= -1 && list[(j-2)/2]!= -1)
            tag=1;
        else 
            tag=0;
     
    
        if(tag==0)
        {
            printf("Invalid tree\n");
            exit(1);
        }
    }
    printf("Tree is Valid\n");     
}

tree CopyBT(tree root)
{
    if(root==NULL)
        return NULL;
    
    tree temp;
    temp = (tree) calloc(1, sizeof(tree));
    temp->data=root->data;
    temp->lchild=CopyBT(root->lchild);
    temp->rchild=CopyBT(root->rchild);
    return temp;
}

int EqualBT(tree root,tree neww)
{
    if(root==NULL && neww==NULL)
        return 1;
      
   if((root->data==neww->data) && EqualBT(root->lchild,neww->lchild) && EqualBT(root->rchild,root->rchild))
        return 1;
  else
    return 0;
} 

