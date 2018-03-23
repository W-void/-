// scanf时，%d和%d\n, %c %c\n和%c%c有很大差别
/*
03-树2 List Leaves（25 分）
Given a tree, you are supposed to list all the leaves in the order of top down, and left to right.
Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (≤10) which is 
the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N−1. Then N lines follow, 
each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, 
a "-" will be put at the position. Any pair of children are separated by a space.
Output Specification:

For each test case, print in one line all the leaves' indices in the order of top down, and left to right. 
There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.
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

4 1 5
*/
#include<stdio.h>
#define maxsize 10
struct tnode{
	int left, right;
}t[10];
typedef struct tnode* Tree;
int BuildTree(Tree t)
{
	int N, i, check[10]={0};
	scanf("%d\n", &N);
	char l, r;
	for(i=0; i<N; i++){
		scanf("%c %c\n", &l, &r);
		t[i].left = l=='-'?-1:l-'0';//printf("%d\n", t[i].left);
		if(t[i].left != -1) check[t[i].left] = 1;
		t[i].right = r=='-'?-1:r-'0';//printf("%d\n", t[i].right);
		if(t[i].right != -1) check[t[i].right] = 1;
	}
	for(i=0; i<N && check[i]; i++);
	return i;
}
typedef struct qnode{
	int front , rear ;
	int data[maxsize];
}*Queue;
void addQ(Queue q, int r)
{
	if((q->rear+1)%maxsize == q->front)
		return;
	q->rear = ++q->rear % maxsize;
	q->data[q->rear] = r;
}
int isEmpty(Queue q){
	return q->front == q->rear;
}
int deleteQ(Queue q){
	if(!isEmpty(q)){
		q->front = ++q->front % maxsize;
		return q->data[q->front];
	}
}
int main()
{
	//freopen("G:\\Dec-Cpp\\7.txt", "r", stdin);
	int r = BuildTree(t);
	Queue q = (Queue)malloc(sizeof(struct qnode));
	q->rear = q->front = 0;
	addQ(q, r);
	int n, f=1;
	while(!isEmpty(q)){
		n = deleteQ(q);//printf("%d", n);
		if(t[n].left==-1 && t[n].right==-1){
			if(!f){
				putchar(' ');
				f = 0;
			}
			printf("%d", n);
		
		}
		else{
			if(t[n].left!=-1) addQ(q, t[n].left);
			if(t[n].right!=-1) addQ(q, t[n].right);
		}
	}
	return 0;
}
