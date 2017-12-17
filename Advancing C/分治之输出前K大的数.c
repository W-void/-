/*
只需要将前K大的数排列好就行
*/
#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a, const void *b)
{
	return *(int *)a - *(int *)b;
}
void swap(int *const a,  int*const b)
{
	int i=*a; *a = *b; *b =i;
}
void solve(int a[], int s, int e, int m)
{
	if(m==e-s+1) return;
	int i = s, j = e, k = a[s];
	while(i<j){
		while(i<j && a[j]<=k)
			j--;
		swap(a+i, a+j);
		while(i<j && a[i]>=k)
			i++;
		swap(a+i, a+j);
	}
	if(i-s+1==m) return;
	else if(i-s+1>m) solve(a, s, i-1, m);
	else solve(a, i+1, e, m-(i-s+1));
}
void QuickSort(int a[], int s, int e)
{
	if(s>=e)
		return;
	int k = a[s];
	int i = s, j = e;
	while(i!=j){
		while(j>i && a[j]<=k)
			j--;
		swap(a+i, a+j);
		while(i<j && a[i]>=k)
			i++;
		swap(a+i, a+j);
	}
	QuickSort(a, s, i-1);
	QuickSort(a, i+1, e);
}
int main()
{
//	freopen("E:\\中国大学MOOC\\程序设计与算法\\in(27).txt","r",stdin);
	int n, m;
	int a[100000];
	scanf("%d", &n);
	int i;
	for(i=0; i<n; i++){
		scanf("%d", a+i);
	}

//	qsort(a, n, sizeof(int), cmp);
	scanf("%d", &m);	
	solve(a, 0, n-1, m);
	QuickSort(a, 0, m-1);
	
	for(i=0; i<m; i++){
		printf("%d\n", a[i]);
	}
//	fclose(stdin);
}
