//  push的次序为先序遍历，pop的次序为中序遍历
/*
1086 Tree Traversals Again (25)（25 分）

An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, suppose that when a 6-node binary 
tree (with the keys numbered from 1 to 6) is traversed, the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); 
pop(); pop(); push(5); push(6); pop(); pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of 
operations. Your task is to give the postorder traversal sequence of this tree.
\ Figure 1
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<=30) which is the total number of 
nodes in a tree (and hence the nodes are numbered from 1 to N). Then 2N lines follow, each describes a stack operation in the format: 
"Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.
Output Specification:
For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is guaranteed to exist. All 
the numbers must be separated by exactly one space, and there must be no extra space at the end of the line.
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
#include<vector>
#include<stack>
using namespace std;

stack<int> s;
vector<int> pre, in, post;
struct node{
    int data;
    node* left, *right;
};
node* creat(int preL, int preR, int inL, int inR)
{
    if(preL>preR) return NULL;
    node* t = new node;
    t->data = pre[preL];
    int i;
    for(i=inL; i<=inR; i++)  if(in[i] == t->data)
        break;
    i -= inL;
    t->left = creat(preL+1, preL+i, inL, inL+i-1);
    t->right = creat(preL+i+1, preR, inL+i+1, inR);
    return t;
}
void pos(node* root)
{
    if(root->left) pos(root->left);
    if(root->right) pos(root->right);
    post.push_back(root->data);
}
int main()
{
    int N, i, dat;
    char c[5];
    scanf("%d", &N);
    for(i=0; i<N*2; i++){
        scanf("%s", c);
        if(c[1]=='u'){
            scanf("%d\n", &dat);
            pre.push_back(dat);
            s.push(dat);
        }
        else{
            in.push_back(s.top());
            s.pop();
        }
    }
    node* root = creat(0, N-1, 0, N-1);
    pos(root);
    for(i=0; i<N; i++)
        printf("%s%d", i?" ":"", post[i]);
}
