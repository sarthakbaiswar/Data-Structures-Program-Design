/** User defined functions definitions */
//CIRCULAR QUEUE


	#define maxsize 5
	#define minvalue -999

	void intializeCQ(int Cq[],int *f,int *r)
	{
		*f=-1;
		*r=-1;
		
 	}
 	int isfullCQ(int Cq[],int f,int r)
	{
		if((f==0 && r==maxsize-1) || (f==r+1))
			return 1;
		return 0;
 	}
 	
	int isemptyCQ(int Cq[],int f,int r)
	{
 		if(f==-1)
 			return 1;
 		return 0;
	 }
 	
	void insertCQ(int Cq[],int *f,int *r,int keycq)
	{
 
 		if(*f==-1)
		{
			*f=0; 			
			*r=0;	
 		}
 		else if(*r==maxsize-1)
 			*r=0;
 		else	
			*r=*r + 1;
 		Cq[*r]=keycq;
 		return;
	 }
 
	 void deleteCQ(int Cq[],int *f,int  *r)
	{
		int keycq;
 	
 		keycq=Cq[*f];

		Cq[*f]=-9999;

 		if(*f==*r)
		{
 			*f=-1;
			*r=-1;
 		}
 		else if(*f==maxsize-1)
 		{	
			*f=0;
		}
 		else
		{
 			*f=*f + 1;
		} 	
 	return;
	 }
 
	 void displayCQ(int Cq[],int f,int r)
	{
 		int i;
		char c1='F',c2='R',c='_';
 		if(f==-1)
		{
 			printf("Empty circular queue, nothing to display\n");
 			return;
 		}
 	
 		printf("Elements of the queue :");
 		if(f<=r)
		{
	 		for(i=0;i<=maxsize-1;i++)
			{
				if(Cq[i]==-9999)
				{
 					printf("\t%c",c);
 				}
 			}	
 		
 			for(i=f;i<=r;i++)
			{
	 			if(i==f)
	 				printf("\t[%c]",c1);		
				if(Cq[i]!=-9999) 				
	 				printf("\t%d",Cq[i]);
	 		}
 		
	 		printf("\t[%c]",c2);
	 	}
 	
 		else
		{ 		
	 		for(i=0;i<=r;i++)
			{
 	 			if(Cq[i]!=-9999)
 					printf("\t%d",Cq[i]);
 			}
 			printf("\t[%c]",c2);
 		
 			for(i=0;i<maxsize;i++)
			{
				if(Cq[i]==-9999)
				{ 				
 					printf("\t%c",c);
 				}
 			}
			
			for(i=f;i<=maxsize-1;i++)
			{
	 			if(i==f)
	 				printf("\t[%c]",c1);
 			
 				if(Cq[i]!=-9999)
 					printf("\t%d",Cq[i]);
 			}
		}
 		
		printf("\n");
 		return;
 	}




