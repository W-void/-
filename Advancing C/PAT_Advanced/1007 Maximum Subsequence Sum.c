/*
1007 Maximum Subsequence Sum（25 分）

Given a sequence of K integers { N1, N2, ..., NK }. A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj } where 1 <= i <= j <= 
K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 
11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:

Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (<= 10000). The 
second line contains K numbers, separated by a space.

Output Specification:

For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The 
numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is 
not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its 
maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
*/
#include<stdio.h>
const int maxn = 10010;
int main()
{
    int n, i, a[maxn], f = 0;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", a+i);
        if(a[i] >= 0)  f = 1;
    }
    if(f == 0){
        printf("0 %d %d", a[0], a[n-1]);
        return 0;
    }
    int dp[maxn], s[maxn];
    dp[0] = a[0];
    for(i=1; i<n; i++){
        if(dp[i-1] < 0){
            dp[i] = a[i];
            s[i] = i;
        }
        else{
            dp[i] = dp[i-1] + a[i];
            s[i] = s[i-1];
        }
    }
    int k = 0;
    for(i=1; i<n; i++){
        if(dp[k] < dp[i])
            k = i;
    }
    printf("%d %d %d", dp[k], a[s[k]], a[k]);
}
