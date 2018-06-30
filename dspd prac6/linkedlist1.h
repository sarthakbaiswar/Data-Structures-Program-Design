//USER DEFINED FUNCTIONS
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

typedef struct nodeLL
{
	int data;
	struct nodeLL* link;
}node;
typedef node* list;

list createNode()
{
	list neww;
	neww = (list)malloc(sizeof(node));
	if (neww == NULL)
	{
		printf("Node not created\n");
	}
	return neww;
}
int lengthLL(list first)
{
	int length = 0;
	if (first == NULL)
		return length;
	while (first != NULL)
	{
		length = length + 1;
		first = first->link;
	}
	return length;
}

void displayLL(list first)
{
	list neww;
	neww=first;
	if(neww==NULL)
	{
	    printf("List is empty");
	    return;
	}
	while(neww!=NULL)
	{   
		printf("%d[%lu]\t", neww->data,(uintptr_t)neww);
		neww = neww->link;
	}
	printf("\n");
}

list insertAtBeg(list first, int key)
{
	list neww;
	neww = createNode();
	neww->data = key;
	neww->link = NULL;
	if (first == NULL)
		return neww;
	neww->link = first;
	return neww;
}

list createLL(list first)
{   
    int key;
    do{
        scanf("%d",&key);
        if(key!=-999)
        {
            first=insertAtBeg(first,key);
        }
       }while(key!=-999);
    return first;
}

list insertAtEnd(list first, int key)
{
	list neww, temp;
	neww = createNode();
	neww->data = key;
	neww->link = NULL;
	if (first == NULL)
		return neww;
	temp = first;
	while (temp->link != NULL)
	{
		temp = temp->link;
	}
	temp->link = neww;
	return first;
}

list insertAtPos(list first, int pos, int key)
{
	int ndx = 0;
	int len;
	list temp;
	len = lengthLL(first);
	if (pos<0||pos>len+1)
	{
		printf("Incorrect position, insert failed\n");
		return first;
	}
	list neww;
	neww = createNode();
	if (neww == NULL)
	{
	    printf("Node not allocated, insert failed\n");
	    exit(0);
	}

	neww->data = key;
	neww->link = NULL;

	if (pos == 1)
	{
		neww->link = first;
		return neww;
	}
	temp = first;
	while (ndx < pos - 2)
	{
		temp = temp->link;
		ndx++;
	}

	neww->link = temp->link;
	temp->link = neww;
	return first;
}



list deleteAtBeg(list first, int *key)
{
	list temp;
	if(first==NULL)
	{
		printf("\tDelete failed, empty list\n");
		return first;
	}
	temp = first;
	(*key) = first->data;
	first=first->link;
	free(temp);
	return first;
}

list deleteAtEnd(list first, int *key)
{
	list temp;
	if(first==NULL)
	{
		printf("\tDelete failed, empty list.\n");
		return first;
	}
	if(first->link==NULL)
	{
		(*key)=first->data;
		free(first);
		return NULL;
	}
	temp=first;
	while (temp->link->link != NULL)
	{
		temp = temp->link;
	}
	(*key)=(temp->link->data);
	temp->link=NULL;
	free(temp->link);
	return first;
}

list deleteAtPos(list first,int pos,int *key)
{
    list temp;
	if(first==NULL)
	{
		printf("empty list");
		return first;
	}
	int len=lengthLL(first);
	if(pos<0 || pos>len)
	{
	    printf("invalid position\n");
	    return first;
	}
	
	if (pos==1)
	{
	    free(first);
	    return first->link;
	}
	int ndx=0;
	temp=first;
	while(ndx<pos-2)
	{
	    temp=temp->link;
	    ndx++;
	}
	*key=temp->link->data;
	temp->link=temp->link->link;

	return first;
}


list reverseLL(list first)
{
	if(first == NULL)	
	{
		printf("empty list\n");
		return first;
	}
	if(first->link==NULL)
	    return first;
	    
	list rev, ptr1, ptr2;	
	rev=first;
	ptr2=first->link->link;
	ptr1=first->link;

	rev->link=NULL;
	ptr1->link=rev;
	
	while(ptr2!=NULL)
	{
		rev=ptr1;
		ptr1=ptr2;
		ptr2=ptr2->link;
		ptr1->link=rev;
	}
	return ptr1;
}

