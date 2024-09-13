// https://neps.academy/br/exercise/2835
// 2835 - Machine Learning

#include <bits/stdc++.h>

#define int int64_t
#define DEBUG(x) std::cout<<#x<<" = "<<x<<'\n';
const int INF = 1ll<<55;
// int mx[4] = {1,0,-1,0}, my[4] = {0,1,0,-1};

void str(std::string& S, char* arr){
    int tam = strlen(arr);
    S.resize(tam);
    for(int i=0; i<tam; ++i)
        S[i]=arr[i];
}

int32_t main(){

    // std::ios::sync_with_stdio(0),std::cin.tie(0);

    int N,K,X;
    std::cin>>N>>K;

    char aux[30];
    std::string topico,word;
    std::unordered_map<std::string, std::string> database;
    std::map<std::string,int> types;

    for(int i=0; i<N; ++i){
        scanf(" %s %d", aux, &K);
        topico = "";
        str(topico,aux);
        for(int j=0; j<K; ++j){
            scanf(" %s", aux);
            str(word,aux);
            database[word] = topico;
        }
    }

    scanf(" %lld", &X);
    for(int i=0; i<X; ++i){
        scanf(" %s", aux);
        str(word,aux);
        if(database.find(word)==database.end())
            continue;
        ++types[database.find(word)->second];
    }

    int max=0;
    for(auto [str,n] : types)
        max = (max<n)? n : max;
    for(auto [str,n] : types)
        if(n==max){
            std::cout<<str<<'\n';
            break;
        }  
    
    return 0;
}
