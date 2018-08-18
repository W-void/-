//
/*
1102 Invert a Binary Tree（25 分）

The following is from Max Howell @twitter:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can't invert a binary tree on a whiteboard so fuck off.
Now it's your turn to prove that YOU CAN invert a binary tree!
Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (≤10) which is the total number of 
nodes in the tree -- and hence the nodes are numbered from 0 to N−1. Then N lines follow, each corresponds to a node from 0 to N−1, and 
gives the indices of the left and right children of the node. If the child does not exist, a - will be put at the position. Any pair of 
children are separated by a space.
Output Specification:

For each test case, print in the first line the level-order, and then in the second line the in-order traversal sequences of the 
inverted tree. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.
Sample Input:

8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
Sample Output:

3 7 2 6 4 0 5 1
6 5 7 4 3 2 0 1
*/
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 12;
struct node{
    int left, right;
}T[maxn];
int flag[maxn] = {0};
vector<int> lev, in;
queue<int> q;
void level(int root)
{
    q.push(root);
    while(!q.empty()){
        root = q.front();
        q.pop();
        lev.push_back(root);
        if(T[root].right!=12) q.push(T[root].right);
        if(T[root].left!=12) q.push(T[root].left);
    }
}
void ino(int root)
{
    if(T[root].right!=12) ino(T[root].right);
    in.push_back(root);
    if(T[root].left!=12) ino(T[root].left);
}
void print(vector<int> &vt)
{
	int i; 
    for(i=0; i<vt.size(); i++)
      printf("%d%s", vt[i], i==vt.size()-1?"\n":" ");
}
int main()
{  
    node* tmp = new node;
    int N, i;
    scanf("%d\n", &N);
    char a, b;
    for(i=0; i<N; i++){
        scanf("%c %c\n", &a, &b);
        tmp->left = a=='-'?12:a-'0';
        tmp->right = b=='-'?12:b-'0';
        T[i] = *tmp;
        flag[tmp->left] = 1;
        flag[tmp->right] = 1;
    }
    for(i=0; i<N; i++)  if(flag[i]==0)
        break;
    level(i);
    ino(i);
    print(lev);
    print(in);
}
