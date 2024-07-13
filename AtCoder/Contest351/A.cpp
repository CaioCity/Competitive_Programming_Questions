// https://atcoder.jp/contests/abc351/tasks/abc351_a
// The bottom of the ninth

#include<iostream>

int main() { 

    int A, B, sumA=0, sumB=0;
    
    for(int i=0; i<9; i++){
    	std::cin>>A;
    	sumA+=A;    	
	}
    	
    for(int i=0; i<8; i++){
    	std::cin>>B;
    	sumB+=B;
	}
    
    std::cout<<(sumA-sumB+1)<<std::endl;
 
    return 0;
}
