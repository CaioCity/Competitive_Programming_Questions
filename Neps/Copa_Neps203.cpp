// https://neps.academy/br/exercise/203
// Copa

#include <bits/stdc++.h>

int main() {

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int K,L;
    std::cin>>K>>L;

    int pot=8;

    std::map<int,std::string> ans;

    ans[8]="final";
    ans[4]="semifinal";
    ans[2]="quartas";
    ans[1]="oitavas";

    while(pot!=1){

        if(K>pot ^ L>pot){
            std::cout<<ans[pot]<<'\n';
        return 0;
        }

        if(K>pot){
            K-=pot;
            L-=pot;
        }

        pot>>=1;
    }

    std::cout<<"oitavas\n";

    return 0;
}
