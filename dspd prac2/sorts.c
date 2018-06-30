/** FILE NAME:dspd2.c
    DATE:04/08/2017
    PURPOSE:To study and implement basic comparative sorting methods - Selection, Insertion, Bubble, Shell and Bucket.
    AUTHOR:SARTHAK BAISWAR
    PROBLEM STATEMENT:
    */

	/** HEADER FILE INCLUSION*/
	#include<stdio.h>
	#include<stdlib.h>

	/*Macro */
	#define maxsize 10000000
	#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

	void insertsort(int [], int);
	void display(int [], int);
	void bubblesort(int [], int);
	void selectionsort(int [], int);
	void shellsort(int [], int);
	void bucketsort(int [], int);
	int get_input(char*);
	void create_arr(int [], int, int);
	void copy_arr(int[], int[], int);


	    /*Main Driver function*/

	    void main()
	{
			int *a;
			int *copy;
			int mode, length, cont;
			int choice;

		do {
			printf("Enter the length of array:\n");
			scanf("%d", &length);

			a = (int*)malloc(sizeof(int)*length);
			copy=(int*)malloc(sizeof(int)*length);

			if (length <= maxsize)
			{
				printf("1.Ascending array\t2.Descending array\n3.Partially unordered array\t4.Array of random numbers\n");
				mode = get_input("mode");
			}
			else
				printf("Array bounds reached\n");

			create_arr(a, length, mode);
			copy_arr(a, copy, length);



			do {
				printf("0.EXIT\t1.Insertion sort\t2.Bubble sort\t3.Selection sort\t4.Shell sort\t5.Bucket sort\n");
				if (length <= maxsize)
				{
					printf("For sorting");
					choice = get_input("choice");
				}


				switch (choice)
				{
				case 0:printf("EXIT\n\n");
					break;

				case 1: printf("ELEMENTS OF ARRAY BEFORE SORTING\n\n");
					display(a, length);
					printf("Insertion sort:\n\n");
					insertsort(a, length);
					printf("ELEMENTS OF ARRAY AFTER SORTING THROUGH INSERTION SORT:\n\n");
					display(a, length);
					copy_arr(copy, a, length);
					break;

				case 2: printf("ELEMENTS OF ARRAY BEFORE SORTING\n\n");
					display(a, length);
					printf("Bubble sort:\n\n");
					bubblesort(a, length);
					printf("ELEMENTS OF ARRAY AFTER SORTING THROUGH BUBBLE SORT:\n\n");
					display(a, length);
					copy_arr(copy, a, length);
					break;

				case 3: printf("ELEMENTS OF ARRAY BEFORE SORTING\n\n");
					display(a, length);
					printf("Selection sort:\n\n");
					selectionsort(a, length);
					printf("ELEMENTS OF ARRAY AFTER SORTING THROUGH SELECTION SORT:\n\n");
					display(a, length);
					copy_arr(copy, a, length);
					break;

				case 4:printf("ELEMENTS OF ARRAY BEFORE SORTING\n\n");
					display(a, length);
					printf("Shell sort:\n\n");
					shellsort(a, length);
					printf("ELEMENTS OF ARRAY AFTER SORTING THROUGH SHELL SORT:\n\n\n");
					display(a, length);
					copy_arr(copy, a, length);
					break;

				case 5: printf("ELEMENTS OF ARRAY BEFORE SORTING\n\n");
					display(a, length);
					printf("Bucket sort:\n\n");
					bucketsort(a, length);
					printf("ELEMENTS OF ARRAY AFTER SORTING THROUGH BUCKET SORT:\n");
					display(a, length);
					copy_arr(copy, a, length);
					break;

				}
			} while (choice != 0);
			printf("Enter any number other than 0 to continue with new array");
			cont = get_input("continue response");
		} while (cont!=0);
	       return;
	}



	void insertsort(int a[], int length)
	   {
		int i,j,key;
		for(j=1;j<length;j++)
		{
				key = a[j];
		    i=j-1;

		    while(i>=0 && a[i]>key)
		    {
		        a[i+1]=a[i];
		            i=i-1;

		    }

		        a[i+1]=key;
		}

		return;
	    }

	void display(int a[], int length)
	{
		int i;

		for(i=0;i<length;i++)
		{
		printf("%d\t", a[i]);
		}
		printf("\n\n");
		return;
	}



	void bubblesort(int a[], int length)
	{
		int i,j,temp;
		for(i=1;i<length;i++)
		{
		    for(j=0;j<length-1;j++)
		    {
		        if(a[j]>a[j+1])
		            swap(a[j],a[j+1],temp);
		    }
		}

	}

	void selectionsort(int a[], int length)
	{
		int i,j,minpos,temp;
		for(i=0;i<length-1;i++)
		{    minpos=i;
		    for(j=i+1;j<length;j++)
		        if(a[minpos]>a[j])
		            minpos=j;

		if (minpos!=i)
		    swap(a[minpos],a[i],temp);
		}
	}

	void shellsort(int a[], int length)
	{
	        int gap,i,j,key;
	        for(gap=length/2;gap>0;gap/=2)
	        {   for(i=gap;i<length;i++)
	                {
	                    key=a[i];
	                    for(j=i;j>=gap && a[j-gap]>key;j-=gap)
	                        a[j]=a[j-gap];
	                        a[j]=key;
	                }

	        }
	}


	/* Function for bucket sort */

	void bucketsort(int a[], int length)

	{
			int flag, pos, k, j, m, i=0;
			int *bucket[10];
			for(i=0;i<10;i++)
				bucket[i]=(int*)malloc(sizeof(int)*maxsize);

			for (pos = 1;flag != length;pos*=10)
			{
				flag = 0;

				for (k = 0;k < length;k++)
				{
					bucket[(a[k] / pos) % 10][k] = a[k];
					if ((a[k] / pos) % 10 == 0)
						flag++;
				}

				if (flag == length)
					return;

				for (j = 0, m = 0;j < 10;j++)
				{
					for (k = 0;k < length;k++)
					{
						if (bucket[j][k] > 0)
						{
							a[m] = bucket[j][k];
							bucket[j][k] = 0;
							m++;
						}

					}
				}
			}

	}



	void create_arr(int a[], int length, int mode)
	{
		int offset, i;

		/*if (length <= maxsize)*/
		{
			switch (mode)
			{

			case 1:	offset = 9999;
				/*if (length != 0 && length < maxsize)*/
				{
					for (i = 0;i < length;i++)
						a[i] = offset + 15 * i;
				}
				break;

			case 2:	offset = 99999;
				/*if (length != 0 && length < maxsize)*/
				{
					for (i = 0;i < length;i++)
						a[i] = offset - 5 * i;
				}
				break;

			case 3:	offset = 9999;
				/*if (length != 0 && length < maxsize)*/
				{
					for (i = 0;i < length;i++)
					{
						if (!(i % 2))
							a[i] = offset + 40 * i;
						else
							a[i] = offset + 60 * i;
					}
				}
				break;

			case 4: offset = 99999;
				srandom(offset);
				/*if (length != 0 && length < maxsize)*/
				{
					for (i = 0;i < length;i++)
						a[i] = random()/13;
				}
				break;
			}
		}
		return;
	}


	void copy_arr(int a[], int copy[], int length)
	{
		int i;
		for (i = 0;i<length;i++)
			copy[i]=a[i];
		return;

	}



	 int get_input(char *str)
	{
    		int value;
		printf("\nenter %s\n", str);

    		scanf("%d",&value);

    		return(value);
	}
