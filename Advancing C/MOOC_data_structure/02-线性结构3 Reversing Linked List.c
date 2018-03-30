//
/*
02-线性结构3 Reversing Linked List（25 分）
Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. 
For example, given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4; if K=4, you must output 4→3→2→1→5→6.
Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (≤10
​5
​​ ) which is the total number of nodes, and a positive K (≤N) which is the length of the sublist to be reversed. 
The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.
Then N lines follow, each describes a node in the format:
Address Data Next
where Address is the position of the node, Data is an integer, and Next is the position of the next node.
Output Specification:

For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.
Sample Input:

00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
Sample Output:

00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/
#include<stdio.h>
struct node{
	int data, next;
}a[100000];
int main()
{
	//freopen("G:\\Dec-Cpp/7.txt", "r", stdin);
	int head, new, old, tmp, i, n, k;
	scanf("%d%d%d\n", &head, &n, &k);
	int add, dat, nex;
	for(i=0; i<n; i++){
		scanf("%d%d%d\n", &add, &dat, &nex);
		a[add].data = dat, a[add].next = nex;
	}

	int headd = head, flag = 1, headdd;
	for(i=1; a[headd].next != -1; headd = a[headd].next, i++);//因为有不在链子里的结点，不懂为什么没有这一步就会出错
	headd =head, new = head, n = i;
	if(k!=1){
		while(k<=n){
		
		old = a[new].next;
        // 反转节点
		for(i=1; i<k; i++){
			tmp = a[old].next;
			a[old].next = new;
			new = old;
			old = tmp;
		}
        // 将反转后的节点与前后连起来
		if(flag) {
			head = new;
			a[headd].next = old;
			flag = 0;
		}
		else{
			headdd = a[headd].next;
			a[headdd].next = old;			
			a[headd].next = new;
			headd = headdd;
		}
		new = old;	
		n -= k;
	}
	}
	
	headd = head;
	while(a[headd].next != -1){
		printf("%05d %d %05d\n", headd, a[headd].data, a[headd].next);
		headd = a[headd].next;
	}
	printf("%05d %d %d\n", headd, a[headd].data, a[headd].next);	
	return 0;
}
