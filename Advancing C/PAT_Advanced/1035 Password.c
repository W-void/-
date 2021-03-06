/*
1035 Password (20)（20 分）

To prepare for PAT, the judge sometimes has to generate random passwords for the users. The problem is that there are always some confusing passwords since it is hard to distinguish 1 (one) from l (L in lowercase), or 0 (zero) from O (o in uppercase). One solution is to replace 1 (one) by @, 0 (zero) by %, l by L, and O by o. Now it is your job to write a program to check the accounts generated by the judge, and to help the juge modify the confusing passwords.
Input Specification:
Each input file contains one test case. Each case contains a positive integer N (<= 1000), followed by N lines of accounts. Each account consists of a user name and a password, both are strings of no more than 10 characters with no space.
Output Specification:
For each test case, first print the number M of accounts that have been modified, then print in the following M lines the modified accounts info, that is, the user names and the corresponding modified passwords. The accounts must be printed in the same order as they are read in. If no account is modified, print in one line "There are N accounts and no account is modified" where N is the total number of accounts. However, if N is one, you must print "There is 1 account and no account is modified" instead.
Sample Input 1:
3
Team000002 Rlsp0dfa
Team000003 perfectpwd
Team000001 R1spOdfa
Sample Output 1:
2
Team000002 RLsp%dfa
Team000001 R@spodfa
Sample Input 2:
1
team110 abcdefg332
Sample Output 2:
There is 1 account and no account is modified
Sample Input 3:
2
team110 abcdefg222
team220 abcdefg333
Sample Output 3:
There are 2 accounts and no account is modified
*/
#include<stdio.h>
#include<malloc.h>
typedef struct person* pson;
struct person{
  char name[15], psw[15];
  int f;
};
int main()
{
  int N, i, j, cnt;
  scanf("%d", &N);
  pson p = (pson)malloc(N * sizeof(struct person));
  for(i = 0, cnt = 0; i<N; i++){
    scanf("%s %s", p[i].name, p[i].psw);
    //判断并修改
    p[i].f = 0;
    for(j = 0; p[i].psw[j]; j++){
      if(p[i].psw[j] == '1'){
        p[i].psw[j] = '@';
        p[i].f = 1;
      }
      else if(p[i].psw[j] == '0'){
        p[i].psw[j] = '%';
        p[i].f = 1;
      }
      else if(p[i].psw[j] == 'l'){
        p[i].psw[j] = 'L';
        p[i].f = 1;
      }
      else if(p[i].psw[j] == 'O'){
        p[i].psw[j] = 'o';
        p[i].f = 1;
      }
    }
    if(p[i].f)
        cnt++;
  }
  //输出
  if(cnt){
    printf("%d\n", cnt);
    for(i = 0; i<N; i++)
      if(p[i].f)
        printf("%s %s\n", p[i].name, p[i].psw);
  }
  else{
    if(N==1) printf("There is 1 account and no account is modified");
    else printf("There are %d accounts and no account is modified", N);
  }
}
