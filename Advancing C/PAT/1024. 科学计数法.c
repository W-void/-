/*
1024. 科学计数法 (20)

科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式[+-][1-9]"."[0-9]+E[+-][0-9]+，
即数字的整数部分只有1位，小数部分至少有1位，该数字及其指数部分的正负号即使对正数也必定明确给出。
现以科学计数法的格式给出实数A，请编写程序按普通数字表示法输出A，并保证所有有效位都被保留。

输入格式：
每个输入包含1个测试用例，即一个以科学计数法表示的实数A。该数字的存储长度不超过9999字节，且其指数的绝对值不超过9999。
输出格式：
对每个测试用例，在一行中按普通数字表示法输出A，并保证所有有效位都被保留，包括末尾的0。

输入样例1：
+1.23400E-03
输出样例1：
0.00123400
输入样例2：
-1.2E+10
输出样例2：
-12000000000
*/
#include<stdio.h>
#include<string.h>

int main()
{
	char c[10000];
	gets(c);
	if(c[0]=='-') putchar(c[0]);
	int index;//记录E的下标
	int i=1;
	while(c[i]){
		if(c[i]=='E') index=i;
		i++;
	}
	//识别指数部分
	int sum=0;
	for(i=index+2; c[i]; i++){
		sum = sum*10 + c[i]-'0';
	}
	//分情况输出
	if(c[index+1]=='+'){//右移
		for(i=1; i<index; i++){
			if(i==2) continue;//小数点跳过
			if(i==sum+3) putchar('.');
			putchar(c[i]);
		}
		for(i=sum-index+3; i>0; i--){//需要补0，右移位数大于等于数字的总位数
			if(i==sum+3) putchar('.');
			putchar('0');
		}
	}
	else{//左移
		for(i=0; i<sum; i++){
			putchar('0');
			if(i==0) putchar('.');
		}
		for(i=1; i<index; i++){
			if(sum!=0 && i==2) continue;//此时不输出小数点
			putchar(c[i]);
		}
	}
	return 0;
}
