/*FILENAME: dspd3.c
  DATE: 11/08/2017
  PURPOSE: To study and implement divide and conquer approach sorting methods - Merge, Quick and Heap.
  AUTHOR: SARTHAK BAISWAR
  PROBLEM STATEMENT: Using the utility functions created in experiment 2, write a menu-driven program to order a list using following 
  "divide and conquer" approaches - Merge, Quick, Heap sorts. You should compare the running time for ordring lists different input
   sizes in respect of the traditional comparison sorts and divide and conquer sorts.
  */


	#include<stdio.h>
	#include<stdlib.h> 
	#include"dspd3.h"
	#include<time.h>
	
	void main()
	{   
			int *a,i;
			int *copy;
			int mode, length, cont;   
			int choice;
			double elapsedT;
			double s[8];
			char *listsort[]={"/0","Insertion sort","Bubble sort","Selection sort","Shell sort","Bucket sort","Merge sort","Quick sort","Heap sort"};
			
			time_t begin,end;
	    
		do {
			printf("Enter the length of array:\n");
			scanf("%d", &length);

			a=(int *)calloc(maxsize,sizeof(int));
			copy=(int *)calloc(maxsize,sizeof(int));
			
			do{
				printf("1.Ascending array\t2.Descending array\n3.Partially unordered array\t4.Array of random numbers\n");
				mode = get_input("mode");
			}while(mode<=0||mode>4);
		

			create_arr(a, length, mode);
			copy_arr(a, copy, length);


		do {
				
            choice =1;
			switch (choice)
			{
				case 1: begin = clock();
					insertsort(a, length);
					end = clock();
					elapsedT = ((double)end-begin)/CLOCKS_PER_SEC;
					s[1]= elapsedT;
					copy_arr(copy, a, length);
					choice++;
					

				case 2: begin = clock();
					bubblesort(a, length);
					end = clock();
					elapsedT = ((double)end-begin)/CLOCKS_PER_SEC;
					s[2]= elapsedT;
					copy_arr(copy, a, length);
					choice++;
					

				case 3: begin = clock();
					selectionsort(a, length);
					end = clock();
					elapsedT = ((double)end-begin)/CLOCKS_PER_SEC;
					s[3]= elapsedT;
				   	copy_arr(copy, a, length);
					choice++;
					

				case 4: begin = clock();
					shellsort(a, length);
					end = clock();
					elapsedT = ((double)end-begin)/CLOCKS_PER_SEC;
					s[4]= elapsedT;
					copy_arr(copy, a, length);
					choice++;
					

				case 5: begin = clock();
					bucketsort(a, length);
					end = clock();
					elapsedT = ((double)end-begin)/CLOCKS_PER_SEC;
					s[5]= elapsedT;
					copy_arr(copy, a, length);
					choice++;
					
					
				case 6: begin = clock();
					merge_sort(a, 0, length-1);
					end = clock();
					elapsedT = ((double)end-begin)/CLOCKS_PER_SEC;
					s[6]= elapsedT;
					copy_arr(copy, a, length);
					choice++;
					  
					
				case 7: begin = clock();
                    quicksort(a, 0, length-1);
					end = clock();
					elapsedT = ((double)end-begin)/CLOCKS_PER_SEC;
					s[7]= elapsedT;
					copy_arr(copy, a, length);
					choice++;
				
				case 8: begin = clock();
                	heapsort(a, length);
					end = clock();
					elapsedT = ((double)end-begin)/CLOCKS_PER_SEC;
					s[8]= elapsedT;
					copy_arr(copy, a, length);
					choice++;
					

				}
			} while (choice<9);

			
			for(i=1;i<=8;i++)
			{
				printf("%d.%s: %g\n",i,*(listsort+i),s[i]);
			}
			printf("\nEnter any number other than 0 to continue with new array");
			cont = get_input("continue response");
		} while (cont!=0);
	       return;
	}
	
/*
EXECUTION TRIAL:

Enter the length of array:
100000
1.Ascending array	2.Descending array
3.Partially unordered array	4.Array of random numbers

enter mode
1
1.Insertion sort: 0.000474
2.Bubble sort: 24.4007
3.Selection sort: 11.3294
4.Shell sort: 0.006047
5.Bucket sort: 0.03138
6.Merge sort: 0.011819
7.Quick sort: 12.9323
8.Heap sort: 0.028194

Enter any number other than 0 to continue with new array
enter continue response
1
Enter the length of array:
100000
1.Ascending array	2.Descending array
3.Partially unordered array	4.Array of random numbers

enter mode
2
1.Insertion sort: 14.033
2.Bubble sort: 33.0949
3.Selection sort: 11.6628
4.Shell sort: 0.008706
5.Bucket sort: 0.02627
6.Merge sort: 0.011731
7.Quick sort: 12.8755
8.Heap sort: 0.027048

Enter any number other than 0 to continue with new array
enter continue response
1
Enter the length of array:
100000
1.Ascending array	2.Descending array
3.Partially unordered array	4.Array of random numbers

enter mode
3
1.Insertion sort: 1.16432
2.Bubble sort: 25.0384
3.Selection sort: 11.3475
4.Shell sort: 0.008527
5.Bucket sort: 0.031366
6.Merge sort: 0.011853
7.Quick sort: 0.020472
8.Heap sort: 0.029561

Enter any number other than 0 to continue with new array
enter continue response
1
Enter the length of array:
100000
1.Ascending array	2.Descending array
3.Partially unordered array	4.Array of random numbers

enter mode
4
1.Insertion sort: 7.04593
2.Bubble sort: 45.0524
3.Selection sort: 11.333
4.Shell sort: 0.029931
5.Bucket sort: 0.05334
6.Merge sort: 0.013964
7.Quick sort: 0.01542
8.Heap sort: 0.034194

Enter any number other than 0 to continue with new array
enter continue response
0

*/