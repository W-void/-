/*
1066 Root of AVL Tree (25)（25 分）

An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most 
one; if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation 
rules.
    
Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<=20) which is the total number of 
keys to be inserted. Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.
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

typedef struct avlnode* tree;
struct avlnode{
    int data, height;
    tree left, right;
};

int max(int a, int b)
{
    return a>b?a:b;
}
int getH(tree t)
{
    if(t == NULL) return 0;
    int leftH = t->left ? t->left->height : 0;
    int rightH = t->right ? t->right->height : 0;
    return max(leftH, rightH)+1;
}
tree LL(tree a)
{
    tree b = a->left;
    a->left = b->right;
    b->right = a;
    a->height = getH(a);
    b->height = getH(b);
    return b;
}
tree RR(tree a)
{
    tree b = a->right;
    a->right = b->left;
    b->left = a;
    a->height = getH(a);
    b->height = getH(b);
    return b;    
}
tree LR(tree a)
{
    a->left = RR(a->left);
    return LL(a);
}
tree RL(tree a)
{
    a->right = LL(a->right);
    return RR(a);
}
tree insert(tree t, int data)
{
    if(!t){
        t = (tree)malloc(sizeof(struct avlnode));
        t->data = data;
        t->left = t->right = NULL;
    }
    else{
        if(data < t->data){
            t->left = insert(t->left, data);
            int leftH = getH(t->left), rightH = getH(t->right);
            if(leftH - rightH == 2){
                if(data < t->left->data)
                    t = LL(t);
                else
                    t = LR(t);
            }
        }
        else{
            t->right = insert(t->right, data);
            int leftH = getH(t->left), rightH = getH(t->right);
            if(leftH - rightH == -2){
                if(data < t->right->data)
                    t = RL(t);
                else
                    t = RR(t);
            }
        }
    }
    t->height = getH(t);
    return t;
}
int main()
{
    int n, i, tmp;
    scanf("%d", &n);
    tree T = NULL;
    for(i=0; i<n; i++){
        scanf("%d", &tmp);
        T = insert(T, tmp);
    }
    printf("%d", T->data);
}
