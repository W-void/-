#include<stdio.h>
int main()
{
	int h1, a1, c1, h2, a2;
	scanf("%d%d%d%d%d", &h1, &a1, &c1, &h2, &a2);
	int x, y=0;
	x = (h2-1)/a1+1; //h2 整出 a1 时，代表刚好能杀死怪兽，不需要加 1 
	if(a2*(x-1)>=h1) y = (a2*(x-1)-h1)/(c1-a2) +1;   // 当可以直接杀死怪兽时，y 不需要赋值，当分子乘除分母时，意味着怪兽刚好能杀死玩家 
	printf("%d\n", x+y);
	while(y--) printf("HEAL\n");
	while(x--) printf("STRIKE\n");
	
}
