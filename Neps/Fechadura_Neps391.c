// https://neps.academy/br/exercise/391

#include <stdio.h>

int main(){
	
	short int N,M,i;
    int moves=0;
	scanf("%hd %hd", &N,&M);
	
	short int Pinos[N];
	for(i=0; i<N; i++)
		scanf("%hu", &Pinos[i]);
		
	for(i=0; i<(N-1); i++){
		if(Pinos[i]<M){
			moves+=(M-Pinos[i]);
			Pinos[i+1]+=(M-Pinos[i]);
		}
		if(Pinos[i]>M){
			Pinos[i+1]-=(Pinos[i]-M);
			moves+=(Pinos[i]-M);
		}
	}
	
	printf("%d\n",moves);
	
	return 0;
}
