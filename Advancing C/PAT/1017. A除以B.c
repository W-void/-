//字符串实现除法
/*
1017. A除以B (20)

本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。

输入格式：
输入在1行中依次给出A和B，中间以1空格分隔。
输出格式：
在1行中依次输出Q和R，中间以1空格分隔。

输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3
*/
#include<stdio.h>
#include<string.h>

int main()
{
	char c[1001];
	scanf("%s", c);
	int b;
	scanf("%d", &b);
	int i=1, j=c[0]-'0', q, r;
	if(j>=b || strlen(c)==1) printf("%d", j/b);//一般情况下首位的0是不输出的，除非结果只有一个0
	j %= b;
	for(i=1; i<strlen(c); i++){
		j = j*10 + c[i]-'0';
		printf("%d", j/b);
		j %= b;
	}
	
	printf(" %d", j);
}
