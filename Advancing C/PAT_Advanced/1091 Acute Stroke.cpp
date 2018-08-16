//  BFS
/*
1091 Acute Stroke (30)（30 分）

One important factor to identify acute stroke (急性脑卒中) is the volume of the stroke core. Given the results of image analysis in which 
the core regions are identified in each MRI slice, your job is to calculate the volume of the stroke core.
Input Specification:
Each input file contains one test case. For each case, the first line contains 4 positive integers: M, N, L and T, where M and N are the 
sizes of each slice (i.e. pixels of a slice are in an M by N matrix, and the maximum resolution is 1286 by 128); L (<=60) is the number 
of slices of a brain; and T is the integer threshold (i.e. if the volume of a connected core is less than T, then that core must not be 
counted).
Then L slices are given. Each slice is represented by an M by N matrix of 0's and 1's, where 1 represents a pixel of stroke, and 0 means 
normal. Since the thickness of a slice is a constant, we only have to count the number of 1's to obtain the volume. However, there might 
be several separated core regions in a brain, and only those with their volumes no less than T are counted. Two pixels are "connected" 
and hence belong to the same region if they share a common side, as shown by Figure 1 where all the 6 red pixels are connected to the 
blue one.
\ Figure 1
Output Specification:
For each case, output in a line the total volume of the stroke core.
Sample Input:
3 4 5 2
1 1 1 1
1 1 1 1
1 1 1 1
0 0 1 1
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0
Sample Output:
26
*/
#include<stdio.h>
#include<queue>
using namespace std;

int M, N, L, T;
int pix[1286][128][61];
int vis[1286][128][61] = {0};
int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};
struct Node{
    int x, y, z;
}node;
queue<Node> Q;

int judge(int x, int y, int z)
{
    if(x>=0 && x<M && y>=0 && y<N && z>=0 && z<L && pix[x][y][z] && !vis[x][y][z])
        return 1;
    return 0;
}
int BFS(int x, int y, int z)
{
    int cnt = 0, i;
    node.x = x, node.y = y, node.z = z;
    Q.push(node);
    vis[x][y][z] = 1;//少写了这一行让我检查了2小时，push和vis是绑定的
    while(!Q.empty()){
        Node top = Q.front();
        Q.pop();
        cnt++;
        for(i=0; i<6; i++){
            x = top.x + X[i];
            y = top.y + Y[i];
            z = top.z + Z[i];
            if(judge(x, y, z)){
                node.x = x, node.y = y, node.z = z;
                Q.push(node);
                vis[x][y][z] = 1;
            }
        }
    }
    if(cnt>=T)  return cnt;
    return 0;
}
int main()
{
    scanf("%d%d%d%d", &M, &N, &L, &T);
    int i, j, k, ans =0;
    for(i=0; i<L; i++){
        for(j=0; j<M; j++){
            for(k=0; k<N; k++){
                scanf("%d", &pix[j][k][i]);
            }
        }
    }
    for(i=0; i<L; i++){
        for(j=0; j<M; j++){
            for(k=0; k<N; k++){
                if(vis[j][k][i] == 0 && pix[j][k][i] == 1){
                    ans += BFS(j, k, i);
                }
            }
        }
    }
    printf("%d", ans);
}
