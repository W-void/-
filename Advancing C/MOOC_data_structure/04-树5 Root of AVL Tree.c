/*
04-树5 Root of AVL Tree（25 分）
An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node 
differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. 
Figures 1-4 illustrate the rotation rules.
  
 
Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.
Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (≤20) 
which is the total number of keys to be inserted. Then N distinct integer keys are given in the next line. 
All the numbers in a line are separated by a space.
Output Specification:

For each test case, print the root of the resulting AVL tree in one line.
Sample Input 1:

5
88 70 61 96 120
Sample Output 1:

70
Sample Input 2:

7
88 70 61 96 120 90 65
Sample Output 2:

88
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct AVLNode* Tree;
struct AVLNode{
  int Data, Height;
  Tree Left, Right;
};
Tree NewNode(int V)
{
  Tree T = (Tree)malloc(sizeof(struct AVLNode));
  T->Data = V;
  T->Left = T->Right = NULL;
  T->Height = 0;
  return T;
}
int max(int a, int b)
{
  return a>b?a:b;
}
int GetHeight(Tree T)
{

	int LeftH = T->Left?T->Left->Height:-1;
  	int RighH = T->Right?T->Right->Height:-1; 
  	return max(LeftH, RighH) + 1;
}
Tree RRRotation(Tree T)
{
  Tree Tmp = T->Right;
  T->Right = Tmp->Left;
  Tmp->Left = T;
  T->Height = GetHeight(T);
  Tmp->Height = GetHeight(Tmp);
  return Tmp;
}
Tree LLRotation(Tree T)
{
  Tree Tmp = T->Left;
  T->Left = Tmp->Right;
  Tmp->Right = T;
  T->Height = GetHeight(T);
  Tmp->Height = GetHeight(Tmp);
  return Tmp;
}
Tree RLRotation(Tree T)
{
  T->Right = LLRotation(T->Right);
  return RRRotation(T);
}
Tree LRRotation(Tree T)
{
  T->Left = RRRotation(T->Left);
  return LLRotation(T);
}
Tree Insert(Tree T, int V)
{
  if(!T){
    T = NewNode(V);
  }
  else{
  	int LeftH = T->Left?T->Left->Height:-1;
  	int RighH = T->Right?T->Right->Height:-1; 

    if(V > T->Data){
      T->Right = Insert(T->Right, V);
      RighH = T->Right?T->Right->Height:-1; 
      if(LeftH - RighH == -2){
      //需要旋转
        if( V > T->Right->Data)//RR Rotation
          T = RRRotation(T);
        else//RL Rotation
          T = RLRotation(T);
      }
    }
      
    else{
      T->Left = Insert(T->Left, V);
      LeftH = T->Left?T->Left->Height:-1;
      if(LeftH - RighH == 2){
        if(V < T->Left->Data)//LL Rotation
          T = LLRotation(T);
        else
          T = LRRotation(T);
      }
    }
  }
  T->Height = GetHeight(T);
  return T;
}

Tree MakeAVLTree(int N)
{
  Tree T = NULL;
  int V;
  while(N--){
    scanf("%d", &V); 
    T = Insert(T, V);
   
  }
  return T;
}
int main()
{
  int N;
  scanf("%d\n", &N); 
  Tree T = MakeAVLTree(N);
  printf("%d", T->Data);
  return 0;
}
