/** User defined functions definitions */
//STACK


	#define maxsize 50
	#define minvalue -999

	void initialize(int stack[],int top)
	{
		stack[0]=minvalue;
	}


	int isEmpty(int stack[],int top)
	{
		if(top==-1)
		{
		printf("EMPTY STACK");
		return 1;
		}
		else
		return 0;
	}
	
	int push(int stack[], int top, int x)
	{
		if(top==maxsize-1)
		{		
			printf("Stack is full; cannot add elements");
			return maxsize-1;
		}
		
		
			top+=1;
			stack[top]=x;
			return top;
	}

	int pop(int stack[], int top, int *x)
	{
		
		if (top==-1)
		{	printf("EMPTY STACK");			
			return -1;
		}
		 
			*x=stack[top];
			top-=1;
			return top;
		
	}

	void display(int stack[], int top)
	{
		int i;
		if (top==-1)
		{	printf("EMPTY STACK");			
			return;
		}
		else
		{
			for(i=top;i>=0 && stack[top]!=minvalue;i--)
			{
				printf("%d\n",stack[i]);
			}
		}
	}


