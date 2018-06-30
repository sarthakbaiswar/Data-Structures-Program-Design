/* 
FILE NAME:dspd6.c
DATE:15/09/2017
PURPOSE: To study single linked linear lists and implement various operations in it, sinert, reverse, order, locate, merge,linked stack, linked queue.
AUTHOR:SARTHAK BAISWAR
PROBLEM STATEMENT: Create a self referential structure, NodeLL to represent a node of a single linked linear list. Implement the routines to - (1) find length of list (2) create a list (3)insert an element- at the beginning, at the end, at the specified position,(4)delete an element from the front, rear, specified position(5)reverse the list(6)search the list.Create a menu driven program to test these routines. 
*/

#include <stdio.h>
#include<stdlib.h>
#include"linkedlist1.h"
#define MAX 5

int main()
{
	list first = NULL, neww, second = NULL, copy = NULL;
	int choice;
	int ch1,ch02,ch03,ch04,ch05;
	int ch2,ch3,cont;
	int key;
	int keyin,keydel,keym,keyPos;
	int n,k;
	int value,mode,pos;
	int len;
	do
	{
	
	    printf("\n-----------------------MENU----------------------\n");
	    printf("\n1.Simple linked list\t2.Linked stack\t3.Linked queue\n");
	
	    printf("Enter a choice: \n");
	    scanf("%d",&choice);
	
	    switch(choice)
	    {   //begin simple linked list.
		    
		    case 1: first = NULL;
		    do
		    {
		        printf("\nSIMPLE LINKED LIST\n");
			    printf("\n0.Exit\t1.createList\t2.insert\t3.delete\t4.reverse\t5.sort\t6.locate\t7.merge\t8.display\t9.copyLL\t10.lengthLL\n");
			    printf("Enter a choice: \n");
			    scanf("%d",&ch1);
			
			    switch(ch1)
			    {	
			    
			        case 1:printf("Enter the elements of the list:\n");
			            if(first==NULL)
			            {
			                first=createLL(first);
			            }
			            break;
			        
				    case 2: printf("\n1.insertAtBeg\t2.insertAtEnd\t3.insertAtPos\t4.insertInOrder\n");
					    printf("Enter a choice: \n");
					    scanf("%d",&ch02);
					
					    switch(ch02)
					    {
						    case 1:printf("Enter a number to be inserted\n");
							    scanf("%d",&keyin);
							    first=insertAtBeg(first, keyin);
							    printf("After inserting at beginning:\n");
							    displayLL(first);
							    break;

						    case 2:printf("Enter a number to be inserted\n");
							    scanf("%d",&keyin);
							    first=insertAtEnd(first, keyin);
							    printf("After inserting at end:\n");
							    displayLL(first);
							    break;
						
						    case 3:printf("Enter a number to be inserted\n");
							    scanf("%d",&keyPos);
							    printf("Enter the position\n");
							    scanf("%d",&pos);
							    first=insertAtPos(first, pos, keyPos);
							    printf("After inserting at given position:\n");
							    displayLL(first);
							    break;
							    
						    case 4:printf("Enter the number to be inserted\n");
						        scanf("%d",&keyin);
							    insertInOrder(first,keyin);
							    printf("After inserting:\n");
							    displayLL(first);
							    break;
						        
					    }
					    break;
			 
				
				    case 3:printf("\n1.deleteAtBeg\t2.deleteAtEnd\t3.deleteAtPos\n");
					    printf("Enter a choice: \n");
					    scanf("%d",&ch03); 

					    switch(ch03)
					    {
						    case 1:
							    first=deleteAtBeg(first, &keydel);
							    printf("Element deleted: %d\n",keydel);
							    printf("After deleting at beginning:\n");
							    displayLL(first);
							    break;

						    case 2:
							    first=deleteAtEnd(first, &keydel);
							    printf("Element deleted: %d\n",keydel);
							    printf("After deleting at end:\n");
							    displayLL(first);
							    break;
							    
							case 3:
							    printf("Enter the position\n");
							    scanf("%d",&pos);
							    first=deleteAtPos(first,pos,&keydel);
							    printf("Element deleted: %d\n",keydel);
							    printf("After deleting at position:\n");
							    displayLL(first);
							    break;
							    
					    }
					    break;

				    case 4:
				        first=reverseLL(first);
					    printf("Reversed list:\n");
					    displayLL(first);
					    break;

				    case 5: printf("\n1.Ascending\t2.Descending\n");
					    printf("Enter a mode: \n");
					    scanf("%d",&mode);
					    first=sortLL(first,mode);
					    displayLL(first);
					    break;


				    case 6:printf("Enter value to be searched:\n");
					    scanf("%d",&value);
					    locateLL(first, value);
					    break;
					    
		            case 7:second=NULL;
				        printf("Create second LL \n");
				        printf("1.Unordered Merge\t2.Ordered Merge\n");
				        printf("Enter the choice:");
				        scanf("%d",&ch04);
				        printf("Enter the size of Second LL:");
				        scanf("%d",&k);
				        switch(ch04)
				        {
				            case 1: 
				                   printf("\n1.InsertAtBeg\t2.InsertAtEnd\t");
				                   printf("3.InsertAtLocation\n");
						           scanf("%d",&ch05);
				                   while(k!=0)
				                   {
				                        printf("enter the key to insert:");
									    scanf("%d",&keym);
									    switch(ch05)
									    {
									    
									    case 1: second=insertAtBeg(second,keym);
									            break;
									    case 2: second=insertAtEnd(second,keym);
									            break;
									    case 3: printf("enter the position:");
									            scanf("%d",&pos);
									            second=insertAtPos(second,pos,keym);
									            break;
									            
									    }
									    k--;
									}
									first=mergeLL(first,second);
									printf("merged list:");
									displayLL(first);
									break;
									
							case 2: first=sortLL(first,1);
				                    while(k!=0)
				                    {
				                        printf("enter the key to insert:");
									    scanf("%d",&keym);
									    first=insertInOrder(first,keym);
									    k--;
									}
		
									first=mergeOrderLL(first,second);
									printf("merged list:");
									displayLL(first);
									break;
						}
						break;
					case 8: printf("Elements of the list:\n");
					        displayLL(first);
					        break;
					        
					case 9: copy=copyLL(first);
					        printf("Elements of the copied list:\n");
					        displayLL(copy);
					        break;
					    
					case 10: len=lengthLL(first);
					         printf("The length of Linked List is %d\n",len);
					         break;
					        
					}
				}while(ch1!=0);
					
					break;
				
				//end of linked list menu.
				
				case 2: //begin of linked stack.
				        printf("\n--------------Linked Stack--------------\n");
				        first=NULL;
			        do{  
			            printf("\n0.Exit\t1.Push\t2.Pop\t3.IsEmpty\t4.AtTop\t5.Display\n");
			            printf("enter the choice:");
			            scanf("%d",&ch2);
			            switch(ch2)
			            {
			                case 1: 		              
			                        printf("Enter the key to be pushed:");
			                        scanf("%d",&key);
			                        first=insertAtBeg(first,key);
			                        printf("Stack elements:");
			                        displayLL(first);
			                        break;
			                    
			                case 2: if(first==NULL)
			                        {
			                            printf("Stack underflow\n"); 
			                            break;
			                        }
			                        first=deleteAtBeg(first,&key);
			                        printf("Element popped is %d\n",key);
			                        printf("Stack elements:");
			                        displayLL(first);
			                        break;
			                        
			                case 3: if(first==NULL)
			                            printf("Stack is empty\n");
			                        else
			                            printf("Stack is Not empty\n");;
			                        break;
			             
			                case 4: if(first==NULL)
			                        {
			                            printf("Stack is Empty ,NO element At top\n");
                                        break;
			                         }
			                         printf("Element at top is %d\n",first->data);
			                        break;
			                        
			                case 5: if(first==NULL)
			                        {
			                            printf("stack is empty\n");
			                            break;
			                        }
			                        printf("Stack elememts: ");
			                        displayLL(first);
			                        break; 
			            }     
			      }while(ch2!=0);
			      break;
			      
			      //end of linked stack.
			      
			      case 3: //begin linked queue.
			              printf("-----------Linked Queue-------------\n");
			              first=NULL;
			        do{
			             printf("\n0.Exit\t1.Insert\t2.Delete\t3.IsEmpty\t4.Display\t5.AtFront\t6.AtRear\n");
			             printf("Enter the choice:\n");
			             scanf("%d",&ch3);
			             switch(ch3)
			             {
		                        case 1: printf("Enter the Key To be inserted:\n");
		                                scanf("%d",&key);
		                                first=insertAtEnd(first,key); 
		                                printf("After insertion:\n");
		                                displayLL(first);
		                                break;
			                          
			                    case 2: if(first==NULL)
			                            {
			                                printf("Queue is Empty\n");
			                                break;
			                             }
			                            first=deleteAtBeg(first,&key);
			                            printf("Deleted element is:%d\n",key);
			                            printf("After deletion:\n");
			                            displayLL(first); 
			                            break;
			                           
			                    case 3: if(first==NULL)
			                                printf("Queue is Empty\n");
			                             else
			                                printf("Queue is not Empty\n");
			                              break;
			                              
                                case 4: if(first==NULL)
                                        {
			                                printf("Queue is Empty\n");
			                                break;
			                            }
			                            printf("Queue elements are:\t");
			                            displayllQueue(first);
			                            break;
			                            
			                    case 5: if(first==NULL)
                                        {
                                            printf("Queue is Empty\n");
                                        }
                                        else
                                        {
			                                first=valueAtFront(first);
			                                printf("Element at Front is %d\n",first->data);
			                            }
			                            break;
			                            
			                    case 6: if(first==NULL)
                                        {
                                            printf("Queue is Empty\n");
                                        }
                                        else
                                        {
			                                neww=valueAtRear(first);
			                                printf("Element at Rear is %d\n",neww->data);
			                            }
			                            break;
			                
			                }
	                }while(ch3!=0);
	                 break;
	                 
	                 //end of linked queue.
			        
	    }
        printf("\nDo you want to continue:");
	    scanf("%d",&cont);
			
	}while(cont!=0);
    
    return 0;
}

