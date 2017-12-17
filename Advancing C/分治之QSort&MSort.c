/*
快速排序和归并排序相比，优点是不需要额外的空间，但代价就是不稳定  
他们复杂度都是NlogN，一般的排序如果遍历的话，需要遍历N次，每次遍历的复杂度都是N，  
N^2变为NlogN的本质是通过增加先验知识(有序)，减少遍历次数(由N变为logN)，并保持每次遍历的复杂度依旧是N(这个应该不能再少了)。
*/
#include<stdio.h>
void merge(int a[], int s, int m, int e, int tmp[])
{
	int l = s, r = m+1, i;
	int pb = 0;
	while(l<=m && r<=e){
		if(a[l]<a[r]){
			tmp[pb++] = a[l++];
		}else tmp[pb++] = a[r++];
	}
	while(l<=m)
		tmp[pb++] = a[l++];
	while(r<=e) 
		tmp[pb++] = a[r++];
	for(i=0; i<pb; i++){
		a[s+i] = tmp[i];
	}
}
void mergeSort(int a[], int s, int e, int tmp[])
{
	if(s<e){
		int m = s + (e-s)/2;
		mergeSort(a, s, m, tmp);
		mergeSort(a, m+1, e, tmp);
		merge(a, s, m, e, tmp);
	}
}
void swap(int *a, int *b)
{
	int i;
	i = *a;
	*a = *b;
	*b = i;
}
void QuickSort(int a[], int s, int e)
{
	if(s>=e)
		return;
	int k = a[s];
	int i = s, j = e;
	while(i!=j){
		while(j>i && a[j]>=k)
			j--;
		swap(a+i, a+j);
		while(i<j && a[i]<=k)
			i++;
		swap(a+i, a+j);
	}
	QuickSort(a, s, i-1);
	QuickSort(a, i+1, e);
}

int main()
{
	int i, n;
	
	int a[10] = {13, 27, 19, 20, 49, 30, 60, 39, 90, 40};
	int b[10];

	//mergeSort(a, 0, 9, b);
	QuickSort(a, 0, 9);
	for(i =0; i<10; i++){
		printf("%d ", a[i]);
	}
}
