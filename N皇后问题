#include<stdio.h>
#include<math.h>
int queenPos[100];  //假设 皇后 不超过 100 个 
int N;

void NQueen(int k)
{
	int i;
	if(k==N){ //N个皇后位置已摆好
		
		for( i=0; i<N; i++){
			printf("%d ", queenPos[i]);
		}
		printf("\n");
		return;
	}
	for( i=0; i<N; i++ ){ //逐列尝试第k个皇后的位置
		int j;
		for(j=0; j<k; j++){
			if( queenPos[j]==i || 
					abs(queenPos[j]-i)== abs(k-j))
				break; //冲突，尝试下个位置
		}
		if( j==k ){ //j==k 说明和前K个皇后都不冲突
			queenPos[k] = i;
			NQueen(k+1);
		}
	}
}

int main()
{
	scanf("%d", &N);
	NQueen(0);
	return 0;
}
