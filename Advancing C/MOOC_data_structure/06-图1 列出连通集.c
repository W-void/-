// 把 j 写成 i 能把人气死，检查半天不知道哪里错了
/*
06-图1 列出连通集（25 分）
给定一个有N个顶点和E条边的无向图，请用DFS和BFS分别列出其所有的连通集。假设顶点从0到N−1编号。进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。
输入格式:

输入第1行给出2个整数N(0<N≤10)和E，分别是图的顶点数和边数。随后E行，每行给出一条边的两个端点。每行中的数字之间用1空格分隔。
输出格式:

按照"{ v
​1
​​  v
​2
​​  ... v
​k
​​  }"的格式，每行输出一个连通集。先输出DFS的结果，再输出BFS的结果。
输入样例:

8 6
0 7
0 1
2 0
4 1
2 4
3 5
输出样例:

{ 0 1 4 2 7 }
{ 3 5 }
{ 6 }
{ 0 1 2 7 4 }
{ 3 5 }
{ 6 }
*/
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10

typedef struct GNode* Graph;
struct GNode{
  int a[MaxSize][MaxSize];
  int visited[MaxSize];
  int Nv, Ne;
};
typedef struct ENode* Edge;
struct ENode{
  int v1, v2;
  // int w;
};
Graph CreateGraph(int Nv)
{
  Graph G = (Graph)malloc(sizeof(struct GNode));
  G->Nv = Nv;
  G->Ne = 0;
  int i, j;
  for(i=0; i<Nv; i++){
    G->visited[i] = 0;
    for(j=0; j<Nv; j++)
      G->a[i][j] = 0;
    }
      
     
  return G;
}
void Insert(Graph G, Edge E)
{
  G->a[E->v1][E->v2] = 1;
  G->a[E->v2][E->v1] = 1;
}
Graph BuildGraph()
{
  int Nv;
  scanf("%d", &Nv);
  Graph G = CreateGraph(Nv);
  scanf("%d", &G->Ne);
  int i;
  if(G->Ne){
    Edge E = (Edge)malloc(sizeof(struct ENode));
    for(i=0; i<G->Ne; i++){
      scanf("%d %d\n", &E->v1, &E->v2);
      Insert(G, E);
    }
  }
  return G;
}
void Dfs(Graph G, int v)
{
  printf("%d ", v);
  G->visited[v] = 1;
  int i;
  for(i=0; i<G->Nv; i++)
    if(!G->visited[i] && G->a[v][i])
      Dfs(G, i);
}
typedef struct QNode* Queue;
struct QNode{
  int front, rear;
  int a[MaxSize];
};
Queue Q;// = (Queue)malloc(sizeof(struct QNode));
//Q->rear = 0, Q->front = 0;
void EnQueue(Queue Q, int v)
{
  Q->rear = (Q->rear + 1) % MaxSize; 
  Q->a[Q->rear] = v;
  
}
int IsEmpty(Queue Q)
{
  return Q->rear == Q->front;
}
int DeQueue(Queue Q)
{
  Q->front = (Q->front + 1) % MaxSize;
  return Q->a[Q->front];
}
void Bfs(Graph G, int v)
{
  printf("%d ", v);
  G->visited[v] = 1;
  EnQueue(Q, v);
  while(!IsEmpty(Q)){
    v = DeQueue(Q);
    int i;
    for(i=0; i<G->Nv; i++)
      if(G->a[v][i] && !G->visited[i]){
          printf("%d ", i);
          G->visited[i] = 1;
          EnQueue(Q, i);
      }     
  }
}
void Clear(Graph G)
{
  int i;
  for(i=0; i<G->Nv; i++)
   G->visited[i] = 0;
}
int main()
{
	freopen("G:/Dec-Cpp/7.txt","r", stdin); 
  Graph G = BuildGraph();
  int i;
  for(i=0; i<G->Nv; i++)
    if(!G->visited[i]){
      printf("{ ");
      Dfs(G, i);
      printf("}\n");
    }
  
  Clear(G);
  Q = (Queue)malloc(sizeof(struct QNode));
  Q->rear = 0, Q->front = 0;
  for(i=0; i<G->Nv; i++)
    if(!G->visited[i]){
      printf("{ ");
      Bfs(G, i);
      printf("}\n");
    }
  return 0;
}
