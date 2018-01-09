/*
文本压缩有很多种方法，这里我们只考虑最简单的一种：把由相同字符组成的一个连续的片段用这个字符和片段中含有这个字符的个数来表示。
例如 ccccc 就用 5c 来表示。如果字符没有重复，就原样输出。例如 aba 压缩后仍然是 aba。
解压方法就是反过来，把形如 5c 这样的表示恢复为 ccccc。
本题需要你根据压缩或解压的要求，对给定字符串进行处理。这里我们简单地假设原始字符串是完全由英文字母和空格组成的非空字符串。

输入格式：
输入第一行给出一个字符，如果是 C 就表示下面的字符串需要被压缩；如果是 D 就表示下面的字符串需要被解压。第二行给出需要被压缩或解压的不超过1000个字符的字符串，以回车结尾。题目保证字符重复个数在整型范围内，且输出文件不超过1MB。

输出格式：
根据要求压缩或解压字符串，并在一行中输出结果。

输入样例 1：
C
TTTTThhiiiis isssss a   tesssst CAaaa as

输出样例 1：
5T2h4is i5s a3 te4st CA3a as

输入样例 2：
D
5T2h4is i5s a3 te4st CA3a as10Z

输出样例 2：
TTTTThhiiiis isssss a   tesssst CAaaa asZZZZZZZZZZ
*/
#include<stdio.h>
#include<string.h>

char c1[1001];
void yasuo()
{
	int i = -1;
	while(c1[++i]){
		int j = i;
		while(c1[++j] == c1[i]);
		if(j-i > 1)
			printf("%d", j-i);
		putchar(c1[i]);
		i = j - 1;
	}
}
void jieya()
{
	int N = strlen(c1);
	int i, d;
	for(i=0; i<N; i++){
		if(c1[i]>'0' && c1[i]<='9'){
			int d = c1[i] - '0';
			while(c1[++i]>='0' && c1[i]<='9'){//数字可能是两位数三位数...
				d = d*10 + c1[i] - '0';
			}
			while(d--){
				putchar(c1[i]);
			}
		}
		else putchar(c1[i]);
	}
}
int main()
{
	char ch;
	scanf("%c", &ch);
	getchar();//回收回车
	gets(c1);
	if(ch=='C')
		yasuo();
	else jieya();
	return 0;
}
