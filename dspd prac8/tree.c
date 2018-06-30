/*
FILE NAME:  tree.c
DATE: 22/09/2017
PURPOSE: To study a tree data structure and demonstrate different traversals on it – Inorder, Pre-Order and Post-Order.
AUTHOR: SARTHAK BAISWAR
PROBLEM STATEMENT: Create a self-referential structure, TreeNode to represent a node of a binary tree. Implement the routines to - (1) create a tree node, (2) create a rooted binary tree from a list [an array] representing DATA content of the nodes of the intended binary tree, (3)perform inorder walk of the tree, (4) perform preorder walk of the tree, (5) perform postorder walk of the tree, (6) find height of the tree [assume ROOT at height 0], (7)count and print all parent [internal] nodes in the tree, and (8) to locate a KEY in the tree.Create a menu-driven program to test these routines.
*/

#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

#define maxsize 50
#define minval -999

int main()
{
    int list[maxsize];
    int ndx=0;
    int choice;
    int len=0,len2=0;
    int i,j,p,p2,l,h,loc,key,eq;
    
    tree root,copy,neww;
    
    do
    {
    printf("\n1.Create tree\t2.Preorder walk\t3.Postorder walk\t4.Inorder walk\t\n5.Height of tree\t6.All parent nodes\t7.All leaf nodes\t\n8.Parent with two children\t9.Locate Element\t10.Copy Tree\t11.Equal trees???\t\n");
    printf("Enter a choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("Give a list(Enter -999 to end the input):\n");
                i=-1;
                do
                {   
                    i++;
                    scanf("%d",&list[i]);            
                }while(list[i]!=minval && i!=maxsize);
                
                list[i]=NDT;
                list[i+1]=minval;
                
                len=lengthList(list);
                validity (list,len);
                root = buildTree(list,len,ndx);
                break;
                
        case 2: printf("Preorder walk is....\n");
                preOrderT(root);
                break;
                
        case 3: printf("Postorder walk is.....\n");
                postOrderT(root);
                break;
                
        case 4: printf("Inorder walk is.....\n");
                inOrderT(root);
                break;
                
        case 5: h=height(root);
                printf("Height of tree: %d\n",h);
                break;
                
        case 6: printf("Parent node:\n");
                p=allParentBT(root);
                printf("\nAll parent nodes: %d\n",p); 
                break; 
                
        case 7: printf("Leaf nodes:\n");
                l=LeafsBT(root);
                printf("\nLeaf nodes: %d",l);
                break; 
                
        case 8: printf("Parents with two children:\n");
                p2=ParentwithtwoChildren(root);
                printf("\nParent with two children: %d",p2);
                break;
                
        case 9: printf("Enter the element to be located:\n");
                scanf("%d",&key);
                loc = LocateInBT(root,key); 
                break;
                
        case 10:printf("Copied Elements:\n");
                copy=CopyBT(root);
                inOrderT(copy);
                break;
                
        case 11:printf("Give a second list to make tree to be compared:\n");
                j=-1;
                do
                {   
                    j++;
                    scanf("%d",&list[j]);
                }while(list[j]!=minval && j!=maxsize);
                
                list[j]=NDT;
                list[j+1]=minval;
                
                len2=lengthList(list);
                validity (list,len2);
                neww = buildTree(list,len2,0);
                eq=EqualBT(root,neww);
                printf("%d\n",eq);
                if(eq==1)
                {
                      printf("Equal trees\n");
                }
                if(eq==0)
                {
                    printf("Not equal trees\n");
                }
         }
         
    }while(choice!=0);

return 0;
}
/*
EXECUTION TRIAL:


1.Create tree	2.Preorder walk	3.Postorder walk	4.Inorder walk	
5.Height of tree	6.All parent nodes	7.All leaf nodes	
8.Parent with two children	9.Locate Element	10.Copy Tree	11.Equal trees???	
Enter a choice:
1
Give a list(Enter -999 to end the input):
27
14
35
10
19
31
42
-999
Tree is Valid

1.Create tree	2.Preorder walk	3.Postorder walk	4.Inorder walk	
5.Height of tree	6.All parent nodes	7.All leaf nodes	
8.Parent with two children	9.Locate Element	10.Copy Tree	11.Equal trees???	
Enter a choice:
2
Preorder walk is....
  27[8423472]  14[8423504]  10[8423536]  19[8423568]  35[8423600]  31[8423632]  42[8423664]
  
1.Create tree	2.Preorder walk	3.Postorder walk	4.Inorder walk	
5.Height of tree	6.All parent nodes	7.All leaf nodes	
8.Parent with two children	9.Locate Element	10.Copy Tree	11.Equal trees???	
Enter a choice:
3
Postorder walk is.....
  10[8423536]  19[8423568]  14[8423504]  31[8423632]  42[8423664]  35[8423600]  27[8423472]
  
1.Create tree	2.Preorder walk	3.Postorder walk	4.Inorder walk	
5.Height of tree	6.All parent nodes	7.All leaf nodes	
8.Parent with two children	9.Locate Element	10.Copy Tree	11.Equal trees???	
Enter a choice:
4
Inorder walk is.....
  10[8423536]  14[8423504]  19[8423568]  27[8423472]  31[8423632]  35[8423600]  42[8423664]
  
1.Create tree	2.Preorder walk	3.Postorder walk	4.Inorder walk	
5.Height of tree	6.All parent nodes	7.All leaf nodes	
8.Parent with two children	9.Locate Element	10.Copy Tree	11.Equal trees???	
Enter a choice:
5
Height of tree: 2

1.Create tree	2.Preorder walk	3.Postorder walk	4.Inorder walk	
5.Height of tree	6.All parent nodes	7.All leaf nodes	
8.Parent with two children	9.Locate Element	10.Copy Tree	11.Equal trees???	
Enter a choice:
6
Parent node:
  27  14  35
All parent nodes: 3

1.Create tree	2.Preorder walk	3.Postorder walk	4.Inorder walk	
5.Height of tree	6.All parent nodes	7.All leaf nodes	
8.Parent with two children	9.Locate Element	10.Copy Tree	11.Equal trees???	
Enter a choice:
7
Leaf nodes:
  10  19  31  42
Leaf nodes: 4

1.Create tree	2.Preorder walk	3.Postorder walk	4.Inorder walk	
5.Height of tree	6.All parent nodes	7.All leaf nodes	
8.Parent with two children	9.Locate Element	10.Copy Tree	11.Equal trees???	
Enter a choice:
8
Parents with two children:
  27  14  35
Parent with two children: 3

1.Create tree	2.Preorder walk	3.Postorder walk	4.Inorder walk	
5.Height of tree	6.All parent nodes	7.All leaf nodes	
8.Parent with two children	9.Locate Element	10.Copy Tree	11.Equal trees???	
Enter a choice:
9
Enter the element to be located:
19
Key 19 is found is given Tree

1.Create tree	2.Preorder walk	3.Postorder walk	4.Inorder walk	
5.Height of tree	6.All parent nodes	7.All leaf nodes	
8.Parent with two children	9.Locate Element	10.Copy Tree	11.Equal trees???	
Enter a choice:
10
Copied Elements:
   10[8423760]  14[8423728]  19[8423792]  27[8423696]  31[8423856]  35[8423824]  42[8423888]
  
1.Create tree	2.Preorder walk	3.Postorder walk	4.Inorder walk	
5.Height of tree	6.All parent nodes	7.All leaf nodes	
8.Parent with two children	9.Locate Element	10.Copy Tree	11.Equal trees???	
Enter a choice:
11
Give a second list to make tree to be compared:
27
14
35
10
19
31
42
-999
Tree is Valid
1
Equal trees

1.Create tree	2.Preorder walk	3.Postorder walk	4.Inorder walk	
5.Height of tree	6.All parent nodes	7.All leaf nodes	
8.Parent with two children	9.Locate Element	10.Copy Tree	11.Equal trees???	
Enter a choice:
0
EXIT

*/
