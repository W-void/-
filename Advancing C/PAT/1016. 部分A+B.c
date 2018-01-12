//32位机int 有正负2*10^9 多的大小，-2^31~2^31-1，应该是不符合这道题的，但是过了，可能判定机器是64位的吧
//原本想用位数更多的字符串做这道题，但一直有一个2分的点过不了
/*
1016. 部分A+B (15)

正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。
现给定A、DA、B、DB，请编写程序计算PA + PB。

输入格式：
输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。
输出格式：
在一行中输出PA + PB的值。

输入样例1：
3862767 6 13530293 3
输出样例1：
399
输入样例2：
3862767 1 13530293 8
输出样例2：
0
#include<stdio.h>
int comp(int a, int d)
{
	int sum=0;
	while(a){
		if(a%10==d)
			sum = sum*10+d;
		a/=10;
	}
	return sum;
}
int main()
{
	int a, da, b, db;
	scanf("%d%d%d%d", &a, &da, &b, &db);
	printf("%d", comp(a, da)+comp(b, db));
}
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char a[11], b[11];
	int DA, DB;
	scanf("%s%d%s%d", a, &DA, b, &DB);
	int numa=0, numb=0;
	int i;
	for(i=0; i<strlen(a); i++){
		if(a[i]==DA+'0') numa++;
	}
	for(i=0; i<strlen(b); i++){
		if(b[i]==DB+'0') numb++;
	}
	char c[11]={0};
	int f=0;
	for(i=0; i<(numa>numb?numa:numb); i++){
		int x = i<numa?DA:0;
		int y = i<numb?DB:0;
		c[i] = '0' + (x + y + f)%10;
		f = (x+y+f)/10;
	}
	if((!numa||!DA) && (!numb||!DB)) printf("0");
	else{
		if(f) printf("1");
		while(i--)
			putchar(c[i]);	
	}
		
}
