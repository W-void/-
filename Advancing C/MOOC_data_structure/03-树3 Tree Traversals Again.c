//前序中序求后序
/*
03-树3 Tree Traversals Again（25 分）
An inorder binary tree traversal can be implemented in a non-recursive way with a stack. 
For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed,
the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). 
Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. 
Your task is to give the postorder traversal sequence of this tree.

Figure 1
Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (≤30) 
which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N). 
Then 2N lines follow, each describes a stack operation in the format: "Push X" where X is the index of the node 
being pushed onto the stack; or "Pop" meaning to pop one node from the stack.
Output Specification:

For each test case, print the postorder traversal sequence of the corresponding tree in one line. 
A solution is guaranteed to exist. All the numbers must be separated by exactly one space, 
and there must be no extra space at the end of the line.
Sample Input:

6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
Sample Output:

3 4 2 6 5 1
*/
#include<stdio.h>
#include<stdlib.h>
#define Max 30
int pre[30], in[30], post[30];

typedef struct snode* Stack;
struct snode{
  int a[30];
  int top;
};
Stack S;
void Push(int k)
{
  S->a[S->top++] = k;
}
int Pop()
{
  return S->a[--S->top];
}
void solve(int preL, int inL, int postL, int n)//preL, inL, postL分别为前中后数组的首地址，n为树上结点的个数
{
    if(n==0) return;
    if(n==1) {post[postL] = pre[preL]; return;}
    int root = pre[preL], i;
    post[postL+n-1] = pre[preL];//将前序的根节点放到后序的最后位置
    for(i=0; i<n; i++){
      if(in[inL+i]==root) break;
    }
    int L = i, R = n - i -1;
    solve(preL+1, inL, postL, L);//遍历左子树
    solve(preL+L+1, inL+L+1, postL+L, R);//遍历右子树
}
int main()
{
    S = (Stack)malloc(sizeof(struct snode));
    S->top = 0;
    int N, i, i_pre = 0, i_in = 0;
    char c[5];
    scanf("%d\n", &N);
    for(i=0; i<2*N; i++){
          scanf("%s", c);
          if(c[1]=='u'){
                scanf("%d\n", &pre[i_pre++]);
                Push(pre[i_pre-1]);
          }
          else
                in[i_in++] = Pop();
    }
    solve(0, 0, 0, N);
    for(i=0; i<N; i++)
        printf("%s%d", i?" ":"", post[i]);//我的编辑器还有pta通不过%c形式的'\0'
    return 0;
}
