

/** FILE NAME:dspd1.c
DATE:21/07/2017
PURPOSE:To study an array ADT and to implement various functions, various operations on array ADT
AUTHOR:SARTHAK BAISWAR
PROBLEM STATEMENT:Create an array and implement the operations - traverse(), insert(), delete(), sort(), search(), merge(), copy(), create(), isFull(), isEmpty() and length().Write a C program to demonstrate an array ADT using user defined functions appropriately using menu-driven approach. Your program should be able to print the array elements appropriately at any or all instances (as required maybe).You must also ensuremthat no input is acquired within the body of functions nor display any prompts/results.
*/

/** Header file inclusions*/

#include<stdio.h>

/**Pre-processor declarations */

#define minvalue -999
#define maxsize 10
#define maxsize2 25

/** User-defined functions declarations */

void initialize(int[]);
int arrlength(int[]);
int isFull(int[], int);
int isEmpty(int[], int);
int copy(int[], int);
void display(int[], int);
int create(int[], int);
int getvalue(int[], int);
int insert(int[], int, int, int);
void swap(int[], int);
void sort(int[], int);
void search(int[], int);
void del(int[], int);
void merge(int[], int, int[], int, int[]);
void traverse(int a[], int len);

/** The Driver function */

void main()
{
	int e, f, choice, index = 0, val = 0;
	int a[maxsize], b[maxsize], c[maxsize2];
	int length = 0, lengthb = 0;

	initialize(a);
	initialize(b);
	initialize(c);

	length = arrlength(a);
	lengthb = arrlength(b);


	do
	{
		printf("\n\n0.exit\t\t1.length\t2.create\t3.display\n4.insert\t5.isFull\t6.isEmpty\t7.copy\n8.sort\t\t9.search\t10.delete\t11.merge\t12.traverse\n");
		printf("\nEnter a choice\n");
		scanf("%d", &choice);


		switch (choice)
		{
		case 0: printf(" EXIT \n");
			break;

		case 1: printf("\nLength of array = %d\n", length);
			break;

		case 2:	length = create(a, length);
			break;

		case 3: display(a, length);
			break;

		case 4: do
				{
				printf("\nEnter the index:\n");
				scanf("%d", &index);
				} while (index<0 || index>length);
				
			printf("\nEnter value:\n");
			val = getvalue(a, length);
			length = insert(a, length, index, val);
			break;

		case 5: f = isFull(a, length);
			printf("isfull =%d\n", f);
			break;

		case 6: e = isEmpty(a, length);
			printf("isEmpty =%d\n", e);
			break;

		case 7: copy(a, length);
			break;

		case 8: sort(a, length);
			break;

		case 9: search(a, length);
			break;

		case 10: del(a, length);
			break;

		case 11: printf("Enter the elements of array b to be passed:\n");
			lengthb = create(b, lengthb);
			merge(a, length, b, lengthb, c);
			break;

		case 12: traverse(a, length);
			break;
		}

	} while (choice != 0);

	return;
}

/** User defined functions definitions */


void initialize(int a[])
{
	a[0] = minvalue;
}


int arrlength(int a[])
{
	int length = 0;
	while (a[length] > minvalue || length > maxsize)
		length++;
	return length;
}


void display(int a[], int length)
{
	int i = 0;

	if (length != 0)
	{
		printf("\nElements of array:\n");
	}

	for (i = 0; i <length; i++)
	{
		if(a[i]!=minvalue)
		printf("%d \n", a[i]);
	}
	return;
}

int isFull(int a[], int length)
{
	if (length == maxsize)
		return 1;
	else
		return 0;
}

int isEmpty(int a[], int length)
{
	if (length == 0)
		return 1;
	else
		return 0;
}

int create(int a[], int length)
{
	int i = 0, value = 0;

	do {
		if (length == maxsize)
		{
			printf("\nmaxsize is reached\n");
			break;
		}

		else
		{
			printf("Enter the array elements:\n");
			

			while (value != minvalue)
			{
				value = getvalue(a, length);

				if (value == minvalue)
					return length;
				else
					length = insert(a, length, length, value);

			}
		}
	} while (length == maxsize && value != minvalue);
}

int insert(int a[], int length, int index, int val)
{
	int i;
	if (length == maxsize)
	{
		printf("\tarray bound reached...\n");
		return length;
	}
	if (val == minvalue)
		return length;

	for (i = length;i >= index;i--)
		a[i + 1] = a[i];
	a[index] = val;
	return length + 1;
}

int getvalue(int a[], int length)
{
	int value;
	if (length == maxsize)
		printf("\nmax size reached\n");
	else
		scanf("%d", &value);
	return value;
}

int copy(int a[], int length)
{
	int i;
	int b[maxsize];

	for (i = 0;i<length;i++)
		b[i] = a[i];

	printf("\nElements of copy array\n");
	for (i = 0;i<length;i++)
		printf("%d ", b[i]);
	return 0;
}

void sort(int a[], int length)
{
	int i;
	if (length == 0)
		printf("\nElements unavailable for sorting\n");

	else
		swap(a, length);

	printf("\nSorted elements:\n");
	for (i = 0;i < length;i++)
		printf("%d ", a[i]);

	return;
}

