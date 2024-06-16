// https://codeforces.com/contest/1974/problem/B

#include <bits/stdc++.h>

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    short int T;

    std::cin>>T;
    
    while(T--){
        
        int N;
        
        std::cin>>N;
        
        char R[N];
       
        std::set<char> V;

        for(int i=0; i<N; i++){
            std::cin>>R[i];
            V.insert(R[i]);
        }
        
        std::map<char,char> conversor;
        auto inicio=V.begin(), fim=V.end();
        fim--;

        int cont=V.size()/2;

        while(cont--){
            conversor.insert(std::make_pair(*(inicio),*(fim)));
            conversor.insert(std::make_pair(*(fim),*(inicio)));
            inicio++;
            fim--;
        }
        
        if(V.size()&1){
            inicio=V.begin();
            cont = V.size()/2;
            while(cont--)
                inicio++;
           conversor.insert(std::make_pair(*inicio,*inicio));
        }

        for(int i=0; i<N; i++)
            std::cout<<(conversor.find(R[i])->second);
        
        std::cout<<std::endl;
    }

    return 0;
}
