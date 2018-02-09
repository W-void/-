// fscanf是真的方便
// 若不知道文件中有几组数据，可这样写：while (fscanf(fp, "%d", &num)!=EOF) //(EOF=-1)
/*
1055. 集体照 (25)

拍集体照时队形很重要，这里对给定的N个人K排的队形设计排队规则如下：

每排人数为N/K（向下取整），多出来的人全部站在最后一排；
后排所有人的个子都不比前排任何人矮；
每排中最高者站中间（中间位置为m/2+1，其中m为该排人数，除法向下取整）；
每排其他人以中间人为轴，按身高非增序，先右后左交替入队站在中间人的两侧（例如5人身高为190、188、186、175、170，
则队形为175、188、190、186、170。这里假设你面对拍照者，所以你的左边是中间人的右边）；
若多人身高相同，则按名字的字典序升序排列。这里保证无重名。
现给定一组拍照人，请编写程序输出他们的队形。

输入格式：
每个输入包含1个测试用例。每个测试用例第1行给出两个正整数N（<=10000，总人数）和K（<=10，总排数）。
随后N行，每行给出一个人的名字（不包含空格、长度不超过8个英文字母）和身高（[30, 300]区间内的整数）。
输出格式：
输出拍照的队形。即K排人名，其间以空格分隔，行末不得有多余空格。注意：假设你面对拍照者，后排的人输出在上方，前排输出在下方。

输入样例：
10 3
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159
输出样例：
Bob Tom Joe Nick
Ann Mike Eva
Tim Amy John
*/
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
struct student{
	char name[10];
	int high;
};
int cmp(const void *a, const void *b)
{
	int c = (*(struct student*)b).high - (*(struct student*)a).high;//结构体成员运算符. 高于 指针运算符 *
	if(c)
		return c;
	else
		return strcmp((*(struct student*)a).name, (*(struct student*)b).name);
}
int main()
{
	/* FILE *fp;
	fp = fopen("G:/Dec-Cpp/1.txt", "r");
	if(fp==NULL)//fopen打开文件失败返回NULL(0);
	{
		printf("open the file is error!\n");
		exit(0);
    } */
	int M, N;
	//fscanf(fp, "%d%d", &M, &N);
	scanf("%d%d", &M, &N);
	struct student* stu = (struct student*)malloc(sizeof(struct student)*M);
	int i;
	for(i=0; i<M; i++){
		//fscanf(fp, "%s%d", stu[i].name, &stu[i].high);
		scanf("%s%d", stu[i].name, &stu[i].high);
	}
	qsort(stu, M, sizeof(stu[0]), cmp);//排序
	struct student* stu2 = (struct student*)malloc(sizeof(struct student)*M);
	int x = M%N + M/N, flag=1;//x表示第一行有几个数据
	//将数据以最终顺序令存到stu2中，最后直接顺序输出stu2
	for(i=0; i<x; i++){
		strcpy(stu2[x/2+(i+1)/2*flag].name, stu[i].name);
		stu2[x/2+(i+1)/2*flag].high = stu[i].high;
		flag  = -flag;//flag一正一负代表一左一右
	}
	
	int y = N-1;//y表示除了第一行还有几行
	int j, k;
	//将剩下的数据存入stu2
	for(j=0; j<y; j++){
		flag = 1;
	    for(k=0; k<N; k++){
	      	strcpy(stu2[x+j*N+N/2+(k+1)/2*flag].name, stu[i].name);
	      	//stu2[x+j*N+N/2+(k+1)/2*flag].high = stu[i].high;	
	      	flag  = -flag, i++;
	    }
   }
	//printf("%d %d %d\n", x, M, N);
    //顺序输出stu2
	for(i=0; i<x-1; i++){
		printf("%s ", stu2[i].name);		
	}
	printf("%s\n", stu2[i++].name);	
	for(j=0; j<y; j++){
		for(k=0; k<M/N; k++)
			printf("%s%c", stu2[i++].name, k!=M/N-1?' ':'\n');
		
	}
	//fclose(fp);
}
