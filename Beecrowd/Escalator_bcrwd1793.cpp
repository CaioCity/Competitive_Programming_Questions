// https://judge.beecrowd.com/en/problems/view/1793

#include <iostream>

int main(){

	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	while(1){
		short int people;
		std::cin>>people;
		
		if(people==0)
			break;

		short int t, tlast, time=10*people;
		std::cin>>tlast;
		for(short int i=1;i<people; i++){
			std::cin>>t;
			if((tlast+10)>t)
				time-=(10-t+tlast);
			tlast=t;
		}
		
		std::cout<<time<<std::endl;
	}

	return 0;
}
