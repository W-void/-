// log2(n) = log(n)/log(2);
/*
04-树6 Complete Binary Search Tree（30 分）

A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
A Complete Binary Tree (CBT) is a tree that is completely filled, with the possible exception of the bottom level,
which is filled from left to right.
Now given a sequence of distinct non-negative integer keys, a unique BST can be constructed if it is required that
the tree must also be a CBT. You are supposed to output the level order traversal sequence of this BST.
Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (≤1000). 
Then N distinct non-negative integer keys are given in the next line. All the numbers in a line are separated by a space 
and are no greater than 2000.
Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding complete binary search tree.
All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.
Sample Input:

10
1 2 3 4 5 6 7 8 9 0
Sample Output:

6 3 8 1 5 7 9 0 2 4
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int comp(const int *a, const int *b)
{
  return *(int*)a - *(int*)b;
}
void solve(int* a, int Aleft, int Aright, int *b, int root)
{
  int n = Aright - Aleft + 1;
  if(!n) return;
  if(n==1){
    b[root] = a[Aleft];
    return;
  }
  int h = log(n)/log(2);
  int x = n - pow(2, h) + 1;
  x = x<pow(2, h-1)?x:pow(2, h-1);
  int L = pow(2, h-1) - 1 + x;
  b[root] = a[Aleft + L];
  solve(a, Aleft, Aleft+L-1, b, root*2+1);
  solve(a, Aleft+L+1, Aright, b, root*2+2);
}
int main()
{
	freopen("G:/Dec-Cpp/8.txt", "r", stdin); 
  int N, *a, *b; 
  scanf("%d\n", &N); 
  a = (int *)malloc(N * sizeof(int));
  b = (int *)malloc(N * sizeof(int));
  int i;
  for(i=0; i<N; i++)
    scanf("%d", a+i);
  qsort(a, N, sizeof(int), comp);
  solve(a, 0, N-1, b, 0);
  for(i=0; i<N; i++)
    printf("%s%d", i?" ":"", b[i]);
  return 0;
}
