// %s 输入以空格，回车，跳格作为结束标志，gets只以回车为结束标志；%s输出只以'\0'为结束标志,用puts输出会自带回车
/*
给定一个 k+1 位的正整数 N，写成 ak...a1a0 的形式，其中对所有 i 有 0 <= ai < 10 且 ak > 0。
N 被称为一个回文数，当且仅当对所有 i 有 ai = ak-i。零也被定义为一个回文数。

非回文数也可以通过一系列操作变出回文数。首先将该数字逆转，再将逆转数与该数相加，如果和还不是一个回文数，就重复这个逆转再相加的操作，
直到一个回文数出现。如果一个非回文数可以变出回文数，就称这个数为延迟的回文数。

给定任意一个正整数，本题要求你找到其变出的那个回文数。

输入格式：
输入在一行中给出一个不超过1000位的正整数。

输出格式：
对给定的整数，一行一行输出其变出回文数的过程。每行格式如下

A + B = C
其中A是原始的数字，B是A的逆转数，C是它们的和。A从输入的整数开始。重复操作直到C在10步以内变成回文数，这时在一行中输出“C is a palindromic number.”
或者如果10步都没能得到回文数，最后就在一行中输出“Not found in 10 iterations.”。

输入样例 1：
97152

输出样例 1：
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.

输入样例 2：
196

输出样例 2：
196 + 691 = 887
887 + 788 = 1675
1675 + 5761 = 7436
7436 + 6347 = 13783
13783 + 38731 = 52514
52514 + 41525 = 94039
94039 + 93049 = 187088
187088 + 880781 = 1067869
1067869 + 9687601 = 10755470
10755470 + 07455701 = 18211171
Not found in 10 iterations.
*/
#include<stdio.h>
#include<string.h>

char a[1001], b[1001];
void reverse()
{
	int n = strlen(a);
	int i;
	for(i=0; i<n; i++){
		b[i] = a[n-1-i];
	}
}
void sum()
{
	int flag = 0, n = strlen(a);
	int i;
	for(i=0; i<n; i++){
		a[i] = a[i] + b[i] - '0' +flag;
		if(a[i]>'9'){
			a[i] = a[i] - 10;
			flag = 1;
		}
		else flag = 0;
	}
	if(flag){
		a[i] = '1';
		a[i+1] = '\0';
	}
	reverse();
	strcpy(a, b);
}
int judge()
{
	reverse();
	return strcmp(a, b);
}
int main()
{
	gets(a);
	int i = 10, flag = 0;
	while(i--){
		if(judge()==0){
			flag = 1;
			break;
		}
		printf("%s", a);//puts(a); //puts 结尾会自动加回车 
		printf(" + ");
		reverse();
		printf("%s", b);//puts(b);
		printf(" = ");
		sum();
		puts(a);
		//printf("\n");	
	}
	if(flag){
		printf("%s", a);//puts(a);
		printf(" is a palindromic number.");
	}
	else printf("Not found in 10 iterations.");
	return 0;
}
