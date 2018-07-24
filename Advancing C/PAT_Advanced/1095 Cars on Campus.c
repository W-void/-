// 题挺碎的，不难
/*
1095 Cars on Campus (30)（30 分）提问

Zhejiang University has 6 campuses and a lot of gates. From each gate we can collect the in/out times and 
the plate numbers of the cars crossing the gate. Now with all the information available, you are supposed to tell, 
at any specific time point, the number of cars parking on campus, and at the end of the day find the cars that 
have parked for the longest time period.
Input Specification:
Each input file contains one test case. Each case starts with two positive integers N (<= 10000), the number of records, 
and K (<= 80000) the number of queries. Then N lines follow, each gives a record in the format
plate_number hh:mm:ss status
where plate_number is a string of 7 English capital letters or 1-digit numbers; hh:mm:ss represents the time point in a day by hour:minute:second, with the earliest time being 00:00:00 and the latest 23:59:59; and status is either in or out.
Note that all times will be within a single day. Each "in" record is paired with the chronologically next record for the same car provided it is an "out" record. Any "in" records that are not paired with an "out" record are ignored, as are "out" records not paired with an "in" record. It is guaranteed that at least one car is well paired in the input, and no car is both "in" and "out" at the same moment. Times are recorded using a 24-hour clock.
Then K lines of queries follow, each gives a time point in the format hh:mm:ss. Note: the queries are given in ascending order of the times.
Output Specification:
For each query, output in a line the total number of cars parking on campus. The last line of output is supposed to give the plate number of the car that has parked for the longest time period, and the corresponding time length. If such a car is not unique, then output all of their plate numbers in a line in alphabetical order, separated by a space.
16 7
JH007BD 18:00:01 in
ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in
JH007BD 05:09:59 in
ZA3Q625 11:42:01 out
JH007BD 05:10:33 in
ZA3Q625 06:30:50 in
JH007BD 12:23:42 out
ZA3Q625 23:55:00 in
JH007BD 12:24:23 out
ZA133CH 17:11:22 out
JH007BD 18:07:01 out
DB8888A 06:30:50 in
05:10:00
06:30:50
11:00:00
12:23:42
14:00:00
18:00:00
23:59:00
Sample Output:
1
4
5
2
1
0
1
JH007BD ZD00001 07:20:09
*/
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 struct cNode{
   char id[10], state[4];
   int time;
 }car[10010], car2[10010];
 struct Node{
   char id[10];
   int time;
 }car3[5000];
 int cmp1(const void* a, const void* b)
 {
   int x = strcmp(((struct cNode*)a)->id, ((struct cNode*)b)->id);
   if(!x)
     x = ((struct cNode*)a)->time - ((struct cNode*)b)->time;
   return x;
 }
int cmp2(const void* a, const void* b)
{
  int x = ((struct cNode*)a)->time - ((struct cNode*)b)->time;
  return x;
}
 int main()
 {	  
   int N, K, i, j, h, m, s;
   scanf("%d%d", &N, &K);
   for(i=0; i<N; i++){
     scanf("%s %d:%d:%d %s", car[i].id, &h, &m, &s, car[i].state);
     car[i].time =(h * 60 + m) * 60  + s;
   }
   qsort(car, N, sizeof(car[0]), cmp1);
   //for(i=0; i<N; i++)
   	//	printf("%s %d %s\n", car[i].id, car[i].time, car[i].state);
   	//	puts("");
   for(i=0, j=0; i<N-1; i++){
     if(strcmp(car[i].id, car[i+1].id)==0 && car[i].state[0]=='i' && car[i+1].state[0]=='o'){
       car2[j++] = car[i];
       car2[j++] = car[i+1];
       i++;
     }
   }
  // for(i=0; i<j; i++)
  // 		printf("%s %d %s\n", car2[i].id, car2[i].time, car2[i].state);
   char tmp[10] = "";
   int cnt = -1, max_t=0;
   for(i=0; i<j; i++,i++){
     if(strcmp(car2[i].id, tmp)){
	   cnt++;
       strcpy(car3[cnt].id, car2[i].id);
       strcpy(tmp, car2[i].id);
       car3[cnt].time = car2[i+1].time - car2[i].time;
     }
    else
      car3[cnt].time += car2[i+1].time - car2[i].time;
    if(max_t<car3[cnt].time)
      max_t = car3[cnt].time;
   }
  // for(i=0; i<=cnt; i++)
   	//	printf("%s %d \n", car3[i].id, car3[i].time);
   int num = j, t;
   qsort(car2, j, sizeof(car2[0]), cmp2);
     // for(i=0; i<j; i++)
   	//	printf("%s %d %s\n", car2[i].id, car2[i].time, car2[i].state);
   int c = 0;//c用来记录个数，因为询问的时间是升序的，所以不用每次都从0开始数，继续上次的结果数就可以
   for(i=0,j=0; i<K; i++){
     scanf("%d:%d:%d", &h, &m, &s);
     t =(h * 60 + m) * 60  + s;
     for(; j<num && car2[j].time<=t; j++){
        if(car2[j].state[0]=='i')
          c++;
        else c--;
     }
     printf("%d\n", c);
   }
  for(i=0; i<=cnt; i++) if(car3[i].time==max_t)
    printf("%s ", car3[i].id);    
  printf("%02d:%02d:%02d", max_t/3600, max_t%3600/60, max_t%60);
  return 0;
 }
