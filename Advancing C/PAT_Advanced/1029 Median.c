// 内存超限，很烦
/*
1029 Median（25 分）提问

Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1 = { 11, 12, 13, 14 } is 12, and the median of S2 = { 9, 10, 15, 16, 17 } is 15. The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.
Given two increasing sequences of integers, you are asked to find their median.
Input Specification:

Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N (≤2×10
​5
​​ ) is the size of that sequence. Then N integers follow, separated by a space. It is guaranteed that all the integers are in the range of long int.
Output Specification:

For each test case you should output the median of the two given sequences in a line.
Sample Input:

4 11 12 13 14
5 9 10 15 16 17
Sample Output:

13
*/
#include<stdio.h>
#include<malloc.h>
int main()
{
  int m, n, i;
  scanf("%d", &m);
  
  int* a = (int*)malloc(sizeof(int)*(m+1));
  for(i=0; i<m; i++)
    scanf("%d", a+i);
  a[m] = 1<<30;
  scanf("%d", &n);
  int* b = (int*)malloc(sizeof(int)*(n+1));
  for(i=0; i<n; i++)
    scanf("%d", b+i);
  b[n] = 1<<30;
  int mid = (m+n-1)/2, j=0, cnt=0;
  i=0;
  while(cnt<mid){
    if(a[i]>b[j])  j++;
    else i++;
    cnt++;
  }
  if(a[i]>b[j])  printf("%d", b[j]);
  else printf("%d", a[i]);
}
