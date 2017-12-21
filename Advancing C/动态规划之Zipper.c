/*
样例输入
3
cat tree tcraete
cat tree catrtee
cat tree cttaree
样例输出
Data set 1: yes
Data set 2: yes
Data set 3: no

题目分析：
    用DP[i][j]来存状态值，DP[i][j]==1则表示 字符串a的前i个字符和字符串b的前j个字符可以组成字符串c的前i+j个字符；
    所以DP[i][j]==1的条件就是--a的第i个字符==c的第i+j个字符&&DP[i-1][j]==1 || b的第j个字符==c的第i+j个字符&&DP[i][j-1]==1
    边界就是DP[i][0],DP[0][j]
*/
#include<stdio.h>
#include<string.h>

int n;
char a[500];
char b[500];
char c[500];


int max(int a, int b)
{
	int i = a>b?a:b;
	return i;
}

int main(){
	scanf("%d", &n);
	int i, j, len_a, len_b, num=1;
	while(n--){
		int DP[500][500] = {0};
		scanf("%s%s%s", a+1, b+1, c+1);	
		len_a = strlen(a+1);
		len_b = strlen(b+1);
		for(i=1; i<=len_a; i++){
			if(a[i]==c[i])
				DP[i][0] = 1;
			else break;
		}
		for(j=1; j<=len_b; j++){
			if(b[i]==c[i])
				DP[0][j] = 1;
			else break;
		}			
		for(i=1; i<=len_a; i++){
			for(j=1; j<=len_b; j++){
				if(c[i+j] == a[i] && DP[i-1][j])  
                    DP[i][j] = 1;  
                if(c[i+j] == b[j] && DP[i][j-1])  
                    DP[i][j] = 1;  
			}
		}
		if(DP[len_a][len_b])
			printf("Data set %d: yes\n", num++);
			
		else
			printf("Data set %d: no\n", num++);
	}
	
	
		
	return 0;
}
/*
描述
Given three strings, you are to determine whether the third string can be formed by combining the characters in the first two strings. The first two strings can be mixed arbitrarily, but each must stay in its original order.

For example, consider forming "tcraete" from "cat" and "tree":

String A: cat
String B: tree
String C: tcraete

As you can see, we can form the third string by alternating characters from the two strings. As a second example, consider forming "catrtee" from "cat" and "tree":

String A: cat
String B: tree
String C: catrtee

Finally, notice that it is impossible to form "cttaree" from "cat" and "tree".
输入
The first line of input contains a single positive integer from 1 through 1000. It represents the number of data sets to follow. The processing for each data set is identical. The data sets appear on the following lines, one data set per line.

For each data set, the line of input consists of three strings, separated by a single space. All strings are composed of upper and lower case letters only. The length of the third string is always the sum of the lengths of the first two strings. The first two strings will have lengths between 1 and 200 characters, inclusive.
输出
For each data set, print:

Data set n: yes

if the third string can be formed from the first two, or

Data set n: no

if it cannot. Of course n should be replaced by the data set number. See the sample output below for an example.
样例输入
3
cat tree tcraete
cat tree catrtee
cat tree cttaree
样例输出
Data set 1: yes
Data set 2: yes
Data set 3: no
*/
