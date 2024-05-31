// https://neps.academy/br/exercise/389

#include <iostream>

int main(){
	
	std::string S;
	
	getline(std::cin,S);
	
	short int tam=S.size();
	for(short int i=0; i<tam; i+=2){
		if(S[i]==' '){
			i--;
			std::cout<<" ";
			continue;
		}
			
		std::cout<<S[i+1];
	}
	
	std::cout<<std::endl;
	
	return 0;
}
