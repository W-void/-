//  就算不写解决冲突的代码，也可以有20分。。。
/*
1078 Hashing (25)（25 分）

The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, and output the positions of the
input numbers. The hash function is defined to be "H(key) = key % TSize" where TSize is the maximum size of the hash table. Quadratic
probing (with positive increments only) is used to solve the collisions.
Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size 
to be the smallest prime number which is larger than the size given by the user.
Input Specification:
Each input file contains one test case. For each case, the first line contains two positive numbers: MSize (<=10^4^) and N (<=MSize) 
which are the user-defined table size and the number of input numbers, respectively. Then N distinct positive integers are given in the 
next line. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print the corresponding positions (index starts from 0) of the input numbers in one line. All the numbers in a line 
are separated by a space, and there must be no extra space at the end of the line. In case it is impossible to insert the number, print 
"-" instead.
Sample Input:
4 4
10 6 4 15
Sample Output:
0 1 4 -
*/
#include<stdio.h>

int isPrime(int N)
{
        if(N<2)  return 0;
        for(int i=2; i<=sqrt(N); i++)
                if(N % i == 0)  return 0;
        return 1;
}
int find_prime(int N)
{
        while(!isPrime(N++));
        return --N;
}
int main()
{
        int N, M, i, j, tmp;
        scanf("%d%d", &N, &M);
        N = find_prime(N);
        int *a = (int*)malloc(sizeof(int) * N);
        memset(a, 0, sizeof(a));
        for(i=0; i<M; i++){
        scanf("%d", &tmp);
        for(j=0; j<N; j++){
                if(a[(tmp+j*j) % N] == 0){
                        printf("%s%d", i ? " " : "", (tmp+j*j) % N);
                        a[(tmp+j*j) % N] = 1;
                        break;
                }
        }
        if(j == N)
                printf("%s-", i ? " " : "");
        }
}
