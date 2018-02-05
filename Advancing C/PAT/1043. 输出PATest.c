//将字母放在数组中再循环判断
/*
1043. 输出PATest(20)

给定一个长度不超过10000的、仅由英文字母构成的字符串。请将字符重新调整顺序，按“PATestPATest....”这样的顺序输出，并忽略其它字符。
当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按PATest的顺序打印，直到所有字符都被输出。

输入格式：
输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。
输出格式：
在一行中按题目要求输出排序后的字符串。题目保证输出非空。

输入样例：
redlesPayBestPATTopTeePHPereatitAPPT
输出样例：
PATestPATestPTetPTePePee
*/
#include<stdio.h>

int main()
{
	int a[7] = {0};//省一个判断
	char c[7] = "PATest";
	char str[10010];
	gets(str);
	int i=-1, j, sum=0;
	while(str[++i]){
		for(j=0; j<6; j++){//判断是不是PATest
			if(c[j]==str[i]){
				sum++;//记录PATest的总个数
				break;
			}
		}
		a[j]++;//若不是PATest则a[6]++，省一个判断
	}
	for(i=0,j=0; i<sum; i++){
		while(a[j]==0)//等于0跳过
			j = (j+1)%6;
		putchar(c[j]);
		a[j]--;
		j = (j+1)%6;
	}
	return 0;
}
