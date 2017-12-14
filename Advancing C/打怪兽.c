#include<stdio.h>
int main()
{
	
	int h1, a1, c1;
	int h2, a2;
	scanf("%d %d %d", &h1, &a1, &c1);
	scanf("%d %d", &h2, &a2);
	int sum = 0, i = 0;
	int a[10000];
	while(h2>0){
		if((h2>a1)&&(h1<=a2)){
			h1 = h1+c1-a2;
			
			a[i++] = 1;
		}else{
			h2 -= a1;
			h1 -= a2;
			a[i++] = 0;
		}
		sum++;
		
	}
	printf("%d\n", sum);
	for(i=0; i<sum; i++){
		if(a[i]) printf("HEAL\n");
		else printf("STRIKE\n");
	}
}
