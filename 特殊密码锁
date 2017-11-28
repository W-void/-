#include<stdio.h>

int GetBit(int N, int i)
{
	return ( N>>i ) & 1 ;
}

void SetBit(int *N, int i, int v)
{
	if(v){
		*N |= (1 << i);
	}
	else *N &= ~(1 << i) ;
 } 
void Flip(int *N, int i)
{
	*N ^= (1 << i);
} 

int main()
{
	int N = 0, M = 0, i = 0, j;
	char c;
	while((c=getchar()) != '\n'){
		j = c - '0';
		SetBit( &N, i++, j );
	}
	i = 0;
	while((c=getchar()) != '\n'){
		j = c - '0';
		SetBit( &M, i++, j );
	}
	int sum = i;
	//printf("%d %d\n", N, M);
	//printf("%d\n", N^M);
	N = N ^ M;
	M = N;
	int number1 = 0;
	for( i=0; i<sum-1; i++){
		//printf("%d\n", GetBit(N, i));
		if( GetBit(N, i)==1 ){
			Flip( &N, i );
			Flip( &N, i+1);
			if( i && i<(sum-2)) Flip( &N, i+2);
			number1++;
		}	
	}
	int number2 = 0;
	for( i=sum-1; i>0; i--){
		//printf("%d\n", GetBit(N, i));
		if( GetBit(M, i)==1 ){
			Flip( &M, i );
			Flip( &M, i-1);
			if( (i!=(sum-1)) && i>1) Flip( &M, i-2);
			number2++;
		}	
	}
//	printf("%p\n", 67108864);
	//printf("%d %d\n", N, M);
	int number = (!N)?number1:number2;
	if( !N || !M ) printf("%d", number);
	else printf("impossible");
}
