// https://atcoder.jp/contests/abc357/tasks/abc357_b
// Uppercase and Lowercase

#include <bits/stdc++.h>

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    std::string S;
    int upper=0;

    std::cin>>S;
    
    int tam=S.length();
    for(int i=0; i<tam; i++)
        if(S[i]>='A' && S[i]<='Z')
            upper++;

    if(upper<(tam-upper))
        for(int i=0; i<tam; i++){
            if(S[i]>='A' && S[i]<='Z')
                S[i]-=('A'-'a');
            std::cout<<S[i];    
        }
    else{
        for(int i=0; i<tam; i++){
            if(S[i]>='a' && S[i]<='z')
                S[i]-=('a'-'A');
            std::cout<<S[i];    
        }
    }

    std::cout<<'\n';

    return 0;
}
