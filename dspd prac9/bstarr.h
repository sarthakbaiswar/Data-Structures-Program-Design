#include<stdio.h>
#include<stdlib.h>
#define maxsize 50

typedef struct bst
{
    int lndx;
    int rndx;
    int data;
}atNode;
typedef struct bst *Bst;

//tail-----------last index 

void CreateNode(Bst atree, int key)
{
    atree->data=key;
    atree->lndx=atree->rndx=-1;   
}

void populate(Bst atree)
{
    for(int i=0;i<maxsize;i++)
    {
        atree[i].data=-99;
        atree[i].lndx=atree[i].rndx=-99;
    }
}

void displayBST(Bst atree)
{
    int i=0;
    printf("\n------------------------\n\n");
    printf("Tindex\tdata\tLindex\tRindex\n");
    while(atree[i].data!=-99)
	{
	    printf("%d\t%d\t%d\t%d\n",i,atree[i].data,atree[i].lndx,atree[i].rndx);
	    i++;
	}
	return;
}

int tempSearch(Bst atree,int ndx)
{
    int i=0;
    while(1)
    {
            if(i==maxsize)
            break;
            if(atree[i].rndx==ndx || atree[i].lndx==ndx)
            break;
            i++;
            //printf("index of while =%d\n",i);
            }
    return i;
}

void shifting(Bst atree,int ndx)
{
    int j=0;
    while(1)
    {                   
            if(j==maxsize)
            break;
            
            if(atree[j].rndx>ndx)
            {
             atree[j].rndx=atree[j].rndx-1;
            }
             
            if(atree[j].lndx>ndx)
            {
            atree[j].lndx=atree[j].lndx-1;
            }
            j++;
     }
            
       
       int i=ndx;             
       while(atree[i].data!=-99)
       {
       atree[i]=atree [i+1];
       i++;
       }
 }           


//i -- index
void preorder(Bst atree, int i)
{
    printf("%d\t",atree[i].data);
    
    if(atree[i].lndx!=-1)
        preorder(atree, atree[i].lndx);
    
    if(atree[i].rndx!=-1)
        preorder(atree, atree[i].rndx);    
}

void inorder(Bst atree, int i)
{
    if(atree[i].lndx != -1)
		inorder( atree, atree[i].lndx );
	
	printf("%d\t",atree[i].data);
	
	if(atree[i].rndx != -1)
		inorder( atree, atree[i].rndx );
}

void postorder(Bst atree, int i)
{

	if(atree[i].lndx != -1)
		postorder( atree, atree[i].lndx );
	
	if(atree[i].rndx != -1)
		postorder( atree, atree[i].rndx );
	
	printf("%d\t",atree[i].data);
}

int findmax(Bst atree)
{
    int ndx=0;
    if(atree[ndx].data!=-1)
    {
        while(atree[ndx].rndx!=-1)
        ndx=atree[ndx].rndx;
        
    }
      return ndx;
}

int findmin(Bst atree,int ndx)
{
    if(atree[ndx].data!=-1)
    {
        while(atree[ndx].lndx!=-1)
        ndx=atree[ndx].lndx;               
    }
      return ndx;
 }
 
int insertBSTArr(Bst atree,int tail,int key)
{
    int ndx = 0;//------------base index
    if (tail==0)
    {
        CreateNode(&atree[tail],key);
        return tail+1;
    }
    else
        while(ndx<=tail)
        {   
            if(key <= atree[ndx].data)
            {
                if((atree[ndx].lndx)==-1)
                {
                    atree[ndx].lndx=tail;
                    CreateNode(&atree[tail],key);
                    return tail+1;
                }
                else
                {
                    ndx=atree[ndx].lndx;
                    continue;
                }
            }    
            else
            if (key > atree[ndx].data)        
            {
                if((atree[ndx].rndx)==-1)
                {
                    atree[ndx].rndx=tail;
                    CreateNode(&atree[tail],key);
                    return tail+1;
                }
                else
                    ndx=atree[ndx].rndx;
                    continue;
            }
            else 
                printf("\nDuplicate key\n");
         }
      return tail+1;
}

//ndx - base index

void DeleteBST(Bst atree,int key,int ndx)
{ 
     int i=0;
     int store;
     while(atree[ndx].data!=key)
     {  
      if(ndx==maxsize)
        break; 
       
       ndx=ndx+1; 
     }
 
  if(atree[ndx].data==key)
  {
 
    if(atree[ndx].rndx==-1 && atree[ndx].lndx==-1)
    {   //-----------for leaf nodes
        i=0;
        
        i=tempSearch(atree,ndx);
        if(key<atree[i].data)
        atree[i].lndx=-1;
        else
        atree[i].rndx=-1;
        atree[ndx].data=0000;
        
        printf("After shifting\n");
        shifting(atree,ndx);
        return;
    }
    
    
    if(atree[ndx].rndx==-1)
    {   //-------------left child
        store=atree[ndx].lndx;
        i=tempSearch(atree,ndx);
        if(key<atree[i].data)
            atree[i].lndx=store;
        else
            atree[i].rndx=store;
        
        atree[ndx].data=0000;
        atree[ndx].lndx=atree[ndx].rndx=-1;
        
        printf("After shifting\n");
        shifting(atree,ndx);
        return;
        
    }
    
    if(atree[ndx].lndx==-1)
    {   //--------------right child
        store=atree[ndx].rndx;
        i=tempSearch(atree,ndx);
        if(key<atree[i].data)
            atree[i].lndx=store;
        else
            atree[i].rndx=store;
        
        atree[ndx].data=0000;
        atree[ndx].lndx=atree[ndx].rndx=-1;
       
        printf("After shifting\n");
        shifting(atree,ndx);
        return;
        
    }
    
    if(atree[ndx].lndx!=-1 && atree[ndx].rndx!=-1)
    {   //---------------two children 
        
         i=tempSearch(atree,ndx);
         store=findmin(atree,atree[ndx].rndx);
         atree[ndx].data=atree[store].data;
         DeleteBST(atree,atree[ndx].data,atree[ndx].rndx);
     }
   }   
}
