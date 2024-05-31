// https://judge.beecrowd.com/en/problems/view/2493

#include <iostream>
#include <stdlib.h>
#include <vector>

char gabarito (unsigned short int);

unsigned short int* X,*Y;
int* Z;

int main(){
	
	short int T;
	
	while(std::cin>>T){
		
		X=(unsigned short int*) calloc( T, sizeof(short int) );
		Y=(unsigned short int*) calloc( T, sizeof(short int) );
		Z=(int*) calloc( T, sizeof(int) );
		
		for(int i=0; i<T; i++)
			scanf("%hu %hu=%d",&X[i],&Y[i],&Z[i]);
		
		std::string V[T];
		unsigned short int E;
		char R;
		std::vector <std::string*> Reprovados;
		short int tam=0;
		
		for( short int i=0; i<T; i++)	{
		
			std::cin>>V[i]>>E>>R;
		
			if( gabarito(E) != R ){
				Reprovados.push_back(&V[i]);
				tam++;
			}
		}		
		
		for( short int i=0; i<tam; i++){
			for(short int j=i+1; j<tam; j++){
				if( (*Reprovados[i]) > *(Reprovados[j]) ){
					std::string* aux=Reprovados[i];
					Reprovados[i]=Reprovados[j];
					Reprovados[j]=aux;
				}
			}
		}
		
		if(tam==0)
			std::cout<<"You Shall All Pass!\n";
		else if(tam==T)
			std::cout<<"None Shall Pass!\n";
		else{
			for(short int i=0, cont=0; i<tam; i++,cont++){
				if(cont)
					std::cout<<" ";
				std::cout<<*(Reprovados[i]);
			}
			std::cout<<std::endl;
		}	
			
	}
	
	return 0;
}

char gabarito (unsigned short int E ){
	
	E--;
	
	if( (X[E] - Y[E]) == Z[E])
		return '-';
	if( (X[E] + Y[E]) == Z[E])
		return '+';
	if( (X[E] * Y[E]) == Z[E])
		return '*';
		
	return 'I';
}
