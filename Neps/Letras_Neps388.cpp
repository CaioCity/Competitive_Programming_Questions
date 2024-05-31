// https://neps.academy/br/exercise/388

#include <iostream>
#include <string>

int main(){
	
	short int n_words=0, words_com=0;
	bool essa_tem=0;
	char X,a;
	std::cin>>X;
	
	std::string ignora_enter,frase;
	getline(std::cin,frase);//ignorar o 1o enter
	getline(std::cin,frase);
	
	for(int i=0, tam=frase.size(); i<tam; i++){
		
		if(frase[i]==X)
			essa_tem=1;
		
		if(frase[i]==' '){
			if(essa_tem)
				words_com++;
			
			n_words++;
			essa_tem=0;
		}
			
	}
	
	if(essa_tem) //para pegar a ultima palavra
		words_com++;
			
	n_words++;
	
	printf("%.1f\n", words_com*100.0/n_words);	
	
	return 0;
}
