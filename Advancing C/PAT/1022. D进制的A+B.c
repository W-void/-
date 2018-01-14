//
/*
1022. D进制的A+B (20)

输入两个非负10进制整数A和B(<=230-1)，输出A+B的D (1 < D <= 10)进制数。

输入格式：
输入在一行中依次给出3个整数A、B和D。
输出格式：
输出A+B的D进制数。

输入样例：
123 456 8
输出样例：
1103
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a, b, d;//根据题目给的A B的范围，int足以
	scanf("%d%d%d", &a, &b, &d);
	a += b;
	char c[1000];
	//itoa(a, c, d);
	int i;
	if(a==0) printf("0");//因为判决条件，若a是0的话将不会输出任何数 
	for(i=0; a; i++){
		c[i] = a%d + '0';
		a /= d;
	}
	while(i>0)
		printf("%c", c[--i]);

	return 0;
}
