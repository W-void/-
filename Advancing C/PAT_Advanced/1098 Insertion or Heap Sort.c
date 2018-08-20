/*
1098 Insertion or Heap Sort（25 分）

According to Wikipedia:
Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort 
removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no 
input elements remain.
Heap sort divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the 
largest element and moving that to the sorted region. it involves the use of a heap data structure rather than a linear-time search to 
find the maximum.
Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can 
you tell which sorting method we are using?
Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (≤100). Then in the next line, N 
integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that 
the target sequence is always ascending. All the numbers in a line are separated by a space.
Output Specification:

For each test case, print in the first line either "Insertion Sort" or "Heap Sort" to indicate the method used to obtain the partial 
result. Then run this method for one more iteration and output in the second line the resuling sequence. It is guaranteed that the 
answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end 
of the line.

Sample Input 1:

10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
Sample Output 1:

Insertion Sort
1 2 3 5 7 8 9 4 6 0
Sample Input 2:

10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9
Sample Output 2:

Heap Sort
5 4 3 1 0 2 6 7 8 9
*/
#include<stdio.h>

#define N 100
int a[N], b[N], n;

void percDown(int n)
{
    int p, child, x = b[0];
    for(p=0; p*2+1<n; p = child){
		    child = 2*p+1; 
        if(child+1<n && b[child+1]>b[child])
            child++;
        if(x > b[child]) break;
        b[p] = b[child];
        
    }
    b[p] = x;
}
int main()
{
    scanf("%d", &n);
    int i, j, f = 0;
    for(i=0; i<n; i++)
        scanf("%d", a+i);
    for(i=0; i<n; i++)
        scanf("%d", b+i);
    for(i=0; i<n; i++)
        if(b[i]>b[i+1])  break;
    for(j=i+1; j<n; j++)
        if(a[j]!=b[j])  f = 1;
    if(!f){//插入排序
        printf("Insertion Sort");
        int tmp = b[i+1];
        for(j=i; j>=0; j--){
            if(b[j]>tmp)
                b[j+1] = b[j];
            else break;
        }
        b[j+1] = tmp;
    }
    else{
        printf("Heap Sort");
        for(i=n-1; i>=0; i--)
            if(b[i] < b[0]) break;
        int tmp = b[0];
        b[0] = b[i];
        b[i] = tmp;
        percDown(i);
    }
    for(i=0; i<n; i++)
        printf("%s%d", i?" ":"\n", b[i]);
}
