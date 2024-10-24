// https://judge.beecrowd.com/en/problems/view/2410
// Sim, eu podia só usar um set
#include <iostream>
#include <stdlib.h>

int main(){

	int N,resp=0,registro;
	bool *V;
	
	std::cin>>N;
	V=(bool*)calloc(1000010, sizeof(bool));
	
	for(int i=0; i<N; i++){
		std::cin>>registro;
		if(!V[registro]){
			V[registro]=1;
			resp++;
		}
	}
	
	std::cout<<resp<<std::endl;
	
	return 0;
}
