/*
1080 Graduate Admission (30)（30 分）提问

It is said that in 2013, there were about 100 graduate schools ready to proceed over 40,000 applications in Zhejiang Province. It would help a lot if you could write a program to automate the admission procedure.
Each applicant will have to provide two grades: the national entrance exam grade G~E~, and the interview grade G~I~. The final grade of an applicant is (G~E~ + G~I~) / 2. The admission rules are:
The applicants are ranked according to their final grades, and will be admitted one by one from the top of the rank list.
If there is a tied final grade, the applicants will be ranked according to their national entrance exam grade G~E~. If still tied, their ranks must be the same.
Each applicant may have K choices and the admission will be done according to his/her choices: if according to the rank list, it is one's turn to be admitted; and if the quota of one's most preferred shcool is not exceeded, then one will be admitted to this school, or one's other choices will be considered one by one in order. If one gets rejected by all of preferred schools, then this unfortunate applicant will be rejected.
If there is a tied rank, and if the corresponding applicants are applying to the same school, then that school must admit all the applicants with the same rank, even if its quota will be exceeded.
Input Specification:
Each input file contains one test case. Each case starts with a line containing three positive integers: N (<=40,000), the total number of applicants; M (<=100), the total number of graduate schools; and K (<=5), the number of choices an applicant may have.
In the next line, separated by a space, there are M positive integers. The i-th integer is the quota of the i-th graduate school respectively.
Then N lines follow, each contains 2+K integers separated by a space. The first 2 integers are the applicant's G~E~ and G~I~, respectively. The next K integers represent the preferred schools. For the sake of simplicity, we assume that the schools are numbered from 0 to M-1, and the applicants are numbered from 0 to N-1.
Output Specification:
For each test case you should output the admission results for all the graduate schools. The results of each school must occupy a line, which contains the applicants' numbers that school admits. The numbers must be in increasing order and be separated by a space. There must be no extra space at the end of each line. If no applicant is admitted by a school, you must output an empty line correspondingly.
Sample Input:
11 6 3
2 1 2 2 2 3
100 100 0 1 2
60 60 2 3 5
100 90 0 3 4
90 100 1 2 0
90 90 5 1 3
80 90 1 0 2
80 80 0 1 2
80 80 0 1 2
80 70 1 3 2
70 80 1 2 3
100 100 0 2 4
Sample Output:
0 10
3
5 6 7
2 8

1 4
*/
#include<stdio.h>
#include<stdlib.h>

struct student{
  int id, ge, gi, sum, r, cho[6], fini;
}stu[40010];
struct school{
  int q, num, last_r;
}sch[110];
int cmp(const void* a, const void* b)
{
  int x = ((struct student*)b)->sum - ((struct student*)a)->sum;
  if(!x){
    x = ((struct student*)b)->ge - ((struct student*)a)->ge;
    if(!x)
      x = ((struct student*)a)->id - ((struct student*)b)->id;
  }
  return x;
}
int cmp2(const void* a, const void* b)
{
  int x = ((struct student*)a)->id - ((struct student*)b)->id;
  return x;
}
int main()
{	   

  int N, M, K, i, j;
  scanf("%d%d%d", &N, &M, &K);
  for(i=0; i<M; i++){
    scanf("%d", &sch[i].q);
    sch[i].num = 0;
    sch[i].last_r = -1;
  }
  for(i=0; i<N; i++){
    scanf("%d%d", &stu[i].ge, &stu[i].gi);
    stu[i].id = i;
    stu[i].sum = stu[i].ge + stu[i].gi;
    stu[i].fini = -1;
    for(j=0; j<K; j++)
      scanf("%d", &stu[i].cho[j]);
  }
  qsort(stu, N, sizeof(stu[0]), cmp);
  int r = 0;
  for(i=0; i<N; i++){
    if(i && (stu[i].sum!=stu[i-1].sum || stu[i].ge!=stu[i-1].ge))
      r = i;
    stu[i].r = r;
  }
  for(i=0; i<N; i++){
    for(j=0; j<K; j++){
      if(sch[stu[i].cho[j]].num < sch[stu[i].cho[j]].q || stu[i].r == sch[stu[i].cho[j]].last_r){
        sch[stu[i].cho[j]].last_r = stu[i].r;
        sch[stu[i].cho[j]].num++;
        stu[i].fini = stu[i].cho[j];
        break;
      }
    }
  }
  qsort(stu, N, sizeof(stu[0]), cmp2);
  for(i=0; i<M; i++){
  	//printf("%d ", i);
    if(sch[i].num){
      int cnt = 0;
      for(j=0; j<N && cnt<sch[i].num; j++){
        if(stu[j].fini==i){
          cnt++;
          printf("%d", stu[j].id);
          if(cnt!=sch[i].num) printf(" ");
        }
      }
    }
    puts("");
  }
}
