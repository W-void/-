/*
05-树7 堆中的路径（25 分）
将一系列给定数字插入一个初始为空的小顶堆H[]。随后对任意给定的下标i，打印从H[i]到根结点的路径。

输入格式:
每组测试第1行包含2个正整数N和M(≤1000)，分别是插入元素的个数、以及需要打印的路径条数。
下一行给出区间[-10000, 10000]内的N个要被插入一个初始为空的小顶堆的整数。最后一行给出M个下标。

输出格式:
对输入中给出的每个下标i，在一行中输出从H[i]到根结点的路径上的数据。数字间以1个空格分隔，行末不得有多余空格。

输入样例:
5 3
46 23 26 24 10
5 4 3
输出样例:
24 23 10
46 23 10
26 10
*/

#include<stdio.h>
#include<stdlib.h>
const int Min = -1<<30;

typedef struct HeapNode* Heap;
struct HeapNode{
  int *Data;
  int Size, MaxSize;
};

Heap Insert(Heap H, int X)
{//堆不可能满，所以不需要判断堆是否已满
  int i = ++H->Size;
  for(; X<H->Data[i/2]; i /= 2)
    H->Data[i] = H->Data[i/2];
  H->Data[i] = X;
  
}
Heap CreateHeap(int N)
{
  Heap H = (Heap)malloc(sizeof(struct HeapNode));
  H->Size = 0, H->MaxSize = N;
  H->Data = (int *)malloc((N+1)* sizeof(int));
  H->Data[0] = Min;
  int X;
  while(N--){
    scanf("%d", &X);
    H = Insert(H, X);
  }
  return H;
}
void printPath(Heap H, int ind)
{
  for(; ind>0; ind /= 2)
    printf("%d%c", H->Data[ind], ind==1?'\n':' ');
}

int main()
{
  int N, M;
  scanf("%d%d\n", &N, &M);
  Heap H = CreateHeap(N);
  int ind;
  while(M--){
    scanf("%d", &ind);
    printPath(H, ind);
  }
  return 0;
}
