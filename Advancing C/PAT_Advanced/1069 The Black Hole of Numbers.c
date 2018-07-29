/*
1069 The Black Hole of Numbers (20)（20 分）提问

For any 4-digit integer except the ones with all the digits being the same, if we sort the digits in non-increasing order first, and then in non-decreasing order, a new number can be obtained by taking the second number from the first one. Repeat in this manner we will soon end up at the number 6174 -- the "black hole" of 4-digit numbers. This number is named Kaprekar Constant.
For example, start from 6767, we'll get:
7766 - 6677 = 1089\ 9810 - 0189 = 9621\ 9621 - 1269 = 8352\ 8532 - 2358 = 6174\ 7641 - 1467 = 6174\ ... ...
Given any 4-digit number, you are supposed to illustrate the way it gets into the black hole.
Input Specification:
Each input file contains one test case which gives a positive integer N in the range (0, 10000).
Output Specification:
If all the 4 digits of N are the same, print in one line the equation "N
N = 0000". Else print each step of calculation in a line until 6174 comes out as the difference. All the numbers must be printed as 4-digit numbers.
Sample Input 1:
6767
Sample Output 1:
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
Sample Input 2:
2222
Sample Output 2:
2222 - 2222 = 0000
*/
#include<stdio.h>
#include<stdlib.h>
int cmp(void const* a, void const* b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int n, m;
	scanf("%d", &n);
	int a[4], i;
	do{
		for(i=0; i<4; i++){
			a[i] = n%10;
			n /= 10;
		}
		qsort(a, 4, sizeof(int), cmp);
		n=0, m=0;
		for(i=0; i<4; i++){
			m = m*10 + a[i];
			n = n*10 + a[3-i];
		}
		printf("%04d - %04d = %04d\n", n, m, n-m);
		n -= m;
	}while(n!=0 && n!=6174);
	return 0;
}
