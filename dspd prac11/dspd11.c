/* 
FILE NAME:dspd11.c
DATE: 12/10/2017
PURPOSE: To study different shortest path algorithms - Warshall's (Path matrix) and Dijkstra's algorithm.
AUTHOR:SARTHAK BAISWAR
PROBLEM STATEMENT: Create an arbitary graph with min of 8 nodes using "graph.h", implement the routines to - (1)find shortest path matrix using Warshall's Algorithm and (2)find shortest path between vertices uisng Dijkstra's Algorithm. Additionally, add routines to create minimum cost spanning tree of graph using Prim's/Kruskal's method. Write a menu-driven program to implement the soluiton. You must include other utility functions in the menu.
*/


#include<stdio.h>
#include<stdlib.h>
#define mx 10
#define INF 99999
#define NDT -1

 void DisplayAdjmatrix(int graph[][mx],int vertices,const char *s)
 {
 printf("\n%s Matrix of directed Graph \n",s);
 printf("---------------------------------------\n");
     for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
     }
   printf("---------------------------------------\n");  
 }
 
  void DisplayAdjmatrixSingle(int arr[],int vertices,const char *s)
  {
 printf("\n%s Matrix of directed Graph \n",s);
 printf("---------------------------------------\n");
     
        for(int j=0;j<vertices;j++)
        {
            printf("%d\t",arr[j]);
        }
        printf("\n");
     
   printf("---------------------------------------\n");  
 }
 
 
 void path_Display(int next[][mx],int src,int dest)
 {
    if(next[src][dest]==NDT)
    {
        printf("No path exists between %d to %d\n",src,dest);
        return;
    }
    printf("%d ",src);
    while(src!=dest)
    {
        src=next[src][dest];
        printf("%d ",src);
    }
    
    return;
 }
 void populate(int arr1[][mx],int vertices,int value)
 {
	int i,j;
	for(i=0;i<vertices;i++)
		for(j=0;j<vertices;j++)
		    arr1[i][j]=value;
	return;
}
 
void graph_FW(int graph[][mx],int vertices)
{
    //matrix intialiaztion
     int dist[mx][mx],next[mx][mx];
     populate(dist,vertices,INF);
      populate(next,vertices,NDT);
      printf("Intital Mtrices:\n");
     DisplayAdjmatrix(dist,vertices,"dist");
      DisplayAdjmatrix(next,vertices,"next");
      printf("---------------------------------\n");
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
             if(i==j && graph[i][j]==INF)
                dist[i][j]=0;
             else
             {
               dist[i][j]=graph[i][j];
             }
            next[i][j]=j;
        }
     }
     int i,j,k,m;
     for(k=0;k<vertices;k++)
     {
             for(i=0;i<vertices;i++)
             {
                for(j=0;j<vertices;j++)
                {
                    if(dist[i][j]> dist[i][k]+ dist[k][j])
                    {
                        dist[i][j]=dist[i][k]+dist[k][j];
                        next[i][j]=next[i][k];
                    }
                 }
             }
      }
      //after algorithm
      DisplayAdjmatrix(dist,vertices,"dist");
      DisplayAdjmatrix(next,vertices,"next");
      
      printf("Enter the source Vertex for finding the shortest path:\n");
              scanf("%d",&m);
              printf("Single Vertex shows ABSENCE of the path from that node to particular node\n");
              printf("\n\nPath between %d and  each vertex:\n",m);
              for(int i=1;i<vertices;i++)
              {
                printf("%d\t:",i);
                path_Display(next,m,i);//m=0
                printf("\n");
              }
                
    return;
 }
   
int find_min_dist(int dist[],int vertices,int visited[])
{
 int i,min_dist=INF,min_pos=NDT;
 for(i=0;i<vertices;i++)
 {
    if(dist[i]<min_dist && !visited[i])
    {
        min_dist=dist[i];
        min_pos=i;
    }
 }
 
 return min_pos;
}
    
 
 void graph_Dijkstra(int graph[][mx],int vertices,int src)
 {
    int u,w,i,alt;
    int dist[mx],visited[mx],pre[mx],q[mx];
    for(i=0;i<vertices;i++)
    {
        dist[i]=INF;
        pre[i]=-1;
        visited[i]=0;
        q[i]=i;
    }
    DisplayAdjmatrixSingle(dist,vertices,"Distance");
    DisplayAdjmatrixSingle(pre,vertices,"Previous");
    DisplayAdjmatrixSingle(visited,vertices,"Visited");
    DisplayAdjmatrixSingle(q,vertices,"Queue");
    for(i=0;i<vertices;i++)
    {
    dist[i]=graph[src][i];
    if(dist[i]!=INF)
        pre[i]=src;
     }//initial settting of Matrices
    dist[src]=0;
    visited[src]=1;//first is always zero unles there is self loop at source
    i=vertices-1;
    while(i!=1)
    {        //while Q is not empty
        u=find_min_dist(dist,vertices,visited);
        printf("U calculated is %d\n",u);
        if(u==-1)
        {
            printf("No Path from the vertex\n");
            continue;
        } 
        visited[u]=1;
        for(w=0;w<vertices;w++)
        {
        alt=dist[u]+graph[u][w];
            if(!visited[w])
            {
                if(alt<dist[w])
                {
                    printf("Distance is changed from %d to %d\n",dist[w],alt);
                    dist[w]=alt;
                    pre[w]=u;
                }
            }
        }
    i--;//removed from Queue
    }
    printf("\n......After...............\n");
    DisplayAdjmatrixSingle(dist,vertices,"Distance");
    DisplayAdjmatrixSingle(pre,vertices,"Previous");
    DisplayAdjmatrixSingle(visited,vertices,"Visited"); 
    
    return;
}

