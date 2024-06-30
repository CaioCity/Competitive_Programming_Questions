// https://atcoder.jp/contests/abc360/tasks/abc360_a
// A Healthy Breakfast

#include <bits/stdc++.h>

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    std::string S;
    std::cin>>S;

    if(S[2]=='M' || (S[1]=='M' && S[0]=='R'))   
        std::cout<<"Yes\n";
    else std::cout<<"No\n";

    return 0;
}
