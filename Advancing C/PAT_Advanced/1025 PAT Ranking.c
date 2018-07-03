/*
1025 PAT Ranking (25)（25 分）

Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. 
Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. 
Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive number N (<=100), 
the number of test locations. Then N ranklists follow, each starts with a line containing a positive integer K (<=300), 
the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. 
All the numbers in a line are separated by a space.
Output Specification:
For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:
registration_number final_rank location_number local_rank
The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. 
The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their
registration numbers.
Sample Input:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
Sample Output:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
	char id[15];
	int score, rank, loc_num;
}stu[30001];
int cmp(const void* a, const void* b)
{
	int i = ((struct student*)b)->score - ((struct student*)a)->score;
	if(!i){
		i = strcmp(((struct student*)a)->id, ((struct student*)b)->id);
	}
	return i;
}
int main()
{
 	//freopen("G:/Dec-Cpp/8.txt", "r", stdin);
	int N, K, i, j, k, num=0;
	scanf("%d", &N);
	for(i=0; i<N; i++){
		scanf("%d", &K);
		for(j=0; j<K; j++){
			scanf("%s%d", stu[num].id, &stu[num].score);
			stu[num].loc_num = i+1;
			num++;
		}
		qsort(stu+num-K, K, sizeof(struct student), cmp);
		stu[num-K].rank = 1;
		for(j=1; j<K; j++){
			if(stu[num-K+j].score != stu[num-K+j-1].score)
				stu[num-K+j].rank =j + 1;
			else
				stu[num-K+j].rank = stu[num-K+j-1].rank;
			//printf("%d\n", stu[j].rank);
		}
	}
	printf("%d\n", num);
	qsort(stu, num, sizeof(struct student), cmp);
	for(i=0, j=1; i<num; i++){
		if(i && stu[i].score != stu[i-1].score)
			j = i+1;
		printf("%s %d %d %d\n", stu[i].id, j, stu[i].loc_num, stu[i].rank);
	}
}
