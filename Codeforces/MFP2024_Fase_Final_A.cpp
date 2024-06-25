// https://codeforces.com/group/9CNwiex6Ir/contest/530284/problem/A
// MFP 2024 Fase Final - A - Arrumando Bandeiras

#include <bits/stdc++.h>

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int N;

    std::cin>>N;

    std::vector<std::string> tipos(26);
    tipos[0]="a";
    for(int i=1; i<16; i++)
        tipos[i]=tipos[i-1]+(char)('a'+i)+tipos[i-1];
    
    if(N>=17){
        std::string ans;
        std::string aux;
        for(int i=16; i<N; i++){
            int count=0;
            for(int j=0; count<100000 && j<tipos[i-1].size(); j++, count++)            
                tipos[i]+=tipos[i-1][j];
            if(count++<100000)
                tipos[i]+=(char)('a'+i);
            for(int j=0; count<100000 && j<tipos[i-1].size(); j++, count++)            
                tipos[i]+=tipos[i-1][j];    
        }
    }
    
        std::cout<<tipos[N-1]<<'\n';
    return 0;
}
