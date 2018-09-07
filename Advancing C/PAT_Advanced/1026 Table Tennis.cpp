//  模拟队列不会
//  当有普通球台和VIP球台时，VIP客户遵循选择最小编号的VIP球台，而非编号最小的球台。应该是这种数据过不了
/*
1026 Table Tennis（30 分）
A table tennis club has N tables available to the public. The tables are numbered from 1 to N. For any pair of players, if there are 
some tables open when they arrive, they will be assigned to the available table with the smallest number. If all the tables are 
occupied, they will have to wait in a queue. It is assumed that every pair of players can play for at most 2 hours.

Your job is to count for everyone in queue their waiting time, and for each table the number of players it has served for the day.

One thing that makes this procedure a bit complicated is that the club reserves some tables for their VIP members. When a VIP table is 
open, the first VIP pair in the queue will have the priviledge to take it. However, if there is no VIP in the queue, the next pair of 
players can take it. On the other hand, if when it is the turn of a VIP pair, yet no VIP table is available, they can be assigned as any 
ordinary players.

Input Specification:
Each input file contains one test case. For each case, the first line contains an integer N (≤10000) - the total number of pairs of 
players. Then N lines follow, each contains 2 times and a VIP tag: HH:MM:SS - the arriving time, P - the playing time in minutes of a 
pair of players, and tag - which is 1 if they hold a VIP card, or 0 if not. It is guaranteed that the arriving time is between 08:00:00 
and 21:00:00 while the club is open. It is assumed that no two customers arrives at the same time. Following the players' info, there 
are 2 positive integers: K (≤100) - the number of tables, and M (< K) - the number of VIP tables. The last line contains M table 
numbers.

Output Specification:
For each test case, first print the arriving time, serving time and the waiting time for each pair of players in the format shown by the 
sample. Then print in a line the number of players served by each table. Notice that the output must be listed in chronological order of 
the serving time. The waiting time must be rounded up to an integer minute(s). If one cannot get a table before the closing time, their 
information must NOT be printed.

Sample Input:
9
20:52:00 10 0
08:00:00 20 0
08:02:00 30 0
20:51:00 10 0
08:10:00 5 0
08:12:00 10 1
20:50:00 10 0
08:01:30 15 1
20:53:00 10 1
3 1
2
Sample Output:
08:00:00 08:00:00 0
08:01:30 08:01:30 0
08:02:00 08:02:00 0
08:12:00 08:16:30 5
08:10:00 08:20:00 10
20:50:00 20:50:00 0
20:51:00 20:51:00 0
20:52:00 20:52:00 0
3 3 2
*/
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;

#define maxn 10010
int n, k, m;
int num[maxn] = {0};
struct node{
    int s, t, f, table;
    bool operator < (const node& a) const{
        return s + t > a.s + a.t;
    }
}player[maxn], tmp;

priority_queue<node, vector<node>, less<node> > q;//最大堆
set<int> st;
int cmp(const node& a, const node& b)
{
    return a.s < b.s;//从小到大排序
}
void print(int t1, int t2)
{
    int h, m, s, t = t2 - t1;
    s = t1 %60;
    t1 /= 60;
    m = t1%60;
    h = t1/60;
    printf("%02d:%02d:%02d ", h, m, s);
    if(t <= 0) printf("%02d:%02d:%02d 0\n", h, m, s);
    else{
    	s = t2 %60;
    	t2 /= 60;
    	m = t2%60;
    	h = t2/60;
    	printf("%02d:%02d:%02d %d\n", h, m, s, (t+30)/60);
	}
    
}
int main()
{
    //freopen("G:/Dec-Cpp/8.txt", "r", stdin); 
    scanf("%d", &n);
    int i, j, h, m, s, t, f, table;
    for(i=0; i<n; i++){
        scanf("%d:%d:%d %d %d", &h, &m, &s, &t, &f);
        player[i].s = (h * 60 + m) * 60 + s;
        t = min(t, 120);
        player[i].t = t * 60;
        player[i].f = f;
    }
    sort(player, player+n, cmp);
    scanf("%d%d", &k, &m);
    for(i=0; i<m; i++){
        scanf("%d", &t);
        st.insert(t-1);
    }
    for(i=0; i<k; i++){//将每个桌子填满
        player[i].table = i;
        q.push(player[i]);
        num[i]++;
        t = player[i].s;
        print(t, t);
    }
    for(; i<n; i++){
        tmp = q.top();
        q.pop();
        table = tmp.table;
        t = tmp.s + tmp.t; // tmp的结束时间
        if(t>=21*3600) break;//闭馆 
        while(player[i].f == -1) i++; //跳过已经服务了的VIP顾客
        if(i>=n) break;
        f = 0;
        if(st.count(table)){//该桌子为 VIP table
            for(j=i; j<n && player[j].s<=t; j++)//找到第一个 VIP
                if(player[j].f == 1){
                    f = 1;
                    break;
                }
        }
        if(f) {
			      player[j].f = -1;//将该VIP标记，后面遇到他就跳过
			      if(j != i) i--;
		    }
        else  j = i;
        print(player[j].s, t);
        player[j].s = max(player[j].s, t);
        player[j].table = table;
        q.push(player[j]);
		    num[table]++;
    }
    for(i=0; i<k; i++)
        printf("%s%d", i?" ":"", num[i]);
}
