// 初始化很重要
/*
1077 Kuchiguse (20)（20 分）

The Japanese language is notorious for its sentence ending particles. Personal preference of such particles can be considered as a reflection of the speaker's personality. Such a preference is called "Kuchiguse" and is often exaggerated artistically in Anime and Manga. For example, the artificial sentence ending particle "nyan~" is often used as a stereotype for characters with a cat-like personality:
Itai nyan~ (It hurts, nyan~)
Ninjin wa iyada nyan~ (I hate carrots, nyan~)
Now given a few lines spoken by the same character, can you find her Kuchiguse?
Input Specification:
Each input file contains one test case. For each case, the first line is an integer N (2<=N<=100). Following are N file lines of 0~256 (inclusive) characters in length, each representing a character's spoken line. The spoken lines are case sensitive.
Output Specification:
For each test case, print in one line the kuchiguse of the character, i.e., the longest common suffix of all N lines. If there is no such suffix, write "nai".
Sample Input 1:
3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~
Sample Output 1:
nyan~
Sample Input 2:
3
Itai!
Ninjinnwaiyada T_T
T_T
Sample Output 2:
nai
*/
#include<stdio.h>
#include<string.h>

void reverse(char* s)
{
  int len = strlen(s), i;
  char c[260] = {0};
  for(i=len-1; i>=0; i--)
    c[len-i-1] = s[i];
  strcpy(s, c);
}
int min(int a, int b, int c)
{
  int m = a>b?b:a;
  m = m>c?c:m;
  return m;
}

int main()
{
  int N, i, j, max = 257;
  scanf("%d", &N);
  getchar();//接收换行符 
  char s[101][260];
  for(i=0; i<N; i++){
    gets(s[i]);
    reverse(s[i]);
    if(i){
      int m = min(strlen(s[i]), strlen(s[i-1]), max);
      max = 0;
      for(j=0; j<m; j++){
        if(s[i][j] == s[i-1][j]) max++;
        else break;
      }
    }
  }
  if(max){
    char c[260];
    for(i=0; i<max; i++)
      c[i] = s[0][i];
    reverse(c);
    puts(c);
  }
    
  else
    printf("nai");
    return 0;
}
