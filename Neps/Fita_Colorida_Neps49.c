// https://neps.academy/br/exercise/49

#include <stdio.h>
#include <stdlib.h>

void define_fita (short int last_zero, short int i, short int* Fita);

int main(){
	
	short int N,i=(-1),j,*Fita;
	scanf("%hd",&N);
	
	Fita=(short int*)calloc(N, sizeof(short int));
	
	do{
		i++;
		scanf("%hd",&Fita[i]);
	} while(Fita[i]!=0);
	
	for(j=0; j<i; j++) //vai escrever as cores da fita antes do 1o zero
		Fita[j]= (i-j)>9 ? 9 : (i-j);
	
	short int last_zero=i;
	
	for(i++; i<N; i++){ //escreve todo o meio da fita (exceto antes do 1o zero e dps do ultimo zero)
		scanf("%hd",&Fita[i]);
		if(Fita[i]==0){
			define_fita(last_zero,i,Fita);
			last_zero=i;
		}
	}
	
	for(i=last_zero+1; i<N; i++) //define o resto da fita;
		Fita[i]= (i-last_zero)>9? 9 : (i-last_zero);
		
	printf("%hd",Fita[0]); 
	for(i=1; i<N; i++)
		printf(" %hd",Fita[i]);
	printf("\n");
	
	
	free(Fita);
	return 0;
}

void define_fita (short int last_zero, short int zero, short int* Fita){
	int i;
	for(i=last_zero+1; i<zero; i++){
		Fita[i]= ((i-last_zero)<(zero-i))? (i-last_zero):(zero-i);
		Fita[i] = Fita[i]>9? 9 : Fita[i];
	}
}
