/* 
FILE NAME:dspd10.c
DATE: 10/10/2017
PURPOSE: To study graph data structure and demonstrate different traversals on DFS and BFS.
AUTHOR:SARTHAK BAISWAR
PROBLEM STATEMENT: Write a C routine to create an arbitary graph (min 6 vertices) using adjacency matrix representation. Write a menu driven program that will include(1)display graph(2)execute DFS(3)bFS. Write a C routine to create an arbitary graph. 
*/

#include<stdio.h>
#include<stdlib.h>
#include"graph.h"

int main()
{
    int graph[MAX][MAX];
    
    populate(graph);
    int vertices,front=-1,rear=-1,ch,choice;
    printf("\t1. Enter u=-1 and v=-1 to terminate the edges\n");
   
    printf("\n1.Undirected graph\t 2.Directed Graph\n");
    printf("Enter the graph choice:");
    scanf("%d",&choice);
   
    printf("Adjacency Matrix for Graph\n");
    printf("\nEnter the no of  vertexes:");
    scanf("%d",&vertices);
    int queue[vertices];
    printf("Valid Graph Vertices Are:\n");
    printf("Index\tVertex\n");
    for(int i=0;i<vertices;i++){
        printf("%d\t%c\n",i,i+65);
    }

    // makes the Adj matrix 
     MakeAdjmatrix(graph,vertices,choice);
     //display the given matrix
     DisplayAdjmatrix(graph,vertices);
     printf("\n");
     
     int Visited[vertices];
     CreateVisited(Visited,vertices);
     
     int source;
     
   do{
   printf("\nTraversals of Directed Graph\n");
   printf("1.DFS traversal\t 2.BFS traversal\t 0.Exit\n");
   printf("Enetr the choice:");
   scanf("%d",&ch);
   switch(ch)
   {
    case 1: if(vertices>0)
            {
                do
                {
                    printf("Enter the source for DFS[0-%d]:",vertices-1);
                    scanf("%d",&source);
                }while(source <0 || source >vertices-1);
                
                CreateVisited(Visited,vertices);
                printf("\nDFS Of Graph is:");
                graph_DFS(graph,Visited,vertices,source);   
            }
            else
                printf("NULL Graph\n"); 
            break;
            
    case 2: if(vertices>0)
            {
                do
                {
                    printf("Enter the source for BFS[0-%d]:",vertices-1);
                    scanf("%d",&source);
                }while(source <0 || source >vertices-1);
                
                CreateVisited(Visited,vertices);
                printf("\nBFS Of Graph is:");
                graph_BFS(graph,Visited,vertices,source,queue,&front,&rear);
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

1.undirected graph	 2.Directed Graph
Enter the graph choice:1

Adjacency Matrix for Graph

Enter the no of  vertexes:4
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

Adjacency Matrix of Undirected Graph 

0(A) 0(B) 0(C) 0(D) 
1(A) 1(B) 1(C) 1(D) 
2(A) 2(B) 2(C) 2(D) 
3(A) 3(B) 3(C) 3(D) 


Traversals of Directed Graph
1.DFS traversal	 2.BFS traversal	 0.Exit
Enter the choice:1
Enter the source for BFS[0-3]:2

DFS Of the UnDirected Graph is:C A B D 


Traversals of Directed Graph
1.DFS traversal	 2.BFS traversal	 0.Exit
Enter the choice:2
Enter the source for BFS[0-3]:2

BFS Of the UnDirected Graph is:C  A  D  B  


Traversals of Directed Graph
1.DFS traversal	 2.BFS traversal	 0.Exit
Enter the choice:0
*/
