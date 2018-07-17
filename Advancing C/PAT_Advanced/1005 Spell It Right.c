// 巧用sprintf函数
/*
1005 Spell It Right (20)（20 分）

Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.
Input Specification:
Each input file contains one test case. Each case occupies one line which contains an N (<= 10^100^).
Output Specification:
For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, 
but no extra space at the end of a line.
Sample Input:
12345
Sample Output:
one five
*/
#include<stdio.h>

int main()
{
  char c[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  char s[110];
  gets(s);
  int i, sum = 0;
  for(i=0; s[i]; i++)
    sum += s[i] - '0';
  sprintf(s, "%d", sum);
  for(i=0; s[i]; i++)
    printf("%s%s", i?" ":"", c[s[i] - '0']);
}
