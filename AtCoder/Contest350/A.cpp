// https://atcoder.jp/contests/abc350/tasks/abc350_a
// Past ABCs

#include <iostream>
	
int main(){
	
	std::string S;
	
	std::cin>>S;
	
	short int number = (S[3]-'0')*100 + (S[4]-'0')*10 + (S[5]-'0');
	
	if( number > 0 && number < 350 && number != 316)
		std::cout<<"Yes\n";
	else
		std::cout<<"No\n";
	
	return 0;
}
