//  DFS
/*
1103 Integer Factorization（30 分）

The K-P factorization of a positive integer N is to write N as the sum of the P-th power of K positive integers. You are supposed to 
write a program to find the K-P factorization of N for any positive integers N, K and P.

Input Specification:

Each input file contains one test case which gives in a line the three positive integers N (<=400), K (<=N) and P (1<P<=7). The numbers 
in a line are separated by a space.

Output Specification:

For each case, if the solution exists, output in the format:

N = n1^P + ... nK^P

where ni (i=1, ... K) is the i-th factor. All the factors must be printed in non-increasing order.

Note: the solution may not be unique. For example, the 5-2 factorization of 169 has 9 solutions, such as 122 + 42 + 22 + 22 + 12,
or 112 + 62 + 22 + 22 + 22, or more. You must output the one with the maximum sum of the factors. If there is a tie, the largest factor 
sequence must be chosen -- sequence { a1, a2, ... aK } is said to be larger than { b1, b2, ... bK } if there exists 1<=L<=K such that 
ai=bi for i<L and aL>bL

If there is no solution, simple output "Impossible".

Sample Input 1:
169 5 2
Sample Output 1:
169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2
Sample Input 2:
169 167 3
Sample Output 2:
Impossible
*/
#include<stdio.h>
#include<vector>
using namespace std;

vector<int> fac, tmp, ans;
int max_sum = -1, N, K, P, i;
int pow(int a, int b)
{
    if(a == 1)  return 1;
    int ans = 1;
    while(b--){
        ans *= a;
    }
    return ans;
}
void init()
{
    int  i = 0, tmp = 0;
    while(tmp<=N){
        fac.push_back(tmp);
        tmp = pow(++i, P);
    }
}
void DFS(int idx, int k, int sum, int fsum)
{
	  if(idx==0 || sum>N || k==K&&sum!=N)  return;//剪枝
    if(sum==N && k==K){
    		if(fsum>max_sum){
    			  ans = tmp;
          	max_sum = fsum;
    		}
        return;
    }

    tmp.push_back(idx);
    DFS(idx, k+1, sum+fac[idx], fsum+idx);
    tmp.pop_back();
    DFS(idx-1, k, sum, fsum);
}
int main()
{
    scanf("%d%d%d", &N, &K, &P);
    init();
    DFS(fac.size()-1, 0, 0, 0);
    if(max_sum == -1)  printf("Impossible");
    else{
        printf("%d = %d^%d", N, ans[0], P);
        for(i=1; i<ans.size(); i++){
            printf(" + %d^%d", ans[i], P);
        }
    }
}
