//  用暴力方法：while(a[j]!=-1){
//                 dep++;
//                 j = a[j];
//            }每个结点都这样计算dep，会超时
/*
1090 Highest Price in Supply Chain (25)（25 分）

A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product 
from supplier to customer.
Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a 
price that is r% higher than P. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, 
and there is no supply cycle.
Now given a supply chain, you are supposed to tell the highest price we can expect from some retailers.
Input Specification:
Each input file contains one test case. For each case, The first line contains three positive numbers: N (<=10^5^), the total number of 
the members in the supply chain (and hence they are numbered from 0 to N-1); P, the price given by the root supplier; and r, the 
percentage rate of price increment for each distributor or retailer. Then the next line contains N numbers, each number S~i~ is the 
index of the supplier for the i-th member. S~root~ for the root supplier is defined to be -1. All the numbers in a line are separated by 
a space.
Output Specification:
For each test case, print in one line the highest price we can expect from some retailers, accurate up to 2 decimal places, and the 
number of retailers that sell at the highest price. There must be one space between the two numbers. It is guaranteed that the price 
will not exceed 10^10^.
Sample Input:
9 1.80 1.00
1 5 4 4 -1 4 5 3 6
Sample Output:
1.85 2
*/
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;

const int maxn = 100010;

vector<int> child[maxn];

int n, maxDepth = 0, num = 0;
double p, r;
void DFS(int root, int dep)
{
    if(dep>maxDepth){
        num = 1;
        maxDepth = dep;
    }
    else if(dep == maxDepth)
        num ++;
    int i, size = child[root].size();
    for(i=0; i<size; i++){
        DFS(child[root][i], dep+1);
    }
}
int main()
{
    scanf("%d%lf%lf", &n, &p, &r);
    int i, c, root;
    for(i=0; i<n; i++){
        int c;
        scanf("%d", &c);
        if(c != -1)
            child[c].push_back(i);
        else
            root = i;
    }
    DFS(root, 0);
    printf("%.2f %d", p * pow(1+r/100, maxDepth), num);
}
