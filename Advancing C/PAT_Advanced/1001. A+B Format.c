// sprintf函数很方便
/*
1001. A+B Format (20)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas 
(unless there are less than four digits).

Input

Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. 
The numbers are separated by a space.

Output

For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input
-1000000 9
Sample Output
-999,991
*/
#include<stdio.h>
#include<string.h>

int main()
{
	int a, b;
	char c[30];
	scanf("%d%d", &a, &b);
	sprintf(c, "%d", a+b);
	int i=0, len = strlen(c);
	if(c[0]=='-'){
		printf("-");
		i=1;
	}
	for(; i<len; i++){
		putchar(c[i]);
		if((len-i-1)%3==0 && (len-i-1))
			putchar(',');
	}
}
