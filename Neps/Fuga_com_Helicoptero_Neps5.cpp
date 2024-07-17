// https://neps.academy/br/exercise/5
// Fuga com Helicoptero

#include <bits/stdc++.h>

#define int int64_t

int32_t main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int H,P,F,D;

    std::cin>>H>>P>>F>>D;

    P-=H;
    F-=H;
    H=0; 
    
    if(F<P){
        if(D==-1)
            std::cout<<"S\n";
        else std::cout<<"N\n";
    }
    else {
        if(D==1)
            std::cout<<"S\n";
        else std::cout<<"N\n";
    }
    
    return 0;
}
