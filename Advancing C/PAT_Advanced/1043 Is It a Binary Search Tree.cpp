//  二叉搜索树的遍历， 要判断这个先序遍历是不是对应着搜索树，就先按他给的先序遍历建一棵搜索树，再先序遍历它，看结果与题目给的一不一样
/*
1043 Is It a Binary Search Tree (25)（25 分）

A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
If we swap the left and right subtrees of every node, then the resulting tree is called the Mirror Image of a BST.
Now given a sequence of integer keys, you are supposed to tell if it is the preorder traversal sequence of a BST or the mirror image of 
a BST.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<=1000). Then N integer keys are 
given in the next line. All the numbers in a line are separated by a space.
Output Specification:
For each test case, first print in a line "YES" if the sequence is the preorder traversal sequence of a BST or the mirror image of a 
BST, or "NO" if not. Then if the answer is "YES", print in the next line the postorder traversal sequence of that tree. All the numbers 
in a line must be separated by a space, and there must be no extra space at the end of the line.
Sample Input 1:
7
8 6 5 7 10 8 11
Sample Output 1:
YES
5 7 6 8 11 10 8
Sample Input 2:
7
8 10 11 8 6 7 5
Sample Output 2:
YES
11 8 10 7 5 6 8
Sample Input 3:
7
8 6 8 5 10 9 11
Sample Output 3:
NO
*/
#include<stdio.h>
#include<vector>
using namespace std;

struct node{
    int data;
    node *left, *right;
};
node* insert(node* root, int tmp)
{
    if(root == NULL){
        root = new node;
        root->data = tmp;
        root->left = root->right = NULL;
    }
    else{
        if(tmp<root->data)
            root->left = insert(root->left, tmp);
        else
            root->right = insert(root->right, tmp);
    }
    return root;
}
vector<int> vt, pre, preM, pos, posM;
void preO(node* root)
{
    pre.push_back(root->data);
    if(root->left) preO(root->left);
    if(root->right) preO(root->right);
}
void preMO(node* root)
{
    preM.push_back(root->data);
    if(root->right) preMO(root->right);
    if(root->left) preMO(root->left);
}
void posO(node* root)
{
    if(root->left) posO(root->left);
    if(root->right) posO(root->right);
    pos.push_back(root->data);
}
void posMO(node* root)
{
    if(root->right) posMO(root->right);
    if(root->left) posMO(root->left);
    posM.push_back(root->data);
}
int main()
{
    int N, i, tmp;
    scanf("%d", &N);
    node* root = NULL;
    for(i=0; i<N; i++){
        scanf("%d", &tmp);
        vt.push_back(tmp);
        root = insert(root, tmp);
    }
    preO(root);
    preMO(root);
    if(vt == pre){
        printf("YES\n");
        posO(root);
        for(i=0; i<pos.size(); i++)
            printf("%s%d", i?" ":"", pos[i]);
    }
    else if(vt == preM){
        printf("YES\n");
        posMO(root);
        for(i=0; i<posM.size(); i++)
            printf("%s%d", i?" ":"", posM[i]);
    }
    else  printf("NO");
}
