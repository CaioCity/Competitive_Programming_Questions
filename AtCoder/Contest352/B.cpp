// https://atcoder.jp/contests/abc352/tasks/abc352_b
// Typing

#include <iostream>

int main(){
	
	std::string S,T;
	
	std::cin>>S>>T;
	
	int tamS=S.size();
	int resp[tamS];
	bool avance;
	
	for(int i=0,j=0; i<tamS;i++){
		avance=0;
		for(; !avance; j++){
			if(S[i]==T[j]){
				resp[i]=(j+1);
				avance=1;
			}
		}
	}
	
	std::cout<<resp[0];
	for(int i=1; i<tamS; i++)
		std::cout<<" "<<resp[i];
	
	std::cout<<std::endl;
	
	return 0;
}

