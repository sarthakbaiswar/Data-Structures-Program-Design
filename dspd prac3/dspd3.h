/*FILENAME: dspd3.h (Functions file)
  DATE: 11/08/2017
  AUTHOR: SARTHAK BAISWAR*/


	#define maxsize 1000000
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
	void merge_sort(int [],int, int);
	void merge(int [] ,int,int,int);
	void quicksort(int [], int, int);
	void heapify(int [], int , int);
	void buildheap(int [], int);
	void heapsort(int [], int);

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
					for (k = 0;k <length;k++)
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

		if (length <= maxsize)
		{
			switch (mode)
			{

			case 1:	offset = 9999;
				if (length != 0 && length < maxsize)
				{
					for (i = 0;i < length;i++)
						a[i] = offset + 15 * i;
				}
				break;

			case 2:	offset = 999999;
				if (length != 0 && length < maxsize)
				{
					for (i = 0;i < length;i++)
						a[i] = offset - 2 * i;
				}
				break;

			case 3:	offset = 9999;
				if (length != 0 && length < maxsize)
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

			case 4: offset = 9999;
				srandom(offset);
				if (length != 0 && length < maxsize)
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

	void merge_sort(int a[],int p,int r)
	{
		int m=1;

		int q;
		if(p<r)
		{
			q=(p+r)/2;

			merge_sort(a,p,q);
			merge_sort(a,q+1,r);
			merge(a,p,q,r);

		}

	return;
	}

	void merge(int a[],int p,int q,int r)
	{
		int n1,n2,i,j,k;
		n1=q-p+1;
		n2=r-q;
		int L[n1+1],R[n2+1];

		for(i=0; i<n1; i++)
			L[i]=a[p+i];

		for(j=0; j<n2; j++)
			R[j]=a[q+j+1];

	L[i]=999999;
	R[j]=999999;

	i=0;
	j=0;
	for(k=p; k<=r; k++)
	{
		if(L[i]<=R[j])
		a[k]=L[i++];
		else
		a[k]=R[j++];
	}

	return;
	}

	void quicksort(int a[], int left, int right)
	{
		 int pivot, i, j, temp;
		if(left < right)
		{
			pivot = left;
			i = left;
			j = right;
			 while(i < j)
			{

				 while(a[i] <= a[pivot] && i <= right)
				 i++;

				while(a[j] > a[pivot] && j >= left)
				j--;

				if(i < j)
				{
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}


		temp = a[j];
		a[j] = a[pivot];
		a[pivot] = temp;

		quicksort(a, left, j-1);
		quicksort(a, j+1, right);
		 }
	}

	//heap sort//
	int parent(int i)
	{
		return (i/2);
	}

	int left(int i)
	{
		return (2*i);
	}

	int right(int i)
	{
		return (2*i+1);
	}



	void heapify(int a[], int i, int n)
	{
		int l,r,large,temp;
		l= left(i);
		r= right(i);
		if ((l<=n-1) && (a[l]>a[i]))
			large=l;
		else
			large=i;
		if ((r<=n-1) && (a[r]>a[large]))
			large =r;
		if (large!=i)
		{
			temp=a[i];
			a[i]=a[large];
			a[large]=temp;
			heapify(a,large,n);
		}
	}


	void buildheap(int a[], int n)
	{
		int i;
		for (i=(n-1)/2;i>=0;i--)
			heapify(a,i,n);
	}

	void heapsort(int a[], int n)
	{
		int i,m,temp;
		buildheap(a,n);
		m=n;
		for (i=n-1;i>=1;i--)
		{
			temp=a[0];
			a[0]=a[i];
			a[i]=temp;
			m=m-1;
			heapify(a,0,m);
		}
	}
