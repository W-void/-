/*
1089 Insert or Merge（25 分）提问

According to Wikipedia:
Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.
Merge sort works as follows: Divide the unsorted list into N sublists, each containing 1 element (a list of 1 element is considered sorted). Then repeatedly merge two adjacent sublists to produce new sorted sublists until there is only 1 sublist remaining.
Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?
Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (≤100). Then in the next line, N integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.
Output Specification:

For each test case, print in the first line either "Insertion Sort" or "Merge Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resuling sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.
Sample Input 1:

10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
Sample Output 1:

Insertion Sort
1 2 3 5 7 8 9 4 6 0
Sample Input 2:

10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
Sample Output 2:

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
  for(cnt=2; cnt<=N/2; cnt*=2){
    for(i=cnt; i<N; i+=cnt*2)
      if(b[i-1]>b[i]){
        f=1;
        break;
      }
    if(f) break;
  } 
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
  int m;
  for(i=1; i<N; i++)
    if(b[i]<b[i-1]){
      m = i;
      break;
    }  
  for(; i<N; i++)
    if(b[i]!=a[i])  break;
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
