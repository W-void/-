//  BFS
/*
1076 Forwards on Weibo（30 分）

Weibo is known as the Chinese version of Twitter. One user on Weibo may have many followers, and may follow many other users as well. 
Hence a social network is formed with followers relations. When a user makes a post on Weibo, all his/her followers can view and forward 
his/her post, which can then be forwarded again by their followers. Now given a social network, you are supposed to calculate the 
maximum potential amount of forwards for any specific user, assuming that only L levels of indirect followers are counted.
Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: N (≤1000), the number of users; and 
L (≤6), the number of levels of indirect followers that are counted. Hence it is assumed that all the users are numbered from 1 to N. 
Then N lines follow, each in the format:
M[i] user_list[i]
where M[i] (≤100) is the total number of people that user[i] follows; and user_list[i] is a list of the M[i] users that followed by 
user[i]. It is guaranteed that no one can follow oneself. All the numbers are separated by a space.
Then finally a positive K is given, followed by K UserID's for query.
Output Specification:

For each UserID, you are supposed to print in one line the maximum potential amount of forwards this user can triger, assuming that 
everyone who can view the initial post will forward it once, and that only L levels of indirect followers are counted.
Sample Input:

7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
Sample Output:

4
5
*/
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int maxn = 1010;
int n, L;
struct node{
    int id, layer;
    node(int _id, int _layer): id(_id), layer(_layer) {}
};
vector<int> G[maxn];
queue<node> q;
int vis[maxn];

int bfs(int root)
{
    memset(vis, 0, sizeof(vis));
    q.push(node(root, 0));
    vis[root] = 1;
    int cnt = 0;
    while(!q.empty()){
        node tmp = q.front();
        q.pop();
        if(tmp.layer < L){
            root = tmp.id;
            int i, size = G[root].size();
            for(i=0; i<size; i++){
                if(vis[G[root][i]] == 0){
                    q.push(node(G[root][i], tmp.layer+1));
                    vis[G[root][i]] = 1;
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int main()
{
    scanf("%d%d", &n, &L);
    int i, j, k, tmp;
    for(i=1; i<=n; i++){
        scanf("%d", &k);
        for(j=0; j<k; j++){
            scanf("%d", &tmp);
            G[tmp].push_back(i);
        }
    }
    scanf("%d", &k);
    for(j=0; j<k; j++){
        scanf("%d", &tmp);
        int num = bfs(tmp);
        printf("%d\n", num);
    }
}
