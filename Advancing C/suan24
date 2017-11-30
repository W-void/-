#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define bool int
#define true 1
#define false 0
double a[4];

bool isZero(double x)
{
	return (fabs(x) <= 0.001);
}

bool count24(double a[], int n)
{
	if( n==1 ){
		if( isZero(a[0]-24) )
			return true;
		else
			return false;
	}
	double b[4];
	int i, j;
	for( i=0; i<n-1; i++ ){
		for( j=1; j<n; j++){
			int m=0, k;
			for( k=0; k<n; k++ ){//将剩下的数放入b中
				if( k!=i && k!=j ){
					b[m++] = a[k];
				}
			}
			//对提出来的两个数进行计算
			b[m] = a[i] + a[j];
			if( count24(b, n-1) )
				return true;
			b[m] = a[i] - a[j];
			if( count24(b, n-1) )
				return true;
			b[m] = a[j] - a[i];
			if( count24(b, n-1) )
				return true;
			b[m] = a[i] * a[j];
			if( count24(b, n-1) )
				return true;
			if( !isZero(a[i])){
				b[m] = a[j]/a[i];
				if( count24(b, n-1) )
					return true;
			}
			if( !isZero(a[j])){
				b[m] = a[i]/a[j];
				if( count24(b, n-1) )
					return true;
			}
		}
	}
	return false;
}
int main()
{
	while(true){
		int i;
		for( i=0; i<4; i++ ){
			scanf("%lf", &a[i]);
		}
		if( isZero(a[0]) ) 
			break;
		if( count24(a, 4) )
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
