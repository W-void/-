//
/*
1050. 螺旋矩阵(25)

本题要求将给定的N个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第1个格子开始，按顺时针螺旋方向填充。
要求矩阵的规模为m行n列，满足条件：m*n等于N；m>=n；且m-n取所有可能值中的最小值。

输入格式：
输入在第1行中给出一个正整数N，第2行给出N个待填充的正整数。所有数字不超过104，相邻数字以空格分隔。
输出格式：
输出螺旋矩阵。每行n个数字，共m行。相邻数字以1个空格分隔，行末不得有多余空格。

输入样例：
12
37 76 20 98 76 42 53 95 60 81 58 93
输出样例：
98 95 93
42 37 81
53 20 76
58 60 76
*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>

int cmp(const void* a, const void* b)
{
	return *(int*)b-*(int*)a;//从大到小排序
}
int main()
{
	int n;
	scanf("%d", &n);
	int *a = (int*)malloc(sizeof(int)*n);
	int i;
	for(i=0; i<n; i++){
		scanf("%d", a+i);
	}
	qsort(a, n, sizeof(int), cmp);
	for(i=sqrt(n); i>0 && n%i; i--);
	int k=i, m=n/i, j, l;//m行k列
	int b[m][k], m1, k1;//int *b = (int*)malloc(sizeof(int)*n);
	for(i=0,j=0,l=0,m1=m,k1=k; i<n; ){//第j行第l列
		while(l<k1&&i<n)
			b[j][l++] = a[i++];
		l--;
		while(j<m1-1&&i<n)
			b[++j][l] = a[i++];
		
		while(l>k-k1&&i<n)
			b[j][--l] = a[i++];
		
		while(j>m-m1+1&&i<n)
			b[--j][l] = a[i++];
		k1--, m1--, l++;		
	}
	for(i=0; i<m; i++)
		for(j=0; j<k; j++)
			printf("%d%c", b[i][j], j==k-1?'\n':' ');
		
	return 0;
}
