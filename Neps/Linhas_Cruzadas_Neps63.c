// https://neps.academy/br/exercise/63

#include <stdio.h>
#include <stdlib.h>

int main(){
	
	unsigned short int N,i,j,*V,aux;
	unsigned int count=0,countif=0,countelse=0;
	
	scanf("%hu",&N);
	
	V=(unsigned short int*) calloc(N+5,sizeof(unsigned short int));
	
	for(i=1; i<=N;i++)
		scanf("%hu", &V[i]);
		
	for(i=1; i<=N;i++){
		if(i<(N/2)){
			for(j=1; j<i; j++)
				if(V[i]<V[j])
					count++;
		}
		else{
			aux=N-V[i];
			for(j=N; i<j; j--)
				if(V[i]<V[j])
					aux--;
			count+=aux;
		}
	}

	printf("%u\n", count);
	
	return 0;
}
