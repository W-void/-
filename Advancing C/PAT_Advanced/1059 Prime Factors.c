/*
1059 Prime Factors (25)（25 分）提问

Given any positive integer N, you are supposed to find all of its prime factors, and write them in the format N = p~1~\^k~1~ * p~2~\^k~2~ *…*p~m~\^k~m~.
Input Specification:
Each input file contains one test case which gives a positive integer N in the range of long int.
Output Specification:
Factor N in the format N = p~1~\^k~1~ * p~2~\^k~2~ *…*p~m~\^k~m~, where p~i~'s are prime factors of N in increasing order, and the exponent k~i~ is the number of p~i~ -- hence when there is only one p~i~, k~i~ is 1 and must NOT be printed out.
Sample Input:
97532468
Sample Output:
97532468=2^2*11*17*101*1291
*/
#include<stdio.h>
#include<math.h>

int prime[100010], cnt = 0;
int isPrime(int a)
{
  int i;
  for(i=2; i<=sqrt(a); i++){
    if(a%i==0)
      return 0;
  }
  return 1;
}
void fine_prime()
{
  int i;
  for(i=2; i<100010; i++){
    if(isPrime(i))
      prime[cnt++] = i;
  }
}
struct factor{
  int e, c;
}fac[10];
int main()
{
  int x, i;
  scanf("%d", &x);  
  printf("%d=", x);
  int num=0;
  for(i=0; x>1; i++){
    if(x%prime[i]==0){
      fac[num].e = prime[i];
      fac[num].c = 0;
      while(x%prime[i]==0){
        fac[num].c++;
        x /= prime[i];
      }
      num++;
    }
  }
  for(i=0; i<num; i++){
    if(i)  putchar('*');
    printf("%d", fac[i].e);
    if(fac[i].c>1)
      printf("^%d", fac[i].c);
  }
}
