// https://atcoder.jp/contests/abc364/tasks/abc364_b
// B - Grid Walk

#include <bits/stdc++.h>

#define int int64_t

int32_t main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int H,W,Si,Sj;
    std::cin>>H>>W>>Si>>Sj;
    --Si;--Sj;

    std::string grid[H];
    for(int i=0; i<H; ++i)
        std::cin>>grid[i];

    std::string moves;
    std::cin>>moves;

    for(char a : moves){
        switch(a){
            case 'R': if(Sj+1<W && grid[Si][Sj+1]=='.') ++Sj; break;
            case 'L': if(Sj-1>=0 && grid[Si][Sj-1]=='.') --Sj; break;
            case 'D': if(Si+1<H && grid[Si+1][Sj]=='.') ++Si; break;
            case 'U': if(Si-1>=0 && grid[Si-1][Sj]=='.') --Si; break;
        }
    }

    std::cout<<Si+1<<' '<<Sj+1<<'\n';

    return 0;
}
