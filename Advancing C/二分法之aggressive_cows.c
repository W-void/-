'''
题意：在一位坐标上给N个点，将C头牛放在N个点中的C个点上使C头牛之间的最小距离最大。
解题思路：将C头牛放在N个点中的C个点上的最大距离是：dis=(Pmax-Pmin)/(C-1).（最大的坐标-最小的坐标在除以C-1）。然后以dis为上限0为下限进行二分搜索。
'''
#include<stdio.h>
int a[100001];
int size;

int judge(int x, int n)
{
	int i, num=0, d = a[0];
	for(i=1; i<size; i++){
		if(a[i]-d >=x) {
			num++;
			d = a[i];
		}
	}
	if(num>=n-1) return 1;
	else return 0;
}
int main()
{
	int n;
	scanf("%d %d\n", &size, &n);
	int i;
	for(i=0; i<size; i++){
		scanf("%d", &a[i]);
		int j;
		for(j=i-1; j>=0; j--){
			if(a[j]>a[j+1]){
				a[j] = a[j+1]+a[j];
				a[j+1] = a[j] - a[j+1];
				a[j] = a[j] - a[j+1];
			}
			else break;
		}
	}
	int high = (a[size-1] - a[0])/(n-1);
	int low = 0;
	while(high>=low){
		int mid = (high + low)/2;
		if(judge(mid, n)){
			low = mid+1;
		}
		else high = mid-1;
	}
	printf("%d\n", low-1);
	return 0;
}
