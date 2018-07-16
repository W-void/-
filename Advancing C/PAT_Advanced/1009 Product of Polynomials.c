/*
1009 Product of Polynomials (25)（25 分）

This time, you are supposed to find A*B where A and B are two polynomials.
Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: 
K N1 a~N1~ N2 a~N2~ ... NK a~NK~, where K is the number of nonzero terms in the polynomial, Ni and a~Ni~ (i=1, 2, ..., K) 
are the exponents and coefficients, respectively. It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.
Output Specification:
For each test case you should output the product of A and B in one line, with the same format as the input.
Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.
Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 3 3.6 2 6.0 1 1.6
*/
#include<stdio.h>
struct Poly{
  int exp;
  double cof;
}poly[1001];
int main()
{
  int K1, K2, i, j;
  double a[2001] = {0};
  scanf("%d", &K1);
  for(i=0; i<K1; i++)
    scanf("%d%lf", &poly[i].exp, &poly[i].cof);
  scanf("%d", &K2);
  for(i=0; i<K2; i++){
    int e;
    double c;
    scanf("%d%lf", &e, &c);
    for(j=0; j<K1; j++)
      a[e + poly[j].exp] += c * poly[j].cof;
  }
  for(i=0, j=0; i<2001; i++){
    if(a[i]) j++;
  }
  printf("%d", j);
  for(i=2000; i>=0; i--)
    if(a[i]) printf(" %d %.1f", i, a[i]);
  return 0;
} 
