/* 
FILE NAME:bsttree.c
DATE: 29/09/2017
PURPOSE: To study and implement binary search tree(BST)-USING LINKED LIST.
AUTHOR:SARTHAK BAISWAR
PROBLEM STATEMENT: Create a header file, "treeADt.h" to include the self-refrential structure, tree node created in experiment no. 08 and routines to - (1)Traverse the tree,(2)find the height of tree,(3)to count and list all leaf nodes and parent nodes using "treeADT.h" implement the BST to- (1)insert a node, (2)delete a node with specified by value, (3)traverse the tree in level oder and (4)create binary search tree using insertNode(). 
*/

#include<stdio.h>
#include<stdlib.h>
#include"bsttree.h"

int main()
{
    int choice,ch01,key,h,p,l,a;    
    tree root;

    do
    {
        printf("\t\tBst menu");
        printf("\n1.Create\t2.Insert\t3.Delete\t4.Display\t5.HeigthBST\t6.All parent nodes\t7.Leaf nodes\t8.All nodes BST\n");
        printf("Enter a choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {   
            case 1: printf("Enter the elements of tree\n");
                    root=createBST();
                    break;
                    
            case 2: printf("Enter the element to be inserted:\n");
                    scanf("%d",&key);
                    root = insertBST(root, key);
                    printf("After insertion:\n");
                    inOrderT(root);
                    break;
                    
            case 3: printf("Enter the element to be deleted:\n");
                    scanf("%d",&key);
                    root = deleteBST(root, key);
                    printf("After deletion:\n");
                    inOrderT(root);
                    break;
            
            case 4:printf("Elements of the tree\n");
                   printf("\n1.Preorder\t2.Inorder\t3.Postorder\t4.Level Order\n");
                   printf("Enter a choice:\n");
                   scanf("%d",&ch01);
                   switch(ch01)
                   {
                        case 1: if(root!=NULL)
                                {
                                    printf("Preorder walk:\n");
                                    preOrderT(root);
                                }
                                else
                                    printf("Empty tree\n");
                                
                                break;
                                
                        case 2: if(root!=NULL)
                                {
                                    printf("Inorder walk:\n");
                                    inOrderT(root);
                                }
                                else
                                    printf("Empty tree\n");
                                
                                break;
                                
                        case 3: if(root!=NULL)
                                {
                                    printf("Postorder walk:\n");
                                    postOrderT(root);
                                }
                                else
                                    printf("Empty tree\n");
                                
                                break;
                                
                         case 4: if(root!=NULL)
                                {   
                                    printf("Level order walk:\n");
                                    h=heightBST(root);
                                    for(int i=1;i<=h+1;i++)
                                    {
                                        levelOrderT(root, i);
                                        printf("\n");
                                    }
                                }
                                else
                                    printf("Empty tree\n");
                                
                                break;
                    }
                    break;
             
             case 5:
                      h=heightBST(root);
                      printf("Height of the tree: %d\n",h);
                      break;
             
             case 6: printf("\nParent nodes:\n"); 
                     p=allParentBST(root);
                     printf("\nNo. of parent nodes: %d\n",p);
                     break;
                     
             case 7: printf("Leaf nodes:\n");
                     l= LeafsBST(root);
                     printf("\nNo. of leaf nodes: %d\n",l);
                     break;
                     
             case 8: printf("\nAll nodes");
                     a=allNodesBST(root);
                     printf("\nNo. of nodes: %d\n",a);
                     break;
                     
                     
          }
      }while(choice!=0);
   return 0;
}

/*
Execution trial:

                                                    Bst menu
1.Create	2.Insert	3.Delete	4.Display	5.HeigthBST	6.All parent nodes	7.Leaf nodes	8.All nodes BST
Enter a choice:
1
Enter the elements of tree
27
14
35
10
19
31
42
-999
		                                            Bst menu
1.Create	2.Insert	3.Delete	4.Display	5.HeigthBST	6.All parent nodes	7.Leaf nodes	8.All nodes BST
Enter a choice:
4
Elements of the tree

1.Preorder	2.Inorder	3.Postorder	4.Level Order
Enter a choice:
1
Preorder walk:
  27  14  10  19  35  31  42		
                                                    Bst menu
1.Create	2.Insert	3.Delete	4.Display	5.HeigthBST	6.All parent nodes	7.Leaf nodes	8.All nodes BST
Enter a choice:
4
Elements of the tree

1.Preorder	2.Inorder	3.Postorder	4.Level Order
Enter a choice:
2
Inorder walk:
  10  14  19  27  31  35  42		
                                                    Bst menu
1.Create	2.Insert	3.Delete	4.Display	5.HeigthBST	6.All parent nodes	7.Leaf nodes	8.All nodes BST
Enter a choice:
4
Elements of the tree

1.Preorder	2.Inorder	3.Postorder	4.Level Order
Enter a choice:
3
Postorder walk:
  10  19  14  31  42  35  27		
                                                    Bst menu
1.Create	2.Insert	3.Delete	4.Display	5.HeigthBST	6.All parent nodes	7.Leaf nodes	8.All nodes BST
Enter a choice:
4
Elements of the tree

1.Preorder	2.Inorder	3.Postorder	4.Level Order
Enter a choice:
4
Level order walk:
   27
   14   35
   10   19   31   42
		                                            Bst menu
1.Create	2.Insert	3.Delete	4.Display	5.HeigthBST	6.All parent nodes	7.Leaf nodes	8.All nodes BST
Enter a choice:
5
Height of the tree: 2
		                                            Bst menu
1.Create	2.Insert	3.Delete	4.Display	5.HeigthBST	6.All parent nodes	7.Leaf nodes	8.All nodes BST
Enter a choice:
6

Parent nodes:
  27  14  35
No. of parent nodes: 3
		                                            Bst menu
1.Create	2.Insert	3.Delete	4.Display	5.HeigthBST	6.All parent nodes	7.Leaf nodes	8.All nodes BST
Enter a choice:
7
Leaf nodes:
  10  19  31  42
No. of leaf nodes: 4
		                                            Bst menu
1.Create	2.Insert	3.Delete	4.Display	5.HeigthBST	6.All parent nodes	7.Leaf nodes	8.All nodes BST
Enter a choice:
8

All nodes  27  14  10  19  35  31  42
No. of nodes: 7
		                                            Bst menu
1.Create	2.Insert	3.Delete	4.Display	5.HeigthBST	6.All parent nodes	7.Leaf nodes	8.All nodes BST
Enter a choice:
2
Enter the element to be inserted:
5
After insertion:
   5  10  14  19  27  31  35  42		
                                                    Bst menu
1.Create	2.Insert	3.Delete	4.Display	5.HeigthBST	6.All parent nodes	7.Leaf nodes	8.All nodes BST
Enter a choice:
3
Enter the element to be deleted:
31
After deletion:
   5  10  14  19  27  35  42		
                                                    Bst menu
1.Create	2.Insert	3.Delete	4.Display	5.HeigthBST	6.All parent nodes	7.Leaf nodes	8.All nodes BST
Enter a choice:
0
EXIT

*/
