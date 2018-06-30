//functions for queue ADT
#define maxsize 5
#define minvalue -9999
int qisempty(int queue[],int front,int rear){
	if(front==-1)
		return 1;
	return 0;
}

int qisfull(int queue[],int front,int rear){
	if(rear==maxsize-1)
		return 1;
	return 0;
}

void insertq(int queue[],int *front,int *rear,int key){
	if(*rear==maxsize-1){
		//printf("queue is full,can not insert\n");
		return;
	}
	*rear+=1;
	queue[*rear]=key;
	if(*front==-1)
		*front=0;
	return;
}

int deleteq(int queue[],int *front,int *rear){
	if(*front==-1){
		printf("queue is empty,can not delete\n");
		return 0;
	}
	int key;
	key=queue[*front];
	queue[*front]=-9999;
	if(*front==0 && *rear==0){
		*front=-1;
		*rear=-1;
	}
	else if((*front)==(*rear))
		*front=*rear=-1;
	else
		*front=(*front)+1;
	return key;
}

void intializeq(int queue[],int *front,int *rear){
	*front=-1;
	*rear=-1;
	queue[0]=minvalue;
}

int valueatfront(int queue[],int *front,int *rear){
	if(*front==-1)
		return minvalue;
	if(*front!=-1)
		return (queue[*front]);
}

int valueatrear(int queue[],int *front,int *rear){
	if(*rear!=-1)
		return (queue[*rear]);
	else
		return minvalue;
}

void displayq(int queue[],int front,int rear){
	if(front==-1){
		printf("queue is empty ,nothing to display\n");
		return;
	}
	int i;
	char ch1='F',ch2='R',ch='#';
	printf("contents of the queue are:\n");
	for(i=0;i<maxsize-1;i++){
	if(queue[i]==-9999 )	//reseting condition
			printf("\t%c",ch);
	}
	
	for(i=front;i<=rear;i++){
		
		if(i==front)
			printf("\t[%c]",ch1);
		printf("\t%d",queue[i]);
		if(i==rear)
			printf("\t[%c]",ch2);
	}
	printf("\n");
	return;
}

	
