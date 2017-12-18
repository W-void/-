/*
long long int用 %lld输出
*/
#include<stdio.h>
long long int sum=0;
void merge(int a[], int s, int mid, int e, int tmp[])
{

	int l = s, r = mid+1;
	int pb = 0, i;
	while(l<=mid && r<=e){
		if(a[l]>a[r]){
			tmp[pb++] = a[l++];
			sum += e-r+1;
		}
		else tmp[pb++] = a[r++];
	}
	while(l<=mid)
		tmp[pb++] = a[l++];
	while(r<=e){
		tmp[pb++] = a[r++];
	}
	for(i=0; i<pb; i++){
		a[s+i] = tmp[i];
	}
	
}
void mergeSort(int a[], int s, int e, int tmp[])
{
	if(s>=e) return 0;
	int mid = s + (e-s)/2;
	
	 mergeSort(a, s, mid, tmp);
	 mergeSort(a, mid+1, e, tmp);
	 merge(a, s, mid, e, tmp);
	
}
int main()
{
	int i, n, a[100010], b[100010];
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", a+i);
	}
	mergeSort(a, 0, n-1, b);
	printf("%lld", sum);
}
