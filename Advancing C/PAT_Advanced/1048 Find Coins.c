//  水
/*
1048 Find Coins (25)（25 分）提问

Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she could only use exactly two coins to pay the exact amount. Since she has as many as 10^5^ coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find two coins to pay for it.
Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (<=10^5^, the total number of coins) and M(<=10^3^, the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers no more than 500. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print in one line the two face values V~1~ and V~2~ (separated by a space) such that V~1~ + V~2~ = M and V~1~ <= V~2~. If such a solution is not unique, output the one with the smallest V~1~. If there is no solution, output "No Solution" instead.
Sample Input 1:
8 15
1 2 8 7 2 4 11 15
Sample Output 1:
4 11
Sample Input 2:
7 14
1 8 7 2 4 11 15
Sample Output 2:
No Solution
*/
#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b)
{
  return *(int*)a - *(int*)b;
}

int main()
{
  int N, M, a[100010], i, j;
  scanf("%d%d", &N, &M);
  for(i=0, j=0; j<N; i++, j++){
    scanf("%d", a+i);
    if(a[i]>=M)  i--;
  }
  qsort(a, i, sizeof(int), cmp);
  for(j=0, i--; j<i;){
    if(a[j]+a[i]>M)  i--;
    else if(a[j]+a[i]<M) j++;
    else break;
  }
  if(j>=i)
    puts("No Solution");
  else
    printf("%d %d", a[j], a[i]);
}
