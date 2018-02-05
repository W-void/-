//while(scanf("%c", &c), c!=13)是不对的
/*
1042. 字符统计(20)

请编写程序，找出一段给定文字中出现最频繁的那个英文字母。

输入格式：
输入在一行中给出一个长度不超过1000的字符串。字符串由ASCII码表中任意可见字符及空格组成，至少包含1个英文字母，以回车结束（回车不算在内）。
输出格式：
在一行中输出出现频率最高的那个英文字母及其出现次数，其间以空格分隔。如果有并列，则输出按字母序最小的那个字母。统计时不区分大小写，输出小写字母。

输入样例：
This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........
输出样例：
e 7
*/
#include<stdio.h>

int main()
{
	int a[26] = {0};
	char b[1010], c;
	gets(b);
	int i=0;
	while(c=b[i]){ //因为后来改的为了用上前面写的代码，所以会有这么多变量
		if(c>='A' && c<='Z')
			c = c - 'A' + 'a';
		if(c>='a' && c<='z')
			a[c-'a']++;
		i++;
	}
	int max = a[25], index = 25;
	int n;
	for(n=24; n>=0; n--){
		if(max<=a[n]){
			max = a[n];
			index = n;
		}
	}
	printf("%c %d", 'a'+index, max);
	return 0;
}
