// 水
/*
1050 String Subtraction (20)（20 分）提问

Given two strings S~1~ and S~2~, S = S~1~ - S~2~ is defined to be the remaining string after taking all the characters in S~2~ from S~1~. Your task is simply to calculate S~1~ - S~2~ for any given strings. However, it might not be that simple to do it fast.
Input Specification:
Each input file contains one test case. Each case consists of two lines which gives S~1~ and S~2~, respectively. The string lengths of both strings are no more than 10^4^. It is guaranteed that all the characters are visible ASCII codes and white space, and a new line character signals the end of a string.
Output Specification:
For each test case, print S~1~ - S~2~ in one line.
Sample Input:
They are students.
aeiou
Sample Output:
Thy r stdnts.
*/
#include<stdio.h>

int main()
{
  char a[10010];
  int b[200]={0}, i;
  gets(a);
  char c;
  while((c=getchar())!='\n')
    b[c]++;
  for(i=0; a[i]; i++)  if(!b[a[i]])
    putchar(a[i]);
}
