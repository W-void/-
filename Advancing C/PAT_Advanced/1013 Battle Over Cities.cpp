//
/*
1013 Battle Over Cities (25)（25 分）

It is vitally important to have all the cities connected by highways in a war. If a city is occupied by the enemy, all the highways 
from/toward that city are closed. We must know immediately if we need to repair any other highways to keep the rest of the cities 
connected. Given the map of cities which have all the remaining highways marked, you are supposed to tell the number of highways need to 
be repaired, quickly.
For example, if we have 3 cities and 2 highways connecting city~1~-city~2~ and city~1~-city~3~. Then if city~1~ is occupied by the 
enemy, we must have 1 highway repaired, that is the highway city~2~-city~3~.
Input
Each input file contains one test case. Each case starts with a line containing 3 numbers N (&lt1000), M and K, which are the total 
number of cities, the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each 
describes a highway by 2 integers, which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. 
Finally there is a line containing K numbers, which represent the cities we concern.
Output
For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.
Sample Input
3 2 3
1 2
1 3
1 2 3
Sample Output
1
0
0
作者: CHEN, Yue
单位: PAT联盟
时间限制: 400 ms
内存限制: 64 MB
代码长度限制: 16 KB

*/
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int maxn = 1010;
vector<int> G[maxn];
int n, m, k, point;
int vis[maxn] = {0};
void DFS(int v)
{
    vis[v] = 1;
    int size = G[v].size(), i;
    for(i=0; i<size; i++){
        if(vis[G[v][i]] == 0 && G[v][i] != point)
            DFS(G[v][i]);
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    int i, j, a, b;
    for(i=0; i<m; i++){
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(i=0; i<k; i++){
        scanf("%d", &point);
        memset(vis, 0, sizeof(vis));
        int cnt = -1;
        for(j=1; j<=n; j++){
            if(!vis[j] && j!=point){
                DFS(j);
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
}
