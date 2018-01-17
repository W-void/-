//不同进制下的结果可能为负号的减法运算
/*
1037. 在霍格沃茨找零钱（20）

如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，
二十九个纳特(Knut)兑一个西可，很容易。”现在，给定哈利应付的价钱P和他实付的钱A，你的任务是写一个程序来计算他应该被找的零钱。

输入格式：
输入在1行中分别给出P和A，格式为“Galleon.Sickle.Knut”，其间用1个空格分隔。
这里Galleon是[0, 107]区间内的整数，Sickle是[0, 17)区间内的整数，Knut是[0, 29)区间内的整数。
输出格式：
在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。

输入样例1：
10.16.27 14.1.28
输出样例1：
3.2.1
输入样例2：
14.1.28 10.16.27
输出样例2：
-3.2.1
*/
#include<stdio.h>
struct money{
	int G, S, K;
}P, A, zhaoling;
int main()
{
	scanf("%d.%d.%d %d.%d.%d",&P.G, &P.S, &P.K, &A.G, &A.S, &A.K);
	int sum1 = (P.G*17+P.S)*29+P.K;
	int sum2 = (A.G*17+A.S)*29+A.K;
	int f=0;
	if(sum1>sum2){
		int tmp=sum1; sum1=sum2; sum2=tmp; f=1;
	}
	sum2 -= sum1;
	zhaoling.K = sum2%29;
	zhaoling.S = sum2/29%17;
	zhaoling.G = sum2/29/17;
	
	printf(f?"-%d.%d.%d":"%d.%d.%d", zhaoling.G, zhaoling.S, zhaoling.K);

	return 0;
}
