// %s 结尾会自动加'\0',字符串为10的数组大小至少应为11
/*
读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

输入格式：每个测试输入包含1个测试用例，
格式为
  第1行：正整数n
  第2行：第1个学生的姓名 学号 成绩
  第3行：第2个学生的姓名 学号 成绩
  ... ... ...
  第n+1行：第n个学生的姓名 学号 成绩
其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。

输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。

输入样例：
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95

输出样例：
Mike CS991301
Joe Math990112
*/

#include<stdio.h>
#include<string.h>
struct stu{
	char name[11];
	char number[11];
	int score;
}min, max;

int main()
{
	min.score = 100;
	max.score = 0;
	int n, a;
	scanf("%d", &n);
	char c1[11], c2[11];
	while(n--){
		scanf("%s", c1);
		scanf("%s", c2);
		scanf("%d", &a);
		if(a>max.score){
			strcpy(max.name, c1);
			strcpy(max.number, c2);
			max.score = a;
		}
		if(a<min.score){
			strcpy(min.name, c1);
			strcpy(min.number, c2);
			min.score = a;
		}
	}
	printf("%s %s\n%s %s", max.name, max.number, min.name, min.number);	
}
