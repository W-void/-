/*
1084 Broken Keyboard (20)（20 分）提问

On a broken keyboard, some of the keys are worn out. So when you type some sentences, the characters corresponding to those keys will not appear on screen.
Now given a string that you are supposed to type, and the string that you actually type out, please list those keys which are for sure worn out.
Input Specification:
Each input file contains one test case. For each case, the 1st line contains the original string, and the 2nd line contains the typed-out string. Each string contains no more than 80 characters which are either English letters [A-Z] (case insensitive), digital numbers [0-9], or "_" (representing the space). It is guaranteed that both strings are non-empty.
Output Specification:
For each test case, print in one line the keys that are worn out, in the order of being detected. The English letters must be capitalized. Each worn out key must be printed once only. It is guaranteed that there is at least one worn out key.
Sample Input:
7_This_is_a_test
_hs_s_a_es
Sample Output:
7TI
*/
#include<stdio.h>

int main()
{
	char a[81], b[80], c[80];//因为我后面的判决条件，这里的a必须至少有81大小，否则若输入有80个字符，则结尾的'\0'将无法写入
	gets(a);
	gets(b);
	int i, j, k;
	for(i=0, j=0, k=0; a[i]; i++){
		if(a[i]!=b[j]){
			c[k++] = a[i];
		}
		else j++;
	}
	int d[80]={0}, index;
	for(i=0; i<k; i++){
		if(c[i]>='a' && c[i]<='z'){
			c[i] = c[i] + 'Z' - 'z';
			index = c[i] - 'A';
		}
		else if(c[i]>='0' && c[i]<='9')
			index = c[i] - '0' + 26;//定义数字排在英文字母之后
		else if(c[i]=='_')
			index = 36;
		else 
			index = c[i] - 'A';
		if(d[index]==0){
			putchar(c[i]);
			d[index] = 1;
		}
	}
	return 0;
}
