// fill 不能对结构体赋值
/*
1097 Deduplication on a Linked List (25)（25 分）

Given a singly linked list L with integer keys, you are supposed to remove the nodes with duplicated absolute values of the keys. That 
is, for each value K, only the first node of which the value or absolute value of its key equals K will be kept. At the mean time, all 
the removed nodes must be kept in a separate list. For example, given L being 21→-15→-15→-7→15, you must output 21→-15→-7, and the 
removed list -15→15.
Input Specification:
Each input file contains one test case. For each case, the first line contains the address of the first node, and a positive N (<= 
10^5^) which is the total number of nodes. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.
Then N lines follow, each describes a node in the format:
Address Key Next
where Address is the position of the node, Key is an integer of which absolute value is no more than 10^4^, and Next is the position of 
the next node.
Output Specification:
For each case, output the resulting linked list first, then the removed list. Each node occupies a line, and is printed in the same 
format as in the input.
Sample Input:
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
Sample Output:
00100 21 23854
23854 -15 99999
99999 -7 -1
00000 -15 87654
87654 15 -1
*/
#include<stdio.h>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

struct Node{
    int add, dat, nex, ord;
}a[100010];
bool cmp(Node a, Node b)
{
    return a.ord < b.ord;
}
int main()
{
    int n, head, i, add;
    scanf("%d%d", &head, &n);
    //fill(a, a+100010, 100010 * 2);
    for(i=0; i<100010; i++){
        a[i].ord = 100010 * 2;
    }
    set<int> st;
    for(i=0; i<n; i++){
        scanf("%d", &add);
        a[add].add = add;
        scanf("%d%d", &a[add].dat, &a[add].nex);
    }
    int p = head, ord1 = 0, ord2 = 100010;
    set<int>::iterator it = st.end();
    while(p != -1){
        if(st.find(abs(a[p].dat)) == it){
            a[p].ord = ord1++;
            st.insert(abs(a[p].dat));
        }
        else{
            a[p].ord = ord2++;
        }
        p = a[p].nex;
    }
    sort(a, a+100010, cmp);
    int cnt = ord1 + ord2 - 100010;
    for(i=0; i<cnt; i++){
        if(i==ord1-1 || i==cnt-1)
            printf("%05d %d -1\n", a[i].add, a[i].dat);
        else
            printf("%05d %d %05d\n", a[i].add, a[i].dat, a[i+1].add);
    }
    return 0;
}
