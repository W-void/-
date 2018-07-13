// dist数组用来存所有顶点到v1的距离，那么vx到vy的距离就等于dist[x]-dist[y]
/*
1046 Shortest Distance (20)（20 分）

The task is really simple: given N exits on a highway which forms a simple cycle, you are supposed to tell the shortest distance between any pair of exits.
Input Specification:
Each input file contains one test case. For each case, the first line contains an integer N (in [3, 10^5^]), followed by N integer distances D~1~ D~2~ ... D~N~, where D~i~ is the distance between the i-th and the (i+1)-st exits, and D~N~ is between the N-th and the 1st exits. All the numbers in a line are separated by a space. The second line gives a positive integer M (<=10^4^), with M lines follow, each contains a pair of exit numbers, provided that the exits are numbered from 1 to N. It is guaranteed that the total round trip distance is no more than 10^7^.
Output Specification:
For each test case, print your results in M lines, each contains the shortest distance between the corresponding given pair of exits.
Sample Input:
5 1 2 4 14 9
3
1 3
2 5
4 1
Sample Output:
3
10
7
*/
#include<stdio.h>
#include<malloc.h>
#include<math.h>

int main()
{
  int N, M, i;
  scanf("%d", &N);
  int *D = (int*)malloc(sizeof(int) * N);
  int *dist = (int*)malloc(sizeof(int) * (N+1));
  dist[0] = 0;
  int sum = 0;
  for(i=0; i<N; i++){
    scanf("%d", D+i);
    sum += D[i];
    dist[i+1] = sum;
  }
  scanf("%d", &M);
  int s, e;
  for(i=0; i<M; i++){
    scanf("%d%d", &s, &e);
    int ans = abs(dist[e-1] - dist[s-1]);
    ans = ans<dist[N]-ans ? ans : dist[N]-ans;
    printf("%d\n", ans);
  }
  return 0;
}
