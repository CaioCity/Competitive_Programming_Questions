https://judge.beecrowd.com/en/problems/view/1021

#include <stdio.h>

int main (){
	//Separação de N
	double N; 
	scanf("%lf", &N);
	int n =(int)N ;
	int n2 = (int)100*((n%2==0 && (n%5!=1))? N-n:N-n+1);
	int i=0,aux;
	
	//Parte Notas
	printf("NOTAS:\n");
	int V[7]={100,50,20,10,5,2};
	while(i<6){
		aux= (n/V[i])*V[i];
		printf("%d nota(s) de R$ %d.00\n", n/V[i], V[i]);
		n-=aux;
		i++;
	}
	
	//Parte moedas
	printf("MOEDAS:\n");
	V[2]=25, V[5]=1;
	i=0;
	while(i<6){
		aux= (n2/V[i])*V[i];
		printf("%d moeda(s) de R$ %.2f\n", n2/V[i] ,(float)V[i]/100);
		n2-=aux;
		i++;
	}
	
	return 0;
}
