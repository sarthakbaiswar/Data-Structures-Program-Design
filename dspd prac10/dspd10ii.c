//Adjacency List 
/* 
FILE NAME:dspd10ii.c
DATE: 10/10/2017
PURPOSE: To study graph data structure and demonstrate different traversals on DFS and BFS.
AUTHOR:SARTHAK BAISWAR
PROBLEM STATEMENT: Write a C routine to create an arbitary graph (min 6 vertices) using adjacency list representation. Write a menu driven program that will include(1)display graph(2)execute DFS(3)bFS. Write a C routine to create an arbitary graph. 
*/
#include<stdlib.h>
#include<stdio.h>
#include"linkedlist1.h"
#define MX 20
struct graphListNode
{
    int vertex;
    struct graphListNode* next;
};
  
  typedef struct graphListNode gnode;
  typedef gnode* graphL;
  
  graphL g[MX];  //array of Gnodes
  
  int Visited_List[MX]={0};
  void Graph_List_DFS(int source_L)
  {
    gnode *w;
    Visited_List[source_L]=1;
    printf("%c  ",source_L+65);
    for(w=g[source_L];w!=NULL;)
    {
        if(!Visited_List[w->vertex])
            Graph_List_DFS(w->vertex);
         w=w->next;
    }
    
 }
 
 void CreateVisited_List(int arr[],int vertices)
 {
    
    for(int i=0;i<vertices;i++)
    {
        arr[i]=0;
    }
    return ;
}
 
 
 graphL  insertInOrder_Graph(graphL first,int key)
 {
    graphL temp,neww;
    
    neww=(gnode*)malloc(sizeof(gnode));
    if(neww==NULL)
        return first;
	neww->vertex=key;
	neww->next=NULL;
	
	if(first==NULL)
	    return neww;
	    
	if(first->vertex >= neww->vertex)
	{
	    neww->next=first;
	    return neww;
	}
	
	temp=first;
	
	while(temp->next != NULL && temp->next->vertex <= neww->vertex)
	    temp=temp->next;

    neww->next=temp->next;
    temp->next=neww;
    return first;
 }

 void insertList(int u,int v,int choice)
 {
        graphL m,n;
        if(g[u]==NULL)
        {
                n=(gnode*)malloc(sizeof(gnode));
                n->vertex=v;
                n->next=NULL;
                g[u]=n;
        }
        else
        {
            m=g[u];
            m=insertInOrder_Graph(m,v);
            g[u]=m;
        }
            if(choice==1 && u!=v)
            {
                if(g[v]==NULL){
                    n=(gnode*)malloc(sizeof(gnode));
                    n->vertex=u;
                    n->next=NULL;
                    g[v]=n;
                 }
                 else{
                    m=g[v];
                    m=insertInOrder_Graph(m,u);
                    g[v]=m;
                }
           }
       
 }	
  
 void CreateEdge_List(int vertices_L,int choice)
 {  
    int u_L,v_L;
    int flag=0;
    
    for(int i=0;i<vertices_L;i++)
    {
            g[i]=NULL;
    }  
    printf("Valid Graph Vertices Are:\n");
    printf("Index\tVertex\n");
    for(int i=0;i<vertices_L;i++)
    {
        printf("%d\t%c\n",i,i+65);
    } 
    
    for(int i=0;i<vertices_L;i++){
        for(int j=0;j<vertices_L;j++){
        printf("Enter the edge[0 to %d]-(u,v):",vertices_L-1);
            scanf("%d%d",&u_L,&v_L);
            if((u_L>=0 && u_L<=vertices_L-1) && v_L>=0 && v_L<=vertices_L-1)
            {
                insertList(u_L,v_L,choice);
            }
            else if(u_L==-1 && v_L==-1)
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
        
        printf("Adj List is:\n");
        printf("--------------------------------\n");
    for(int i=0;i<vertices_L;i++)
    {
           graphL temp;
           temp=g[i];
           printf("\n");
           printf("%d(%c) :  ||-> ",i,i+65);
           int j=1;
           while(temp!=NULL)
           {
           printf("%d(%c)   ",temp->vertex,temp->vertex+65);
            temp=temp->next;
            j++;
           }
    }
    printf("\n");
    printf("--------------------------------\n");
    
    
     
        
   }
    
   void Graph_List_BFS(int source,list first_q)
   {
       int visited[MX]={0};
       int temp,w;
       graphL p;
       first_q=insertAtEnd(first_q,source);
       visited[source]=1;
       while(first_q){
        first_q=deleteAtBeg(first_q,&temp);
        if(visited[temp]==1)
            printf("%c  ",temp+65);
        for(p=g[temp];p!=NULL;p=p->next)
        {
            w=p->vertex;
                if(visited[w]==0)
                {
                    visited[w]=1;
                    first_q=insertAtEnd(first_q,w);
                }
        }
    }
 
 return;
}
    
   
int main()
{
            list first=NULL;
            int ch,source,choice,vertices;
            
            printf("\t1. Enter u=-1 and v=-1 to terminate the edges\n");
            
            printf("\n1.undirected graph\t 2.Directed Graph\n");
            printf("Enter the graph choice:");
            scanf("%d",&choice);
            printf("Adjacency List for Graph\n");
            
            printf("\nEnter the no of vertexes: ");
            scanf("%d",&vertices);
            CreateEdge_List(vertices,choice);
            do{
            printf("\n------------------------------\n");
            printf("\nTraversals of Directed Graph\n");
            printf("1.DFS traversal\t 2.BFS traversal\t 0.Exit\n");
            printf("Enetr the choice:");
            scanf("%d",&ch);
            switch(ch){
            case 1: if(vertices>0)
                    {
                    do{
                        printf("Enter the source for DFS[0-%d]:",vertices-1);
                        scanf("%d",&source);
                    }while(source <0 || source >vertices-1);
                    printf("\nDFS Of the Directed Graph is:");
                    Graph_List_DFS(source);
                    }
                    else
                        printf("NULL graph\n");
                    break;
                    
            case 2: if(vertices>0)
                    {
                    do{
                        printf("Enter the source for BFS[0-%d]:",vertices-1);
                        scanf("%d",&source);
                     }while(source <0 || source >vertices-1);
                    printf("\nBFS Of the Directed Graph is:");
                    Graph_List_BFS(source,first);
                    }
                     else
                        printf("NULL graph\n");
                    break;
            }
            }while(ch!=0);


            return 0;
}

/*
	1. Enter u=-1 and v=-1 to terminate the edges
------------------------------------
1.Undirected graph	 2.Directed Graph
Enter the graph choice:1
Creating the Adjacency List for Graph
-------------------------------------
Enter the no of vertexes:4
Valid Graph Vertices Are:
Index	Vertex
0	A
1	B
2	C
3	D
Enter the edge[0 to 3]-(u,v):0 1
Enter the edge[0 to 3]-(u,v):0 2
Enter the edge[0 to 3]-(u,v):1 3
Enter the edge[0 to 3]-(u,v):2 3
Enter the edge[0 to 3]-(u,v):-1 -1
Adj List is:
--------------------------------

0(A) :  ||-> 1(B)   2(C)   
1(B) :  ||-> 0(A)   3(D)   
2(C) :  ||-> 0(A)   3(D)   
3(D) :  ||-> 1(B)   2(C)   
--------------------------------

--------------------------------

Traversals of Directed Graph
1.DFS traversal	 2.BFS traversal	 0.Exit
Enetr the choice:1
Enter the source for DFS[0-3]:2

DFS Of the Directed Graph is:C  A  B  D  
-------------------------------

Traversals of Directed Graph
1.DFS traversal	 2.BFS traversal	 0.Exit
Enetr the choice:2
Enter the source for BFS[0-3]:2

BFS Of the Directed Graph is:C  A  D  B  
-------------------------------

Traversals of Directed Graph
1.DFS traversal	 2.BFS traversal	 0.Exit
Enetr the choice:0
*/
