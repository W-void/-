//多源最短路径Floyd算法
/*
07-图4 哈利·波特的考试（25 分）
哈利·波特要考试了，他需要你的帮助。这门课学的是用魔咒将一种动物变成另一种动物的本事。例如将猫变成老鼠的魔咒是haha，
将老鼠变成鱼的魔咒是hehe等等。反方向变化的魔咒就是简单地将原来的魔咒倒过来念，例如ahah可以将老鼠变成猫。
另外，如果想把猫变成鱼，可以通过念一个直接魔咒lalala，也可以将猫变老鼠、老鼠变鱼的魔咒连起来念：hahahehe。
现在哈利·波特的手里有一本教材，里面列出了所有的变形魔咒和能变的动物。老师允许他自己带一只动物去考场，要考察他把这只动物变成任意一只指定动物的本事。
于是他来问你：带什么动物去可以让最难变的那种动物（即该动物变为哈利·波特自己带去的动物所需要的魔咒最长）需要的魔咒最短？
例如：如果只有猫、鼠、鱼，则显然哈利·波特应该带鼠去，因为鼠变成另外两种动物都只需要念4个字符；而如果带猫去，则至少需要念6个字符才能把猫变成鱼；
同理，带鱼去也不是最好的选择。

输入格式:

输入说明：输入第1行给出两个正整数N (≤100)和M，其中N是考试涉及的动物总数，M是用于直接变形的魔咒条数。为简单起见，我们将动物按1~N编号。
随后M行，每行给出了3个正整数，分别是两种动物的编号、以及它们之间变形需要的魔咒的长度(≤100)，数字之间用空格分隔。
输出格式:

输出哈利·波特应该带去考场的动物的编号、以及最长的变形魔咒的长度，中间以空格分隔。如果只带1只动物是不可能完成所有变形要求的，则输出0。
如果有若干只动物都可以备选，则输出编号最小的那只。
输入样例:

6 11
3 4 70
1 2 1
5 4 50
2 6 50
5 6 60
1 3 70
4 6 60
3 6 80
5 1 100
2 4 60
5 2 80
输出样例:

4 70
*/
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
#define INF 10000
typedef struct GNode* MGraph;
struct GNode{
  int Ne, Nv;
  int Data[MaxSize][MaxSize];
  int visited[MaxSize];
  int Dist[MaxSize][MaxSize];
};
typedef struct ENode* Edge;
struct ENode{
  int v1, v2, w;
};
MGraph CreateG(int Nv)
{
  MGraph G = (MGraph)malloc(sizeof(struct GNode));
  G->Nv = Nv;
  G->Ne = 0;
  int i, j;
  for(i=0; i<Nv; i++){
    G->visited[i] = 0;
    for(j=0; j<Nv; j++)
      G->Data[i][j] = INF;
    G->Data[i][i] = 0;
  }
  return G;
}
void Insert(MGraph G, Edge E)
{
  G->Data[E->v1 - 1][E->v2 - 1] = E->w;
  G->Data[E->v2 - 1][E->v1 - 1] = E->w;
}
MGraph BuildGraph()
{
  int Nv;
  scanf("%d", &Nv);
  MGraph G = CreateG(Nv);
  scanf("%d", &G->Ne);
  int i;
  if(G->Ne){
    Edge E = (Edge)malloc(sizeof(struct ENode));
    for(i=0; i<G->Ne; i++){
      scanf("%d %d %d\n", &E->v1, &E->v2, &E->w);
      Insert(G, E);
    }
  }
  return G;
}
void Floyd(MGraph G)
{
  int i, j, k;
  for(i=0; i<G->Nv; i++)
    for(j=0; j<G->Nv; j++)
      G->Dist[i][j] = G->Data[i][j];
  for(k=0; k<G->Nv; k++)
    for(i=0; i<G->Nv; i++)
      for(j=0; j<G->Nv; j++)
        if(G->Dist[i][j] > G->Dist[i][k] + G->Dist[k][j])
          G->Dist[i][j] = G->Dist[i][k] + G->Dist[k][j];
}
void FindMin(MGraph G)
{
  int i, j, max, min = INF, argmin;
  for(i=0; i<G->Nv; i++){
    max = 0;
    for(j=0; j<G->Nv; j++){
      if(max < G->Dist[i][j]) 
        max = G->Dist[i][j];
    }
    if(min > max){
      argmin = i+1;
	  min = max;
	}
  }
  if(min == INF) printf("0");
  else printf("%d %d", argmin, min);
}
void FindAnimal(MGraph G)
{
  Floyd(G);
  FindMin(G);
}
int main()
{//freopen("G:/Dec-Cpp/8.txt", "r", stdin); 
  MGraph G = BuildGraph();
//  int i, j;
//  for(i=0; i<G->Nv; i++)
//  for(j=0; j<G->Nv; j++) 
//  printf("%d %d %d\n", i, j, G->Data[i][j]);
  FindAnimal(G);
  return 0;
}
