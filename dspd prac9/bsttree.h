#include<stdio.h>
#include<stdlib.h>
#define minvalue -999

struct treeNode 
{
    int data;
    struct treeNode *lchild;
    struct treeNode *rchild;
};
typedef struct treeNode tNode;
typedef tNode* tree;

tree insertBST(tree root,int key)
{
    if(root==NULL)
    {
        root=(tree)malloc(sizeof(tree));
        if (root==NULL)
           printf("Underflow\n");
        else
        {
            root->data=key;
            root->lchild=root->rchild=NULL;
        }
     }
     
     else if(key<root->data)
        root->lchild=insertBST(root->lchild,key);
     
     
     else if(key>root->data)
        root->rchild=insertBST(root->rchild,key);
     
     else 
        printf("Duplicate trees, insertion not allowed\n");
     
     return root;
 }
 
tree createBST()
{
    tree root;
    root=NULL;
    int key;
    do{
        scanf("%d",&key);
        if(key!= -999)
            root=insertBST(root,key);
    
    }while(key!= -999);
    return root;
}

tree FindminNode(tree root)
{
    if(root==NULL)
        return NULL;
    if(root->lchild==NULL)
        return root;
        
        return FindminNode(root->lchild);
}
 
 tree deleteBST(tree root,int key)
 {
    tree temp;
            
    if(root==NULL)
    {
            printf("Tree is empty, Deletion failed\n");
            return NULL;
    }
    
    if(key < root->data)
        root->lchild=deleteBST(root->lchild,key);                 
    else if(key > root->data)
        root->rchild=deleteBST(root->rchild,key);
    
    else
    {       
        if(root->lchild!=NULL && root->rchild!=NULL)
        {   
            temp=FindminNode(root->rchild);
            root->data=temp->data;
            root->rchild=deleteBST(root->rchild,root->data);
        }
        else
        {
            temp=root;
            if(root->rchild==NULL)                      
                root=root->lchild;
            else if(root->lchild==NULL)                
                root=root->rchild;                    
            
            free(temp);
        }
        
      }
      
      return root;
}   

int heightBST(tree root)
{ 
    if(root==NULL || (root->lchild==NULL && root->rchild==NULL))
            return 0;
    
    int leftH,rightH,max;
    leftH=heightBST(root->lchild);
    
    rightH=heightBST(root->rchild);
    
    if(leftH>rightH)
        return (leftH+1);
    else
        return rightH+1;
}

//display

void preOrderT(tree root)
{
    if(root != NULL) 
    {
        printf("%4d", root->data);
        preOrderT(root->lchild);
        preOrderT(root->rchild);
    }
}

void inOrderT(tree root)
{
    if(root != NULL)
    {
        inOrderT(root->lchild);
        printf("%4d", root->data);
        inOrderT(root->rchild);
    }
}

void postOrderT(tree root)
{
    if(root != NULL) 
    {
        postOrderT(root->lchild);
        postOrderT(root->rchild);
        printf("%4d", root->data);
    }
}

void levelOrderT(tree root, int i)
{
    if(root==NULL)
        return;
    
    if(i==1)
        printf(" %4d",root->data);
    else if (i>1)
    {
        levelOrderT(root->lchild, i-1);
        levelOrderT(root->rchild, i-1);
    }
    
}

int allParentBST(tree root)
{
    if(root == NULL ||(root->lchild == NULL && root->rchild == NULL))
        return 0;
        printf("%4d",root->data);
    return ( allParentBST(root->lchild) + allParentBST(root->rchild) + 1 );
}

int LeafsBST(tree root)
{
    if(root == NULL)
        return 0;
    if(root->lchild == NULL && root->rchild == NULL)
    {
        printf("%4d", root->data);
        return 1;
    }
    return LeafsBST(root->lchild) + LeafsBST(root->rchild);
}

int allNodesBST(tree root)
{
    int count = 1;
    if(root == NULL)
        return 0;
    printf("%4d",root->data);
    count = count + allNodesBST(root->lchild);
    count = count + allNodesBST(root->rchild);
    return count;
}

