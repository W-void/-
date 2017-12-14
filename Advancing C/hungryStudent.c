#include<stdio.h>
int main()
{
	int i, n, x, r;
	scanf("%d", &n);
	int a[100];
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
		
	}
	
	int j;
	for(i=0; i<n; i++){
		r = 0;
		x = a[i];
		for(j=0; r<=x; ){
			if(!((x-r)%3)) break;
			r = 7*(++j);
		}
		if(x>=r) printf("YES\n");
		else printf("NO\n");
	}
}
