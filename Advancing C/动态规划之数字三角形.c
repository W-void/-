/*
5   //行数和列数
7 
3 8 
8 1 0 
2 7 4 4 
4 5 2 6 5
在上面的数字三角形中寻找在上面的数字三角形中寻找一条从顶部到底边的路径，使得路径上所经过的数字之和最大。
路径上的每一步都只能往左下或右下走。只需要求出这个最大和即可，不必给出具体路径。 

解题思路：若单纯地用递归，则会有太多重复计算，复杂度为O(n)，所以从后往前算，并将计算结果存起来，这样复杂度为O(n^2).
*/
#include<stdio.h>
int max(int a, int b)
{
	int i = a>b?a:b;
	return i;
}
#define MAX 100
int n;
int D[MAX][MAX];
int sum[MAX];
int main()
{
	int i, j;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		for(j=0; j<=i; j++){
			scanf("%d", &D[i][j]);
		}
	}
	for(i=0; i<n; i++){
		sum[i] = D[n-1][i];
	}
	for(i=n-2; i>=0; i--){
		for(j=0; j<=i; j++){
			sum[j] = D[i][j] + max(sum[j], sum[j+1]); 
		}
	}
	printf("%d\n", sum[0]);
	return 0;
}
