// https://codeforces.com/group/9CNwiex6Ir/contest/530284/problem/I
// MFP 2024 Fase Final - I - Inquietação Musical

#include <bits/stdc++.h>

int32_t main(){

    // std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int N,M,pts,ans=0,sum=0,number=0,j=0;
    char carac;
    std::string word;

    std::cin>>N>>carac;

    std::vector<std::string> music(N);

    getline(std::cin, music[0]);
    music[0]=carac+music[0];
    
    for(int i=1; i<N; ++i)
        getline(std::cin, music[i]);

    std::cin>>M;
    std::unordered_map<std::string, int> nota;
    for(int i=0;i<M; i++){
        std::cin>>word;
        std::cin>>pts;
        nota[word]=pts;
    }

    int sz=music.size();
    for(int k=0; k<sz; k++){ 
        std::string& S=music[k];
        int tam=S.size();
        pts=0;
        for(int i=0; i<tam; i++){
            word.clear();
            while(i<tam && S[i]!=' '){
                word+=S[i];
                ++i;
            }
            pts+=nota[word];
            sum+=nota[word];
        }
        if(ans<=pts){
            ans=pts;
            number=j;
        }
        ++j;
    }

    std::cout<<sum<<" "<<number+1<<'\n';
    return 0;
}
