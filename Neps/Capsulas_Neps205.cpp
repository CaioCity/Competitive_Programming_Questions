// https://neps.academy/br/exercise/205

#include <bits/stdc++.h>

#define int int64_t
int bs( int inicio, int fim, int N, int target, int V[] );

int64_t coins (int dia, int N, int V[]);

int32_t main() {

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int N,F,min;
    std::cin>>N>>F;

    int ciclo[N];

    for(int i=0; i<N; ++i){
        std::cin>>ciclo[i];
        min=std::min(min,ciclo[i]);
    }

    int limite = F*min +10;
    std::cout<<bs(0,limite, N, F, ciclo)<<'\n';

    return 0;
}

int bs( int inicio, int fim, int N, int target, int V[] ){

    if(fim-inicio<=1){
        if(coins(inicio, N, V) >= target)
            return inicio;
        else if (coins(fim, N, V) >= target)
            return fim;
        return fim+1;
    }

    int meio= (inicio+fim)/2;
    int aux=coins(meio, N, V);

    if(aux==target){
        --meio;
        while(meio>=0 && coins(meio, N, V)==target) 
            --meio;
        return 1+meio;
    }

    if(aux<target)
        return bs(meio+1, fim, N, target, V);
    if(aux>target)
        return bs(inicio, meio-1, N, target, V);

    return 1;
}

int64_t coins (int dia, int N, int V[]){
    int64_t ans=0;
    for(int i=0; i<N; ++i)
        ans+=(dia/V[i]);
    return ans;
}
