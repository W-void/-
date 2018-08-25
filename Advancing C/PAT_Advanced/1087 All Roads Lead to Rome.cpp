// Dijkstra
/*
1087 All Roads Lead to Rome（30 分）

Indeed there are many different tourist routes from our city to Rome. You are supposed to find your clients the route with the least 
cost while gaining the most happiness.
Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers N (2≤N≤200), the number of cities, 
and K, the total number of routes between pairs of cities; followed by the name of the starting city. The next N−1 lines each gives the 
name of a city and an integer that represents the happiness one can gain from that city, except the starting city. Then K lines follow, 
each describes a route between two cities in the format City1 City2 Cost. Here the name of a city is a string of 3 capital English 
letters, and the destination is always ROM which represents Rome.
Output Specification:

For each test case, we are supposed to find the route with the least cost. If such a route is not unique, the one with the maximum 
happiness will be recommanded. If such a route is still not unique, then we output the one with the maximum average happiness -- it is 
guaranteed by the judge that such a solution exists and is unique.
Hence in the first line of output, you must print 4 numbers: the number of different routes with the least cost, the cost, the 
happiness, and the average happiness (take the integer part only) of the recommanded route. Then in the next line, you are supposed to 
print the route in the format City1->City2->...->ROM.
Sample Input:

6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1
Sample Output:

3 3 195 97
HZH->PRS->ROM
*/
#include<stdio.h>
#include<map>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

const int maxn = 210;
const int inf = 1<<30;
int G[maxn][maxn], vis[maxn] = {0}, weight[maxn];
int d[maxn], hap[maxn], n_route[maxn] = {0}, n_city[maxn], pre[maxn];
int n, m;
map<string, int> city2index;
map<int, string> index2city;

void Dijkstra()
{
    fill(d, d+maxn, inf);
    d[0] = 0;
    n_city[0] = 0;
    n_route[0] = 1;
    hap[0] = 0;
    int i;
    for(i=0; i<n; i++){
        int u = -1, min = inf, j, v;
        for(j=0; j<n; j++)
            if(!vis[j] && min>d[j]){
                min = d[j];
                u = j;
            }
        if(u == -1) return;
        vis[u] = 1;
        for(v=0; v<n; v++){
            if(!vis[v] && G[u][v]!=inf){
                if(d[v] > d[u]+G[u][v]){
                    d[v] = d[u]+G[u][v];
                    hap[v] = hap[u] + weight[v];
                    n_city[v] = n_city[u] + 1;
                    n_route[v] = n_route[u];
                    pre[v] = u;
                }
                else if(d[v] == d[u]+G[u][v]){
                    n_route[v] += n_route[u];
                    if(hap[v] < hap[u] + weight[v]){
                        hap[v] = hap[u] + weight[v];
                        n_city[v] = n_city[u] + 1;
                        pre[v] = u;
                    }
                    else if(hap[v] == hap[u] + weight[v] && n_city[v] > n_city[u] + 1){
                        n_city[v] = n_city[u] + 1;
                        pre[v] = u;
                    }
                }
            }
        }
    }
}
void DFS(int u)
{
    if(u == 0){
        printf("%s", index2city[u].c_str());
        return;
    }
    DFS(pre[u]);
    printf("->%s", index2city[u].c_str());
}
int main()
{
    string start, a, b;
    cin >> n >> m >> start; //scanf("%d%d %s", &n, &m, start);
    city2index[start] = 0;
    index2city[0] = start;
    int i, w;
    for(i=1; i<n; i++){
        cin >> a >> w; //scanf("%s %d", a, &w);
        city2index[a] = i;
        index2city[i] = a;
        weight[i] = w;
    }
    fill(G[0], G[0]+maxn*maxn, inf);
    for(i=0; i<m; i++){
        cin >> a >> b >> w; //scanf("%s %s %d", a, b, &w);
        int u = city2index[a];
        int v = city2index[b];
        G[u][v] = G[v][u] = w;
    }
    Dijkstra();
    int u = city2index["ROM"];
    printf("%d %d %d %d\n", n_route[u], d[u], hap[u], hap[u]/n_city[u]);
    DFS(u);
}
