/*
1081 检查密码（15 分）
本题要求你帮助某网站的用户注册模块写一个密码合法性检查的小功能。该网站要求用户设置的密码必须由不少于6个字符组成，
并且只能有英文字母、数字和小数点 .，还必须既有字母也有数字。
输入格式：

输入第一行给出一个正整数 N（≤ 100），随后 N 行，每行给出一个用户设置的密码，为不超过 80 个字符的非空字符串，以回车结束。
输出格式：

对每个用户的密码，在一行中输出系统反馈信息，分以下5种：
如果密码合法，输出Your password is wan mei.；
如果密码太短，不论合法与否，都输出Your password is tai duan le.；
如果密码长度合法，但存在不合法字符，则输出Your password is tai luan le.；
如果密码长度合法，但只有字母没有数字，则输出Your password needs shu zi.；
如果密码长度合法，但只有数字没有字母，则输出Your password needs zi mu.。
输入样例：

5
123s
zheshi.wodepw
1234.5678
WanMei23333
pass*word.6
输出样例：

Your password is tai duan le.
Your password needs shu zi.
Your password needs zi mu.
Your password is wan mei.
Your password is tai luan le.
*/
#include<stdio.h>
int Check(const char* c)
{
  int ans=1, len=0, zimu =0, shuzi =0, wro =0, i;
  for(i=0; c[i]!=0; i++){
    if(c[i]>='0' && c[i]<='9') shuzi++;
    else if(c[i]>='a' && c[i]<='z' || c[i]>='A' && c[i]<='Z') zimu++;
    else if(c[i]!='.') wro++;
  }
  if(i<6) ans = 2;
  else if(wro) ans =3;
  else if(!shuzi) ans = 4;
  else if(!zimu) ans = 5;
  return ans;
}
int main()
{
  int ans, N;
  char c[101] = "\0";
  scanf("%d\n", &N);
  while(N--){
    gets(c);
    switch(ans = Check(c)){
      case 1:
      printf("Your password is wan mei.");
      break;
      case 2:
      printf("Your password is tai duan le.");
      break;
      case 3:
      printf("Your password is tai luan le.");
      break;
      case 4:
      printf("Your password needs shu zi.");
      break;
      case 5:
      printf("Your password needs zi mu.");
      break;
    }
    if(N) putchar('\n');
  }
  return 0;
}
