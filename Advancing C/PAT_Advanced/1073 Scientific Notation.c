/*
1073 Scientific Notation (20)（20 分）

Scientific notation is the way that scientists easily handle very large numbers or very small numbers. The notation matches the regular expression [+-][1-9]"."[0-9]+E[+-][0-9]+ which means that the integer portion has exactly one digit, there is at least one digit in the fractional portion, and the number and its exponent's signs are always provided even when they are positive.
Now given a real number A in scientific notation, you are supposed to print A in the conventional notation while keeping all the significant figures.
Input Specification:
Each input file contains one test case. For each case, there is one line containing the real number A in scientific notation. The number is no more than 9999 bytes in length and the exponent's absolute value is no more than 9999.
Output Specification:
For each test case, print in one line the input number A in the conventional notation, with all the significant figures kept, including trailing zeros,
Sample Input 1:
+1.23400E-03
Sample Output 1:
0.00123400
Sample Input 2:
-1.2E+10
Sample Output 2:
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
