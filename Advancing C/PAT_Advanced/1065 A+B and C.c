//tmp因为规定为long long了，所以会被当成负数。 而a+b在2^64和2^63-1 之间会被当做无符号长整型处理。
/*
1065 A+B and C (64bit) (20)（20 分）

Given three integers A, B and C in [-2^63^, 2^63^], you are supposed to tell whether A+B > C.
Input Specification:
The first line of the input gives the positive number of test cases, T (<=10).
Then T test cases follow, each consists of a single line containing three integers A, B and C, separated by single spaces.
Output Specification:
For each test case, output in one line "Case #X: true" if A+B&gtC, or "Case #X: false" otherwise, 
where X is the case number (starting from 1).
Sample Input:
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0
Sample Output:
Case #1: false
Case #2: true
Case #3: false

*/
#include<stdio.h>
int main()
{

  int T, i=1, flag;
  long long A, B, C;
  scanf("%d", &T);
  while(T--){
    scanf("%lld%lld%lld", &A, &B, &C);
    long long tmp = A + B; //没有这行代码会有两个测试点过不了
    if(A>0 && B>0 && tmp<0) flag = 1;
    else if(A<0 && B<0 && tmp>=0) flag = 0;
    else if(A+B>C) flag = 1;
    else flag = 0;
    if(flag)
      printf("Case #%d: true\n", i++);
    else
      printf("Case #%d: false\n", i++);
  }
  return 0;
}
