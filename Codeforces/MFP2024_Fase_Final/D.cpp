// https://codeforces.com/group/9CNwiex6Ir/contest/530284/problem/D
// MFP 2024 Fase Final - D - Definindo Funções

#include <bits/stdc++.h>

#define int int64_t

int backtracking(int girl, int sum, int skill[6][6], bool pos[6]);

int32_t main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int skill[6][6];
    bool pos[6]={0};
    for(int i=0; i<6; i++)
        for(int j=0; j<6; j++)
            std::cin>>skill[i][j];

    std::cout<<backtracking(0, 0, skill, pos)<<'\n';

    return 0;
}

int backtracking(int girl, int sum, int skill[6][6], bool pos[6]){
    if(girl==5){
        for(int i=0; i<6; i++)
            if(pos[i]==0)
                return sum+skill[5][i];
    }
    else{
        int pts=0;
        for(int i=0; i<6; ++i){
            if(pos[i]==0){
                pos[i]=1;
                pts=std::max(pts,backtracking(girl+1, sum+skill[girl][i], skill, pos));
                pos[i]=0;
            }
        }
        return pts;
    }

    return 0;
}
