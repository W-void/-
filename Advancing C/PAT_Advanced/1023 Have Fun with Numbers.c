/*
1023 Have Fun with Numbers (20)（20 分）

Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will 
obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different 
permutation. Check to see the result if we double it again!
Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to 
tell if the resulting number consists of only a permutation of the digits in the original number.
Input Specification:
Each input file contains one test case. Each case contains one positive integer with no more than 20 digits.
Output Specification:
For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the 
digits in the original number, or "No" if not. Then in the next line, print the doubled number.
Sample Input:
1234567899
Sample Output:
Yes
2469135798
*/
#include<stdio.h>
#include<string.h>
int main()
{
  char a[21], b[21] = {0};
  int i, carry = 0, f = 0;
  gets(a);
  for(i = strlen(a) - 1; i>=0; i--){
    b[i] = (a[i] - '0') * 2 % 10 + '0' + carry;
    carry = (a[i] - '0') * 2 / 10;
  }
  if(carry) printf("No\n1");
  else{
    int cnt[10] = {0};
    for(i=0; a[i]; i++)
      cnt[a[i] - '0']++;
    for(i=0; b[i]; i++)
      if(--cnt[b[i] - '0'] < 0){
        f = 1;
        break;
      }
    if(f) puts("No");
    else puts("Yes");
  }
 
  puts(b);
}
