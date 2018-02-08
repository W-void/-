//#include<stdlib.h> atof
/*
1054. 求平均值 (20)

本题的基本要求非常简单：给定N个实数，计算它们的平均值。但复杂的是有些输入数据可能是非法的。一个“合法”的输入是[-1000，1000]区间内的实数，
并且最多精确到小数点后2位。当你计算平均值的时候，不能把那些非法的数据算在内。

输入格式：
输入第一行给出正整数N（<=100）。随后一行给出N个实数，数字间以一个空格分隔。
输出格式：
对每个非法输入，在一行中输出“ERROR: X is not a legal number”，其中X是输入。
最后在一行中输出结果：“The average of K numbers is Y”，其中K是合法输入的个数，Y是它们的平均值，精确到小数点后2位。
如果平均值无法计算，则用“Undefined”替换Y。如果K为1，则输出“The average of 1 number is Y”。

输入样例1：
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
输出样例1：
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
输入样例2：
2
aaa -9999
输出样例2：
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);
	int num=0;
	double sum=0;
	char x[100];
	while(n--){
		scanf("%s", x);
		int f=1, i, index1=0, index2, dot_count=0;
		if(x[0]=='-'|| x[0]=='+') index1=1;
		for(i=index1; x[i]; i++){
			if(x[i]>='0'&&x[i]<='9'||x[i]=='.'){
				if(x[i]=='.'){
					dot_count++;
					index2=i;
				}					
			}
			else{
				f=0;
				break;
			}							
		}
		if(dot_count>1||i-index2>3) f=0;
		double a = atof(x);
		if(a>1000||a<-1000) f=0;
		if(f){
			sum += a;
			num++;
		}
		else{
			printf("ERROR: %s is not a legal number\n", x);
		}
		
	}
	//printf("The average of %d numbers is ", num);
	if(num==1)
		printf("The average of %d number is %.2f", num, sum/num);//number不是numbers
	else if(num)
			printf("The average of %d numbers is %.2f", num, sum/num);
	else
		printf("The average of 0 numbers is Undefined");	
	
}
