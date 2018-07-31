// 有趣的一道题
/*
1049 Counting Ones (30)（30 分）

The task is simple: given any positive integer N, you are supposed to count the total number of 1's in the decimal form of the integers
from 1 to N. For example, given N being 12, there are five 1's in 1, 10, 11, and 12.
Input Specification:
Each input file contains one test case which gives the positive N (<=2^30^).
Output Specification:
For each test case, print the number of 1's in one line.
Sample Input:
12
Sample Output:
5
*/
#include<stdio.h>

int main()
{
        int N;
        scanf("%d", &N);
        int cnt = 0, now, left, right, a = 1;
        while(N/a){ // 求每一位 1 出现的次数
                right = N%a;
                now = N/a%10;
                left = N/a/10;
                if(now == 0) cnt += left * a;
                else if(now == 1) cnt += left * a + right +1;
                else cnt += (left + 1) * a;
                a *= 10;
        }
        printf("%d", cnt);
}
