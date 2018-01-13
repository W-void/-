//连续的%c需要getchar回收回车
//一直有一个2分的测试点错误
//%c输入数据存在的问题：http://www.icourse163.org/learn/HIT-69005?tid=1002224001#/learn/content?type=detail&id=1002961178&cid=1003430413&replay=true
/*
1018. 锤子剪刀布 (20)

大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：
现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：
输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。
C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。
输出格式：
输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。
如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int change(char c)
{
	switch(c){
		case 'B': return 0;
		case 'C': return 1;
		case 'J': return 2;
	}
}
int main()
{
	int N;
	scanf("%d", &N);
	char a, b; //甲a乙b
	int aa, bb; //将字符转换成数字方便比较
	int count[3]={0};//记录胜负的次数
	int a1[3]={0};//记录甲每个手势的胜利次数
	int b1[3]={0};
	while(N--){
		getchar();//连续的%c需要getchar回收回车
		scanf("%c %c", &a, &b);
		aa = change(a);
		bb = change(b);
		if(aa==bb)
			count[1]++;//平了
		else if((aa+1)%3==bb){
			count[0]++;//甲胜
			a1[aa]++;//胜利的手势次数加一
		}		
		else{
			count[2]++;//甲败
			b1[bb]++;
		} 
	}
	printf("%d %d %d\n", count[0], count[1], count[2]);
	printf("%d %d %d\n", count[2], count[1], count[0]);
	int maxa=0, maxb=0;
	if(a1[maxa]<a1[1]) maxa=1;
	if(a1[maxa]<a1[2]) maxa=2;
	if(a1[maxb]<b1[1]) maxb=1;
	if(a1[maxb]<b1[2]) maxb=2;
	char c[3] = {'B', 'C', 'J'};
	printf("%c %c", c[maxa], c[maxb]);
}
