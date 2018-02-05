//strtok大法好，strtok在切割字符串的时间，实际上就是将分割符的字符delimiter替换为'\0'并且返回首地址，会改变原来的数据！
//这道题蛮坑的，主要是若能被13乘除，末尾的0是不写的，剩下的就是格式问题了，末尾不能有空格
/*函数功能： 
  切割字符串，将str切分成一个个子串 
函数参数： 
  str：在第一次被调用的时间str是传入需要被切割字符串的首地址；在后面调用的时间传入NULL。 
  delimiters：表示切割字符串（字符串中每个字符都会 当作分割符）。 
函数返回值： 
  当s中的字符查找到末尾时，返回NULL; 
  如果查不到delimiter所标示的字符，则返回当前strtok的字符串的指针。*/
/*
1044. 火星数字(20)

火星人是以13进制计数的：

地球人的0被火星人称为tret。
地球人数字1到12的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
火星人将进位以后的12个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
例如地球人的数字“29”翻译成火星文就是“hel mar”；而火星文“elo nov”对应地球数字“115”。为了方便交流，请你编写程序实现地球和火星数字之间的互译。

输入格式：
输入第一行给出一个正整数N（<100），随后N行，每行给出一个[0, 169)区间内的数字 —— 或者是地球文，或者是火星文。
输出格式：
对应输入的每一行，在一行中输出翻译后的另一种语言的数字。

输入样例：
4
29
5
elo nov
tam
输出样例：
hel mar
may
115
13
*/
#include<stdio.h>
#include<string.h>

int main()
{
	char c1[][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
	char c2[][4] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
	int n;
	scanf("%d", &n);
	getchar();
	int i;
	char c[100][10];
	for(i=0; i<n; i++){
		gets(c[i]);	
	}
	for(i=0; i<n; i++){
		if(c[i][0]>='0' && c[i][0]<='9'){
			int sum=0, j=0;
			while(c[i][j]){
				sum = sum*10 + c[i][j] - '0';
				j++;
			}
			if(sum/13){
				printf("%s", c2[sum/13-1]);
				sum %= 13;
				if(sum) printf(" %s", c1[sum]);
				putchar('\n');
			}
			else
				printf("%s\n", c1[sum]);
		}
		else{
			int j, sum = 0;
			char *c3=strtok(c[i], " ");
			for(j=0; j<12; j++){
				if(!strcmp(c3, c2[j])){
					sum = (j+1)*13;
					c3 = strtok(NULL, " ");
					break;
				}
			}
			if(c3!=NULL){
				for(j=0; j<13; j++){
					if(!strcmp(c3, c1[j])){
						sum = sum + j;
						break;
					}
				}
			}	
			printf("%d\n", sum);
		}
	}
	return 0;
}
