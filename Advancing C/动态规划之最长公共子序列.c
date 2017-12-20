/*
动态规划关键在于选取合适的状态(子问题)使得状态之间无后效性，
然后从边界开始，由已知推未知，边推边储存(因为子问题是相互重叠的)，直到求出最终的状态(即解)
*/
#include<stdio.h>
#include<string.h>

#define Max 1000
int n;
char s1[Max];
char s2[Max];
int maxLen[Max][Max];

int max(int a, int b)
{
	int i = a>b?a:b;
	return i;
}

int main()
{
	scanf("%s", s1);
	scanf("%s", s2);
	int lenth1 = strlen(s1);
	int lenth2 = strlen(s2);
	int i, j;
	for(i=0; i<=lenth1; i++)
		maxLen[i][0] = 0;
	for(j=0; j<=lenth2; j++)
		maxLen[0][j] = 0;
	for(i=1; i<=lenth1; i++){
		for(j=1; j<=lenth2; j++){
			if(s1[i] == s2[j]){
				maxLen[i][j] = maxLen[i-1][j-1]+1;
			}
			else{
				maxLen[i][j] = max(maxLen[i][j-1], maxLen[i-1][j]);
			}
		}
	}
	printf("%d", maxLen[lenth1][lenth2]);
}
