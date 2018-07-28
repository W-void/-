//
/*
1035 插入与归并（25 分）提问

根据维基百科的定义：
插入排序是迭代算法，逐一获得输入数据，逐步产生有序的输出序列。每步迭代中，算法从输入序列中取出一元素，将之插入有序序列中正确的位置。如此迭代直到全部元素有序。
归并排序进行如下迭代操作：首先将原始序列看成 N 个只包含 1 个元素的有序子序列，然后每次迭代归并两个相邻的有序子序列，直到最后只剩下 1 个有序的序列。
现给定原始序列和由某排序算法产生的中间序列，请你判断该算法究竟是哪种排序算法？
输入格式：

输入在第一行给出正整数 N (≤100)；随后一行给出原始序列的 N 个整数；最后一行给出由某排序算法产生的中间序列。这里假设排序的目标序列是升序。数字间以空格分隔。
输出格式：

首先在第 1 行中输出Insertion Sort表示插入排序、或Merge Sort表示归并排序；然后在第 2 行中输出用该排序算法再迭代一轮的结果序列。题目保证每组测试的结果是唯一的。数字间以空格分隔，且行首尾不得有多余空格。
输入样例 1：

10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
输出样例 1：

Insertion Sort
1 2 3 5 7 8 9 4 6 0
输入样例 2：

10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
输出样例 2：

Merge Sort
1 2 3 8 4 5 7 9 0 6
*/
#include<stdio.h>
#include<stdlib.h>

int *a, *b, N;
void print()
{
  int i;
  printf("%d", b[0]);
  for(i=1; i<N; i++)
    printf(" %d", b[i]);
}
int cmp(const void* a, const void* b)
{
  return *(int*)a - *(int*)b;
}
int min(int a, int b)
{
  return a<b?a:b;
}
void Merge()
{
  int cnt, i, f=0;
  //连续子序列至少为2，则从4开始判断
  for(cnt=2; cnt<=N/2; cnt*=2){
    for(i=cnt; i<N; i+=cnt*2)
      if(b[i-1]>b[i]){
        f=1;
        break;
      }
    if(f) break;
  } 
  // cnt中存的是子序列长度，这时需要对cnt*2的长度进行排序
  for(i=0; i<N; i+=cnt*2)
    qsort(b+i, min(cnt*2, N-i), sizeof(int), cmp);
  print();
}

int main()
{
  int i;
  scanf("%d", &N);
  a = (int*)malloc(sizeof(int) * N);
  b = (int*)malloc(sizeof(int) * N);
  for(i=0; i<N; i++)
    scanf("%d", a+i);
  for(i=0; i<N; i++)
    scanf("%d", b+i);
  //判断是否为插入排序
  int m;//记录插入排序进行到哪一步了
  for(i=1; i<N; i++)
    if(b[i]<b[i-1]){
      m = i;
      break;
    }  
  for(; i<N; i++)
    if(b[i]!=a[i])  break;
  // i==N说明是插入排序
  if(i == N){
    printf("Insertion Sort\n");
    qsort(b, m+1, sizeof(int), cmp);
    print();
  }
  else{
    printf("Merge Sort\n");
    Merge();
  }
}
