#include<stdio.h>
int a[100000];
int N, M;
int judge(int mid)
{
	int num = 0, sum =0, i;
	for(i=0; i<N; i++){
		sum += a[i];
		if(sum>mid){
			sum = a[i];
			num++;
		}
	}
	if(num<M) return 0;
	else return 1;
}
int main()
{
	scanf("%d %d", &N, &M);
	int i, sum, max=0;
	for(i=0; i<N; i++){
		scanf("%d", &a[i]);
		sum += a[i];
		if(a[i]>max) max = a[i];
	}
	int high = sum, low = max, mid;
	while(high>low){
		mid = (high+low)/2;
		if(judge(mid))
			low = mid+1;
		else high = mid ;
	}
	printf("%d\n", high);
}
/*
描述
农夫约翰是一个精明的会计师。他意识到自己可能没有足够的钱来维持农场的运转了。他计算出并记录下了接下来 N (1 ≤ N ≤ 100,000) 天里每天需要的开销。

约翰打算为连续的M (1 ≤ M ≤ N) 个财政周期创建预算案，他把一个财政周期命名为fajo月。每个fajo月包含一天或连续的多天，每天被恰好包含在一个fajo月里。

约翰的目标是合理安排每个fajo月包含的天数，使得开销最多的fajo月的开销尽可能少。



输入
第一行包含两个整数N,M，用单个空格隔开。
接下来N行，每行包含一个1到10000之间的整数，按顺序给出接下来N天里每天的开销。
输出
一个整数，即最大月度开销的最小值。
样例输入
7 5
100
400
300
100
500
101
400
样例输出
500
*/
