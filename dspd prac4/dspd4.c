/** FILE NAME:dspd4.c
DATE:08/09/2017
PURPOSE: To study and implement different linear data structures using arrays - Stack ADT, Queue ADT, Circular Queue ADT.
AUTHOR:SARTHAK BAISWAR
PROBLEM STATEMENT: Using array based allocation to initialize stack, queue and circular queue and implement the permissible operations on them. Write a menu-driven program in C to test these data structures. The solution involving use of structure(s) to realize the mentioned data structures will be preferred(but not essential).
*/

/** HEADER FILE INCLUSION*/
#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include"cqueue.h"
#include"queue.h"

void main()
{	
	int choice1,cont;

	//STACK VARIABLES
	int stack[maxsize];
	int top = -1;
	int choice2,x;

	//QUEUE VARIABLES
	int q[maxsize];
	int front, rear;
	int choice3,keyq,e,fu,del;

	//CIRCULAR QUEUE VARIABLES
	int Cq[maxsize],f,r;
	int keycq,choice4,p,s;
			
	
		
do{
	printf("\n0.EXIT\t1.STACK\t2.QUEUE\t3.CIRCULAR QUEUE\n");
	printf("Enter choice\n");
	scanf("%d",&choice1);
	switch(choice1)
	{
	case 1: printf("--------------------------------STACK-----------------------------------");
		initialize(stack, top);						
		do
		{
		printf("\n\n0.exit\t\t1.PUSH\t2.POP\t3.DISPLAY\n");
			do
			{
				printf("\nEnter a choice between 0 to 3\n");
				scanf("%d", &choice2);
			}while(choice2<0 || choice2>3);

		switch (choice2)
		{
			case 0: printf(" EXIT \n");
				break;

			case 1: printf("Enter the elememt/s to be pushed in:\n");
				scanf("%d",&x);	
				top=push(stack, top, x);
				break;

			case 2:	top=pop(stack, top);
				break;

			case 3: printf("Elements of stack: \n");
				display(stack, top);
				break;


		}

		} while (choice2 != 0);
		break;

	case 2: printf("---------------------------------QUEUE--------------------------------");
		intializeq(q,&front,&rear);						
		do
		{
			printf("\n0.exit\t1.isEmptyQueue\t2.isFullQueue\t3.DisplayQueue\t4.Insert\t5.Delete\n");
			do
			{
				printf("\nEnter a choice between 0 to 5\n");
				scanf("%d", &choice3);
			}while(choice3<0 || choice3>5);

			switch (choice3)
			{
				case 0: printf(" EXIT \n");
					break;

				case 1: e = isEmptyQueue(q, front, rear);
					printf("%d",e);
					break;

				case 2:	fu = isFullQueue(q, front, rear);
					printf("%d",fu);
					break;

				case 3: displayQueue(q, front, rear);
					break;
	
				case 4:	printf("Enter the element to be inserted\n");
					scanf("%d",&keyq);
					insertQueue(q, &front, &rear, keyq);
					break;
	
				case 5: del = deleteQueue(q, &front, &rear);
					printf("Deleted element : %d", del);
					break;


			}

		} while (choice3 != 0);
		break;

	case 3: printf("-----------------------------------CIRCULAR QUEUE------------------------------------");
		intializeCQ(Cq,&f,&r);						
		do
		{
			printf("\n0.EXIT\t1.InsertCQ\t2.DeleteCQ\t3.isFullCQ\t4.isEmptyCQ\t5.Display\n");
			printf("enter choice:\n");
			scanf("%d",&choice4);
			switch(choice4)
			{
				case 0: printf("EXIT from circular queue\n");
					break;				
				case 1: if(!(isfullCQ(Cq,f,r)))
						{
							printf("Enter the number to be inserted:\n");
							scanf("%d",&keycq);
							insertCQ(Cq,&f,&r,keycq);
						}
					else
						printf("queue is full\n");
					break;
				case 2: if((f==-1)!=1)
						deleteCQ(Cq,&f,&r);
					else
						printf("queue is empty\n");
					break;
				case 3: p=isfullCQ(Cq,f,r);
					printf("%d",p);
					break;
				case 4: s=isemptyCQ(Cq,f,r);
					printf("%d",s);
					break;
				case 5: displayCQ(Cq,f,r);
					break;

			}
		}while(choice4!=0);
			break;
	}
	
	printf("Enter number other than 0 to continue\n");
	scanf("%d",&cont);
	
}while(cont != 0);


return;
}
