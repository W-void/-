//  同 B1030
/*
1085 Perfect Sequence (25)（25 分）提问

Given a sequence of positive integers and another positive integer p. The sequence is said to be a "perfect sequence" if M <= m * p where M and m are the maximum and minimum numbers in the sequence, respectively.
Now given a sequence and a parameter p, you are supposed to find from the sequence as many numbers as possible to form a perfect subsequence.
Input Specification:
Each input file contains one test case. For each case, the first line contains two positive integers N and p, where N (<= 10^5^) is the number of integers in the sequence, and p (<= 10^9^) is the parameter. In the second line there are N positive integers, each is no greater than 10^9^.
Output Specification:
For each test case, print in one line the maximum number of integers that can be chosen to form a perfect subsequence.
Sample Input:
10 8
2 3 20 4 5 1 6 7 8 9
Sample Output:
8
*/
#include<stdio.h>
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
