// https://codeforces.com/problemset/problem/1985/H1
// H1 - Maximize the Largest Component (Easy Version)

#include <bits/stdc++.h>

#define int int64_t
#define DEBUG(x) std::cout<<#x<<" = "<<x<<'\n';
const int INF = 1ll<<55;
int mx[4] = {1,0,-1,0}, my[4] = {0,1,0,-1};

int32_t main(){

    std::ios::sync_with_stdio(0),std::cin.tie(0);

    int t;
    std::cin>>t;
    
    while(t--){

        int N,M,a,b,ans=0;
        std::cin>>N>>M;

        std::vector<std::string> grid0 (N);
        std::vector<std::vector<int>> grid (N, std::vector<int> (M, 0));
        std::vector<int> conex(1); // Indexar em 1, 1a pos eh lixo

        for(int i=0; i<N; ++i){
            std::cin>>grid0[i];
            grid0[i] = grid0[i];
        }

        for(int number = 1,i=0; i<N; ++i)
            for(int j=0; j<M; ++j)
                if(grid0[i][j]=='#' && grid[i][j]==0){
                    int tam = 0;
                    std::queue<std::pair<int,int>> fila;
                    fila.push({i,j});
                    while(!fila.empty()){
                        std::tie(a,b) = fila.front();
                        fila.pop();

                        if(grid[a][b]!=0)
                            continue;
                        grid[a][b] = number;
                        ++tam;

                        for(int A,B,k=0; k<4; ++k){
                            A = a + mx[k]; 
                            B = b + my[k];
                            if( A>=0 && A<N && B>=0 && B<M && grid0[A][B]=='#' && grid[A][B]==0 )
                                fila.push({A,B});
                        }
                    }
                    conex.push_back(tam);
                    ++number;
                }
        
        for(int i=0; i<N; ++i){
            int sum = M;
            std::unordered_set<int> S;
            for(int j=0; j<M; ++j){
                for(int k=-1; k<2; ++k)
                    if(i+k>=0 && i+k<N)
                        S.insert(grid[i+k][j]);
                if(grid[i][j]!=0)
                    --sum;
            }
            for(int C : S)
                sum+=conex[C];
            ans = std::max(ans,sum);
        }
        
        for(int j=0; j<M; ++j){
            int sum = N;
            std::unordered_set<int> S;
            for(int i=0; i<N; ++i){
                if(grid[i][j]!=0) --sum;
                for(int k=-1; k<2; ++k)
                    if(j+k>=0 && j+k<M)
                        S.insert(grid[i][j+k]);
            }
            for(int C : S)
                sum+=conex[C];
            ans = std::max(ans,sum);
        }

        std::cout<<ans<<'\n';
    }

    return 0;
}
