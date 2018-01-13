/*
1019. 数字黑洞 (20)

给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，然后用第1个数字减第2个数字，将得到一个新的数字。
一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。

例如，我们从6767开始，将得到

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...

现给定任意4位正整数，请编写程序演示到达黑洞的过程。

输入格式：
输入给出一个(0, 10000)区间内的正整数N。
输出格式：
如果N的4位数字全相等，则在一行内输出“N - N = 0000”；否则将计算的每一步在一行内输出，直到6174作为差出现，输出格式见样例。
注意每个数字按4位数格式输出。

输入样例1：
6767
输出样例1：
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
输入样例2：
2222
输出样例2：
2222 - 2222 = 0000
*/
#include<stdio.h>
#include<stdlib.h>
int cmp(void const *a, void const *b)
{
	return *(char *)b-*(char *)a;//从大到小排序
}
int sort(int n)
{
	char c[5]={'0'};
	int i;
	for(i=0; i<4; i++){
		c[i] = '0' + n%10;
		n /= 10;
	}
	qsort(c, 4, sizeof(c[0]), cmp);
	int m = 0;
	for(i=0; i<4; i++){
		m = m*10 + c[i] - '0';
	}
	return m;
}
int reverse(int n)
{
	int m=0, i=4;
	while(i--){
		m = m*10 + n%10;
		n /= 10;
	}
	return m;
}
void print_four(int n)
{
	n = reverse(n);
	int i=4;
	while(i--){
		printf("%d", n%10);
		n /= 10;
	}
}
void print(int n, int m)
{
	print_four(n);
	printf(" - ");
	print_four(m);
	printf(" = ");
	print_four(n-m);
	puts("");
}
int main()
{
	int n, m;
	scanf("%d", &n);
	if(n%1111==0){
		printf("%d - %d = 0000", n, n);
	}
	else
		do{
			n = sort(n);
			m = reverse(n);
			print(n, m);
			n = n - m;		
		}while(n!=6174);
	return 0;
}
