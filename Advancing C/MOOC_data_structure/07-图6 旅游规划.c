// Dijkstra算法应用
/*
07-图6 旅游规划（25 分）
有了一张自驾旅游路线图，你会知道城市间的高速公路长度、以及该公路要收取的过路费。现在需要你写一个程序，
帮助前来咨询的游客找一条出发地和目的地之间的最短路径。如果有若干条路径都是最短的，那么需要输出最便宜的一条路径。

输入格式:

输入说明：输入数据的第1行给出4个正整数N、M、S、D，其中N（2≤N≤500）是城市的个数，顺便假设城市的编号为0~(N−1)；
M是高速公路的条数；S是出发地的城市编号；D是目的地的城市编号。随后的M行中，每行给出一条高速公路的信息，
分别是：城市1、城市2、高速公路长度、收费额，中间用空格分开，数字均为整数且不超过500。输入保证解的存在。

输出格式:

在一行里输出路径的长度和收费总额，数字间以空格分隔，输出结尾不能有多余空格。

输入样例:

4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
输出样例:

3 40
*/
#include<stdio.h>
#include<stdlib.h>
#define maxsize 500
#define INF 1<<30
typedef struct GNode* Graph;
struct GNode{
  int Nv, Ne;
  int S, D;
  int Data[maxsize][maxsize][2];
  int Dist[maxsize];
  int Collect[maxsize];
  int cost[maxsize];
  int path[maxsize];
};
Graph CreateG(int Nv)
{
  Graph G = malloc(sizeof(struct GNode));
  G->Nv = Nv;
  G->Ne = 0;
  int v, w; 
  for(v = 0; v<G->Nv; v++){
    for(w = 0; w < G->Nv; w++){
      G->Data[v][w][0] = INF;
      G->Data[v][w][1] = INF;
    }
	G->Collect[v] = 0;
    G->Data[v][v][0] = 0;
    G->Data[v][v][1] = 0;
    G->Dist[v] = INF;
    G->cost[v] = INF;
    G->path[v] = -1;
  }
  return G;
}
typedef struct ENode* Edge;
struct ENode{
  int v1, v2, w1, w2;
};
void Insert(Edge E, Graph G)
{
  G->Data[E->v1][E->v2][0] = E->w1;  
  G->Data[E->v1][E->v2][1] = E->w2;
  G->Data[E->v2][E->v1][0] = E->w1;  
  G->Data[E->v2][E->v1][1] = E->w2;
}
Graph BuildG()
{
  int Nv;
  scanf("%d", &Nv);
  Graph G = CreateG(Nv);
  scanf("%d %d %d\n", &G->Ne, &G->S, &G->D);
  int i;
  Edge E = malloc(sizeof(struct ENode));
  for(i = 0; i < G->Ne; i++){
    scanf("%d %d %d %d\n", &E->v1, &E->v2, &E->w1, &E->w2);
    Insert(E, G);
  }
  for(i = 0; i < G->Nv; i++){
    G->cost[i] = G->Data[G->S][i][1];
    G->Dist[i] = G->Data[G->S][i][0];
  }
  return G;  
}
int FindMin(Graph G)
{
  int v, min = INF, argmin = -1;
  for(v = 0; v<G->Nv; v++)
    if(!G->Collect[v] && G->Dist[v]<min){
    	argmin = v;
    	min = G->Dist[v];
	}
      
  return argmin;
}
void Dijkstra(Graph G)
{
  int v, i;
  while(1){
    v = FindMin(G);
    //printf("%d\n", v);
    if(v == -1) break;
    G->Collect[v] = 1;
    for(i=0; i<G->Nv; i++){
      if(!G->Collect[i] && G->Data[v][i][0]<INF)
        if(G->Dist[v] + G->Data[v][i][0] < G->Dist[i]){
          G->Dist[i] = G->Dist[v] + G->Data[v][i][0];
          G->cost[i] = G->cost[v] + G->Data[v][i][1];
          G->path[i] = v;
        }
        else if(G->Dist[v] + G->Data[v][i][0] == G->Dist[i]  && G->cost[i] > G->cost[v] + G->Data[v][i][1]){
          G->cost[i] = G->cost[v] + G->Data[v][i][1];
          G->path[i] = v;
        }
    }
  }
}
int main()
{
  //freopen("G:/Dec-Cpp/8.txt", "r", stdin); 
  Graph G = BuildG();
  Dijkstra(G);
  printf("%d %d", G->Dist[G->D], G->cost[G->D]);
  return 0;
}
