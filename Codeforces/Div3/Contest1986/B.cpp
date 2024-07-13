// https://codeforces.com/contest/1986/problem/B
// Matrix Stabilization

#include <bits/stdc++.h>

int mx[4]={1,0,-1,0},my[4]={0,1,0,-1};

int32_t greater(int i, int j, int n, int m, std::vector<std::vector<int32_t>>& grid){
    int maior=0;
    for(int k=0; k<4; ++k)
        if((i+mx[k])>=0 && (i+mx[k])<n && (j+my[k])>=0 && (j+my[k])<m)
            if(grid[i+mx[k]][j+my[k]]>=grid[i][j])
                return false;
            else maior=std::max(maior, grid[i+mx[k]][j+my[k]]);
    return maior+1;
}

int main(){

    std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);

    int t,n,m,i,j;
    std::cin>>t;

    while(t--){
        std::cin>>n>>m;
        std::vector<std::vector<int32_t>> grid (n,std::vector<int> (m));
        for(i=0; i<n; ++i)
            for(j=0; j<m; ++j)
                std::cin>>grid[i][j];

        for(i=0; i<n; ++i){
            for(j=0; j<m; ++j){
                int key=greater(i,j,n,m,grid);
                if(key)
                    grid[i][j]=key-1; 
            }
        }
           
        for(int a=0; a<n; ++a){
            for(int b=0; b<m; ++b)
                std::cout<<grid[a][b]<<' ';
            std::cout<<'\n';
        }

    }

    return 0;
}
