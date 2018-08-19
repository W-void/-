/*
1004 Counting Leaves (30)（30 分）

A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.
Input
Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), 
the number of non-leaf nodes. Then M lines follow, each in the format:
ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit 
ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.
Output
For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. 
The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.
The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 
0 leaf node; and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.
Sample Input
2 1
01 1 02
Sample Output
0 1
*/
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 100;
vector<int> node[maxn];
vector<int> ans;
void BFS(int root)
{
    queue<int> q;
    q.push(root);
    int j = 0, num = 1, cnt = 0;
    while(!q.empty()){
        root = q.front();
        int size = node[root].size(), i;
        if(size){
            cnt++;
            for(i=0; i<size; i++){
                q.push(node[root][i]);
            }
        }
        q.pop();
        j++;
        if(j == num){
            ans.push_back(num-cnt);
            j = 0;
            cnt = 0;
            num = q.size();
        }
    }
}
int main()
{
    int n, m, i, j, k, root, child;
    scanf("%d%d", &n, &m);
    for(i=0; i<m; i++){
        scanf("%d%d", &root, &k);
        for(j=0; j<k; j++){
            scanf("%d", &child);
            node[root].push_back(child);
        }
    }
    BFS(1);
    k = ans.size();
    for(i=0; i<k; i++)
        printf("%s%d", i?" ":"", ans[i]);
}
