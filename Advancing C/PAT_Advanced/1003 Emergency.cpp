// Dijkstra算法
/*
1003 Emergency (25)（25 分）

As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities 
connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the 
map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and 
at the mean time, call up as many hands on the way as possible.
Input
Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of 
cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that 
you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. 
Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the 
length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.
Output
For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of 
rescue teams you can possibly gather.\ All the numbers in a line must be separated by exactly one space, and there is no extra space 
allowed at the end of a line.
Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4
*/
#include<stdio.h>
#include<string>
using namespace std;

const int INF = 1<<30;
const int maxn = 510;

int G[maxn][maxn], vis[maxn] = {0}, weight[maxn];//weight[]存每个节点的点权值
int n, m, c1, c2;
int num[maxn] = {0}, w[maxn] = {0}, d[maxn]; // num[]存最短路径个数，w[]存最大搜救队数，d[]存每个结点到根节点距离

void Dijkstra()
{
    fill(d, d+n, INF);
    d[c1] = 0;
    num[c1] = 1;
    w[c1] = weight[c1];
    int i, j;
    for(i=0; i<n; i++){
        int min = INF, u = -1;
        for(j=0; j<n; j++){   //找到未访问结点中距离c1最近的结点
            if(!vis[j] && d[j] < min){
                min = d[j];
                u = j;
            }
        }
        if(u == -1)  return; //不存在未访问结点，即图非连通
        vis[u] = 1;
        for(j=0; j<n; j++){
            if(!vis[j] && G[u][j] <INF){ //处理u的每个邻接点
                if(G[u][j] + d[u] < d[j]){ // c1到u再到j的路线比c1直接到j的路线更短
                    d[j] = G[u][j] + d[u];
                    w[j] = w[u] + weight[j]; //c1到w的搜救队总数等于c1到u的搜救队总数加w的点权值
                    num[j] = num[u]; //c1到j的路线数等于c1到u的路线数
                }
                else if(G[u][j] + d[u] == d[j]){// c1到u再到j的路线比c1直接到j的路线等距
                    num[j] += num[u];
                    if(w[j] < w[u] + weight[j]){ //距离相同，但这条线路的搜救队更多
                        w[j] = w[u] + weight[j];
                    }
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    int i, a, b, tmp;
    for(i=0; i<n; i++)
        scanf("%d", weight+i);
    fill(G[0], G[0] + maxn*maxn, INF);
    for(i=0; i<m; i++){
        scanf("%d%d%d", &a, &b, &tmp);
        G[a][b] = G[b][a] = tmp;
    }
    Dijkstra();
    printf("%d %d", num[c2], w[c2]);
}
