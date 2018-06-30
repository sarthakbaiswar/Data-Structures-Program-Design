#include"queue1.h"
#include<stdlib.h>
#include<stdio.h>

#define MAX 20

void populate(int arr1[MAX][MAX])
{
	int i,j;
	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)
		    arr1[i][j]=0;
	return;
}

void CreateVisited(int arr[],int vertices)
{    
    for(int i=0;i<vertices;i++){
        arr[i]=0;
    }
    return ;
}


void graph_DFS(int arr[][MAX],int Visited[],int vertices,int index)
{ 
    printf("%c ",index+65);
    Visited[index]=1;
    for(int count=0;count<vertices;count++)
    {
        if(!(Visited[count]) && arr[index][count]==1)
            graph_DFS(arr,Visited,vertices,count);
    }
     
 }
 
 void DisplayAdjmatrix(int graph[][MAX],int vertices)
 {
     printf("\nAdjacency Matrix of Undirected Graph \n");
     printf("------------------------------------------\n");
         for(int i=0;i<vertices;i++)
         {
            for(int j=0;j<vertices;j++)
            {
                printf("%d ",graph[i][j]);
            }
            printf("\n");
         }
     printf("-------------------------------------------\n");  
 }
     
void MakeAdjmatrix(int graph[][MAX],int vertices,int choice)
{
    int u,v,flag=0;
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            printf("Enter the edge[0 to %d]-(u,v):",vertices-1);
            scanf("%d%d",&u,&v);
            if((u>=0 && u<=vertices-1) && v>=0 && v<=vertices-1)
            {
                graph[u][v]=1;
                
                if(choice==1)
                graph[v][u]=1;
            }
            else if(u==-1 && v==-1)
            {
                flag=1;
                break;
            }
            else
                printf("Invalid.....\n");
        }
        if(flag==1)
            break;
    }
}

void graph_BFS(int arr[][MAX],int visited[],int vertices,int source,int queue[],int *front,int *rear)
{
    int temp,w;
    insertq(queue,front,rear,source);
    visited[source]=1;
    
    while(!qisempty(queue,*front,*rear))
    {
        temp = deleteq(queue,front,rear);
        if(visited[temp]==1)
            printf("%c ", temp+65);
        
        for(int j=0;j<vertices;j++)
        {
            if(arr[temp][j]==1)
            {
                w=j;
                if(visited[w]==0)
                {
                    visited[w]=1;
                    insertq(queue,front,rear,w);
                }
            }
            
            if(*front==vertices-1)
                *front=-1;
        }
    }
    return;
}


