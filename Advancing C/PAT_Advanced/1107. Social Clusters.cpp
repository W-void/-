// 查并集
/*
1107. Social Clusters (30)

When register on a social network, you are always asked to specify your hobbies in order to find some potential friends with the same 
hobbies. A "social cluster" is a set of people who have some of their hobbies in common. You are supposed to find all the clusters.
Input Specification:
Each input file contains one test case. For each test case, the first line contains a positive integer N (<=1000), the total number of 
people in a social network. Hence the people are numbered from 1 to N. Then N lines follow, each gives the hobby list of a person in the 
format:

Ki: hi[1] hi[2] ... hi[Ki]
where Ki (>0) is the number of hobbies, and hi[j] is the index of the j-th hobby, which is an integer in [1, 1000].
Output Specification:
For each case, print in one line the total number of clusters in the network. Then in the second line, print the numbers of people in 
the clusters in non-increasing order. The numbers must be separated by exactly one space, and there must be no extra space at the end of 
the line.

Sample Input:
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
Sample Output:
3
4 3 1
*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int N = 1010;
int hobby[N];
int s[N];
int find(int a)
{
    if(s[a] < 0)  return a;
    return s[a] = find(s[a]);
}
void Union(int a, int b)
{
    int r1 = find(a), r2 = find(b);
    if(r1 != r2){
        s[r2] += s[r1];
        s[r1] = r2;
    }
}
int main()
{
    int n, i, j, k, h;
    scanf("%d", &n);
    memset(s, -1, sizeof(s)); //负数的绝对值就是集合元素的个数，所以要初始化成-1
    memset(hobby, -1, sizeof(hobby)); //因为我定义hobby中的值是从0开始的，所以要初始化成-1
    for(i=0; i<n; i++){
        scanf("%d:", &k);
        for(j=0; j<k; j++){
            scanf("%d", &h);
            if(hobby[h] == -1){//hobby[h]第一次被访问
                  hobby[h] = i;
            }
            Union(i, hobby[h]);
        }
    }
    sort(s, s+N);
    for(j=0, k=0; n>j; j-=s[k++]);
	  printf("%d", k);
    for(i=0; i<k; i++)
        printf("%s%d", i?" ":"\n", -s[i]);
}
