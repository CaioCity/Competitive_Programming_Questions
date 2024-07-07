// https://codeforces.com/problemset/problem/258/A
// Little Elephant and Bits

#include <bits/stdc++.h>

int32_t main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    std::string S;
    std::cin>>S;

    int tam=S.size()-1;
    bool zero=0;

    for(int i=0; i<tam; ++i){
        if(S[i]=='0' && !zero)
            zero=1;
        else std::cout<<S[i];
    }

    if(zero)
        std::cout<<S[tam]<<'\n';

    return 0;
}
