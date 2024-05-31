// https://judge.beecrowd.com/en/problems/view/1039

#include <iostream>
#include <cmath>

#define	distance(a,b,c,d) sqrt(((a-c)*(a-c))+((b-d)*(b-d)))
#define cos ((X2-X1)/distance(X1,Y1,X2,Y2))
#define sin (Y2-Y1)/distance(X1,Y1,X2,Y2)

int main(){
	
	int R1,X1,Y1,R2,X2,Y2;
	double X3,Y3;
	
	while(std::cin>>R1){
		std::cin>>X1>>Y1>>R2>>X2>>Y2;
		
		if(X1==X2 && Y1==Y2){
			if(R1>=R2)
				std::cout<<"RICO\n";
			else 
				std::cout<<"MORTO\n";
		}
		else{
			X3 = X2 + R2*cos;
			Y3 = Y2 + R2*sin;		
			
			if( distance(X1,Y1,X3,Y3) <= R1 )
				std::cout<<"RICO\n";
			else 
				std::cout<<"MORTO\n";
		}
	}
	
	return 0;
}


