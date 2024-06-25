// https://codeforces.com/contest/1986/problem/A
// X Axis

#include <bits/stdc++.h>

int f(short int pos, short int a, short int b, short int c);

int main(){

    std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);

    short int t,a,b,c;
    std::cin>>t;

    while(t--){
        int ans=INT32_MAX;
        std::cin>>a>>b>>c;
        for(short int i=1; i<=10; i++)
            ans=std::min(ans,f(i,a,b,c));
        std::cout<<ans<<'\n';
    }

    return 0;
}

int f(short int pos, short int a, short int b, short int c){
    return (int)(std::abs(a-pos)+std::abs(b-pos)+std::abs(c-pos));
}
