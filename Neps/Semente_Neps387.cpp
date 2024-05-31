// https://neps.academy/br/exercise/387

#include <iostream>
#include <cmath>

int main(){
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	int Fita, maior_dist=0;
	short int N_gotas;
	std::cin>>Fita>>N_gotas;
	
	int  first_gota;
	std::cin>>first_gota;
	
	int gota=first_gota, last_gota=first_gota;
	for(short int i=1; i<N_gotas; i++){
		std::cin>>gota;
		maior_dist= (maior_dist>(gota-last_gota-1))? maior_dist : (gota-last_gota-1);
		last_gota=gota;
	}
	
	int tempo= ( ceil(maior_dist/2.0) > (first_gota-1))? ceil(maior_dist/2.0) : (first_gota-1);
	tempo= (tempo>(Fita-gota))? tempo:(Fita-gota);
	std::cout<<tempo<<std::endl;
	return 0;
}