list sortLL(list first,int mode)
{
	list iptr,jptr;
	int key;
	if(first==NULL || first->link==NULL)
		return first;
	
	for(iptr=first;iptr->link!=NULL;iptr=iptr->link)
	{
		for(jptr=iptr->link;jptr!=NULL;jptr=jptr->link)
		{
			switch(mode)
			{
				case 1: if(iptr->data > jptr->data)
				        {
							key=iptr->data;
							iptr->data=jptr->data;
							jptr->data=key;
						}
						break;
						
				case 2: if(iptr->data < jptr->data)
				        {
							key=iptr->data;
							iptr->data=jptr->data;
							jptr->data=key;
						}
						break;
			}
		}
	}
	
	return first;
}


void locateLL(list first,int value)
{
	list neww;
	neww=first;
	int count=0;
	for(;neww!=NULL;)
	{
		if(neww->data==value)
		{
			count+=1;
			printf("value is found at \t%d\n",count);
			
			return;
		}
		neww=neww->link;
		count+=1;
	}
	printf("Element  %d is not found \n",value);
	return;
}
	
	
list mergeLL(list first,list second)
{
    if(first==NULL && second==NULL)
    {
        printf("can not create the list ,both the lists are empty\n");
        return NULL;
    } 
     
     if(first==NULL)
        return second;
     if(second==NULL)
        return first;
      else
      {
     
         list neww;
         neww=first;
         
         while(neww->link!=NULL)
         {
            neww=neww->link;
         }
         neww->link=second;
         return first;
      }     
}
     
list mergeOrderLL(list first,list second)
{    
     list neww,temp;
     if(first==NULL)
        return second;
     if(second==NULL)
        return first;
        
      if(first==NULL && second==NULL)
      {
        printf("can not create the list ,both the lists are empty\n");
        return NULL;
     } 
     
     while(second!=NULL)
     {
            neww=second;
          
           if(neww->data <= first->data)
           {
                second=second->link;
                neww->link=first;
                first=neww;
                
           }
           
           neww=second;
           temp=first;
           while(temp->link!=NULL && temp->link->data <= neww->data)
           {
                temp=temp->link;
           }
      
           second=second->link;
           neww->link=temp->link;
           temp->link=neww;
         
     }
     return first;
}        
    
    
list  insertInOrder(list first,int key)
{
    list temp,neww;
    
    neww=createNode();
    if(neww==NULL)
        return first;
	neww->data=key;
	neww->link=NULL;
	
	if(first==NULL)
	    return neww;
	    
	if(first->data >= neww->data)
	{
	    neww->link=first;
	    return neww;
	}
	
	temp=first;
	
	while(temp->link != NULL && temp->link->data <= neww->data)
	    temp=temp->link;

    neww->link=temp->link;
    temp->link=neww;
    return first;
 }
	
list copyLL(list first)
{
    list neww,dupl,temp,cpy;
    if(first==NULL)
        return NULL;
    neww=createNode();
    neww->data=first->data;
    neww->link=NULL;
    dupl=neww;
    
    temp=first;
    
    while(temp->link!=NULL)
    {
        cpy=neww;
        temp=temp->link;
        neww=createNode();
        neww->data=temp->data;
        neww->link=NULL;
        cpy->link=neww;
     }   
        neww->link=NULL;
        return dupl;
}
        
 list valueAtFront(list first)
 {
         	return first;
  }
	
 list valueAtRear(list first)
 {
    list neww;
            
            neww=first;
            while(neww->link!=NULL)
            {
                neww=neww->link;
            } 
            return neww;
 }       

void displayllQueue(list first)
{
    list front,rear,temp;
    front=valueAtFront(first);
    rear=valueAtRear(first);

	int i;
	char ch1='F',ch2='R',ch='#';
	for(temp=front;temp!=NULL;temp=temp->link)
	{
		
		if(temp==front)
			printf("\t[%c]",ch1);
		printf("\t%d",temp->data);
		if(temp==rear)
			printf("\t[%c]",ch2);
	}
	printf("\n");
	return;
}


