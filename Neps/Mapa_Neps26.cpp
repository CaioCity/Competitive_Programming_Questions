// https://neps.academy/br/exercise/26
// Mapa (OBI 2017)

#include <bits/stdc++.h>

int my[4]={1,0,-1,0}, mx[4]={0,1,0,-1};

#define int int64_t

int32_t main() {

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int L,C,A,B;

    bool next=1;

    std::cin>>L>>C;

    std::vector<std::string> grid (L);

    for(int i=0; i<L; ++i)
        std::cin>>grid[i];
    
    for(int i=0; i<L; ++i)
        for(int j=0; j<C; ++j)
            if(grid[i][j]=='o'){
                A=i; B=j;
                break;
            }

    while(next){

        grid[A][B]='.';

        next=0;

        for(int i=0; i<4; ++i)
            if(A+my[i]>=0 && A+my[i]<L && B+mx[i]>=0 && B+mx[i]<C && grid[A+my[i]][B+mx[i]]=='H'){
                A+=my[i]; 
                B+=mx[i];
                next=1;
                break;
            }

    }

    std::cout<<A+1<<' '<<B+1<<'\n';

    return 0;
}
