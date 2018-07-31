//  ! 优先级高于 %
/*
1015 Reversible Primes (20)（20 分）

A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal
system 73 is a reversible prime because its reverse 37 is also a prime.
Now given any two positive integers N (< 10^5^) and D (1 < D <= 10), you are supposed to tell if N is a reversible prime with radix D.
Input Specification:
The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by
a negative N.
Output Specification:
For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.
Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No
*/
#include<stdio.h>
#include<math.h>
int isPrime(int N)
{
  if(N<2) return 0;
  int i, s = sqrt(N);
  for(i=2; i<=s; i++) if(N % i==0) //不能if(!N % i)
    return 0;
  return 1;
}
int main()
{ 
  int N, D;
  int a[100];
  while(scanf("%d%d", &N, &D) == 2){
    if(isPrime(N)){
      int len=0;
      while(N){
        a[len++] = N % D;
        N /= D;
      }
      int i;
      for(i=0; i<len; i++)
        N = N * D + a[i];
      if(isPrime(N))  puts("Yes");
      else puts("No");
    }
    else puts("No");
  }
}
