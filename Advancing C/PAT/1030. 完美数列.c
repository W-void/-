// 找到了那两个测试点不过的原因，没有考虑所有数都属于完美数列的情况 //很烦，牛客网能过，PAT有两个测试点过不去
/*
1030. 完美数列(25)

给定一个正整数数列，和正整数p，设这个数列中的最大值是M，最小值是m，如果M <= m * p，则称这个数列是完美数列。
现在给定参数p和一些正整数，请你从中选择尽可能多的数构成一个完美数列。

输入格式：
输入第一行给出两个正整数N和p，其中N（<= 105）是输入的正整数的个数，p（<= 109）是给定的参数。第二行给出N个正整数，每个数不超过109。
输出格式：
在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。

输入样例：
10 8
2 3 20 4 5 1 6 7 8 9
输出样例：
8
*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int cmp(void const* a, void const* b)
{
	return *(int*)b-*(int*)a;
}
int main()
{
	int n;
	long long p;
	scanf("%d%lld", &n, &p);
	int *a = (int*)malloc(n*sizeof(int));
	int i;
	for(i=0; i<n; i++){
		scanf("%d", a+i);
	}
	qsort(a, n, sizeof(int), cmp);//从大到小排序
	long long  M=a[0];
	int max=0, k=0;
	for(i=0; i<n; i++){
		if(M>a[i]*p){//若没有满足判断的，则max的值一直是0
			max = max>i-k?max:i-k;//将这次的个数与以前的最大值比较，取大者
			M=a[++k];
			i--;
		}
	}
	if(!max)  max = n;//max还是初始化时的0，证明所有的a[i]均满足a[0]<=a[i]*p;
	printf("%d", max);
	return 0;
}
