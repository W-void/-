//  优先队列 priority_queue, 小于号重载，一般构造函数
/*
1014 Waiting in Line（30 分）

Suppose a bank has N windows open for service. There is a yellow line in front of the windows which devides the waiting area into two 
parts. The rules for the customers to wait in line are:

The space inside the yellow line in front of each window is enough to contain a line with M customers. Hence when all the N lines are 
full, all the customers after (and including) the (NM+1)st one will have to wait in a line behind the yellow line.
Each customer will choose the shortest line to wait in when crossing the yellow line. If there are two or more lines with the same 
length, the customer will always choose the window with the smallest number.
Customer[i] will take T[i] minutes to have his/her transaction processed.
The first N customers are assumed to be served at 8:00am.
Now given the processing time of each customer, you are supposed to tell the exact time at which a customer has his/her business done.

For example, suppose that a bank has 2 windows and each window may have 2 customers waiting inside the yellow line. There are 5 
customers waiting with transactions taking 1, 2, 6, 4 and 3 minutes, respectively. At 08:00 in the morning, customer~1~ is served at 
window~1~ while customer~2~ is served at window~2~. Customer~3~ will wait in front of window~1~ and customer~4~ will wait in front of 
window~2~. Customer~5~ will wait behind the yellow line.

At 08:01, customer~1~ is done and customer~5~ enters the line in front of window~1~ since that line seems shorter now. Customer~2~ will 
leave at 08:02, customer~4~ at 08:06, customer~3~ at 08:07, and finally customer~5~ at 08:10.

Input

Each input file contains one test case. Each case starts with a line containing 4 positive integers: N (<=20, number of windows), M 
(<=10, the maximum capacity of each line inside the yellow line), K (<=1000, number of customers), and Q (<=1000, number of customer 
queries).

The next line contains K positive integers, which are the processing time of the K customers.

The last line contains Q positive integers, which represent the customers who are asking about the time they can have their transactions 
done. The customers are numbered from 1 to K.

Output

For each of the Q customers, print in one line the time at which his/her transaction is finished, in the format HH:MM where HH is in 
[08, 17] and MM is in [00, 59]. Note that since the bank is closed everyday after 17:00, for those customers who cannot be served before 
17:00, you must output "Sorry" instead.

Sample Input

2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7
Sample Output

08:07
08:06
08:10
17:00
Sorry
*/
#include<stdio.h>
#include<queue>
using namespace std;

#define maxn 1010
int n, m, k, Q;
int cost[maxn], time[maxn], cur[25] = {0};//cost记录每个顾客的花费时间，time记录每个顾客的结束时间，cur记录每个窗口最后一个顾客的结束时间
struct node{
    int win, e; //win为窗口号，e为该顾客的结束时间
    node() {}
    node(int _win, int _e): win(_win), e(_e) {}
    bool operator < (const node & a) const
    {
        if(e != a.e)
            return e > a.e;
        else
            return win > a.win;
    }
}Node;

//priority_queue<node, vector<node>, greater<node> > q; //越来越大，从小到大，需要重载大于号
priority_queue<node, vector<node>, less<node> > q; //越来越小，从大到小，需要重载小于号

int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &Q);
    int i, j, tmp, t, hh, mm;
    for(i=0; i<k; i++)
        scanf("%d", cost+i);
    for(i=0; i<n*m; i++){
    	  j = i%n; //窗口号
        q.push(node(j, cur[j] + cost[i]));
        cur[j] += cost[i];
        time[i] = cur[j];
    }
    for(; i<k; i++){
        Node = q.top();
        q.pop();
        j = Node.win;
        q.push(node(j, cur[j] + cost[i]));
        cur[j] += cost[i];
        time[i] = cur[j];
    }
    int fini = 540;
    for(i=0; i<Q; i++){
        scanf("%d", &tmp);
        tmp--;
        t = time[tmp];
        if(t - cost[tmp] >= fini)  printf("Sorry\n");
        else{
            mm = t % 60;
            hh = t / 60 + 8;
            printf("%02d:%02d\n", hh, mm);
        }
    }
    return 0;
}
