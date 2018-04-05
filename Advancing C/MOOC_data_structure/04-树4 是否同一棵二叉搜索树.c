//
/*
04-树4 是否同一棵二叉搜索树（25 分）
给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。
例如分别按照序列{2, 1, 3}和{2, 3, 1}插入初始为空的二叉搜索树，都得到一样的结果。
于是对于输入的各种插入序列，你需要判断它们是否能生成一样的二叉搜索树。

输入格式:
输入包含若干组测试数据。每组数据的第1行给出两个正整数N (≤10)和L，分别是每个序列插入元素的个数和需要检查的序列个数。
第2行给出N个以空格分隔的正整数，作为初始插入序列。最后L行，每行给出N个插入的元素，属于L个需要检查的序列。

简单起见，我们保证每个插入序列都是1到N的一个排列。当读到N为0时，标志输入结束，这组数据不要处理。

输出格式:
对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。

输入样例:
4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0
输出样例:
Yes
No
No
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct TNode *Tree;
struct TNode{
  int Data;
  Tree Left, Right;
  int flag;
};
Tree NewNode(int v)
{
  Tree T = (Tree)malloc(sizeof(struct TNode));
  T->Data = v;
  T->Left = T->Right = NULL;
  T->flag = 0;
  return T;
}
Tree Insert(Tree T, int v)
{
  if(!T){
    T = NewNode(v);
  }
  else{
    if(v < T->Data)
      T->Left = Insert(T->Left, v);
    else
      T->Right = Insert(T->Right, v);
  }
  return T;
}
Tree MakeTree(int N)
{
  Tree T;
  int v;
  while(N--){
    scanf("%d", &v);
    T = Insert(T, v);
  }
}
int check(Tree T, int v)
{
  while(T->flag == 1){
    if(v>T->Data)
      T = T->Right;
    else
      T = T->Left;
  }
  T->flag = 1;
  if(T->Data != v) return 1;
  else return 0;
}
int Judge(Tree T, int N)
{
  int v, f = 0;
  while(N--){
    scanf("%d", &v);
    if(!f && check(T, v)) f = 1;
  }
  if(f) return 1;
  else return 0;
}
void Reset(Tree T)
{//先序遍历
  if(!T) return;
  T->flag = 0;
  Reset(T->Left);
  Reset(T->Right);
}
void Free(Tree T)
{//后序遍历
  if(T->Left) Free(T->Left);
  if(T->Right) Free(T->Right);
  free(T);
}
int main()
{
  int N, L;
  Tree T;
  while(scanf("%d %d\n", &N, &L) == 2){
    T = MakeTree(N);
    while(L--){
      if(!Judge(T, N))
        printf("Yes\n");
      else
        printf("No\n");
      Reset(T);
    }
  }
  Free(T);
  return 0;
}
