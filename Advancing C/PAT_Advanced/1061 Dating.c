/*
1061 Dating (20)（20 分）

Sherlock Holmes received a note with some strange strings: "Let's date! 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm". It took him only a minute to figure out that those strange strings are actually referring to the coded time "Thursday 14:04" -- since the first common capital English letter (case sensitive) shared by the first two strings is the 4th capital letter 'D', representing the 4th day in a week; the second common character is the 5th capital letter 'E', representing the 14th hour (hence the hours from 0 to 23 in a day are represented by the numbers from 0 to 9 and the capital letters from A to N, respectively); and the English letter shared by the last two strings is 's' at the 4th position, representing the 4th minute. Now given two pairs of strings, you are supposed to help Sherlock decode the dating time.
Input Specification:
Each input file contains one test case. Each case gives 4 non-empty strings of no more than 60 characters without white space in 4 lines.
Output Specification:
For each test case, print the decoded time in one line, in the format "DAY HH:MM", where "DAY" is a 3-character abbreviation for the days in a week -- that is, "MON" for Monday, "TUE" for Tuesday, "WED" for Wednesday, "THU" for Thursday, "FRI" for Friday, "SAT" for Saturday, and "SUN" for Sunday. It is guaranteed that the result is unique for each case.
Sample Input:
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
Sample Output:
THU 14:04
*/
#include<stdio.h>
#include<string.h>

int main()
{
	char a[60], b[60], c[10]={0};
	char *day[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	gets(a);
	gets(b);
	int i, f=1;//f是防止后面的相同字母将前两个覆盖掉 
	for(i=0; a[i]&&b[i]; i++){
		if(a[i]==b[i]){
			if(f==1){
				int j=a[i]-'A';
				if(j>=0 && j<7){
					c[0] = day[j][0], c[1]=day[j][1], c[2] = day[j][2], c[3]=' ';
					f++; 
				}
			}
			else if(f==2){
				int j = a[i] - '0';
				if(j>=0 && j<=9){
					c[4] = '0', c[5] = '0'+j;
					f++;
				}
				else{
					j = a[i] -'A';
					if(j>=0 && j<=13){
						c[4] = '1'+j/10, c[5] = '0'+j%10;
						f++;
					}
				}
			}	
		}	
	}
	gets(a);
	gets(b);
	for(i=0; a[i]&&b[i]; i++){
		if(a[i]==b[i]){
			if(a[i]>='A' && a[i]<='Z' || a[i]>='a' && a[i]<='z'){
				c[6] = ':', c[7] = '0' + i/10, c[8] = '0' + i%10;
				break;//防止被后面的相同字母覆盖掉 
			}
		}
	}
	puts(c); 
}
