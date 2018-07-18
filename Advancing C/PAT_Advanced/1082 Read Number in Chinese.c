// 一定要小心边界数据
/*
1082 Read Number in Chinese (25)（25 分）

Given an integer with no more than 9 digits, you are supposed to read it in the traditional Chinese way. 
Output "Fu" first if it is negative. For example, -123456789 is read as
"Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu".
Note: zero ("ling") must be handled correctly according to the Chinese tradition. For example, 100800 is "yi Shi Wan ling ba Bai".
Input Specification:
Each input file contains one test case, which gives an integer with no more than 9 digits.
Output Specification:
For each test case, print in a line the Chinese way of reading the number. 
The characters are separated by a space and there must be no extra space at the end of the line.
Sample Input 1:
-123456789
Sample Output 1:
Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu
Sample Input 2:
100800
Sample Output 2:
yi Shi Wan ling ba Bai
*/

#include<stdio.h>
#include<string.h>
int main()
{
  char *a[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
  char *b[] = {"", " Wan", " Yi"};
  char *c[] = {"", " Shi", " Bai", " Qian"};
  // freopen("G:/Dec-Cpp/8.txt", "r", stdin);

  char s[11];
  gets(s);
  int len = strlen(s), i = 0, cnt = 0;
  if(s[0] == '-'){
    printf("Fu");
    i++;
  }
  if(s[0] == '0'){ //有一个测试点专门卡零
    printf("ling");  return 0;
  } 
  for(; i<len; i++){
    if(s[i] != '0') {
      if(s[i-1] == '0' && (len-1-i) % 4 != 3) printf(" ling");//808000应该读作ba Shi Wan ba Qian
      printf("%s%s", i?" ":"", a[s[i] - '0']);
      printf("%s", c[(len-1-i) % 4]);
      cnt = 0;
    }
    else
      cnt++;
    if(!((len-1-i) % 4) && cnt<4)  //cnt是数零的个数，例如800008000就不应该输出‘Wan’，但是好像没有专门测试这种情况的数据
      printf("%s", b[(len-1-i) / 4]);
  }
  
}
