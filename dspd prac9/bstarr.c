/* 
FILE NAME:bstarr.c
DATE: 29/09/2017
PURPOSE: To study and implement binary search tree(BST)-USING ARRAY.
AUTHOR:SARTHAK BAISWAR
PROBLEM STATEMENT: Write C routines involving array-based implementation of BST to- (1)insert a node,(2)delete a node,(3)traverse a tree in inorder and either in preorder or postorder. Write a menu driven program to enable simulating the array based routines for BST. 
*/

#include<stdio.h>
#include<stdlib.h>
#include"bstarr.h"
#define maxsize 50

int main()
{
    atNode tree[maxsize]={1};
	populate(tree);
	
	int treeIndex = 0,key=0,temp,cont,ch;
    do{
   
	printf("\t\t\tBST menu\n");
	printf("1.Create List and BST\t 2.Inorder\t 3.Preorder\n");
	printf("4. Postorder\t 5.FindMin in Tree\t 6. FindMax in Tree\n");
	printf("7. Delete in BST\t 8. Display BST Structure\t 0. EXIT\n\n");
	
	scanf("%d",&ch);
	switch(ch){
   case 1:
	        printf("Enter the elements of BST\n");
	        printf("Enter -999 to terminate the tree\n");
	
	        while(key!=-999){
	            scanf("%d",&key);
	            if(key!=-999){
	                
	            treeIndex=insertBSTArr(tree, treeIndex, key);
	            }
	        }
	        break;
	 
	case 2: if(treeIndex!=0)
	        {  
	        printf("\nInorder traverse is:\t");
	        inorder(tree, 0);
	        }
	        else
	            printf("Empty tree\n");
	        break;
	        
    case 3: if(treeIndex!=0)
            {
            printf("\nPreorder traverse is:\t");
	        preorder(tree,0);
	        }
	        else
	            printf("Empty tree\n");
	        break;
	        
	case 4: if(treeIndex!=0)
	        {
	        printf("\nPostorder traverse is:\t");
	        postorder(tree, 0);
	        }
	        else
	            printf("Empty tree\n");
	        break;
	     
	case 5: if(treeIndex!=0)
	        {
	        temp=findmin(tree,0);
	        printf("Minimum of tree is: %d\n",tree[temp].data);
	        }
	        else
	            printf("Empty tree\n");
	        break;
	        
	case 6: if(treeIndex!=0)
	        {
	        temp=findmax(tree);
	        printf("\nMaximum of tree is: %d\n",tree[temp].data);
	        }
	        else
	            printf("Empty tree\n");
	        break;
	        
	case 7: if(treeIndex!=0)
	        {
	        printf("Enter the value for deletion\n");
	        scanf("%d",&key);
	        DeleteBST(tree,key,0);
	        printf("Tree After deletion: ");
	        preorder(tree,0);
	        displayBST(tree);
	        }
	        else
	            printf("Empty tree , No deletion\n");
	        break;
	
	case 8: printf("BST Structure is:\n");
	        displayBST(tree);
	        break;
	
	case 0: printf("Exiting from menu\n");
	        break;
    } 
	
	}while(ch!=0);
    
    return 0;


}

/*
Execution trial:

			BST menu
1.Create List and BST	 2.Inorder	 3.Preorder
4. Postorder	 5.FindMin in Tree	 6. FindMax in Tree
7. Delete in BST	 8. Display BST Structure	 0. EXIT

1
Enter the elements of BST
Enter -999 to terminate the tree
27
14
35
10
19
31
42
-999
			BST menu
1.Create List and BST	 2.Inorder	 3.Preorder
4. Postorder	 5.FindMin in Tree	 6. FindMax in Tree
7. Delete in BST	 8. Display BST Structure	 0. EXIT

2

Inorder traverse is:	10	14	19	27	31	35	42	
            BST menu
1.Create List and BST	 2.Inorder	 3.Preorder
4. Postorder	 5.FindMin in Tree	 6. FindMax in Tree
7. Delete in BST	 8. Display BST Structure	 0. EXIT

3

Preorder traverse is:	27	14	10	19	35	31	42	
            BST menu
1.Create List and BST	 2.Inorder	 3.Preorder
4. Postorder	 5.FindMin in Tree	 6. FindMax in Tree
7. Delete in BST	 8. Display BST Structure	 0. EXIT

4

Postorder traverse is:	10	19	14	31	42	35	27	
            BST menu
1.Create List and BST	 2.Inorder	 3.Preorder
4. Postorder	 5.FindMin in Tree	 6. FindMax in Tree
7. Delete in BST	 8. Display BST Structure	 0. EXIT

5
Minimum of tree is: 10
			BST menu
1.Create List and BST	 2.Inorder	 3.Preorder
4. Postorder	 5.FindMin in Tree	 6. FindMax in Tree
7. Delete in BST	 8. Display BST Structure	 0. EXIT

6

Maximum of tree is: 42
			BST menu
1.Create List and BST	 2.Inorder	 3.Preorder
4. Postorder	 5.FindMin in Tree	 6. FindMax in Tree
7. Delete in BST	 8. Display BST Structure	 0. EXIT

8
BST Structure is:

------------------------

Tindex	data	Lindex	Rindex
0	27	1	2
1	14	3	4
2	35	5	6
3	10	-1	-1
4	19	-1	-1
5	31	-1	-1
6	42	-1	-1
			BST menu
1.Create List and BST	 2.Inorder	 3.Preorder
4. Postorder	 5.FindMin in Tree	 6. FindMax in Tree
7. Delete in BST	 8. Display BST Structure	 0. EXIT

7
Enter the value for deletion
10
After shifting
Tree After deletion: 27	14	19	35	31	42	
------------------------

Tindex	data	Lindex	Rindex
0	27	1	2
1	14	-1	3
2	35	4	5
3	19	-1	-1
4	31	-1	-1
5	42	-1	-1
			BST menu
1.Create List and BST	 2.Inorder	 3.Preorder
4. Postorder	 5.FindMin in Tree	 6. FindMax in Tree
7. Delete in BST	 8. Display BST Structure	 0. EXIT

7
Enter the value for deletion
42
After shifting
Tree After deletion: 27	14	19	35	31	
------------------------

Tindex	data	Lindex	Rindex
0	27	1	2
1	14	-1	3
2	35	4	-1
3	19	-1	-1
4	31	-1	-1
			BST menu
1.Create List and BST	 2.Inorder	 3.Preorder
4. Postorder	 5.FindMin in Tree	 6. FindMax in Tree
7. Delete in BST	 8. Display BST Structure	 0. EXIT

8
BST Structure is:

------------------------

Tindex	data	Lindex	Rindex
0	27	1	2
1	14	-1	3
2	35	4	-1
3	19	-1	-1
4	31	-1	-1
			BST menu
1.Create List and BST	 2.Inorder	 3.Preorder
4. Postorder	 5.FindMin in Tree	 6. FindMax in Tree
7. Delete in BST	 8. Display BST Structure	 0. EXIT

0
Exiting from menu

*/
