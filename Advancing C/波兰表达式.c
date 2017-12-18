#include<stdio.h>
#include<stdlib.h>

double exp()
{
	char s[20]; //因为是浮点型
	scanf("%s", s);
	switch(s[0]){
		case '+': return exp() + exp();
		case '-': return exp() - exp();
		case '*': return exp() * exp();
		case '/': return exp() / exp();
		default: return atof(s);
		
	}
}
int main()
{
	printf("%lf", exp());
	return 0;
}
