// https://judge.beecrowd.com/en/problems/view/2592

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
	
	
	bool errado;
	
	while(1){
		
		unsigned short int i,N, *gabarito,*resposta;
		scanf("%hu",&N);
		
		if(N==0)
			break;
			
			
		gabarito = (unsigned short int*) calloc(N+5, sizeof(short int));
		resposta = (unsigned short int*) calloc(N+5, sizeof(short int));
		
		for( i=0; i<N; i++)	
			gabarito[i]=i+1;
			
		int tentativas = 0;
		
		do{
			
		tentativas++;
		errado=0;
		for( i=0; i<N; i++)
			scanf("%hu", resposta+i);

		for( i=0; i<N; i++){
	
		//	printf("Comparando resp[%d] com gab[%d], %d e %d\n", i,i, resposta[i], gabarito[i]);
			if(resposta[i]!=gabarito[i]){
				errado=1;
				break;
			}
		//	printf("errado=%d\n", errado);
		}
		} while(errado==1);
		
	//	printf("SAI DO LOOP");
		printf("%d\n",tentativas);	
		
		free(gabarito);
		free(resposta);
	}
		
	return 0;
}
