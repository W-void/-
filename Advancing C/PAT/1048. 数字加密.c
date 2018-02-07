//题目没表述清楚，还以为输出与B的长度是一样的,最后结果首位的0也要输出
/*
1048. 数字加密(20)

本题要求实现一种数字加密方法。首先固定一个加密用正整数A，对任一正整数B，将其每1位数字与A的对应位置上的数字进行以下运算：
对奇数位，对应位的数字相加后对13取余——这里用J代表10、Q代表11、K代表12；对偶数位，用B的数字减去A的数字，若结果为负数，则再加10。
这里令个位为第1位。

输入格式：
输入在一行中依次给出A和B，均为不超过100位的正整数，其间以空格分隔。
输出格式：
在一行中输出加密后的结果。

输入样例：
1234567 368782971
输出样例：
3695Q8118
*/
#include<stdio.h>
#include<string.h>
int main()
{
	char a[102], b[102], c[102]={0};
	char d[] = "0123456789JQK";
	scanf("%s%s", a, b);
	int len_a = strlen(a);
	int len_b = strlen(b);
	int len = len_a>len_b?len_a:len_b;
	int i;
	if(len_a>len_b){//b补零
		for(i=0; i<=len_b; i++)
			b[len_a-i] = b[len_b-i];
		for(i=0; i<len_a-len_b; i++)
			b[i] = '0';
	}
	else if(len_b>len_a){//a补零
		for(i=0; i<=len_a; i++)
			a[len_b-i] = a[len_a-i];
		for(i=0; i<len_b-len_a; i++)
			a[i] = '0';
	}
	for(i=1; len-i>=0; i++){
		
		if(i%2)
			c[len-i] = d[(a[len-i]-'0'+b[len-i]-'0')%13];
		else
			c[len-i] = (b[len-i]-a[len-i]+10)%10+'0';
	
	}
	puts(c);
	return 0;
}
