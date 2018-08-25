// 求顶点间距离时，一定要初始化邻接矩阵
/*
1072 Gas Station（30 分）

A gas station has to be built at such a location that the minimum distance between the station and any of the residential housing is as 
far away as possible. However it must guarantee that all the houses are in its service range.

Now given the map of the city and several candidate locations for the gas station, you are supposed to give the best recommendation. If 
there are more than one solution, output the one with the smallest average distance to all the houses. If such a solution is still not 
unique, output the one with the smallest index number.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 positive integers: N (<= 103), the total number of 
houses; M (<= 10), the total number of the candidate locations for the gas stations; K (<= 104), the number of roads connecting the 
houses and the gas stations; and DS, the maximum service range of the gas station. It is hence assumed that all the houses are numbered 
from 1 to N, and all the candidate locations are numbered from G1 to GM.

Then K lines follow, each describes a road in the format
P1 P2 Dist
where P1 and P2 are the two ends of a road which can be either house numbers or gas station numbers, and Dist is the integer length of 
the road.

Output Specification:

For each test case, print in the first line the index number of the best location. In the next line, print the minimum and the average 
distances between the solution and all the houses. The numbers in a line must be separated by a space and be accurate up to 1 decimal 
place. If the solution does not exist, simply output “No Solution”.

Sample Input 1:

4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2

Sample Output 1:

G1
2.0 3.3

Sample Input 2:

2 1 2 10
1 G1 9
2 G1 20
Sample Output 2:
No Solution
*/
#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 1020;
const int inf = 1<<30;
int n, m, k, ds;
int G[maxn][maxn], vis[maxn] = {0}, d[maxn];

int getId(char* c)
{
    int i;
    if(c[0] == 'G') {
        sscanf(c, "%*c%d", &i);
        i += n;
    }
    else sscanf(c, "%d", &i);
    return i;
}
void Dijkstra(int s)
{
    fill(d, d+n+m+1, inf);
    d[s] = 0;
    int i;
    for(i=1; i<=n+m; i++){
        int u = -1, min = inf, j, v;
        for(j=1; j<=n+m; j++)
            if(!vis[j] && d[j]<min){
                u = j;
                min = d[j];
            }
        if(u == -1) return;
        vis[u] = 1;
        for(v=1; v<=n+m; v++)
            if(!vis[v] && G[u][v]!=inf && d[v] > d[u] + G[u][v])
                d[v] = d[u] + G[u][v];
    }
}

int main()
{
    scanf("%d%d%d%d\n", &n, &m, &k, &ds);
    int i, j, w;
    char a[5], b[5];
    fill(G[0], G[0] + maxn*maxn, inf);
    for(i=0; i<k; i++){
        scanf("%s %s %d\n", a, b, &w);
        int u = getId(a);
        int v = getId(b);
        G[u][v] = G[v][u] = w; 
    }
    double ansAvg = inf, ansD = -1;
    int ansId = -1;
    for(i=1; i<=m; i++){
        fill(vis, vis+maxn, 0);
        Dijkstra(n+i);
        double avg = 0, minD = inf;
        for(j=1; j<=n; j++){
            if(d[j] > ds){
                minD = -1;
                break;
            }
            if(minD > d[j]) minD = d[j];
            avg += d[j];
        }
        if(minD == -1) continue;
        if(ansD < minD){
            ansD = minD;
            ansAvg = avg;
            ansId = i;
        }
        else if(ansD == minD && ansAvg > avg){
            ansAvg = avg;
            ansId = i;
        }
    }
    if(ansId == -1) printf("No Solution");
    else  printf("G%d\n%.1f %.1f", ansId, ansD, ansAvg/n);

}
