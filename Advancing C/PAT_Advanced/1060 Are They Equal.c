/*
1060 Are They Equal (25)（25 分）

If a machine can save only 3 significant digits, the float numbers 12300 and 12358.9 are considered equal since they are both saved as 
0.123*10^5^ with simple chopping. Now given the number of significant digits on a machine and two float numbers, you are supposed to 
tell if they are treated equal in that machine.
Input Specification:
Each input file contains one test case which gives three numbers N, A and B, where N (<100) is the number of significant digits, and A 
and B are the two float numbers to be compared. Each float number is non-negative, no greater than 10^100^, and that its total digit 
number is less than 100.
Output Specification:
For each test case, print in a line "YES" if the two numbers are treated equal, and then the number in the standard form 
"0.d~1~...d~N~*10\^k" (d~1~>0 unless the number is 0); or "NO" if they are not treated equal, and then the two numbers in their 
standard form. All the terms must be separated by a space, with no extra space at the end of a line.
Note: Simple chopping is assumed without rounding.
Sample Input 1:
3 12300 12358.9
Sample Output 1:
YES 0.123*10^5
Sample Input 2:
3 120 128
Sample Output 2:
NO 0.120*10^3 0.128*10^3
*/
#include<stdio.h>
#include<string.h>
char A[110], B[110];
void change(char *s, int n)
{
    int i = 0, j = 0, k, e = 0, len = strlen(s);
    char tmp[110] = {0};
    while(s[i]=='0') i++;//去除前面的0
    for(j=i; s[j]!='.' && j<len; j++, e++);
    j = 0;
    tmp[j++] = '0';
    tmp[j++] = '.';
    if(s[i] == '.'){
    	  while(s[++i]=='0'){
			      e--;
		    }
		if(i == len)
			  e = 0;
	  }
	for(k=0; k<n; k++){
        if(s[i] == '.')
        	i++;
        if(i<len)
            tmp[j++] = s[i++];
        else
            tmp[j++] = '0';
    } 
    strcat(tmp, "*10^\0");
    if(e >= 0)	tmp[j+4] = '0' + e;
    else{
    	tmp[j+4] = '-';
    	tmp[j+5] = '0' - e;
	  }	
    strcpy(s, tmp);  
}
int main()
{
    int N;
    scanf("%d %s %s", &N, A, B);
    change(A, N);
    change(B, N);
    if(strcmp(A, B) == 0){
        printf("YES %s", A);
    }
    else{
        printf("NO %s %s", A, B);
    }
}
