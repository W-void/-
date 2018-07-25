//  很有意思的贪心
/*
1033 To Fill or Not to Fill (25)（25 分）提问

With highways available, driving a car from Hangzhou to any other city is easy. But since the tank capacity of a car is limited, we have to find gas stations on the way from time to time. Different gas station may give different price. You are asked to carefully design the cheapest route to go.
Input Specification:
Each input file contains one test case. For each case, the first line contains 4 positive numbers: C~max~ (<= 100), the maximum capacity of the tank; D (<=30000), the distance between Hangzhou and the destination city; D~avg~ (<=20), the average distance per unit gas that the car can run; and N (<= 500), the total number of gas stations. Then N lines follow, each contains a pair of non-negative numbers: P~i~, the unit gas price, and D~i~ (<=D), the distance between this station and Hangzhou, for i=1,...N. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print the cheapest price in a line, accurate up to 2 decimal places. It is assumed that the tank is empty at the beginning. If it is impossible to reach the destination, print "The maximum travel distance = X" where X is the maximum possible distance the car can run, accurate up to 2 decimal places.
Sample Input 1:
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
Sample Output 1:
749.17
Sample Input 2:
50 1300 12 2
7.10 0
7.00 600
Sample Output 2:
The maximum travel distance = 1200.00
*/
#include<stdio.h>
#include<stdlib.h>
struct gnode{
  float p, d;
}sta[505];
int cmp(const void* a, const void* b)
{
  return ((struct gnode*)a)->d - ((struct gnode*)b)->d;
}
int main()
{
  int N, i, j, k;
  float C, D, avg, min, max, d = 0;
  scanf("%f%f%f%d", &C, &D, &avg, &N);
  for(i=0; i<N; i++)
    scanf("%f%f", &sta[i].p, &sta[i].d);
  sta[N].p = 0, sta[N].d = D;
  qsort(sta, N+1, sizeof(sta[0]), cmp);
  max = avg * C;
  if(sta[0].d != 0){
    printf("The maximum travel distance = 0.00");
    return 0;
  }
  float price = 0, nowTank = 0;
  for(i=0; i<N; ){
    for(j=i+1, min=1<<30, k=-1; sta[j].d-sta[i].d<=max && j<=N; j++){
      if(min>sta[j].p){
        min = sta[j].p;
        k = j;
      }
      if(min<sta[i].p)
        break;
    }
    if(k==-1) break;
    float need = (sta[k].d - sta[i].d)/avg;
    if(sta[k].p<sta[i].p){
      if(nowTank<need){
        price += sta[i].p * (need - nowTank);
        nowTank = 0;
      }
      else{
        nowTank -= need;
      }
    }
    else{
      price += sta[i].p * (C - nowTank);
      nowTank = C - (sta[k].d - sta[i].d)/avg;
    }
    i = k;
  }
  if(i==N)
    printf("%.2f", price);
  else
    printf("The maximum travel distance = %.2f", sta[i].d+max);
}
