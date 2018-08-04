//  STL之set
/*
1063 Set Similarity (25)（25 分）

Given two sets of integers, the similarity of the sets is defined to be N~c~/N~t~*100%, where N~c~ is the number of distinct common 
numbers shared by the two sets, and N~t~ is the total number of distinct numbers in the two sets. Your job is to calculate the 
similarity of any given pair of sets.
Input Specification:
Each input file contains one test case. Each case first gives a positive integer N (<=50) which is the total number of sets. Then N 
lines follow, each gives a set with a positive M (<=10^4^) and followed by M integers in the range [0, 10^9^]. After the input of sets, 
a positive integer K (<=2000) is given, followed by K lines of queries. Each query gives a pair of set numbers (the sets are numbered 
from 1 to N). All the numbers in a line are separated by a space.
Output Specification:
For each query, print in one line the similarity of the sets, in the percentage form accurate up to 1 decimal place.
Sample Input:
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
Sample Output:
50.0%
33.3%
*/
#include<stdio.h>
#include<set>
using namespace std;

set<int>st[51];
void comp(int N, int M)
{
    int a = st[N].size(), b = st[M].size();
    int cnt = 0;
    set<int>::iterator end = st[M].end();
    set<int>::iterator it = st[N].begin();
    for(; it != st[N].end(); it++){ //set 的遍历
        if(st[M].find(*it) != end) // 没找到就会返回end值
            cnt++;
    }
    printf("%.1f%%\n", cnt * 100.0 / (a+b-cnt));
}
int main()
{
    int N, M, i, j, tmp;
    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d", &M);
        for(j=0; j<M; j++){
            scanf("%d", &tmp);
            st[i].insert(tmp);
        }
    }
    scanf("%d", &tmp);
    for(i=0; i<tmp; i++){
        scanf("%d%d", &N, &M);
        comp(N-1, M-1);
    }
}
