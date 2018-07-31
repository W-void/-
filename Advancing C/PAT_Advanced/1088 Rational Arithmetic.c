/*
1088 Rational Arithmetic (20)（20 分）

For two rational numbers, your task is to implement the basic arithmetics, that is, to calculate their sum, difference, product and
quotient.
Input Specification:
Each input file contains one test case, which gives in one line the two rational numbers in the format "a1/b1 a2/b2". The numerators
and the denominators are all in the range of long int. If there is a negative sign, it must appear only in front of the numerator. 
The denominators are guaranteed to be non-zero numbers.
Output Specification:
For each test case, print in 4 lines the sum, difference, product and quotient of the two rational numbers, respectively. 
The format of each line is "number1 operator number2 = result". Notice that all the rational numbers must be in their simplest form
"k a/b", where k is the integer part, and a/b is the simplest fraction part. If the number is negative, it must be included in a pair
of parentheses. If the denominator in the division is zero, output "Inf" as the result. 
It is guaranteed that all the output integers are in the range of long int.
Sample Input 1:
2/3 -4/2
Sample Output 1:
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
Sample Input 2:
5/3 0/6
Sample Output 2:
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
*/
#include<stdio.h>
#include<math.h>

long long a1, b1, a2, b2;
long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a%b);
}
void myprint(long long a, long long b)
{
	if(a==0)
		printf("0");
	else{
		long long tmp = abs(gcd(a, b));
		a /= tmp, b /= tmp;
		if(a<0)
			printf("(-");
		if(a/b)
			printf("%lld", abs(a/b));
		if(b!=1){
			if(a/b) putchar(' ');
			printf("%lld", abs(a%b));
			printf("/%lld", b);
		}
		if(a<0)
			putchar(')');			
	}
}
void myprint2(char c)
{
	myprint(a1, b1);
	printf(" %c ", c);
	myprint(a2, b2);
	printf(" = ");
}
int main()
{
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	myprint2('+');
	myprint(a1*b2+a2*b1, b1*b2);
	puts("");
	myprint2('-');
	myprint(a1*b2-a2*b1, b1*b2);
	puts("");
	myprint2('*');
	myprint(a1*a2, b1*b2);
	puts("");
	myprint2('/');
	if(a2>0)
		myprint(a1*b2, b1*a2);
	else if(a2<0)
		myprint(-a1*b2, -b1*a2);
	else puts("Inf");
	
	return 0;
}
