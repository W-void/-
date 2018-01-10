/*
读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。
输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu
*/
#include<stdio.h>
#include<string.h>
void print_num(int sum)
{
	char *name[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	int a[4] = {0}, i = 0;
	while(sum){
		a[i++] = sum%10;
		sum /= 10;
	}
	while(--i){
		printf("%s ", name[a[i]]);
	}
	printf("%s", name[a[0]]);
}
int main()
{
	char c[101];
	gets(c);
	int i = 0, sum = 0;
	while(c[i]){
		sum += c[i++] - '0';
	}
	print_num(sum);
}
