// https://atcoder.jp/contests/abc350/tasks/abc350_b
// Dentist Aoki

#include <iostream>
#include <stdlib.h>

int main(){
	
	short int N,Q;
	short int operado;
	bool *mouth=0;
	
	std::cin>>N>>Q;
	
	mouth=(bool*) calloc(N+3, sizeof(bool));
	
	for(int i=0; i<Q; i++){
		std::cin>>operado;

		if(!mouth[operado]){
			mouth[operado]=1;
			N--;
		}
		else{
			mouth[operado]=0;
			N++;
		}
	}
	
	std::cout<<N<<std::endl;
	
	return 0;
}
