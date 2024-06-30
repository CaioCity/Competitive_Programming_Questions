// https://atcoder.jp/contests/abc360/tasks/abc360_b
// Vertical Reading

#include <bits/stdc++.h>

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    std::string S,T,aux;
    std::cin>>S>>T;

    int tam=S.size();

    for(int w=1; w<tam; ++w){
        for(int c=0; c<w; ++c){
            aux="";
            for(int i=0; i*w+c < tam; ++i)
                aux+=S[i*w+c];
            if(aux==T){
                std::cout<<"Yes\n";
                return 0;
            }
        }
    }

    std::cout<<"No\n";

    return 0;
}
