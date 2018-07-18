// copy from B1015
/*
1062 Talent and Virtue (25)（25 分）

About 900 years ago, a Chinese philosopher Sima Guang wrote a history book in which he talked about people's talent and virtue. According to his theory, a man being outstanding in both talent and virtue must be a "sage（圣人）"; being less excellent but with one's virtue outweighs talent can be called a "nobleman（君子）"; being good in neither is a "fool man（愚人）"; yet a fool man is better than a "small man（小人）" who prefers talent than virtue.
Now given the grades of talent and virtue of a group of people, you are supposed to rank them according to Sima Guang's theory.
Input Specification:
Each input file contains one test case. Each case first gives 3 positive integers in a line: N (<=10^5^), the total number of people to be ranked; L (>=60), the lower bound of the qualified grades -- that is, only the ones whose grades of talent and virtue are both not below this line will be ranked; and H (<100), the higher line of qualification -- that is, those with both grades not below this line are considered as the "sages", and will be ranked in non-increasing order according to their total grades. Those with talent grades below H but virtue grades not are cosidered as the "noblemen", and are also ranked in non-increasing order according to their total grades, but they are listed after the "sages". Those with both grades below H, but with virtue not lower than talent are considered as the "fool men". They are ranked in the same way but after the "noblemen". The rest of people whose grades both pass the L line are ranked after the "fool men".
Then N lines follow, each gives the information of a person in the format:
ID_Number Virtue_Grade Talent_Grade
where ID_Number is an 8-digit number, and both grades are integers in [0, 100]. All the numbers are separated by a space.
Output Specification:
The first line of output must give M (<=N), the total number of people that are actually ranked. Then M lines follow, each gives the information of a person in the same format as the input, according to the ranking rules. If there is a tie of the total grade, they must be ranked with respect to their virtue grades in non-increasing order. If there is still a tie, then output in increasing order of their ID's.
Sample Input:
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
Sample Output:
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student{
	int num, score_d, score_c, sum;
}*stu;
int cmp(void const *a, void const *b)
{
	int i = (*(struct student*)b).sum-(*(struct student*)a).sum;
	if(i==0){
		i = (*(struct student*)b).score_d-(*(struct student*)a).score_d;
		if(i==0)
			i = (*(struct student*)a).num-(*(struct student*)b).num;
	}
	return i;
}
void print_stu(int i)
{
	printf("%d %d %d\n", stu[i].num, stu[i].score_d, stu[i].score_c);
}
int main()
{
	int N, L, H;
	scanf("%d%d%d", &N, &L, &H);
	stu = (struct student*)malloc(N*sizeof(struct student));
	int i, j;
	int a, b, c;
	for(i=0, j=0; i<N; i++){
		scanf("%d%d%d", &a, &b, &c);
		if(b>=L && c>=L){
			stu[j].num = a;
			stu[j].score_d = b;
			stu[j].score_c = c;
			stu[j].sum = b+c;
			j++;
		}	
	}
	printf("%d\n", j);
	qsort(stu, j, sizeof(stu[0]), cmp);//先按总分排序，再分四次输出四类学生
	for(i=0; i<j; i++){
		if(stu[i].score_d>=H && stu[i].score_c>=H){
			print_stu(i);
		}
	}
	for(i=0; i<j; i++){
		if(stu[i].score_d>=H && stu[i].score_c<H){
			print_stu(i);
		}
	}
	for(i=0; i<j; i++){
		if(stu[i].score_d<H &&stu[i].score_c<=stu[i].score_d&& stu[i].score_c<H ){
			print_stu(i);
		}
	}
	for(i=0; i<j; i++){
		if(stu[i].score_d<H && stu[i].score_c>stu[i].score_d){
			print_stu(i);
		}
	}
}
