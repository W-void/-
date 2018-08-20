//  搜索树的中序遍历是有序的
/*
1064 Complete Binary Search Tree (30)（30 分）

A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
A Complete Binary Tree (CBT) is a tree that is completely filled, with the possible exception of the bottom level, which is filled from 
left to right.
Now given a sequence of distinct non-negative integer keys, a unique BST can be constructed if it is required that the tree must also be 
a CBT. You are supposed to output the level order traversal sequence of this BST.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<=1000). Then N distinct non-
negative integer keys are given in the next line. All the numbers in a line are separated by a space and are no greater than 2000.
Output Specification:
For each test case, print in one line the level order traversal sequence of the corresponding complete binary search tree. All the 
numbers in a line must be separated by a space, and there must be no extra space at the end of the line.
Sample Input:
10
1 2 3 4 5 6 7 8 9 0
Sample Output:
6 3 8 1 5 7 9 0 2 4
*/
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

const int maxn = 1010;
int in[maxn];
vector<int> dat;
queue<int> q;
void inorder(int root, int n)
{
    if(root>=n)   return;
    inorder(root*2+1, n);
    in[root] = q.front();
    q.pop();
    inorder(root*2+2, n);
}

int main()
{
    int n, i, t;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &t);
        dat.push_back(t);
    }
    sort(dat.begin(), dat.end());
    for(i=0; i<n; i++)
        q.push(dat[i]);
    inorder(0, n);
    for(i=0; i<n; i++)
        printf("%s%d", i?" ":"", in[i]);
}
