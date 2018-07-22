//看了warning才发现错的原因，<<的优先级比+号低
/*
1028 List Sorting (25)（25 分）

Excel can sort records according to any column. Now you are supposed to imitate this function.
Input
Each input file contains one test case. For each case, the first line contains two integers N (<=100000) and C, where N is the number of records and C is the column that you are supposed to sort the records with. Then N lines follow, each contains a record of a student. A student's record consists of his or her distinct ID (a 6-digit number), name (a string with no more than 8 characters without space), and grade (an integer between 0 and 100, inclusive).
Output
For each test case, output the sorting result in N lines. That is, if C = 1 then the records must be sorted in increasing order according to ID's; if C = 2 then the records must be sorted in non-decreasing order according to names; and if C = 3 then the records must be sorted in non-decreasing order according to grades. If there are several students who have the same name or grade, they must be sorted according to their ID's in increasing order.
Sample Input 1
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
Sample Output 1
000001 Zoe 60
000007 James 85
000010 Amy 90
Sample Input 2
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98
Sample Output 2
000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60
Sample Input 3
4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
Sample Output 3
000001 Zoe 60
000007 James 85
000002 James 90
000010 Amy 90
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
  int id, score;
  char name[10];
}stu[100001];
int C;
int cmp(const void* x, const void* y)
{
  struct student* a = (struct student*)x;
  struct student* b = (struct student*)y;
  if(C==1) return a->id - b->id;
  else if(C==2) #include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
  int id, score;
  char name[10];
}stu[100001];
int C;
int cmp(const void* x, const void* y)
{
  struct student* a = (struct student*)x;
  struct student* b = (struct student*)y;
  if(C==1) return a->id - b->id;
  else if(C==2) return (strcmp(a->name, b->name)<<1) + a->id>b->id?1:-1;
  else return ((a->score - b->score)<<1) + a->id>b->id?1:-1;
}
int main()
{
  int  N, i;
  scanf("%d%d", &N, &C);
  for(i=0; i<N; i++)
    scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].score);
  qsort(stu, N, sizeof(stu[0]), cmp);
  for(i=0; i<N; i++)
    printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
  return 0;
}
  else return ((a->score - b->score)<<1) + a->id>b->id?1:-1;
}
int main()
{
  int  N, i;
  scanf("%d%d", &N, &C);
  for(i=0; i<N; i++)
    scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].score);
  qsort(stu, N, sizeof(stu[0]), cmp);
  for(i=0; i<N; i++)
    printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
  
}
