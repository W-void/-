// qsort排四次序
/*
1012 The Best Rank (25)（25 分）

To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algebra), and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.
For example, The grades of C, M, E and A - Average of 4 students are given as the following:
StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.
Input
Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (<=2000), which are the total number of students, and the number of students who would check their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. Then there are M lines, each containing a student ID.
Output
For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.
The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.
If a student is not on the grading list, simply output "N/A".
Sample Input
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
Sample Output
1 C
1 M
1 E
1 A
3 A
N/A
*/
#include<stdio.h>
#include<stdlib.h>

struct student{
  int id, grade[4];
}stu[2001];

int idx;
int cmp(const int *a, const int *b)
{
  return ((struct student*)b)->grade[idx] - ((struct student*)a)->grade[idx];
} 
int Rank[1000000][4] = {0};
int min(int tmp)
{
  int i = 0, j;
  for(j=1; j<4; j++){
    if(Rank[tmp][j] < Rank[tmp][i])
      i = j;
  }
  return i;
}

int main()
{
  int N, M, i;
 
  char c[] = {"ACME"};
  scanf("%d %d", &N, &M);
  for(i=0; i<N; i++){
    scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
    stu[i].grade[0] = (stu[i].grade[1]+stu[i].grade[2]+stu[i].grade[3]+1)/3;
  }
  // 为每个分数排序
  for(idx=0; idx<4; idx++){
    //用qsort排四次序，并将顺序记录在Rank数组中
    qsort(stu, N, sizeof(stu[0]), cmp);
    Rank[stu[0].id][idx] = 1;
    for(i=1; i<N; i++)
      if(stu[i].grade[idx] == stu[i-1].grade[idx])
        Rank[stu[i].id][idx] = Rank[stu[i-1].id][idx];
      else
        Rank[stu[i].id][idx] = i + 1;
  }
  //输出
  int tmp;
  for(i=0; i<M; i++){
    scanf("%d", &tmp);
    if(Rank[tmp][0] == 0) 
      puts("N/A");
    else{
      int j = min(tmp);
      printf("%d %c\n", Rank[tmp][j], c[j]);
    }
  }
}
