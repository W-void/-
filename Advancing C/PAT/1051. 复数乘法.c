//好坑的一道题，-0.04~-0.会四舍五入成-0，而我们希望他是0
/*
1051. 复数乘法 (15)

复数可以写成(A + Bi)的常规形式，其中A是实部，B是虚部，i是虚数单位，满足i2 = -1；也可以写成极坐标下的指数形式(R*e(Pi))，
其中R是复数模，P是辐角，i是虚数单位，其等价于三角形式 R(cos(P) + isin(P))。

现给定两个复数的R和P，要求输出两数乘积的常规形式。

输入格式：
输入在一行中依次给出两个复数的R1, P1, R2, P2，数字间以空格分隔。
输出格式：
在一行中按照“A+Bi”的格式输出两数乘积的常规形式，实部和虚部均保留2位小数。注意：如果B是负数，则应该写成“A-|B|i”的形式。

输入样例：
2.3 3.5 5.2 0.4
输出样例：
-8.68-8.23i
*/
#include<stdio.h>
#include<math.h>
int main()
{
	double R1, P1, R2, P2;
	scanf("%lf%lf%lf%lf", &R1, &P1,&R2, &P2);
	double a, b;
	a = R1*R2*cos(P1+P2);
	b = R1*R2*sin(P1+P2);
	if(fabs(a)<0.005) a=0;
	if(fabs(b)<0.005) b=0;
	printf("%.2f%+.2fi", a, b);
	return 0;
}
