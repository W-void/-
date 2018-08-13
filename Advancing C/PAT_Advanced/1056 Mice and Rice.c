// queue
/*
1056 Mice and Rice (25)（25 分）

Mice and Rice is the name of a programming contest in which each programmer must write a piece of code to control the movements of a 
mouse in a given map. The goal of each mouse is to eat as much rice as possible in order to become a FatMouse.
First the playing order is randomly decided for N~P~ programmers. Then every N~G~ programmers are grouped in a match. The fattest mouse 
in a group wins and enters the next turn. All the losers in this turn are ranked the same. Every N~G~ winners are then grouped in the 
next match until a final winner is determined.
For the sake of simplicity, assume that the weight of each mouse is fixed once the programmer submits his/her code. Given the weights of 
all the mice and the initial playing order, you are supposed to output the ranks for the programmers.
Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers: N~P~ and N~G~ (<= 1000), the number 
of programmers and the maximum number of mice in a group, respectively. If there are less than N~G~ mice at the end of the player's 
list, then all the mice left will be put into the last group. The second line contains N~P~ distinct non-negative numbers W~i~ 
(i=0,...N~P~-1) where each W~i~ is the weight of the i-th mouse respectively. The third line gives the initial playing order which is a 
permutation of 0,...N~P~-1 (assume that the programmers are numbered from 0 to N~P~-1). All the numbers in a line are separated by a 
space.
Output Specification:
For each test case, print the final ranks in a line. The i-th number is the rank of the i-th programmer, and all the numbers must be 
separated by a space, with no extra space at the end of the line.
Sample Input:
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3
Sample Output:
5 5 5 2 5 5 5 3 1 3 5
*/
#include<stdio.h>
#include<queue>
using namespace std;

int main()
{
    int np, ng, i, j, tmp;
    scanf("%d%d", &np, &ng);
    int *a = new int[np];
    int *b = new int[np];
    queue<int> q;
    for(i=0; i<np; i++)
        scanf("%d", a+i);
    for(i=0; i<np; i++){
        scanf("%d", &tmp);
        q.push(tmp);
    }
    int p = np, group;
    while(q.size() != 1){
    	group = (p + ng - 1) / ng;
        int max, idx;
        for(i=0; i<group; i++){
            max = -1;
            for(j=0; j<ng && i*ng+j<p; j++){
                tmp = q.front();
                b[tmp] = group + 1;
                q.pop();
                if(a[tmp] > max){
                    idx = tmp;
                    max = a[tmp];
                }
            }
            q.push(idx);
        }
        p = q.size();
    }
    b[q.front()] = 1;
    for(i=0; i<np; i++)
        printf("%s%d", i?" ":"", b[i]);
}
