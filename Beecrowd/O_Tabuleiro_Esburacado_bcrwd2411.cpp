// https://judge.beecrowd.com/en/problems/view/2411

#include <iostream>
#include <stdlib.h>

int main(){

	std::pair<int,int> b1,b2,b3,b4,pos;
	b1=std::make_pair(1,3);
	b2=std::make_pair(2,3);
	b3=std::make_pair(2,5);
	b4=std::make_pair(5,4);
	pos=std::make_pair(4,3);
	
	short int N;
	char mov;
	std::cin>>N;
	
	for(int i=0; i<N; i++){
		
		std::cin>>mov;
		
		switch(mov){
			case '1':
				pos.first++;
				pos.second+=2;
				break;
			case '2':
				pos.first+=2;
				pos.second++;
				break;
			case '3':
				pos.first+=2;
				pos.second--;
				break;
			case '4':
				pos.first++;
				pos.second-=2;
				break;
			case '5':
				pos.first--;
				pos.second-=2;
				break;
			case '6':
				pos.first-=2;
				pos.second--;
				break;
			case '7':
				pos.first-=2;
				pos.second++;
				break;
			case '8':
				pos.first--;
				pos.second+=2;
				break;
		}
		
		if( pos==b1 || pos==b2 || pos==b3 || pos==b4){
			std::cout<<i+1<<std::endl;
			exit(0);
		}
	}
	
	std::cout<<N<<std::endl;
	
	return 0;
}
