// https://neps.academy/br/exercise/1022
// Estrada

#include <bits/stdc++.h>

int main(){
    
    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int T,N;
    std::cin>>T>>N;

    int city[N+2];
    float menor=INT64_MAX,aux;

    city[0]=0;
    city[N+1]=T;
    
    for(int i=1; i<=N; i++)
        std::cin>>city[i];

    std::sort(city,city+N+2);  
    
    for(int i=2; i<N; i++){
        aux= (city[i+1]-city[i])/2.0 + (city[i]-city[i-1])/2.0;
        menor= menor<aux? menor:aux;
    }

    aux = city[1] + (city[2]-city[1])/2.0; 
    menor= menor<aux? menor:aux;
    aux = aux = T-city[N] + (city[N]-city[N-1])/2.0;
    menor= menor<aux? menor:aux;

    std::cout<<std::fixed<<std::setprecision(2);
    std::cout<<menor<<'\n';   

    return 0;
}
