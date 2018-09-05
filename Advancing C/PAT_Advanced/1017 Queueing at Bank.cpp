//  优先队列排序只能重载符号，不能直接用cmp；sort和优先队列的排序函数正好相反
/*
1017 Queueing at Bank（25 分）
Suppose a bank has K windows open for service. There is a yellow line in front of the windows which devides the waiting area into two 
parts. All the customers have to wait in line behind the yellow line, until it is his/her turn to be served and there is a window 
available. It is assumed that no window can be occupied by a single customer for more than 1 hour.

Now given the arriving time T and the processing time P of each customer, you are supposed to tell the average waiting time of all the 
customers.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 numbers: N (≤10^4 ) - the total number of customers, 
and K (≤100) - the number of windows. Then N lines follow, each contains 2 times: HH:MM:SS - the arriving time, and P - the processing 
time in minutes of a customer. Here HH is in the range [00, 23], MM and SS are both in [00, 59]. It is assumed that no two customers 
arrives at the same time.

Notice that the bank opens from 08:00 to 17:00. Anyone arrives early will have to wait in line till 08:00, and anyone comes too late (at 
or after 17:00:01) will not be served nor counted into the average.

Output Specification:
For each test case, print in one line the average waiting time of all the customers, in minutes and accurate up to 1 decimal place.

Sample Input:
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10
Sample Output:
8.2
*/
#include<stdio.h>
#include<queue>
#include <algorithm>
using namespace std;

#define maxn 10010
int n, k;
struct tNode{
    int t, p;
    tNode() {}
    tNode(int _t, int _p): t(_t), p(_p) {}
    bool operator < (const tNode& a) const{
        return t + p > a.t + a.p;
    }
}cus[maxn], node;
int  precessing[maxn];
int cmp(tNode& a, tNode& b)
{
    // 返回为true就不交换，从小到大排序
    return a.t < b.t;
}
priority_queue<tNode, vector<tNode>, less<tNode> > q;

int main()
{
    scanf("%d%d", &n, &k);
    int hh, mm, ss, p, i, num = 0, time;
    for(i=0; i<n; i++){
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &p);
        time = (hh * 60 + mm) * 60 +ss;
        if(time <= 17 * 3600){ //超过下午5点的顾客直接排除
            cus[num++] = tNode(time, p * 60);
        }
    }
    sort(cus, cus+num, cmp);
    for(i=0; i<k; i++){//先填满窗口
        if(cus[i].t < 8*3600){
        	  precessing[i] = 8*3600 - cus[i].t;
        	  cus[i].t = 8 * 3600;//易错点1：忘了将早于8点来的顾客的开始时间设置为8点
		    }  
        else  precessing[i] = 0;
        q.push(cus[i]);
    }
    for(; i<num; i++){//对剩下的客户
        node = q.top();
        q.pop();
        time = node.t + node.p - cus[i].t;
        precessing[i] = time > 0 ? time : 0;
        if(time > 0)
            cus[i].t += time;//易错点2：忘了改变排队顾客的开始时间
        q.push(cus[i]);
    }
    for(i=0, time = 0; i<num; i++)
    	  time += precessing[i];
        
    double ans = time*1.0/60/num;
    printf("%.1f", ans);
}
