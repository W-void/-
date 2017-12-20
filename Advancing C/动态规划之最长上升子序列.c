/*
Sample Input
7
1 7 3 5 9 4 8
Sample Output
4

这道题的状态方程还是比较简单的，以第i个元素结尾的子序列长度等于左边且比第i个元素小的子序列长度加一，最后再对所有状态求max即可
*/
#include<stdio.h>

#define Max 1000
int n;
int a[Max];
int b[Max];

int max(int a, int b)
{
	int i = a>b?a:b;
	return i;
}

int main()
{
	scanf("%d", &n);
	int i;
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
		b[i] = 1;
	}
	int j;
	int maxLen = 1;
	for(i=1; i<n; i++){
		for(j=0; j<i; j++){
			if(a[i]>a[j]){
				b[i] = max(b[j]+1, b[i]);
				maxLen = max(b[i], maxLen);
			}
				
		}
	}
	printf("%d", maxLen);
}
