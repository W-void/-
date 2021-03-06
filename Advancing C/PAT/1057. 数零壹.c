// 位运算，isalpha, tolower
//本来以为能想到位运算已经很好了，没想到看到了别人更简洁的代码，学海无涯啊
//如果输入中没有字母的话，即N=0, 有0个0和0个1
/*
1057. 数零壹(20)

给定一串长度不超过105的字符串，本题要求你将其中所有英文字母的序号（字母a-z对应序号1-26，不分大小写）相加，得到整数N，
然后再分析一下N的二进制表示中有多少0、多少1。例如给定字符串“PAT (Basic)”，其字母序号之和为：16+1+20+2+1+19+9+3=71，
而71的二进制是1000111，即有3个0、4个1。

输入格式：
输入在一行中给出长度不超过105、以回车结束的字符串。
输出格式：
在一行中先后输出0的个数和1的个数，其间以空格分隔。

输入样例：
PAT (Basic)
输出样例：
3 4
*/
#include<stdio.h>
#include<ctype.h>
int main()
{
	char c;
	int N=0;
	while((c=getchar())!='\n')
		if(isalpha(c))
			N += tolower(c)-'a'+0;
	int count[2] = {0};
	while(N){
		count[N&1]++;
		N >>= 1;
	}
	printf("%d %d", count[0], count[1]);
}
/*
#include<stdio.h>
#include<string.h>
int main()
{
	char c[100010];
	gets(c);
	int i, N=0; 
	for(i=0; c[i]; i++){
		if(c[i]>='A'&&c[i]<='Z')
			N += c[i]-'A'+1;
		else if(c[i]>='a'&&c[i]<='z')
			N += c[i]-'a'+1;
	}
	int s1=0, s0=0;
	while(N){
		if(N&1)
			s1++;
		else 
			s0++;
		N = N>>1;
	}
	printf("%d %d", s0, s1);
}
*/