/*
EXECUTION TRIAL:


-----------------------MENU----------------------

1.Simple linked list	2.Linked stack	3.Linked queue
Enter a choice: 
1

SIMPLE LINKED LIST

0.Exit	1.createList	2.insert	3.delete	4.reverse	5.sort	6.locate	7.merge	8.display	9.copyLL	10.lengthLL
Enter a choice: 
1
Enter the elements of the list:
11
22
-999

SIMPLE LINKED LIST

0.Exit	1.createList	2.insert	3.delete	4.reverse	5.sort	6.locate	7.merge	8.display	9.copyLL	10.lengthLL
Enter a choice: 
2

1.insertAtBeg	2.insertAtEnd	3.insertAtPos	
Enter a choice: 
1
Enter a number to be inserted
10
After inserting at beginning:
10[37894256]	22[37894224]	11[37894192]	

SIMPLE LINKED LIST

0.Exit	1.createList	2.insert	3.delete	4.reverse	5.sort	6.locate	7.merge	8.display	9.copyLL	10.lengthLL
Enter a choice: 
2

1.insertAtBeg	2.insertAtEnd	3.insertAtPos	
Enter a choice: 
2
Enter a number to be inserted
55
After inserting at end:
10[37894256]	22[37894224]	11[37894192]	55[37894288]	

SIMPLE LINKED LIST

0.Exit	1.createList	2.insert	3.delete	4.reverse	5.sort	6.locate	7.merge	8.display	9.copyLL	10.lengthLL
Enter a choice: 
3

1.deleteAtBeg	2.deleteAtEnd	3.deleteAtPos
Enter a choice: 
3
Enter the position
3
Element deleted: 11
After deleting at position:
10[37894256]	22[37894224]	55[37894288]	

SIMPLE LINKED LIST

0.Exit	1.createList	2.insert	3.delete	4.reverse	5.sort	6.locate	7.merge	8.display	9.copyLL	10.lengthLL
Enter a choice: 
4
Reversed list:
55[37894288]	22[37894224]	10[37894256]	

SIMPLE LINKED LIST

0.Exit	1.createList	2.insert	3.delete	4.reverse	5.sort	6.locate	7.merge	8.display	9.copyLL	10.lengthLL
Enter a choice: 
5

1.Ascending	2.Descending
Enter a mode: 
1
10[37894288]	22[37894224]	55[37894256]	

SIMPLE LINKED LIST

0.Exit	1.createList	2.insert	3.delete	4.reverse	5.sort	6.locate	7.merge	8.display	9.copyLL	10.lengthLL
Enter a choice: 
6
Enter value to be searched:
22
value is found at 	2

SIMPLE LINKED LIST

0.Exit	1.createList	2.insert	3.delete	4.reverse	5.sort	6.locate	7.merge	8.display	9.copyLL	10.lengthLL
Enter a choice: 
7
Create second LL 
1.Unordered Merge	2.Ordered Merge
Enter the choice:2
Enter the size of Second LL:2
enter the key to insert:444
enter the key to insert:555
merged list:10[37894288]	22[37894224]	55[37894256]	444[37894320]	555[37894352]	

SIMPLE LINKED LIST

0.Exit	1.createList	2.insert	3.delete	4.reverse	5.sort	6.locate	7.merge	8.display	9.copyLL	10.lengthLL
Enter a choice: 
9
Elements of the copied list:
10[37894384]	22[37894416]	55[37894448]	444[37894480]	555[37894512]	

SIMPLE LINKED LIST

0.Exit	1.createList	2.insert	3.delete	4.reverse	5.sort	6.locate	7.merge	8.display	9.copyLL	10.lengthLL
Enter a choice: 
10
The length of Linked List is 5

SIMPLE LINKED LIST

0.Exit	1.createList	2.insert	3.delete	4.reverse	5.sort	6.locate	7.merge	8.display	9.copyLL	10.lengthLL
Enter a choice: 
8
Elements of the list:
10[37894288]	22[37894224]	55[37894256]	444[37894320]	555[37894352]	

SIMPLE LINKED LIST

0.Exit	1.createList	2.insert	3.delete	4.reverse	5.sort	6.locate	7.merge	8.display	9.copyLL	10.lengthLL
Enter a choice: 
0

Do you want to continue:1

-----------------------MENU----------------------

1.Simple linked list	2.Linked stack	3.Linked queue
Enter a choice: 
2

------------------Linked Stack---------------------

0.Exit	1.Push	2.Pop	3.IsEmpty	4.AtTop	5.Display
enter the choice:1
Enter the key to be pushed:22
Stack elements:22[37894544]	

0.Exit	1.Push	2.Pop	3.IsEmpty	4.AtTop	5.Display
enter the choice:1
Enter the key to be pushed:99
Stack elements:99[37894576]	22[37894544]	

0.Exit	1.Push	2.Pop	3.IsEmpty	4.AtTop	5.Display
enter the choice:2
Element popped is 99
Stack elements:22[37894544]	

0.Exit	1.Push	2.Pop	3.IsEmpty	4.AtTop	5.Display
enter the choice:3
Stack is Not empty

0.Exit	1.Push	2.Pop	3.IsEmpty	4.AtTop	5.Display
enter the choice:1
Enter the key to be pushed:77
Stack elements:77[37894576]	22[37894544]	

0.Exit	1.Push	2.Pop	3.IsEmpty	4.AtTop	5.Display
enter the choice:1
Enter the key to be pushed:555
Stack elements:555[37894608]	77[37894576]	22[37894544]	

0.Exit	1.Push	2.Pop	3.IsEmpty	4.AtTop	5.Display
enter the choice:4
Element at top is 555

0.Exit	1.Push	2.Pop	3.IsEmpty	4.AtTop	5.Display
enter the choice:5
Stack elememts: 555[37894608]	77[37894576]	22[37894544]	

0.Exit	1.Push	2.Pop	3.IsEmpty	4.AtTop	5.Display
enter the choice:0

Do you want to continue:1

-----------------------MENU----------------------

1.Simple linked list	2.Linked stack	3.Linked queue
Enter a choice: 
3
--------------------Linked Queue------------------

0.Exit	1.Insert	2.Delete	3.IsEmpty	4.Display	5.AtFront	6.AtRear
Enter the choice:
1
Enter the Key To be inserted:
55
After insertion:
55[37894640]	

0.Exit	1.Insert	2.Delete	3.IsEmpty	4.Display	5.AtFront	6.AtRear
Enter the choice:
1
Enter the Key To be inserted:
22
After insertion:
55[37894640]	22[37894672]	

0.Exit	1.Insert	2.Delete	3.IsEmpty	4.Display	5.AtFront	6.AtRear
Enter the choice:
1
Enter the Key To be inserted:
11
After insertion:
55[37894640]	22[37894672]	11[37894704]	

0.Exit	1.Insert	2.Delete	3.IsEmpty	4.Display	5.AtFront	6.AtRear
Enter the choice:
3
Queue is not Empty

0.Exit	1.Insert	2.Delete	3.IsEmpty	4.Display	5.AtFront	6.AtRear
Enter the choice:
2
Deleted element is:55
After deletion:
22[37894672]	11[37894704]	

0.Exit	1.Insert	2.Delete	3.IsEmpty	4.Display	5.AtFront	6.AtRear
Enter the choice:
4
Queue elements are:		[F]	22	11	[R]

0.Exit	1.Insert	2.Delete	3.IsEmpty	4.Display	5.AtFront	6.AtRear
Enter the choice:
5
Element at Front is 22

0.Exit	1.Insert	2.Delete	3.IsEmpty	4.Display	5.AtFront	6.AtRear
Enter the choice:
6
Element at Rear is 11

0.Exit	1.Insert	2.Delete	3.IsEmpty	4.Display	5.AtFront	6.AtRear
Enter the choice:
0

Do you want to continue:0
*/

