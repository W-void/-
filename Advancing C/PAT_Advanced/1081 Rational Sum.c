//  虽然乘积可能超过int，但没有数据测这块，否则abs函数应该会出错
/*
1081 Rational Sum (20)（20 分）

Given N rational numbers in the form "numerator/denominator", you are supposed to calculate their sum.
Input Specification:
Each input file contains one test case. Each case starts with a positive integer N (<=100), followed in the next line N rational
numbers "a1/b1 a2/b2 ..." where all the numerators and denominators are in the range of "long int". If there is a negative number, 
then the sign must appear in front of the numerator.
Output Specification:
For each test case, output the sum in the simplest form "integer numerator/denominator" where "integer" is the integer part of the sum,
"numerator" < "denominator", and the numerator and the denominator have no common factor. You must output only the fractional part if 
the integer part is 0.
Sample Input 1:
5
2/5 4/15 1/30 -2/60 8/3
Sample Output 1:
3 1/3
Sample Input 2:
2
4/3 2/3
Sample Output 2:
2
Sample Input 3:
3
1/3 -1/6 1/8
Sample Output 3:
7/24
*/
#include<stdio.h>
#include<math.h>
typedef long long ll;
typedef struct {
  ll up, down;
}fraction;
int gcd(ll a, ll b)
{
  return b==0 ? a : gcd(b, a%b);
}

fraction reduction(fraction a)
{
  if(a.down < 0){
    a.down *= -1;
    a.up *= -1;
  }
  if(a.up == 0)
    a.down = 1;
  else{
    int d = gcd(abs(a.up), abs(a.down));
    a.up /= d;
    a.down /= d;
  }
  return a;
}
fraction add(fraction a, fraction b)
{
  fraction ans;
  ans.up = a.up * b.down + a.down * b.up;
  ans.down = a.down * b.down;
  return reduction(ans);
}
void print(fraction a)
{
  if(a.down == 1)  printf("%lld", a.up);
  else if(abs(a.up)>abs(a.down))
    printf("%lld %lld/%lld", a.up/a.down, abs(a.up)%a.down, a.down);
  else  
    printf("%lld/%lld", a.up, a.down);
}
int main()
{
  int N, i;
  scanf("%d", &N);
  fraction sum, tmp;
  sum.up = 0, sum.down = 1;
  for(i=0; i<N; i++){
    scanf("%lld/%lld", &tmp.up, &tmp.down);
    tmp = reduction(tmp);
    sum = add(sum, tmp);
  }
  print(sum);
}
