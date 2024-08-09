// https://codeforces.com/contest/1999/problem/B
// B - Card Game

#include <bits/stdc++.h>

#define int int64_t

int solve();

int32_t main (){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int t;
        
    std::cin>>t;

    while(t--)
        std::cout<<solve()<<'\n';

    return 0;
}

int solve(){
    int a1,a2,b1,b2,M1=0,M2=0;
    std::cin>>a1>>a2>>b1>>b2;

    if(a1<a2)
		std::swap(a1,a2);
	if(b1<b2)
		std::swap(b1,b2);	

	if(a1 == a2){
		if(a1>=b1 && a1>b2)
			return 4;
		return 0;
	}

	if(a2==b2){
		if(b1==b2)
			return 4;
		if(a1>b1)
			return 2;
	}

	if(a2>b2){
		if(a2<b1 && a1>=b1)
			return 2;
		if(a2>=b1)
			return 4;
	}		

    return 0;
}
