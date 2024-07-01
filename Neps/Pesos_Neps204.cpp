// https://neps.academy/br/exercise/204
// Pesos

#include <bits/stdc++.h>

int32_t main() {

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int N;
    std::cin>>N;

    int box[N+1];
    box[0]=0;
    for(int i=1; i<=N; ++i){
        std::cin>>box[i];
        if(box[i]-box[i-1]>8){
            std::cout<<"N\n";
            return 0;
        }
    }

    std::cout<<"S\n";

    return 0;
}
