// 理解题意很重要
/*
1096 Consecutive Factors (20)（20 分）

Among all the factors of a positive integer N, there may exist several consecutive numbers. For example, 630 can be factored as 
3*5*6*7, where 5, 6, and 7 are the three consecutive numbers. Now given any positive N, you are supposed to find the maximum number of 
consecutive factors, and list the smallest sequence of the consecutive factors.
Input Specification:
Each input file contains one test case, which gives the integer N (1<N<2^31^).
Output Specification:
For each test case, print in the first line the maximum number of consecutive factors. Then in the second line, print the smallest 
sequence of the consecutive factors in the format "factor[1]*factor[2]*...*factor[k]", where the factors are listed in increasing 
order, and 1 is NOT included.
Sample Input:
630
Sample Output:
3
5*6*7
*/
#include<stdio.h>

typedef long long ll;
int main()
{
    ll N;
    scanf("%lld", &N);
    int sqr = sqrt(N);
    int i, j, max = 0, len, max_i, tmp;
    for(i=2; i<=sqr; i++){
        tmp = i,j = i, len = 0;
        while(N %tmp == 0){
            len++;
            tmp *= (++j);
        }
        if(max<len){
            max = len;
            max_i = j - len; //记录下第一个因子
        }
    }
    if(!max)    printf("1\n%lld", N); //max还是初始化时的0，说明N只能被自己除
    else{
        printf("%d\n", max);
        for(i=0; i<max; i++)
            printf("%s%d", i ? "*": "", max_i + i);
    }
}
