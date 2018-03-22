// 创建堆栈，用ind记录已经入过栈的最大数，当新扫描到一个数num后，若ind>num，则应该出栈并判断与num相不相等；否则应该一直入栈直到ind==num。
/*
02-线性结构4 Pop Sequence（25 分）

Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly.
You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. 
For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

Input Specification:
Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000): 
M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked). 
Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.

Output Specification:
For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.

Sample Input:
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2

Sample Output:
YES
NO
NO
YES
NO
*/
#include<stdio.h>
typedef struct snode* stack;
struct snode{
  int *data;
  int top, maxsize;
};
int push(stack ptrs,int a)
{
  if(ptrs->top==ptrs->maxsize-1)
    return 0;
  ptrs->data[++ptrs->top] = a;
  return 1;
}
int pop(stack ptrs)
{
  if(ptrs->top == -1)
    return 0;
  return ptrs->data[ptrs->top--];
}
int main()
{
  int m, n, k, i, num;
  scanf("%d%d%d", &m, &n, &k);
  stack s = (stack)malloc(sizeof(struct snode));
  s->maxsize = m, s->top = -1; // 堆栈初始化，top代表栈顶的下标
  s->data = (int*)malloc(s->maxsize*sizeof(int));
  while(k--){
    int ind = 0, flag = 0;
    for(i=0; i<n; i++){
      scanf("%d", &num);
      while(num>ind){
        if(!push(s, ++ind)) flag = 1;//栈满
      }
      if(pop(s)!=num) flag = 1;//与出栈元素不符
    }
    if(flag) printf("NO\n");
    else printf("YES\n");
  }
  
  return 0;
}
