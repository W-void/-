// 将float改为double就会出错
/*
1070 Mooncake (25)（25 分）提问

Mooncake is a Chinese bakery product traditionally eaten during the Mid-Autumn Festival. Many types of fillings and crusts can be found in traditional mooncakes according to the region's culture. Now given the inventory amounts and the prices of all kinds of the mooncakes, together with the maximum total demand of the market, you are supposed to tell the maximum profit that can be made.
Note: partial inventory storage can be taken. The sample shows the following situation: given three kinds of mooncakes with inventory amounts being 180, 150, and 100 thousand tons, and the prices being 7.5, 7.2, and 4.5 billion yuans. If the market demand can be at most 200 thousand tons, the best we can do is to sell 150 thousand tons of the second kind of mooncake, and 50 thousand tons of the third kind. Hence the total profit is 7.2 + 4.5/2 = 9.45 (billion yuans).
Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers N (<=1000), the number of different kinds of mooncakes, and D (<=500 thousand tons), the maximum total demand of the market. Then the second line gives the positive inventory amounts (in thousand tons), and the third line gives the positive prices (in billion yuans) of N kinds of mooncakes. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print the maximum profit (in billion yuans) in one line, accurate up to 2 decimal places.
Sample Input:
3 200
180 150 100
7.5 7.2 4.5
Sample Output:
9.45
*/
#include<stdio.h>
#include<stdlib.h>

struct yuebing{
	double a, b;//a为库存，b为总售价，刚开始以为是int型，有两个小测试点过不了
	float c; //将float 改成 double就会出错，很奇怪
}*str;
int cmp(void const *x, void const *y)
{
	return (*(struct yuebing*)y).c > (*(struct yuebing*)x).c ;
}

int main()
{
	int n;
	double m;
	scanf("%d%lf", &n, &m);
	str = (struct yuebing*)malloc(n*sizeof(struct yuebing));
	int i;
	for(i=0; i<n; i++){
		scanf("%lf", &str[i].a);
	}
	for(i=0; i<n; i++){
		scanf("%lf", &str[i].b);
		str[i].c = str[i].b/str[i].a;
	}
	qsort(str, n, sizeof(str[0]), cmp);
	double sum = 0;
	for(i=0; m>=str[i].a; i++){
		sum += str[i].b;
		m -= str[i].a;
	}
	sum += m*str[i].c;
	printf("%.2f", sum);
	return 0;
}
