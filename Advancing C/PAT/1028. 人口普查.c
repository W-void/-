//需要注意 1.字符数组要初始化 2.当所有的生日都是非法的,只输出0，不然会提示格式错误，如果没有初始化的话，会有一个测试点显示答案错误
/*
1028. 人口普查(20)

某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。

这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过200岁的老人，而今天是2014年9月6日，
所以超过200岁的生日和未出生的生日都是不合理的，应该被过滤掉。

输入格式：
输入在第一行给出正整数N，取值在(0, 105]；随后N行，每行给出1个人的姓名（由不超过5个英文字母组成的字符串）、以及按“yyyy/mm/dd”（即年/月/日）格式给出的生日。题目保证最年长和最年轻的人没有并列。
输出格式：
在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。

输入样例：
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
输出样例：
3 Tom John
*/
#include<stdio.h>
#include<math.h>

int main()
{
	int n;
	scanf("%d", &n);
	int i=0, oldest=20140907, youngest=18141905;//记录有效生日个数
	char name[6], max[6]={0}, min[6]={0};
	int year, month, day;
	while(n--){
		scanf("%s%d/%d/%d", name, &year, &month, &day);
		int j = year*10000+month*100+day;
		if(j<20140907 && j>18140905){
			i++;
			if(j<oldest){
				strcpy(max, name);
				oldest = j;
			} 
			if(j>youngest){
				strcpy(min, name);
				youngest = j;
			} 
		}
	}
	if(i)
		printf("%d %s %s", i, max, min);
	else 
		printf("0");
	return 0;
}
