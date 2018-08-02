// 质因子分解
/*
1059 Prime Factors (25)（25 分）提问

Given any positive integer N, you are supposed to find all of its prime factors, and write them in the format N = p~1~\^k~1~ * 
p~2~\^k~2~ *…*p~m~\^k~m~.
Input Specification:
Each input file contains one test case which gives a positive integer N in the range of long int.
Output Specification:
Factor N in the format N = p~1~\^k~1~ * p~2~\^k~2~ *…*p~m~\^k~m~, where p~i~'s are prime factors of N in increasing order, and the 
exponent k~i~ is the number of p~i~ -- hence when there is only one p~i~, k~i~ is 1 and must NOT be printed out.
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
int p[100010] = {0};
void find_prime()
{
  int i, j;
  for(i=2; i<100010; i++){
    //if(isPrime(i))  prime[cnt++] = i;
    if(p[i]==0){
      prime[cnt++] = i;
      for(j=i+i; j<100010; j +=i)//埃氏筛法
        p[j] = 1;
    }
      
  }
}
struct factor{
  int e, c;
}fac[10];
int main()
{
  find_prime();
  int x, i;
  scanf("%d", &x);  
  printf("%d=", x);
  if(x==1)  {printf("1");return 0;}
  int num=0, sqr = sqrt(x);
  for(i=0; x>1 && prime[i]<=sqr; i++){
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
  if(num == 0) printf("%d", x);
  for(i=0; i<num; i++){
    if(i)  putchar('*');
    printf("%d", fac[i].e);
    if(fac[i].c>1)
      printf("^%d", fac[i].c);
  }
}
