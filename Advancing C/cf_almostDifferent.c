#include<stdio.h>
#include<malloc.h>

#define size 100000
typedef struct Node* Hash;
struct Node{
	int key;
	int cnt;
	Hash next;
};

Hash hashTable[size];

void creatHash()
{
	int i;
	for(i=0; i<size; i++){
		hashTable[i] = NULL;
	}
}

Hash search(int k)
{
	int loc = k%size;
	Hash ret = NULL;
	Hash tmp = hashTable[loc];
	
	while(tmp && tmp->key!=k)
		tmp = tmp->next;
	if(tmp)
		ret = tmp;
	return ret;
}

void insert(int k)
{
	int loc = k%size;
	Hash tmp = hashTable[loc];
	Hash i = search(k);
	if(i){
		i->cnt++;
	}
	else{
		Hash N = (Hash)malloc(sizeof(struct Node));
		N->key = k;
		N->cnt = 1;
		if(tmp==NULL){
			N->next = NULL;	
			
		}
		else{
			N->next = tmp;
			//tmp = N;
		}
		hashTable[loc] = N;
	}	
}
int app[200010][2];
int main()
{
	creatHash();
	int n;
	scanf("%d",&n);
	long long int a[n];
	int i;
	int ai, b, c;
	for( i=0;i<n;i++)
	{
		scanf("%lld",a+i);
		insert(a[i]);
		ai = search(a[i])?search(a[i])->cnt:0;
		b = search(a[i]-1)?search(a[i]-1)->cnt:0;
		c = search(a[i]+1)?search(a[i]+1)->cnt:0;
		app[i][0]= ai +b +c - 1;
		//printf("app %d 0 : %d %d %d %d\n",i,app[i][0] ,ai,b,c);
	}

	for( i=0;i<n;i++)
	{
		ai = search(a[i])?search(a[i])->cnt:0;
		b = search(a[i]-1)?search(a[i]-1)->cnt:0;
		c = search(a[i]+1)?search(a[i]+1)->cnt:0;
		app[i][1]=ai+b+c-1-app[i][0];
		//printf("app %d 1 : %d %d %d %d\n",i,app[i][1],ai,b,c );
	}

	unsigned long long sum1=0;
	unsigned long long sum2=0;
	for(i=0;i<n;i++)
	{
		sum1 += a[i]*(i-app[i][0]);
		sum2 += a[i]*(n-i-1-app[i][1]);
	}
	if(sum1>=sum2)
		printf("%llu", sum1-sum2);
	else
		printf("\-%llu", sum2-sum1);
	return 0;
}

