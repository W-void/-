#include<stdio.h>
#include<stdlib.h>

int comparator(const void *p, const void *q)
{
long int l = *(long int *)p;
long int r = *(long int *)q;
return (l-r);

}
int main()
{
	int a[5000] = {0};
	int n, i, max=1,count=1;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	qsort(a,n,sizeof(long int),comparator);
	for(i=1; i<n; i++){
		if(a[i]!=a[i-1]){
			count = 1;
		}
		else{
			count++;
			max = max<count?count:max;
		}
	}
	printf("%d", max);
	
}
