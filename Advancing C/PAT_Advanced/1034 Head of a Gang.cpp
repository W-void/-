//
/*
1034 Head of a Gang (30)（30 分）

One way that the police finds the head of a gang is to check people's phone calls. If there is a phone call between A and B, we say that 
A and B is related. The weight of a relation is defined to be the total time length of all the phone calls made between the two persons. 
A "Gang" is a cluster of more than 2 persons who are related to each other with total relation weight being greater than a given 
threshold K. In each gang, the one with maximum total weight is the head. Now given a list of phone calls, you are supposed to find the 
gangs and the heads.
Input Specification:
Each input file contains one test case. For each case, the first line contains two positive numbers N and K (both less than or equal to 
1000), the number of phone calls and the weight threshold, respectively. Then N lines follow, each in the following format:
Name1 Name2 Time
where Name1 and Name2 are the names of people at the two ends of the call, and Time is the length of the call. A name is a string of 
three capital letters chosen from A-Z. A time length is a positive integer which is no more than 1000 minutes.
Output Specification:
For each test case, first print in a line the total number of gangs. Then for each gang, print in a line the name of the head and the 
total number of the members. It is guaranteed that the head is unique for each gang. The output must be sorted according to the 
alphabetical order of the names of the heads.
Sample Input 1:
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 1:
2
AAA 3
GGG 3
Sample Input 2:
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 2:
0
*/
#include<cstdio>
#include<map>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

struct node{
    int v, w;
    node(int _v, int _w) : v(_v), w(_w) {}
};
const int maxn = 2010;
int adj[maxn][maxn] = {0};
map<string, int> head; // head用map来做，因为map会根据key自动排序
map<string, int> str2int;
map<int, string> int2str;
int weight[maxn] = {0}, vis[maxn] = {0};
int n, k, numPerson = 0;

int change(string s)
{
    if(str2int.find(s) != str2int.end())
        return str2int[s];
    str2int[s] = numPerson;
    int2str[numPerson] = s;
    return numPerson++;
}
void DFS(int nowVisit, int &h, int &numMember, int &totalValue)
{
    vis[nowVisit] = 1;
    numMember++;
    //printf("_%d ", numMember);
    if(weight[h] < weight[nowVisit])  h = nowVisit;
    int i;
    for(i=0; i<numPerson; i++){
        if(adj[nowVisit][i]){ //因为可能有回路，所以不能在这里判断 && vis[i] == 0
            totalValue += adj[nowVisit][i];
            adj[nowVisit][i] = adj[i][nowVisit] = 0;
            if(vis[i] == 0)
            	DFS(i, h, numMember, totalValue);
        }
    }
}

int main()
{
    //freopen("G:/Dec-Cpp/8.txt", "r", stdin); 
    scanf("%d%d\n", &n, &k);
    int i, w;
    string s1, s2;
    for(i=0; i<n; i++){
        cin>>s1>>s2>>w;
        int id1 = change(s1);
        int id2 = change(s2);
        weight[id1] += w;
        weight[id2] += w;
        adj[id1][id2] += w;
        adj[id2][id1] += w;
    }
    for(i=0; i<numPerson; i++)
        if(!vis[i]){
        	//printf("\n%d: ", i);
            int h = i, numMember = 0, totalValue = 0;
            DFS(i, h, numMember, totalValue);
            //printf("%d\n", totalValue);
            //printf("%d %d\n", numMember, totalValue);
            if(numMember > 2 && totalValue > k){
            	//printf("%d %d\n", numMember, totalValue);
            	  head[int2str[h]] = numMember;
			      }
        }
    printf("%d", head.size());
    map<string, int>::iterator it = head.begin();
    for(; it != head.end(); it++)
        cout<<"\n"<<it->first<<" "<< it->second;//printf("\n%s %d", (it->first).c_str(), it->second);
}
