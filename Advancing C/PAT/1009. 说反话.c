//%s输出不以空格为结束标志，只认'\0
/*
1009. 说反话 (20)

给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入格式：测试输入包含一个测试用例，在一行内给出总长度不超过80的字符串。字符串由若干单词和若干空格组成，
其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用1个空格分开，输入保证句子末尾没有多余的空格。
输出格式：每个测试用例的输出占一行，输出倒序后的句子。

输入样例：
Hello World Here I Come
输出样例：
Come I Here World Hello
*/
#include<stdio.h>
#include<string.h>

int main()
{
	char c[81] = {0};
	gets(c);
	int i=strlen(c), j;
	c[i] = ' '; //简化后面的判断
	for(i--; i>0; i--){
		if(c[i]==' '){
			//printf("%s ", c+i+1);原本以为%s输出也以空格为结束标志
			j = i;
			while(c[++j]!=' ') printf("%c", c[j]);
			printf(" ");
		}
	}
	while(c[i]!=' ') printf("%c", c[i++]);
	return 0;
}
	