void search(int a[], int length)
{
	int i, search = 0;
	if (length != 0)
	{
		printf("Enter search:\t");
		scanf("%d", &search);

		for (i = 0;i<length;i++)
		{
			if (a[i] == search)
			{
				printf("\nSearch element is present at %d position\n", i + 1);
				return;
			}
		}
		if (i == length)
			printf("\nSearch element is not present\n");
	}
	return;
}

void swap(int a[], int length)
{
	int i, j, temp = 0;
	for (i = 0;i<length;i++)
	{
		for (j = i + 1;j<length;j++)
		{

			if (a[i]>a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	return;
}

void del(int a[], int length)
{
	int i, k;
	printf("Enter the position of the element to be deleted:\n");
	scanf("%d", &k);

	while (k <= length)
	{
		a[k - 1] = a[k];
		k++;
	}

	length = length - 1;
}

void merge(int a[], int length, int b[], int lengthb, int c[])
{
	int i, j, k = 0;
	lengthb = arrlength(b);
	printf("\nMerged array:\n");

	for (i = 0;i<length;i++)
	{
		c[k] = a[i];
		k++;
	}k--;

	for (j = 0;j<lengthb;j++)
	{
		c[k] = b[j];
		k++;
	}k--;
	for (k = 1; k <(length + lengthb); k++)
		printf("c[%d]=%d\n", k-1, c[k-1]);

	return;
}

void traverse(int a[], int length)
{
	int i;
	int *pa = a;

	for (i = 0; i<length-1; i++)
		printf("a[%d]= %d,\t *(pa+%d) = %d\n", i, a[i], i, *(pa + i));
	return;
}

/*
EXECUTION TRIAL:

0.exit		1.length	2.create	3.display
4.insert	5.isFull	6.isEmpty	7.copy
8.sort		9.search	10.delete	11.merge	12.traverse

Enter a choice
2
Enter the array elements:
22
33
44
-999


0.exit		1.length	2.create	3.display
4.insert	5.isFull	6.isEmpty	7.copy
8.sort		9.search	10.delete	11.merge	12.traverse

Enter a choice
3

Elements of array:
22 
33 
44 


0.exit		1.length	2.create	3.display
4.insert	5.isFull	6.isEmpty	7.copy
8.sort		9.search	10.delete	11.merge	12.traverse

Enter a choice
1

Length of array = 3


0.exit		1.length	2.create	3.display
4.insert	5.isFull	6.isEmpty	7.copy
8.sort		9.search	10.delete	11.merge	12.traverse

Enter a choice
4

Enter the index:
3

Enter value:
11


0.exit		1.length	2.create	3.display
4.insert	5.isFull	6.isEmpty	7.copy
8.sort		9.search	10.delete	11.merge	12.traverse

Enter a choice
5
isfull =0


0.exit		1.length	2.create	3.display
4.insert	5.isFull	6.isEmpty	7.copy
8.sort		9.search	10.delete	11.merge	12.traverse

Enter a choice
6
isEmpty =0


0.exit		1.length	2.create	3.display
4.insert	5.isFull	6.isEmpty	7.copy
8.sort		9.search	10.delete	11.merge	12.traverse

Enter a choice
7

Elements of copy array
22 33 44 11 

0.exit		1.length	2.create	3.display
4.insert	5.isFull	6.isEmpty	7.copy
8.sort		9.search	10.delete	11.merge	12.traverse

Enter a choice
8

Sorted elements:
11 22 33 44 

0.exit		1.length	2.create	3.display
4.insert	5.isFull	6.isEmpty	7.copy
8.sort		9.search	10.delete	11.merge	12.traverse

Enter a choice
9
Enter search:	33

Search element is present at 3 position


0.exit		1.length	2.create	3.display
4.insert	5.isFull	6.isEmpty	7.copy
8.sort		9.search	10.delete	11.merge	12.traverse

Enter a choice
10
Enter the position of the element to be deleted:
2


0.exit		1.length	2.create	3.display
4.insert	5.isFull	6.isEmpty	7.copy
8.sort		9.search	10.delete	11.merge	12.traverse

Enter a choice
3

Elements of array:
11 
33 
44 


0.exit		1.length	2.create	3.display
4.insert	5.isFull	6.isEmpty	7.copy
8.sort		9.search	10.delete	11.merge	12.traverse

Enter a choice
11
Enter the elements of array b to be passed:
Enter the array elements:
555
666
-999

Merged array:
c[0]=11
c[1]=33
c[2]=44
c[3]=555
c[4]=666


0.exit		1.length	2.create	3.display
4.insert	5.isFull	6.isEmpty	7.copy
8.sort		9.search	10.delete	11.merge	12.traverse

Enter a choice
12
a[0]= 11,	 *(pa+0) = 11
a[1]= 33,	 *(pa+1) = 33
a[2]= 44,	 *(pa+2) = 44


0.exit		1.length	2.create	3.display
4.insert	5.isFull	6.isEmpty	7.copy
8.sort		9.search	10.delete	11.merge	12.traverse

Enter a choice
0
 EXIT

*/









			
			

