// https://codeforces.com/contest/1993/problem/B
// Parity and Sum

#include <bits/stdc++.h>

#define int int64_t

int32_t main (){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int t, N, A, impar, par, maior_impar, maior_par;
        
    std::cin>>t;

    while(t--){
        std::cin>>N;

        std::vector<int> pares;

        impar=0, maior_impar = 0, maior_par = 0;

        for(int i=0; i<N; ++i){
            std::cin>>A;
            if(A&1){
                ++impar;
                maior_impar = maior_impar<A? A : maior_impar;
            }
            else {
                maior_par = maior_par<A? A : maior_par;
                pares.push_back(A);
            }
        }

        std::sort(pares.begin(), pares.end());

        if(impar != 0 && impar!=N){
            int bonus=0;
      
            for(int par : pares){
                while(par>maior_impar){
                    maior_impar+=maior_par;
                    ++bonus;
                }
                maior_impar += par;
            }

            std::cout<<N-impar+bonus<<'\n';
        }
        else std::cout<<"0\n";
    }

    return 0;
}
