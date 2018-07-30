/*
1104 Sum of Number Segments (20)（20 分）提问

Given a sequence of positive numbers, a segment is defined to be a consecutive subsequence. For example, given the sequence {0.1, 0.2, 0.3, 0.4}, we have 10 segments: (0.1) (0.1, 0.2) (0.1, 0.2, 0.3) (0.1, 0.2, 0.3, 0.4) (0.2) (0.2, 0.3) (0.2, 0.3, 0.4) (0.3) (0.3, 0.4) (0.4).
Now given a sequence, you are supposed to find the sum of all the numbers in all the segments. For the previous example, the sum of all the 10 segments is 0.1 + 0.3 + 0.6 + 1.0 + 0.2 + 0.5 + 0.9 + 0.3 + 0.7 + 0.4 = 5.0.
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N, the size of the sequence which is no more than 10^5^. The next line contains N positive numbers in the sequence, each no more than 1.0, separated by a space.
Output Specification:
For each test case, print in one line the sum of all the numbers in all the segments, accurate up to 2 decimal places.
Sample Input:
4
0.1 0.2 0.3 0.4 
Sample Output:
5.00
*/
#include<stdio.h>

int main()
{
	double sum = 0, x;
	int n;
	scanf("%d", &n);
	int i;
	for(i=0; i<n; i++){
		scanf("%lf", &x);
        //关键就是找出每个数出现的次数，总次数=以这个数为第一个数的片段数+不以这个数为第一个数的片段数
		sum += x*((n-i)+(long long int)i*(n-i));//转换成long long型，否则会有两个测试点过不了
	}
	printf("%.2f", sum);
	return 0;
}
