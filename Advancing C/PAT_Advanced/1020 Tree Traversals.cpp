//  后序中序求层次
/*
1020 Tree Traversals (25)（25 分）

Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are 
supposed to output the level order traversal sequence of the corresponding binary tree.
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in 
the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line 
are separated by a space.
Output Specification:
For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line 
must be separated by exactly one space, and there must be no extra space at the end of the line.
Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:
4 1 6 3 5 7 2
*/
#include<stdio.h>
#include<queue>
using namespace std;

const int maxn = 35;
int pos[maxn], in[maxn];
typedef struct Node* Tree;
struct Node{
    int data;
    Tree left, right;
};
Tree creat(int posL, int posR, int inL, int inR)
{
    if(posL > posR)  return NULL;
    Tree T = new Node;
    T->data = pos[posR];
    int i;
    for(i=inL; i<=inR; i++){
        if(in[i] == pos[posR])  break;
    }
    i = i - inL;
    T->left = creat(posL, posL+i-1, inL, inL+i-1);
    T->right = creat(posL+i, posR-1, inL+i+1, inR);
    return T;
}

int main()
{
    int N, i;
    scanf("%d", &N);
    for(i=0; i<N; i++)
        scanf("%d", pos+i);
    for(i=0; i<N; i++)
        scanf("%d", in+i);
    Tree root = creat(0, N-1, 0, N-1);
    queue<Node*> Q;
    Q.push(root);
    int f = 1;
    while(!Q.empty()){
        root = Q.front();
        if(f) f=0;
        else  printf(" ");
        printf("%d", root->data);
        Q.pop();
        if(root->left!=NULL)  Q.push(root->left);
        if(root->right!=NULL) Q.push(root->right);
    }
  
}
