// https://neps.academy/br/exercise/493

#include <iostream>

int main(){
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	std::string gab,frase;
	std::cin>>gab>>frase;
	
	for(short int i=0,tam=frase.size(); i<tam; i++)
		std::cout<<gab[frase[i]-'a'];
	
	std::cout<<std::endl;
	
	return 0;
}
