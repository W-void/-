//  Dijkstra + DFS
/*
1018 Public Bike Management (30)（30 分）

There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world. One may rent a 
bike at any station and return it to any other stations in the city.

The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the stations. A station is said to be in perfect 
condition if it is exactly half-full. If a station is full or empty, PBMC will collect or send bikes to adjust the condition of that 
station to perfect. And more, all the stations on the way will be adjusted as well.

When a problem station is reported, PBMC will always choose the shortest path to reach that station. If there are more than one shortest 
path, the one that requires the least number of bikes sent from PBMC will be chosen.


Figure 1
Figure 1 illustrates an example. The stations are represented by vertices and the roads correspond to the edges. The number on an edge 
is the time taken to reach one end station from another. The number written inside a vertex S is the current number of bikes stored at 
S. Given that the maximum capacity of each station is 10. To solve the problem at S3, we have 2 different shortest paths:

1. PBMC -> S1 -> S3. In this case, 4 bikes must be sent from PBMC, because we can collect 1 bike from S1 and then take 5 bikes to S3, so 
that both stations will be in perfect conditions.

2. PBMC -> S2 -> S3. This path requires the same time as path 1, but only 3 bikes sent from PBMC and hence is the one that will be 
chosen.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 numbers: Cmax (<= 100), always an even number, is the 
maximum capacity of each station; N (<= 500), the total number of stations; Sp, the index of the problem station (the stations are 
numbered from 1 to N, and PBMC is represented by the vertex 0); and M, the number of roads. The second line contains N non-negative 
numbers Ci (i=1,...N) where each Ci is the current number of bikes at Si respectively. Then M lines follow, each contains 3 numbers: Si, 
Sj, and Tij which describe the time Tij taken to move betwen stations Si and Sj. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print your results in one line. First output the number of bikes that PBMC must send. Then after one space, output 
the path in the format: 0->S1->...->Sp. Finally after another space, output the number of bikes that we must take back to PBMC after the 
condition of Sp is adjusted to perfect.

Note that if such a path is not unique, output the one that requires minimum number of bikes that we must take back to PBMC. The judge's 
data guarantee that such a path is unique.

Sample Input:
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
Sample Output:
3 0->2->3 0

*/
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

const int inf = 1<<30;
const int maxn = 510;
int cmax, sp, n, m, minNeed = inf, minRemain = inf;
int G[maxn][maxn], weight[maxn];
int d[maxn], vis[maxn] = {0};
vector<int> path[maxn], tmPath, fiPath;
void Dijkstra()
{
    fill(d, d+n+1, inf);
    d[0] = 0;
    int i, j;
    for(i=0; i<=n; i++){
        int min = inf, u = -1, v;
        for(j=0; j<=n; j++){
            if(!vis[j] && d[j]<min){
                u = j;
                min = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = 1;
        for(v=0; v<=n; v++){
            if(!vis[v] && G[u][v]!=inf){
                if(d[v] > G[u][v] + d[u]){
                    d[v] = G[u][v] + d[u];
                    path[v].clear();
                    path[v].push_back(u);
                }else if(d[v] == G[u][v] + d[u]){
                    path[v].push_back(u);
                }
            }
        }
    }
}
void DFS(int v)
{
    tmPath.push_back(v);
    if(v == 0){
        int need = 0, remain = 0, i;
        for(i=tmPath.size()-2; i>=0; i--){
            int id = tmPath[i];
            if(weight[id] > cmax)
                remain += weight[id] - cmax;
            else{
                if(remain > cmax - weight[id])
                    remain -= cmax - weight[id];
                else{
                    need += cmax - weight[id] - remain;
                    remain = 0;
                }
            }
        }
        if(need < minNeed){
            minNeed = need;
            fiPath = tmPath;
            minRemain = remain;
        }
        else if(need == minNeed && minRemain > remain){
            minRemain = remain;
            fiPath = tmPath;
        }
    }
    else{
        int i, size = path[v].size();
        for(i=0; i<size; i++)
            DFS(path[v][i]);
    }
    tmPath.pop_back();
}
int main()
{
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    cmax /= 2;
    int i, a, b, w;
    for(i=1; i<=n; i++)
        scanf("%d", weight+i);
    fill(G[0], G[0]+maxn*maxn, inf);
    for(i=0; i<m; i++){
        scanf("%d%d%d", &a, &b, &w);
        G[a][b] = G[b][a] = w;
    }
    Dijkstra();
    DFS(sp);
    printf("%d ", minNeed);
    for(i=fiPath.size()-1; i>=0; i--)
        printf("%d%s", fiPath[i], i?"->":" ");
    printf("%d", minRemain);
}
