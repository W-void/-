/*
1027 Colors in Mars (20)（20 分）

People in Mars represent the colors in their computers in a similar way as the Earth people. 
That is, a color is represented by a 6-digit number, where the first 2 digits are for Red, the middle 2 digits for Green, 
and the last 2 digits for Blue. The only difference is that they use radix 13 (0-9 and A-C) instead of 16.
Now given a color in three decimal numbers (each between 0 and 168), you are supposed to output their Mars RGB values.
Input
Each input file contains one test case which occupies a line containing the three decimal color values.
Output
For each test case you should output the Mars RGB value in the following format: first output "#", 
then followed by a 6-digit number where all the English characters must be upper-cased. If a single color is only 1-digit long, 
you must print a "0" to the left.
Sample Input
15 43 71
Sample Output
#123456
*/
#include<stdio.h>
int main()
{
  int R, G, B;
  scanf("%d%d%d", &R, &G, &B);
  char radix[] = "0123456789ABC";
  printf("#%c%c%c%c%c%c", radix[R/13], radix[R%13], radix[G/13], radix[G%13], radix[B/13], radix[B%13]);
}
