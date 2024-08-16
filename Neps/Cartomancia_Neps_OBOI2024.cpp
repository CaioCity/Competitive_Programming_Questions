// https://neps.academy/br/competition/2006/exercise/2731
// B - Cartomancia

#include <bits/stdc++.h>

#define int int64_t

int32_t main (){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int N, Eacc=0,Wacc=0,sorte=0, Esorte=0, Wsorte=0;
    std::cin>>N;

    std::string Enzo, Wolf, gab;
    std::cin>>Enzo>>Wolf>>gab;

    for(int i=0; i<N; ++i){
        
        if(gab[i]=='?'){
            if(Enzo[i]!=Wolf[i]){ ++Esorte; ++Wsorte; }
            continue;
        }

        if(Enzo[i]=='?')
            ++Esorte; 
        if(Enzo[i]==gab[i])
            ++Eacc;
        if(Wolf[i]=='?')
            ++Wsorte;
        if(Wolf[i]==gab[i])
            ++Wacc;
    }

    // std::cout<<"Eacc = "<<Eacc<<" "<<Esorte<<" = Esorte\n";
    // std::cout<<"Wacc = "<<Wacc<<" "<<Wsorte<<" = Wsorte\n";

    if(Eacc==Wacc && Esorte+Wsorte==0)
        std::cout<<"Empate\n";
    else if(Eacc > Wacc+Wsorte)
        std::cout<<"Enzo\n";
    else if(Wacc > Eacc+Esorte)
        std::cout<<"Lobo\n";
    else std::cout<<"Indefinido\n";

    return 0;
}
