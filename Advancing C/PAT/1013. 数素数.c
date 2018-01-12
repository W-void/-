/*
1013. 数素数 (20)

令Pi表示第i个素数。现任给两个正整数M <= N <= 104，请输出PM到PN的所有素数。

输入格式：
输入在一行中给出M和N，其间以空格分隔。
输出格式：
输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/
#include<stdio.h>
#include<math.h>
#include<malloc.h>

int isPrime(int n)
{
	//if(n==1) return 1; 1不是素数 
	int i;
	for(i=2; i<=sqrt(n); i++){
		if(n%i==0) return 0;
	}
	return 1;
}
int main()
{
	int M, N;
	scanf("%d%d", &M, &N);
	int *prime = (int*)malloc(N*sizeof(int));
	int i, p;
	for(i=2,p=0; p<N; i++){
		if(isPrime(i)) prime[p++] = i;
	}
	for(i=M; i<N; i++){
		printf("%d", prime[i-1]);
		if((i-M+1)%10==0) puts("");
		else printf(" ");
	}
	printf("%d", prime[N-1]); //最后一个数后面不能有空格 
}
	
