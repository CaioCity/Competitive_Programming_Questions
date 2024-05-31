// https://neps.academy/br/exercise/492

#include <iostream>

short int montar ( short int, short int*);

int main(){
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	short int N;
	std::cin>>N;
	
	short int base[N];
	for(int i=0; i<N; i++)
		std::cin>>base[i];
	
	(montar(N, base)==1)? std::cout<<"preta\n" : std::cout<<"branca\n";
		
	return 0;
}

short int montar (short int tam, short int* base){
	if(tam==1){
		return base[0];
	}
	tam--; //a prróxima fileira tem 1 bola a menos
	for(short int index=0; index<tam; index++){
		if(base[index]==base[index+1])
			base[index]=1;
		else
			base[index]= (-1);
	}
	return montar(tam, base);
}
