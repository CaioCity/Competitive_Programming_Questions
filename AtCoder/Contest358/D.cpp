// https://atcoder.jp/contests/abc358/tasks/abc358_d
// Souvenirs

#include <bits/stdc++.h>

int main() {

    std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);

    int N,M;
    int possible=0,j=0;
    int64_t ans=0;

    std::cin>>N>>M;

    int B[M],prices[N];

    for(int i=0; i<N; i++)
        std::cin>>prices[i];
    for(int i=0; i<M; i++)
        std::cin>>B[i];
    
    std::sort(prices,prices+N);
    std::sort(B,B+M);

    for(int i=0; i<M; i++){
        if(j==N)
            break;
        for(; j<N; j++){
            if(prices[j]>=B[i]){
                // std::cout<<"+ "<<prices[j]<<'\n';
                ans+=prices[j++];
                possible++;
                break;
            }   
        }
    }

    if(possible< M)
        std::cout<<"-1\n";
    else std::cout<<ans<<'\n';

    return 0;
}
