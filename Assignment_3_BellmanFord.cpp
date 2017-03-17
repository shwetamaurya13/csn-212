#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
struct Edge
    {
    long long source, dest, weight;
};
struct Graph
    {
    long long v,e;
    struct Edge *edge;
};
struct Graph * createGraph(long long V, long long E)
    {
    struct Graph *graph= (struct Graph *)malloc(sizeof(struct Graph));
    graph->v=V;
    graph->e=E;
    graph->edge= (struct Edge *)malloc(sizeof(struct Edge)*E);
    return graph;
}
 void BellmanFord(struct Graph *graph, int src)
     {
     long long dist[graph->v];
     for(long long i=0; i<graph->v; i++){
         dist[i]=INT_MAX;
     }
     dist[src]=0;
     for(long long i=0; i<graph->v-1; i++)
         {
         for(long long j=0; j<graph->e; j++)
             {
             long long p=graph->edge[j].source;
             long long q=graph->edge[j].dest;
             if(dist[q]>dist[p]+graph->edge[j].weight && dist[p]!=INT_MAX)
                 dist[q]=dist[p]+graph->edge[j].weight;
         }
     }
     for(long long j=0; j<graph->e; j++)
             {
             long long p=graph->edge[j].source;
             long long q=graph->edge[j].dest;
             if(dist[q]>dist[p]+graph->edge[j].weight && dist[p]!=INT_MAX)
               {
                cout<<"Graph has negative weight cycle \n";
               }
         }
     cout<<"Distance array "<<endl;
     for(int i=0; i<graph->v; i++)
         {
             cout<<dist[i]<<" ";
         }
 }

int main() {
    long long v, e;
    //cout<<"Enter the number of vertices of the graph "<<endl;
    cin>>v;
    //cout<<"Enter number of edges "<<endl;
    cin>>e;
    struct Graph *graph=createGraph(v,e);
    //cout<<"For every edge, enter the following data "<<endl;
    for(long long i=0; i<e; i++)
        {
        //cout<<"Enter the source vertex, destination vertex and weight of the edge "<<endl;
        cin>>graph->edge[i].source;
        //graph->edge[i].source=rand() % v;
        cin>>graph->edge[i].dest;
        //graph->edge[i].dest=rand() % v;
        cin>>graph->edge[i].weight;
        //graph->edge[i].weight= rand()%100 - 50;
    }
    long long src;
    //cout<<"Enter source vertex (you should name vertices starting from 0 like 0,1,2,3....v-1)"<<endl;
    cin>>src;
    clock_t stime,ftime;
    stime=clock();
    BellmanFord(graph,src);
    ftime=clock();
    cout<<"\n time of execution: "<<ftime-stime;
    return 0;
}
