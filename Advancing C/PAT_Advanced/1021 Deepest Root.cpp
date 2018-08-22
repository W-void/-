// 先以1为根节点做一遍dfs找到最深的叶子节点的集合A，再从A中随便选一个结点做dfs，找到最深的结点集合B，A并B就是最终结果
/*
1021 Deepest Root (25)（25 分）

A graph which is connected and acyclic can be considered a tree. The height of the tree depends on the selected root. Now you are 
supposed to find the root that results in a highest tree. Such a root is called the deepest root.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the number of 
nodes, and hence the nodes are numbered from 1 to N. Then N-1 lines follow, each describes an edge by given the two adjacent nodes' 
numbers.
Output Specification:
For each test case, print each of the deepest roots in a line. If such a root is not unique, print them in increasing order of their 
numbers. In case that the given graph is not a tree, print "Error: K components" where K is the number of connected components in the 
graph.
Sample Input 1:
5
1 2
1 3
1 4
2 5
Sample Output 1:
3
4
5
Sample Input 2:
5
1 3
1 4
2 5
3 4
Sample Output 2:
Error: 2 components
*/
#include<cstdio>
#include<vector>
#include<set>
#include<string.h>
using namespace std;

const int maxn = 10010;
vector<int> G[maxn];
int vis[maxn] = {0}, n, maxDep = 0;
set<int> st, ans;

void dfs(int root, int depth)
{
    vis[root] = 1;
    depth++;
    if(depth>maxDep){
        maxDep = depth;
        st.clear();
        st.insert(root);
    }
    else if(depth == maxDep)
        st.insert(root);
    int size = G[root].size(), i;
    for(i=0; i<size; i++){
        if(!vis[G[root][i]])
            dfs(G[root][i], depth);
    }
}
int main()
{
    scanf("%d", &n);
    int i, a, b, cnt = 0;
    for(i=0; i<n-1; i++){
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i, 0);
            cnt++;
        }
    }
    if(cnt>1) printf("Error: %d components", cnt);
    else{
        memset(vis, 0, sizeof(vis));
        ans = st;
        set<int>::iterator it = st.begin();
        int root = *it;
        st.clear();
        dfs(root, 0);
        for(it=st.begin(); it!=st.end(); it++) //这里若是简化成for(; it!=st.end(); it++)测试点0会出错
            ans.insert(*it);
        for(it=ans.begin(); it!=ans.end(); it++)
            printf("%d\n", *it);
    }
}
