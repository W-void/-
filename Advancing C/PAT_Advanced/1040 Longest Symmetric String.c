//  动态规划
/*
1040 Longest Symmetric String（25 分）

Given a string, you are supposed to output the length of the longest symmetric sub-string. For example, given Is PAT&TAP symmetric?, the longest symmetric sub-string is s PAT&TAP s, hence you must output 11.
Input Specification:

Each input file contains one test case which gives a non-empty string of length no more than 1000.
Output Specification:

For each test case, simply print the maximum length in a line.
Sample Input:

Is PAT&TAP symmetric?
Sample Output:

11

*/

#include<stdio.h>
#include<string.h>

#define maxn  1010

int main()
{
    char s[maxn];
    gets(s);
    int dp[maxn][maxn] = {0}, len = strlen(s), i, j, l, ans = 1;
    for(i=0; i<len-1; i++){
        dp[i][i] = 1;
        if(s[i] == s[i+1]){
            dp[i][i+1] = 1;
            ans = 2;   //测试数据就没有结果是2的
        }
    }
    dp[i][i] = 1;
    for(l=3; l<=len; l++){ // 从长度为3的子串开始遍历, 注意是 <= 而不是 =
        for(i=0; i <= len-l; i++){ // i为子串左端点
            j = i + l - 1;  // j为子串右端点
            if(s[i] == s[j] && dp[i+1][j-1]){ // 子串的左右端点相同且[i+1, j-1]的子串是回文子串
                dp[i][j] = 1;
                ans = l;
            }
        }
    }
    printf("%d", ans);
}
