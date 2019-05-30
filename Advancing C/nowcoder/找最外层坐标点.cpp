/*
时间限制：1秒

空间限制：32768K

P为给定的二维平面整数点集。定义 P 中某点x，如果x满足 P 中任意点都不在 x 的右上方区域内（横纵坐标都大于x），则称其为“最大的”。求出所有“最大的”点的集合。（所有点的横坐标和纵坐标都不重复, 坐标轴范围在[0, 1e9) 内）

如下图：实心点为满足条件的点的集合。请实现代码找到集合 P 中的所有 ”最大“ 点的集合并输出。

输入描述:
第一行输入点集的个数 N， 接下来 N 行，每行两个数字代表点的 X 轴和 Y 轴。
对于 50%的数据,  1 <= N <= 10000;
对于 100%的数据, 1 <= N <= 500000;

输出描述:
输出“最大的” 点集合， 按照 X 轴从小到大的方式输出，每行两个数字分别代表点的 X 轴和 Y轴。

输入例子1:
5
1 2
5 3
4 6
7 5
9 0

输出例子1:
4 6
7 5
9 0
*/

#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<vector>
using namespace std;


struct point{
    int x, y;
};

int cmp(const void *a, const void *b){
    int a_x = ((struct point*)a)->x, a_y = ((struct point*)a)->y;
    int b_x = ((struct point*)b)->x, b_y = ((struct point*)b)->y;
    if(a_x == b_x){
        return a_y - b_y;
    }
    else
        return a_x - b_x; //升序排列
}

struct point *P;
int main(){
    int N, i, j, x, y;
    scanf("%d", &N);
    P = (point*)malloc(N * sizeof(struct point));
    for(i=0; i<N; i++){
        scanf("%d%d", &P[i].x, &P[i].y);     
    }
    qsort(P, N, sizeof(struct point), cmp);
    int *Pmax = (int*)malloc(sizeof(int) * N), max = 1<<31;
    for(i=N-1; i>=0; i--){//计算右侧所有点的y的最大值
        max = P[i].y > max ? P[i].y : max;
        Pmax[i] = max;
    }
    vector<struct point> ans;
    for(i=0; i<N; i++){
        if(P[i].y > Pmax[i+1])
            printf("%d %d\n", P[i].x, P[i].y);
    }
    return 0;
}
