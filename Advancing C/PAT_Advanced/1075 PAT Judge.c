/*
1075 PAT Judge (25)（25 分）

The ranklist of PAT is generated from the status list, which shows the scores of the submittions. This time you are supposed to generate the ranklist for PAT.
Input Specification:
Each input file contains one test case. For each case, the first line contains 3 positive integers, N (<=10^4^), the total number of users, K (<=5), the total number of problems, and M (<=10^5^), the total number of submittions. It is then assumed that the user id's are 5-digit numbers from 00001 to N, and the problem id's are from 1 to K. The next line contains K positive integers p[i] (i=1, ..., K), where p[i] corresponds to the full mark of the i-th problem. Then M lines follow, each gives the information of a submittion in the following format:
user_id problem_id partial_score_obtained
where partial_score_obtained is either -1 if the submittion cannot even pass the compiler, or is an integer in the range [0, p[problem_id]]. All the numbers in a line are separated by a space.
Output Specification:
For each test case, you are supposed to output the ranklist in the following format:
rank user_id total_score s[1] ... s[K]
where rank is calculated according to the total_score, and all the users with the same total_score obtain the same rank; and s[i] is the partial score obtained for the i-th problem. If a user has never submitted a solution for a problem, then "-" must be printed at the corresponding position. If a user has submitted several solutions to solve one problem, then the highest score will be counted.
The ranklist must be printed in non-decreasing order of the ranks. For those who have the same rank, users must be sorted in nonincreasing order according to the number of perfectly solved problems. And if there is still a tie, then they must be printed in increasing order of their id's. For those who has never submitted any solution that can pass the compiler, or has never submitted any solution, they must NOT be shown on the ranklist. It is guaranteed that at least one user can be shown on the ranklist.
Sample Input:
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0
Sample Output:
1 00002 63 20 25 - 18
2 00005 42 20 0 22 -
2 00007 42 - 25 - 17
2 00001 42 18 18 4 2
5 00004 40 15 0 25 -
*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

struct student{
  int id, score[7], num, f, total;
}stu[10002];
int cmp(const void* a, const void* b)
{
  int x = ((struct student*)b)->total - ((struct student*)a)->total;
  if(!x){
    x = ((struct student*)b)->num - ((struct student*)a)->num;
    if(!x)
      x = ((struct student*)a)->id - ((struct student*)b)->id;
  }
  return x;
}
int main()
{
  int N, k, M, i;
  scanf("%d%d%d", &N, &k, &M);
  int *a = (int*)malloc((k+1) * sizeof(int));
  for(i=1; i<=k; i++)
    scanf("%d", a+i);
  for(i=0; i<N; i++){
    memset(stu[i].score, -1, sizeof(stu[i].score));
    stu[i].num = 0;
    stu[i].f = 0;
    stu[i].total = 0;
    stu[i].id = i+1;
  }
  int id, s, p;
  for(i=0; i<M; i++){
    scanf("%d%d%d", &id, &p, &s);
    id--;
    if(s==-1 && stu[id].score[p] == -1) 	
    	stu[id].score[p] = 0;
    else{
    	if(s == a[p] && stu[id].score[p] != s) stu[id].num++;
	    if(s >= stu[id].score[p]){
  	    stu[id].total += s;
  		  if(stu[id].score[p] != -1) 
  		  	stu[id].total -= stu[id].score[p];
  		  stu[id].score[p] = s;
  		  stu[id].f = 1;
  	  }
  	}
  }
  qsort(stu, N, sizeof(stu[0]), cmp);
  int r = 1, j;
  for(i=0; i<N; i++){
  	if(!stu[i].f)  continue;
    if(i>0 && stu[i].total!= stu[i-1].total)
      r = i+1;
    printf("%d %05d %d", r, stu[i].id, stu[i].total);
    for(j=1; j<=k; j++){
      if(stu[i].score[j]==-1) printf(" -");
      else printf(" %d", stu[i].score[j]);
    }
    puts("");
  }
}
