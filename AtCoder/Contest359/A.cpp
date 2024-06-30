// https://atcoder.jp/contests/abc359/tasks/abc359_a
// Count Takahashi

#include <iostream>

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    std::string S;
    short int N,ans=0;
    std::cin>>N;
    while(N--){
        std::cin>>S;
        if(S!="Aoki")
            ans++;
    }
    std::cout<<ans<<'\n';
    return 0;
}
