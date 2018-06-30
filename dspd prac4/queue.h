/** User defined functions definitions */
//QUEUE


	#define maxsize 5
	#define minvalue -999

	void intializeq(int q[],int *front,int *rear)
	{
		*front=-1;
		*rear=-1;
		q[0]=minvalue;
	}


	int isEmptyQueue(int q[], int front, int rear)
	{
		if(front == -1)
			return 1;
		
			return 0;
	}

	int isFullQueue(int q[], int front, int rear)
	{
		if(rear==maxsize-1)
			return 1;
		
			return 0;
	}

	void insertQueue(int q[], int *front, int *rear, int key)	
	{
		if(*rear==maxsize-1)
		{
			printf("Queue is full, cannot insert");
			return;
		}
		
		*rear = *rear + 1;
		
		q[*rear] = key;
		
		if(*front == -1)
			*front = 0;
		return;
	} 

	int deleteQueue(int q[], int *front, int *rear)
	{
		int key;		
		if(*front == -1)
		{
			printf("\nCannot delete, queue is empty\n");
			return 0;
		}
		key = q[*front];

		q[*front]=-9999;
		
		if(*front==0 && *rear==0)
		{
			*front=-1;
			*rear=-1;
		}

		else if((*front)==(*rear))
			*front=*rear=-1;
		else
			(*front)=(*front)+1;
		return key;
	}

	void displayQueue(int q[], int front, int rear)
	{
		int i;
		char c1='F',c2='R',c='_';
		if(front == -1)
		{	printf("queue is empty");
			return;
		}
		for(i=0;i<maxsize-1;i++)
		{
			if(q[i]==-9999 )	//reseting condition
			printf("\t%c",c);
		}
	
		for(i=front;i<=rear;i++)
		{
		
			if(i==front)
				printf("\t[%c]",c1);
				printf("\t%d",q[i]);
			if(i==rear)
				printf("\t[%c]",c2);
		}
		printf("\n");
		return;
	}
