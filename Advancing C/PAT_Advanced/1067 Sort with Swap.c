// 分为两种情况，一轮交换中包不包括0
/*
1067 Sort with Swap(0,*) (25)（25 分）提问

Given any permutation of the numbers {0, 1, 2,..., N-1}, it is easy to sort them in increasing order. But what if Swap(0, *) is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:
Swap(0, 1) => {4, 1, 2, 0, 3}\ Swap(0, 3) => {4, 1, 2, 3, 0}\ Swap(0, 4) => {0, 1, 2, 3, 4}
Now you are asked to find the minimum number of swaps need to sort the given permutation of the first N nonnegative integers.
Input Specification:
Each input file contains one test case, which gives a positive N (<=10^5^) followed by a permutation sequence of {0, 1, ..., N-1}. All the numbers in a line are separated by a space.
Output Specification:
For each case, simply print in a line the minimum number of swaps need to sort the given permutation.
Sample Input:
10 3 5 7 2 6 4 9 0 8 1
Sample Output:
9
*/
#include<stdio.h>

int main()
{
  int N, i, a[100010];
  scanf("%d", &N);
  for(i=0; i<N; i++)
    scanf("%d", a+i);
  int f, cnt = 0, j = 0, tmp;
  for(i=0, j=0; j<N; j++){
    f = 0;
    i = j;
    if(a[i]==i) continue;
    while(a[i]!=i){
      if(a[i] == 0)  f = 1;
      tmp = a[i];
	    a[i] = i;
      i = tmp;
      cnt++;
    }
    if(f) cnt--;//这一轮交换中有0，次数需要减1
    else  cnt++;//这一轮交换中没有0，次数需要加1
  }
  printf("%d", cnt);
}
