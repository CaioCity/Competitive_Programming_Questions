// https://neps.academy/br/exercise/264
// Fusoes - Union find

#include <bits/stdc++.h>

void unir(int A,int B, std::vector<int>& pai, std::vector<int>& filhos);

int find (int B, std::vector<int>& pai);

int main(){

    std::ios::sync_with_stdio(0),std::cin.tie(0), std::cout.tie(0);

    int N,K;
    char X;
    int B1,B2;

    std::cin>>N>>K;

    std::vector<int> filhos (N+3,1), pai(N+3);
    for(int i=0; i<=N; i++)
        pai[i]=i;

    while(K--){
        std::cin>>X>>B1>>B2;
        if(X=='F') unir(B1,B2,pai,filhos);
        else if(find(B1,pai)==find(B2,pai))
            std::cout<<"S\n";
        else std::cout<<"N\n";
    }

    return 0;
}

void unir(int A,int B, std::vector<int>& pai, std::vector<int>& filhos){
    A=find(A,pai); B=find(B,pai);
    if(filhos[A]>filhos[B]){
        pai[B]=A;
        filhos[A]++;
    }
    else {
        pai[A]=B;
        filhos[B]++;
    }
}

int find (int B, std::vector<int>& pai){
    if(pai[B]==B)
        return B;
    return pai[B]=find(pai[B],pai);
}
