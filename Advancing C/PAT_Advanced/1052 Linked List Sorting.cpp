//  不懂为什么没有有效节点要输出0 -1
/*
1052 Linked List Sorting (25)（25 分）

A linked list consists of a series of structures, which are not necessarily adjacent in memory. We assume that each structure contains 
an integer key and a Next pointer to the next structure. Now given a linked list, you are supposed to sort the structures according to 
their key values in increasing order.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive N (< 10^5^) and an address of the head node, 
where N is the total number of nodes in memory and the address of a node is a 5-digit positive integer. NULL is represented by -1.
Then N lines follow, each describes a node in the format:
Address Key Next
where Address is the address of the node in memory, Key is an integer in [-10^5^, 10^5^], and Next is the address of the next node. It 
is guaranteed that all the keys are distinct and there is no cycle in the linked list starting from the head node.
Output Specification:
For each test case, the output format is the same as that of the input, where N is the total number of nodes in the list and all the 
nodes must be sorted order.
Sample Input:
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345
Sample Output:
5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1
*/
#include<stdio.h>
#include<stdlib.h>
#include<map> 
using namespace std;

typedef struct Node* pNode;
struct Node{
    int add, dat, nex, flag;
}node[100010];
int cmp(const void* a, const void* b)
{
    pNode x = (pNode)a;
    pNode y = (pNode)b;
    if(!x->flag || !y->flag)
        return y->flag - x->flag;
    return  x->dat - y->dat;
}
int main()
{	
    int N, head, i;
    scanf("%d%d", &N, &head);
    map<int, int> mp;
    for(i=0; i<N; i++){
        scanf("%d%d%d", &node[i].add, &node[i].dat, &node[i].nex);
        node[i].flag = 0;
        mp[node[i].add] = i;
    }
    int cnt = 0, tmp;
    while(head != -1){
    	tmp = mp.find(head)->second;
        node[tmp].flag = 1;
        head = node[tmp].nex;
        cnt++;
    }
    qsort(node, N, sizeof(node[0]), cmp);
    if(!cnt){
        printf("0 -1\n");
    }else{
        printf("%d %05d\n", cnt, node[0].add);
        for(i=0; i<cnt-1; i++)
            printf("%05d %d %05d\n", node[i].add, node[i].dat, node[i+1].add);
        printf("%05d %d -1\n", node[i].add, node[i].dat);
    }
    
}
