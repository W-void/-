//这道题真麻烦，唯一的知识点就是辗转相除法求最大公约数
/*
1034. 有理数四则运算(20)

本题要求编写程序，计算2个有理数的和、差、积、商。

输入格式：
输入在一行中按照“a1/b1 a2/b2”的格式给出两个分数形式的有理数，其中分子和分母全是整型范围内的整数，负号只可能出现在分子前，分母不为0。
输出格式：
分别在4行中按照“有理数1 运算符 有理数2 = 结果”的格式顺序输出2个有理数的和、差、积、商。注意输出的每个有理数必须是该有理数的最简形式“k a/b”，
其中k是整数部分，a/b是最简分数部分；若为负数，则须加括号；若除法分母为0，则输出“Inf”。题目保证正确的输出中没有超过整型范围的整数。

输入样例1：
2/3 -4/2
输出样例1：
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
输入样例2：
5/3 0/6
输出样例2：
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
*/
#include<stdio.h>
#include<math.h>
long long gcd(long long a, long long b)
{
	long long tmp;
	while(a%b){
		tmp = a%b;
		a = b;
		b = tmp;
	}
	if(b>0) return b;
	else return -b;
}
void myprint(long long a, long long b)
{
	if(a==0)
		printf("0");
	else{
		long long tmp = gcd(a, b);
		a /= tmp, b /= tmp;
		if(a<0)
			printf("(-");
		if(a/b)
			printf("%lld", abs(a/b));
		if(b!=1){
			if(a/b) putchar(' ');
			printf("%lld", abs(a%b));
			printf("/%lld", b);
		}
		if(a<0)
			putchar(')');			
	}
}
void myprint2(long long a1, long long b1,long long a2, long long b2, char c)
{
	myprint(a1, b1);
	printf(" %c ", c);
	myprint(a2, b2);
	printf(" = ");
}
int main()
{
	long long a1, b1, a2, b2;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	myprint2(a1, b1, a2, b2, '+');
	myprint(a1*b2+a2*b1, b1*b2);
	puts("");
	myprint2(a1, b1, a2, b2, '-');
	myprint(a1*b2-a2*b1, b1*b2);
	puts("");
	myprint2(a1, b1, a2, b2, '*');
	myprint(a1*a2, b1*b2);
	puts("");
	myprint2(a1, b1, a2, b2, '/');
	if(a2>0)
		myprint(a1*b2, b1*a2);
	else if(a2<0)
		myprint(-a1*b2, -b1*a2);
	else puts("Inf");
	
	return 0;
}
