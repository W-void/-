// 用了DFS和BFS两种方法找深度最浅的叶子节点，BFS比DFS快一点
/*
1106. Lowest Price in Supply Chain (25)

A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product 
from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a 
price that is r% higher than P. Only the retailers will face the customers. It is assumed that each member in the supply chain has 
exactly one supplier except the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the lowest price a customer can expect from some retailers.

Input Specification:

Each input file contains one test case. For each case, The first line contains three positive numbers: N (<=105), the total number of 
the members in the supply chain (and hence their ID's are numbered from 0 to N-1, and the root supplier's ID is 0); P, the price given 
by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then N lines follow, each 
describes a distributor or retailer in the following format:

Ki ID[1] ID[2] ... ID[Ki]

where in the i-th line, Ki is the total number of distributors or retailers who receive products from supplier i, and is then followed 
by the ID's of these distributors or retailers. Kj being 0 means that the j-th member is a retailer. All the numbers in a line are 
separated by a space.

Output Specification:

For each test case, print in one line the lowest price we can expect from some retailers, accurate up to 4 decimal places, and the 
number of retailers that sell at the lowest price. There must be one space between the two numbers. It is guaranteed that the all the 
prices will not exceed 1010.

Sample Input:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0
2 6 1
1 8
0
0
0
Sample Output:
1.8362 2
*/
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

int n;
double p, r;
const int maxn = 100010;
vector<int> node[maxn];
int depth = maxn, num = 0;

void DFS(int root, int dep)
{
    int size = node[root].size(), i;
    if(!size){
        if(dep<depth){
            depth = dep;
            num = 1;
        }
        else if(dep == depth){
            num++;
        }
    }
    else{
        for(i=0; i<size; i++)
            DFS(node[root][i], dep+1);
    }
}
void BFS(int root, int dep)
{
    queue<int> q;
    q.push(root);
    int cnt = 1, j = 0;
    while(!q.empty()){
        root = q.front();
        int size = node[root].size(), i;
        for(i=0; i<size; i++){
            q.push(node[root][i]);
        }
        if(size == 0) //到达叶子节点，计数器加一
            num++;
        q.pop();
        j++;
        if(j == cnt){ //遍历完完整的一层
            cnt = q.size();
            j = 0;
            if(num){ // 找到叶子节点
                depth = dep;
                break;
            }
            dep++;
        }
    }
}
int main()
{
    scanf("%d%lf%lf", &n, &p, &r);
    int i, j, k, tmp;
    for(i=0; i<n; i++){
        scanf("%d", &k);
        for(j=0; j<k; j++){
            scanf("%d", &tmp);
            node[i].push_back(tmp);
        }
    }
    //DFS(0, 0);
    BFS(0, 0);
    printf("%.4f %d", pow(1+r/100, depth) * p, num);
}
