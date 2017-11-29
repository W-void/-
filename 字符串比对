#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int flag = 1;
void solve(char* a, char* b, int j, int lenA, int lenB)
{
	if((lenB-j)<lenA) return;
	int k;
	for(k=0;k<lenA;k++){
		if( a[k]!=b[j+k]) break;
	}
	if( k==lenA ){
			printf("%d ", j);
			flag = 0;
			//solve(a, b, j+k, lenA, lenB);
		}
	solve(a, b, j+1, lenA, lenB);
		
}
int main()
{
	char a[1000], b[1000];
	gets(a);
	gets(b);
	int lenA = strlen(a);
	int lenB = strlen(b);
	solve(a, b, 0, lenA, lenB);
	/* int i, j;
	int flag = 1;
	for( i=0; i<=lenB-lenA; i++){
		for( j=0; j<lenA; j++ ){
			
			if( a[j]!=b[i+j]) break;
			
		}
		if( j==lenA ){
			printf("%d ", i);
			flag = 0;
		}
			
	}*/
	if(flag) printf("-1"); 
	return 0;
}
