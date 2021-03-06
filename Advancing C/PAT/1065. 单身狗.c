//这道题和上道题类似，都是将读进来的数作为数组的下标，以达到简化的目的
/*
1065. 单身狗(25)

“单身狗”是中文对于单身人士的一种爱称。本题请你从上万人的大型派对中找出落单的客人，以便给予特殊关爱。

输入格式：
输入第一行给出一个正整数N（<=50000），是已知夫妻/伴侣的对数；随后N行，每行给出一对夫妻/伴侣——为方便起见，每人对应一个ID号，
为5位数字（从00000到99999），ID间以空格分隔；之后给出一个正整数M（<=10000），为参加派对的总人数；随后一行给出这M位客人的ID，以空格分隔。
题目保证无人重婚或脚踩两条船。
输出格式：
首先第一行输出落单客人的总人数；随后第二行按ID递增顺序列出落单的客人。ID间用1个空格分隔，行的首尾不得有多余空格。

输入样例：
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
输出样例：
5
10000 23333 44444 55555 88888
*/
#include<stdio.h>

int main()
{
	int N, a[100001]={0}, x, y;
	scanf("%d", &N);
	while(N--){
		scanf("%d%d", &x, &y);
		a[x+1]=y+1, a[y+1]=x+1;//因为初始化的0和0号ID冲突了
	}
	int K, i, count=0;
	scanf("%d", &K);
	for(i=0; i<K; i++){
		scanf("%d", &x);
		if(a[x+1]==0){//单身狗
			a[x+1] = -1;
			count++;
		}
		else{
			if(a[a[x+1]]==-1){//伴侣已经登记过了
				a[a[x+1]] = 0;//将伴侣的登记注销掉
				a[x+1] = 0;
				count--;
			}
			else{//伴侣没有来
				a[x+1] = -1;//将这个人标记为落单
				count++;
			}
		}
	}
	printf("%d\n", count);
	for(i=1; i<100001 && count>0; i++)
		if(a[i]==-1)
			printf("%05d%c", i-1, --count?' ':'\0');
}
