//有两个测试点会大于int，要用long long
/*
1040. 有几个PAT（25）

字符串APPAPT中包含了两个单词“PAT”，其中第一个PAT是第2位(P),第4位(A),第6位(T)；第二个PAT是第3位(P),第4位(A),第6位(T)。
现给定字符串，问一共可以形成多少个PAT？

输入格式：
输入只有一行，包含一个字符串，长度不超过105，只包含P、A、T三种字母。
输出格式：
在一行中输出给定字符串中包含多少个PAT。由于结果可能比较大，只输出对1000000007取余数的结果。

输入样例：
APPAPT
输出样例：
2
*/
#include<stdio.h>
#include<string.h>
int main()
{
	char c[100010];
	long long int numP=0, numPA=0, numPAT=0;//有两个测试点会大于int
	gets(c);
	int i;
	for(i=0; i<strlen(c); i++){
		if(c[i]=='P') numP++;
		else if(c[i]=='A') numPA += numP;//每出现一个A，就会和前面所有的P组成新的PA
		else numPAT += numPA;//每出现一个T，就会和前面所有的PA组成新的PAT
	}
	printf("%d", numPAT%1000000007);
	return 0;
}
