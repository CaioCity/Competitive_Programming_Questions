// https://atcoder.jp/contests/abc356/tasks/abc356_c
// Keys

#include <bits/stdc++.h>

void bitbit (int pot2n, short int N, bool keys[]);

int main(){

    short int N,M,K,C,aux,doors;
    int answer=0,pot2n=1;

    std::cin>>N>>M>>K;

    for(short int i=0; i<N; i++)
        pot2n*=2;
        
    std::vector<std::tuple<short int, std::vector<short int>, char>> testes(M);

    for( auto&[C, vetor, caractere] : testes ){
        std::cin>>C;
        for(int i=0; i<C; i++){
            std::cin>>aux;
            vetor.push_back(aux); 
        }
        
        std::cin>>caractere;
    }

    bool keys[N];

    while(pot2n--){
        bitbit(pot2n,N,keys);
        
        doors=0;
        for( auto [C, seq, gab] : testes){
            aux=0;
            for(int i=0; i<C; i++){
                if( keys[seq[i]-1] )
                    aux++;
            }
                
            if(!(aux>=K && gab=='o') && !(aux<K && gab=='x'))
                break;
            else 
                doors++;
        }
        if(doors==M)
            answer++;
    }        

    printf("%d\n",answer);

    return 0;
}

void bitbit (int pot2n, short int N, bool keys[]){
    for(int i=0,aux=pot2n; i<N; i++){
        keys[i]=aux&1;
        aux=aux>>1;
    }
}
