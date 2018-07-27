// 这道题一共有20个测试点，你就知道坑有多多，比如很容易让人以为进制都是小于37的；
// 明确了进制的那个数是不会超过longlong的，但在算另一个数的时候却可能溢出；
// 我并没有用二分法，所以测试点7过不了
/*
1010 Radix (25)（25 分）提问

Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is "yes", if 6 is a decimal number and 110 is a binary number.
Now for any pair of positive integers N1 and N2, your task is to find the radix of one number while that of the other is given.
Input Specification:
Each input file contains one test case. Each case occupies a line which contains 4 positive integers:\ N1 N2 tag radix\ Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the set {0-9, a-z} where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number "radix" is the radix of N1 if "tag" is 1, or of N2 if "tag" is 2.
Output Specification:
For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print "Impossible". If the solution is not unique, output the smallest possible radix.
Sample Input 1:
6 110 1 10
Sample Output 1:
2
Sample Input 2:
1 ab 1 2
Sample Output 2:
Impossible
*/
#include<stdio.h>
#include<string.h>

void change(char *N1, char *N2)
{
  char tmp[20];
  strcpy(tmp, N1);
  strcpy(N1, N2);
  strcpy(N2, tmp);
}
int toDigit(char c)
{
  if(c<='9')
    return c-'0';
  else
    return c-'a'+10;
}
long long to10(char *N, int r)
{
  int i = -1;
  long long sum = 0;
  while(N[++i]){
    sum = sum * r + toDigit(N[i]);
    if(sum<0)
      return -1;
  }                                                                                                                              
  return sum;
}
int max(char* N)
{
  int i, max = 0, tmp;
  for(i=0; N[i]; i++){
    tmp = toDigit(N[i]);
    max = max>tmp?max:tmp;
  }
  return max;
}
int main()
{
  int tag, radix, i;
  char N1[15], N2[15];
  scanf("%s%s%d%d", N1, N2, &tag, &radix);
  if(tag==2)
    change(N1, N2);
  long long a = to10(N1, radix);
  int c = max(N2);
  long long b;
  for(i=c+1; ; i++){
    b = to10(N2, i);
    if(a==b){
      printf("%d", i);
      return 0;
    }
    else if(a<b || b<0)
      break;
  }
  puts("Impossible");
}