int min_key(int dist[],int visited[],int vertices)
{
    int min=INF,minpos=-1;
    int i;
    for(i=0;i<vertices;i++)
    {
        if(!visited[i] && dist[i]<min)
        {
            min=dist[i];
            minpos=i;
        }
    }
    return minpos;
}

void graph_Prims(int graph[][mx],int vertices,int src)
{
        int i,j,u;
        int dist[mx]={INF},mst_P[mx]={NDT},visited[mx]={0};
        int show[2][mx];
        for(i=0;i<vertices;i++)
        {
            dist[i]=INF;
            mst_P[i]=-1;
            visited[i]=0;
        }
        DisplayAdjmatrixSingle(dist,vertices,"Distance");
        DisplayAdjmatrixSingle(mst_P,vertices,"MSTParents");
        DisplayAdjmatrixSingle(visited,vertices,"Visited");
        for(i=0;i<vertices;i++)
        {
            dist[i]=graph[src][i];
            if(dist[i]!=INF)
                mst_P[i]=0;
        }
        dist[src]=0;
        visited[src]=1;
        int v;
        j=0;
        for(i=0;i<vertices-1;i++)
        {
            u=min_key(dist,visited,vertices);
            printf("....U Chosen is :%d\n",u);
            visited[u]=1;
            show[0][j]=mst_P[u];
            show[1][j++]=u;
            DisplayAdjmatrixSingle(dist,vertices,"Distance");
            DisplayAdjmatrixSingle(visited,vertices,"Visited");
            for(v=0;v<vertices;v++)
            {
                {
                    if(visited[v]==0 && dist[v]>graph[u][v]){
                    mst_P[v]=u;
                    dist[v]=graph[u][v];

                  }
                }
            }
        }
        printf("\n......After...............\n");
    DisplayAdjmatrixSingle(dist,vertices,"Distance");
    DisplayAdjmatrixSingle(mst_P,vertices,"MSTParents");
    DisplayAdjmatrixSingle(visited,vertices,"Visited");

    printf("MST EDGES IN THE ORDER ARE:\n");
    for(i=0;i<vertices-1;i++)
    {
            printf("%d\t%d\n",show[0][i],show[1][i]);
    }


}

  //Main menu
 
int main()
{
    int dist[mx][mx],next[mx][mx];
    int vertices,cost,u,v,flag=0;
    int adjMat[mx][mx];
    printf("No Negative weights Should be included for Djkistra's Algorithm\n");
    printf("No Negative cycles Should be included for F-W Algorithm\n");
    //printf(" GRAPH Entered is Assumed to be DIRECTED Graph\n");
    printf("\nEnter the no of vertices:");
    scanf("%d",&vertices);
    populate(adjMat,vertices,INF);
     
    printf("Initial Matrices:\n");
    DisplayAdjmatrix(adjMat,vertices,"adj");
     
    printf("-----------------------------------------\n");
    
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
       
         printf("\nEnter the edge[0 to %d]-(u,v):",vertices-1);
            scanf("%d%d",&u,&v);
         if(u==-1 && v==-1)
         {
                flag=1;
                break;
         }
         printf("\nEnter the value for the edge:");
         scanf("%d",&cost);
         //adjMat[v][u]=cost;
         adjMat[u][v]=cost;
        
        }
          if(flag==1)
            break;
    }
    
    DisplayAdjmatrix(adjMat,vertices,"adj");
    int ch;
    int m;
    do
    {
        printf("1.F-W Algorithm\t2.Djkistra's Algorithm\t3.Prim's Algorithm\t0.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:graph_FW(adjMat,vertices);
                     printf("----------------------------------------------\n");
                     break;
              
            case 2:
                    printf("Enter the source vertex for Dikestra's:");
                    scanf("%d",&m);
                    graph_Dijkstra(adjMat,vertices,m);
                    break;
                     printf("----------------------------------------------\n");
                     break;
                     
            case 3:
                    printf("Enter the Source vertex for MST using Prims:");
                    scanf("%d",&m);
                    graph_Prims(adjMat,vertices,m);
                    printf("------------------------------------------------\n");
                    break;

         }
     }while(ch!=0);
    
    return 0;
   }
